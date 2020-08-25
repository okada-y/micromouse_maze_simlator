function[maze_wall,maze_wall_search,contour_map,row_num_node,col_num_node] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,maze_goal,run_mode)%#codegen

%maze_solve 実機での迷路探索関数
%入力 迷路壁情報,迷路探索情報,迷路縦サイズ,迷路横サイズ,ゴール座標,
%出力 壁情報,探索情報

%C言語関数インクルード
if coder.target('MATLAB')
else
    coder.updateBuildInfo('addSourceFiles','C:\work\matlab\maze_sim_git\src\C_src\matlab_movement.c');
    coder.cinclude('C:\work\matlab\maze_sim_git\src\C_src\matlab_movement.h');
    coder.updateBuildInfo('addSourceFiles','C:\work\matlab\maze_sim_git\src\C_src\matlab_IR_sensor.c');
    coder.cinclude('C:\work\matlab\maze_sim_git\src\C_src\matlab_IR_sensor.h');
end

%ローカル変数定義
stop_flg = uint8(0);    % ゴール時ストップフラグ(0:移動継続　1:ストップ)
start_flg = uint8(0);   % スタートフラグ(0:動作中　1:停止からの移動開始)
goal_after_flg = uint8(0); %ゴール直後フラグ(0:ゴール直後でない, 1:ゴール直後)
wall_flg = uint8(0);    %壁フラグ(1:前、2:右、（4:後ろ)、8:左)

% グローバル変数宣言
global maze_fig;
global g_direction;
% global maze_goal;
global matrix_dir;
global g_d_direction;
global l_direction;
global move_dir_property;
global turn_pattern;

%ローカル変数宣言
new_goal = zeros(1,2,'uint8');
new_goal_size = uint8(1);
contour_map = zeros(32,32,'uint16');
row_num_node = ones(33,32,'uint16')*uint16(65535);
col_num_node = ones(32,33,'uint16')*uint16(65535);
goal_section = [0,0];

%ノードの属性定義
%0:行方向, 1:列方向,　2:セクション（マス）
matrix_dir = struct('Row',uint8(0),'Col',uint8(1),'section',uint8(2));

%絶対方角定義
g_direction = struct('North',uint8(0),'East',uint8(1),'South',uint8(2),'West',uint8(3));
%斜め込みの絶対方角定義
g_d_direction = struct('North',uint8(0),'North_East',uint8(1),'East',uint8(2),'South_East',uint8(3),...
    'South',uint8(4),'South_West',uint8(5),'West',uint8(6),'North_West',uint8(7));

%マウス方向定義
l_direction = struct('front',uint8(0),'right',uint8(1),'back',uint8(2),'left',uint8(3));

%移動方向属性定義
%直進or斜め
move_dir_property = struct('straight',uint8(0),'diagonal',uint8(1));

%パターン番号定義
turn_pattern = struct('default',uint8(0),'r_45',uint8(1),'l_45',uint8(2),'r_90',uint8(3),'l_90',uint8(4),'r_135',uint8(5),'l_135',uint8(6),'r_180',uint8(7),'l_180',uint8(8));

%壁情報定義
wall = struct('nowall',uint8(0),'wall',uint8(1));

%探索情報定義
search = struct('unknown',uint8(0),'known',uint8(1));

%走行モード定義
r_mode = struct('search',uint8(0),'fust_run',uint8(1),'fust_run_diagonal',uint8(2));

%% 探索
if run_mode == r_mode.search
    
    %マウスの初期位置設定
    current_x = uint8(1);
    current_y = uint8(1);
    current_dir = g_direction.North;
    
    if coder.target('MATLAB')
        %for MATLAB
        %迷路探索状況を表す表面を作成
        [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        %マウス位置表示用オブジェクト初期化
        [h] = hgtransform_init;
        %探索開始位置プロット
        figure(maze_fig);
        hold on
        plot(current_x * 9 -4.5,current_y * 9 -4.5,'ob','MarkerFaceColor','b','Parent',h);
        hold off
    else
        %for C gen
    end
    
    %各フラグを定義
    start_flg = uint8(1);%停止直後
    stop_flg = uint8(1);%停止処理を実施する
    goal_after_flg = uint8(0);%ゴール直後フラグはクリア
    
    %一マス前進
    [current_x,current_y] = move_step(current_x,current_y,current_dir);
    %C言語でのスタート処理
    if ~coder.target('MATLAB')
        coder.ceval('m_start_movement',start_flg,wall_flg,uint8(move_dir_property.straight));
    end
    start_flg = uint8(0);%停止直後フラグをクリア
    
    %ゴールをプロット
    goal_plot(goal_size,maze_goal);
    
    %足立法による探索
    [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map,start_flg]...
        = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,maze_goal,goal_size,start_flg,stop_flg,goal_after_flg);
    
    %ひとまづゴール(停止)
    %各フラグを定義
    start_flg = uint8(1);%停止直後
    stop_flg = uint8(0);%停止処理を実施しない
    goal_after_flg = uint8(1);%ゴール直後フラグをたてる
    
    %ゴールをすべて探索
    while 1
        search_flag = uint8(0);
        for N=1:1:goal_size
            I = maze_wall_search(maze_goal(N,2),maze_goal(N,1));
            if I ~= 15
                new_goal(1,:) = uint8([maze_goal(N,1),maze_goal(N,2)]);
                search_flag = uint8(1);
                break
            end
        end
        if search_flag == 1
            [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map,start_flg]...
                = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,new_goal,coder.ignoreConst(new_goal_size),start_flg,stop_flg,goal_after_flg);
            goal_after_flg = uint8(1);%ゴール直後フラグをたてる
        else
            break
        end
        
    end
    
    %未探索マスがなくなるまで。
    %現地点から一番近い未探索マスを探索
    %現在地からコンターマップを展開、探索済みでないマスが見つかれば、そこをゴールとする。
    
    
%     while 1
%         
%         [contour_map,max_length,new_goal] = make_map_new_goal(maze_wall,maze_wall_search,current_x,current_y);
%         if(new_goal(1) == 0)
%             %新規ゴールが見つからないとき、停止処理を実施
%             if ~coder.target('MATLAB')
%                 coder.ceval('m_goal_movement',start_flg,wall_flg,uint8(move_dir_property.straight));
%             end
%             break
%             %新規ゴールが見つかったとき。
%         else
%             %         new_goal(1,:) = [col_temp,row_temp];
%             new_goal_size = uint8(1);
%             %ゴールをプロット
%             goal_plot(new_goal_size,new_goal);
%             %既存のコンターを使用し、探索。
%             [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map,start_flg]...
%                 = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,new_goal,coder.ignoreConst(new_goal_size),start_flg,stop_flg,goal_after_flg);
%             goal_after_flg = uint8(1);%ゴール直後フラグをたてる
%         end
%     end
    
    
    %スタートを目的地として足立法で再探索
    %各フラグを定義
    start_flg = uint8(1);%停止直後
    stop_flg = uint8(1);%停止処理を実施する
    goal_after_flg = uint8(1);%ゴール直後フラグをたてる
    
    new_goal(1,:) = uint8([1,1]);
    [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map,start_flg]...
        = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,coder.ignoreConst(new_goal),coder.ignoreConst(new_goal_size),start_flg,stop_flg,goal_after_flg);
    
    if coder.target('MATLAB')
        %for MATLAB
        %探索情報を可視化
        maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
    else
        %for code generation
    end
    
end

%% 最短走行
if run_mode == r_mode.fust_run
    %探索情報をもとに等高線MAPを生成
    [contour_map,max_length] = make_map_fustrun(maze_goal,maze_wall,maze_wall_search);
    
    %コンターマップの描画
    if coder.target('MATLAB')
        for l = 1:32
            for j = 1:32
                text((j-1)*9+4.5,(l-1)*9+4.5,string(contour_map(l,j)),'HorizontalAlignment','center');
            end
        end
    end
    
    %最短距離走行
    fust_run(maze_wall,contour_map,maze_goal,max_length)
end

%% 斜めでの最短走行

if run_mode == r_mode.fust_run_diagonal
    %最短経路生成
    %ゴールマスのノードをすべてゴールノードとし、マップ生成
    [row_num_node,col_num_node,goal_num,start_num] = make_map_fustrun_diagonal(maze_goal,goal_size,maze_wall,maze_wall_search);
    
    %ゴール付近のルート最適化のため、マップ再生成
    %スタートからゴールノードまで、ルート生成し、ゴールノード、方向を確定
    [goal_node,goal_matrix_dir,goal_dir]=decide_goal_node_dir(maze_goal,goal_size,row_num_node,col_num_node);
    %確定されたゴールノード、方向からゴールマス、ノードを再定義
    [goal_section,goal_node2,goal_matrix_dir2]=decide_goal_section(maze_goal,goal_node,goal_matrix_dir,goal_dir);
    %確定されたゴールマスから、再度マップを生成
    goal_section = [goal_section(2),goal_section(1)];%x,yに変換
    [row_num_node,col_num_node,goal_num,start_num] = make_map_fustrun_diagonal(goal_section,1,maze_wall,maze_wall_search);
    
    %生成されたMAPをもとに最短走行
    make_route_diagonal(row_num_node,col_num_node,goal_section,goal_node2,goal_matrix_dir2);
    
    
end


%% search_adachi 足立法での探索
    function [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map,start_flg]...
            = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,exploration_goal,l_goal_size,start_flg,stop_flg,goal_after_flg) %#codegen
        %入力　現在位置x,y,現在方向,迷路行方向サイズ,迷路列方向サイズ,迷路壁情報,迷路壁の探索情報,ゴール座標
        %出力  現在位置x,y,現在方向,壁情報,探索情報
        
        %local変数宣言
        goal_flg = uint8(0); %ゴール判定フラグ
        temp_maze_wall = uint8(0);%壁情報更新確認用変数
        contour_flg = uint8(0);
        max_l = uint16(65535);
        %     search_start_x = current_x %探索開始時x
        %     search_start_y = current_y %探索開始時y
        search_start_x = uint8(1);
        search_start_y = uint8(1);
        
        %初回のコンターマップ作製
        [contour_map,~] = make_map_find(exploration_goal,l_goal_size,maze_wall,current_x,current_y);
        
        while 1
            %壁情報取得
            %ゴール直後は壁情報を更新しない
            if goal_after_flg ~= 1
                temp_maze_wall = maze_wall(current_y,current_x);
                [maze_wall,maze_wall_search] = wall_set(maze_row_size,maze_col_size,current_x,current_y,current_dir,maze_wall,maze_wall_search);
                %壁情報が更新されれば、コンター更新のフラグを立てる。
                if temp_maze_wall ~= maze_wall(current_y,current_x)
                    contour_flg = uint8(1);
                end
            else
                %ゴール直後のとき
                goal_after_flg= uint8(0);%ゴール直後フラグをクリア
            end
            
            
            if coder.target('MATLAB')
                maze_wall_plot(maze_wall,current_x,current_y,maze_row_size,maze_col_size);
            end
            
            % 等高線MAP生成
            %壁情報に変更があった場合のみ
            if(contour_flg)
                [contour_map,~] = make_map_find(exploration_goal,l_goal_size,maze_wall,current_x,current_y);
            end
            
            %現在位置がゴールか判定
            for i = 1:1:l_goal_size
                if (current_x == exploration_goal(i,1)) && (current_y == exploration_goal(i,2))
                    goal_flg = uint8(1);
                end
            end
            
            %ゴール時処理
            if goal_flg == 1
                if stop_flg == 1 %ゴール時停止フラグが立っているとき
                    %停止動作を実施
                    if ~coder.target('MATLAB')
                        coder.ceval('m_goal_movement',start_flg,wall_flg,uint8(move_dir_property.straight));
                    end
                end
                %ゴール時停止フラグが立っていなければ、動作させたまま終了
                break
            end
            
            % 進行方向選定
            %優先順位　北⇒東⇒南⇒西
            [next_dir] = get_nextdir2(current_x,current_y,maze_wall,contour_map,max_l);
            
            % 現在方向と進行方向に応じた処理
            switch rem((4 + next_dir - current_dir),4)
                case l_direction.front
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("front")
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_front',start_flg,wall_flg,uint8(move_dir_property.straight));
                    end
                    %スタート直後フラグをクリア
                    start_flg = uint8(0);
                    %壁フラグをクリア
                    wall_flg = uint8(0);
                    
                case l_direction.right
                    [current_dir] = turn_clk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("right")
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_right',start_flg,wall_flg,uint8(move_dir_property.straight));
                    end
                    %スタート直後フラグをクリア
                    start_flg = uint8(0);
                    %壁フラグをクリア
                    wall_flg = uint8(0);
                    
                case l_direction.back
                    [current_dir] = turn_180deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("back")
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_back',start_flg,wall_flg,uint8(move_dir_property.straight));
                    end
                    %スタート直後フラグをクリア
                    start_flg = uint8(0);
                    %壁フラグをクリア
                    wall_flg = uint8(0);
                    
                case l_direction.left
                    [current_dir] = turn_conclk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("left")
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_left',start_flg,wall_flg,uint8(move_dir_property.straight));
                    end
                    %スタート直後フラグをクリア
                    start_flg = uint8(0);
                    %壁フラグをクリア
                    wall_flg = uint8(0);
                    
                otherwise
            end
            
            if coder.target('MATLAB')
                %for MATLAB
                %オブジェクト位置更新
                hgtransform_update(h,current_x,current_y,search_start_x,search_start_y,9);
                %探索状況の更新
                maze_search_plot_update(search_surf,maze_wall_search,maze_col_size,maze_row_size);
                drawnow limitrate nocallbacks
                %pause(0.01)
            else
                %for code generation
            end
        end
    end


%% move_step 一マス前進する関数
    function [current_x,current_y] = move_step(current_x,current_y,current_dir)
        %入力 現在位置x,y,現在方向
        %出力 現在位置x,y
        
        %北に一マス
        if current_dir == g_direction.North
            current_y = current_y+1;
            %disp("north_step")
        end
        
        %東に一マス
        if current_dir == g_direction.East
            current_x = current_x+1;
            %disp("east_step")
        end
        
        %南に一マス
        if current_dir == g_direction.South
            current_y = current_y-1;
            %disp("south_step")
        end
        
        %西に一マス
        if current_dir == g_direction.West
            current_x = current_x-1;
            %disp("west_step")
        end
        
    end

%% turn_180deg 180度ターンする関数
    function [current_dir] = turn_180deg(current_dir)
        %入力 現在方向
        %出力 現在方向
        
        current_dir = rem((4+current_dir)-2,4);
        
    end

%% turn_clk_90deg 時計周りに90度ターンする関数
    function[current_dir]= turn_clk_90deg(current_dir)
        %入力 現在方向
        %出力 現在方向
        
        current_dir = rem((4+current_dir)+1,4);
        
    end

%% turn_conclk_90deg 反時計周りに90度回る関数
    function[current_dir]= turn_conclk_90deg(current_dir)
        %入力　現在方向
        %出力　現在方向
        current_dir = rem((4+current_dir) - 1,4);
        
    end

%%  wall_set 壁情報取得
    function [maze_wall,maze_wall_search] = wall_set(maze_row_size,maze_col_size,current_x,current_y,current_dir,maze_wall,maze_wall_search)
        %matlab上では画像から取得した壁情報を参照する。
        %入力:画像から得た迷路情報,迷路行方向壁枚数,迷路列方向壁枚数,
        %     現在地座標x,y,現在進行方向,迷路壁情報,迷路壁探索情報
        %出力:迷路壁情報,迷路壁探索情報
        
        %グローバル変数(matlabでは迷路データを、Cでは壁センサ値を参照)
        %for matlab
        global maze_serial;
        %for C gen
        %壁センサ閾値
        global wall_sensor_front_th;
        global wall_sensor_right_th;
        global wall_sensor_left_th;
        
        
        %ローカル変数宣言
        wall_write = uint8(zeros(1,4));%壁情報書き込み用バッファ(N,E,S,W)
        serch_write = uint8(zeros(1,4));%探索情報書き込み用バッファ(N,E,S,W)
        %壁センサAD値格納変数
        wall_sensor_front = int16(0);
        wall_sensor_right = int16(0);
        wall_sensor_left = int16(0);
        
        %マウスの方向に基づく壁情報取得
        %マウスの方向と絶対方向の差=マウスの方向となることを利用し、
        %絶対角度と整合をとる。
        
        %前方の壁判定
        if coder.target('MATLAB')
            %for matlab
            %既知の迷路情報をもとに、壁の有無を判定
            if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),current_dir) ) %非ゼロの時実行
                %壁情報取得
                wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
            end
        else
            %for Cgen
            %センサ値取得
            wall_sensor_front = coder.ceval('m_get_front_sensor');
            %センサ値をもとに、壁の有無を判定
            if int16(wall_sensor_front) > int16(wall_sensor_front_th)
                %壁情報取得
                wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
                %壁フラグセット
                wall_flg = bitor(wall_flg,1,'uint8');
            end
            
        end
        %探索情報取更新
        serch_write(uint8(1),rem(current_dir,4)+uint8(1)) = search.known;
        
        %右壁判定
        if coder.target('MATLAB')
            %for matlab
            %既知の迷路情報をもとに、壁の有無を判定
            if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+1,4)) )
                wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
            end
        else
            %for Cgen
            %センサ値取得
            wall_sensor_right = coder.ceval('m_get_right_sensor');
            %センサ値をもとに、壁の有無を判定
            if int16(wall_sensor_right) > int16(wall_sensor_right_th)
                %壁情報取得
                wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
                %壁フラグセット
                wall_flg = bitor(wall_flg,2,'uint8');
            end
        end
        %探索情報取更新
        serch_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = search.known;
        
        %後方は情報を得ることができないので処理しない。
        
        %左壁判定
        if coder.target('MATLAB')
            %for matlab
            %既知の迷路情報をもとに、壁の有無を判定
            if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+3,4)) )
                wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
            end
        else
            %for Cgen
            %センサ値取得
            wall_sensor_left = coder.ceval('m_get_left_sensor');
            %センサ値をもとに、壁の有無を判定
            if int16(wall_sensor_left) > int16(wall_sensor_left_th)
                %壁情報取得
                wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
                %壁フラグセット
                wall_flg = bitor(wall_flg,8,'uint8');
            end
        end
        %探索情報取更新
        serch_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = search.known;
        
        %ここまで
        
        %壁情報,探索情報を入力
        %北側
        maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North) * wall_write(1,g_direction.North+1));
        maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.North) * serch_write(1,g_direction.North+1));
        
        %東側
        maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East) * wall_write(1,g_direction.East+1));
        maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.East) * serch_write(1,g_direction.East+1));
        
        %南側
        maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South) * wall_write(1,g_direction.South+1));
        maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.South) * serch_write(1,g_direction.South+1));
        %西側
        maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West) * wall_write(1,g_direction.West+1));
        maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.West) * serch_write(1,g_direction.West+1));
        
        %隣り合うマスの情報にも入力
        %北側のマスの南側の壁情報
        if current_y < maze_row_size-1
            maze_wall(current_y+1,current_x) = bitor(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.South) * wall_write(1,g_direction.North+1));
            maze_wall_search(current_y+1,current_x) = bitor(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.South) * serch_write(1,g_direction.North+1));
        end
        %東側のマスの西側の壁情報
        if current_x < maze_col_size-1
            maze_wall(current_y,current_x+1) = bitor(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.West) * wall_write(1,g_direction.East+1));
            maze_wall_search(current_y,current_x+1) = bitor(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.West) * serch_write(1,g_direction.East+1));
        end
        
        %南側のマスの北側の壁情報
        if current_y > 1
            maze_wall(current_y-1,current_x) = bitor(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.North) * wall_write(1,g_direction.South+1));
            maze_wall_search(current_y-1,current_x) = bitor(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.North) * serch_write(1,g_direction.South+1));
        end
        
        %西側のマスの東側の壁情報
        if current_x > 1
            maze_wall(current_y,current_x-1) = bitor(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.East) * wall_write(1,g_direction.West+1));
            maze_wall_search(current_y,current_x-1) = bitor(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.East) * serch_write(1,g_direction.West+1));
        end
        
        %現在地がゴールでない場合
        tempx  = logical(maze_goal(1:end,1) == current_x);
        tempy  = logical(maze_goal(1:end,2) == current_y);
        temp = ~max(tempx .* tempy);
        if(temp)
            
            %柱に対し、3方向探索済みかつ、すべて壁がない場合、もう一方向の壁を確定させる。
            %北,東に壁がない場合
            if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))...
                    && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))
                
                %北のマスの東が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.East))...
                        && (bitand(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))
                    %東のマスの北の壁が確定、探索済みとする。
                    maze_wall(current_y,current_x+1) = bitor(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.North));
                    maze_wall_search(current_y,current_x+1) = bitor(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.North));
                    %隣り合うマス（東北マス）の南の壁も確定
                    maze_wall(current_y+1,current_x+1) = bitor(maze_wall(current_y+1,current_x+1),bitshift(uint8(1),g_direction.South));
                    maze_wall_search(current_y+1,current_x+1) = bitor(maze_wall_search(current_y+1,current_x+1),bitshift(uint8(1),g_direction.South));
                end
                %東のマスの北が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.North))...
                        && (bitand(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))
                    %北のマスの東の壁が確定、探索済みとする。
                    maze_wall(current_y+1,current_x) = bitor(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.East));
                    maze_wall_search(current_y+1,current_x) = bitor(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.East));
                    %隣り合うマス（東北マス）の西の壁も確定
                    maze_wall(current_y+1,current_x+1) = bitor(maze_wall(current_y+1,current_x+1),bitshift(uint8(1),g_direction.West));
                    maze_wall_search(current_y+1,current_x+1) = bitor(maze_wall_search(current_y+1,current_x+1),bitshift(uint8(1),g_direction.West));
                end
                
                
            end
            
            %北,西に壁がない場合
            if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))...
                    && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))
                %北のマスの西が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.West))...
                        && (bitand(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))
                    %西のマスの北の壁が確定、探索済みとする。
                    maze_wall(current_y,current_x-1) = bitor(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.North));
                    maze_wall_search(current_y,current_x-1) = bitor(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.North));
                    %隣り合うマス（北西マス）の南の壁も確定
                    maze_wall(current_y+1,current_x-1) = bitor(maze_wall(current_y+1,current_x-1),bitshift(uint8(1),g_direction.South));
                    maze_wall_search(current_y+1,current_x-1) = bitor(maze_wall_search(current_y+1,current_x-1),bitshift(uint8(1),g_direction.South));
                end
                
                %西のマスの北が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.North))...
                        && (bitand(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))
                    %北のマスの西の壁が確定、探索済みとする。
                    maze_wall(current_y+1,current_x) = bitor(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.West));
                    maze_wall_search(current_y+1,current_x) = bitor(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.West));
                    %隣り合うマス（北西マス）の東の壁も確定
                    maze_wall(current_y+1,current_x-1) = bitor(maze_wall(current_y+1,current_x-1),bitshift(uint8(1),g_direction.East));
                    maze_wall_search(current_y+1,current_x-1) = bitor(maze_wall_search(current_y+1,current_x-1),bitshift(uint8(1),g_direction.East));
                end
            end
            
            %南,東に壁がない場合
            if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))...
                    && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South))
                %南のマスの東が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.East))...
                        && (bitand(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))
                    %東のマスの南の壁が確定、探索済みとする。
                    maze_wall(current_y,current_x+1) = bitor(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.South));
                    maze_wall_search(current_y,current_x+1) = bitor(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.South));
                    %隣り合うマス（南東マス）の北の壁も確定
                    maze_wall(current_y-1,current_x+1) = bitor(maze_wall(current_y-1,current_x+1),bitshift(uint8(1),g_direction.North));
                    maze_wall_search(current_y-1,current_x+1) = bitor(maze_wall_search(current_y-1,current_x+1),bitshift(uint8(1),g_direction.North));
                end
                %東のマスの南が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.South))...
                        && (bitand(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South))
                    %南のマスの東の壁が確定、探索済みとする。
                    maze_wall(current_y-1,current_x) = bitor(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.East));
                    maze_wall_search(current_y-1,current_x) = bitor(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.East));
                    %隣り合うマス（南東マス）の西の壁が確定。探索済みとする
                    maze_wall(current_y-1,current_x+1) = bitor(maze_wall(current_y-1,current_x+1),bitshift(uint8(1),g_direction.West));
                    maze_wall_search(current_y-1,current_x+1) = bitor(maze_wall_search(current_y-1,current_x+1),bitshift(uint8(1),g_direction.West));
                end
            end
            
            %南,西に壁がない場合
            if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))...
                    && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South))
                %南のマスの西が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.West))...
                        && (bitand(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))
                    %西のマスの南の壁が確定、探索済みとする。
                    maze_wall(current_y,current_x-1) = bitor(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.South));
                    maze_wall_search(current_y,current_x-1) = bitor(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.South));
                    %隣り合うマス（南西マス）の北の壁が確定。探索済みとする
                    maze_wall(current_y-1,current_x-1) = bitor(maze_wall(current_y-1,current_x-1),bitshift(uint8(1),g_direction.North));
                    maze_wall_search(current_y-1,current_x-1) = bitor(maze_wall_search(current_y-1,current_x-1),bitshift(uint8(1),g_direction.North));
                end
                %西のマスの南が探索済み　かつ　壁がないとき
                if bitand(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.South))...
                        && (bitand(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South))
                    %南のマスの西の壁が確定、探索済みとする。
                    maze_wall(current_y-1,current_x) = bitor(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.West));
                    maze_wall_search(current_y-1,current_x) = bitor(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.West));
                    %隣り合うマス（南西マス）の東の壁が確定。探索済みとする
                    maze_wall(current_y-1,current_x-1) = bitor(maze_wall(current_y-1,current_x-1),bitshift(uint8(1),g_direction.East));
                    maze_wall_search(current_y-1,current_x-1) = bitor(maze_wall_search(current_y-1,current_x-1),bitshift(uint8(1),g_direction.East));
                end
            end
        end
    end
%% make_map_new_goal 現在位置から新規のゴールを目指すためのMAPを作る。
    function [contour_map,max_length,new_goal] = make_map_new_goal(maze_wall,maze_wall_search,current_x,current_y)
        
        % 迷路パラメータ設定
        max_length = uint16(65535);
        %新規ゴール座標格納用変数
        new_goal = uint8([0,0]);
        
        %コンター更新マス保管用
        contor_renew_square = zeros(1024,2,'uint8'); %更新座標
        contor_renew_square_temp = zeros(1024,2,'uint8'); %更新座標更新用
        contor_renew_square_idx = uint8(1);%更新座標
        contor_renew_square_idx_temp = uint8(1);%更新座標更新用
        
        %MAPの初期化(すべての要素にmax_lengthを入力)
        %32マス分mapを保持
        %16bitにすべき
        contour_map = ones(32,32,'uint16');
        contour_map = contour_map * max_length;
        
        %スタート地点の歩数を1だけ減らし、判別可能な状態にする。
        contour_map(current_y,current_x) = max_length - uint16(1);
        
        %初回の更新座標 = 現在位置　を入力
        contor_renew_square(1,:) = [current_y,current_x];
        
        %現在の位置からコンターを展開。
        %未探索位置にコンターが展開されればそこを新規ゴールとし、終了する。
        for tempi = 0:1:max_length-1 %歩数カウントは0~max_length
            %map更新確認用フラグ
            change_flag = uint8(0);
            
            %更新された座標に対し、コンターマップを展開
            for tempn = 1:1:contor_renew_square_idx
                %北側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.North)) == wall.nowall)
                    %北側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) == max_length
                        contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) = max_length-(tempi + uint16(2));
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        %更新した地点が未探索領域であれば、そこを新規ゴール点とし、コンター展開を終了する。
                        if(maze_wall_search(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) ~=15)
                            new_goal = [contor_renew_square(tempn,2),contor_renew_square(tempn,1)+1];
                            break
                        end
                    end
                end
                
                %東側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.East)) == wall.nowall)
                    %東側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) == max_length
                        contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = max_length-(tempi + uint16(2));
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        %更新した地点が未探索領域であれば、そこを新規ゴール点とし、コンター展開を終了する。
                        if(maze_wall_search(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) ~=15)
                            new_goal = [contor_renew_square(tempn,2)+1,contor_renew_square(tempn,1)];
                            break
                        end
                    end
                end
                
                %南側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.South)) == wall.nowall)
                    %南側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) == max_length
                        contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) = max_length-(tempi + uint16(2));
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        %更新した地点が未探索領域であれば、そこを新規ゴール点とし、コンター展開を終了する。
                        if(maze_wall_search(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) ~=15)
                            new_goal = [contor_renew_square(tempn,2),contor_renew_square(tempn,1)-1];
                            break
                        end
                    end
                end
                
                %西側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.West)) == wall.nowall)
                    %西側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) == max_length
                        contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = max_length-(tempi + uint16(2));
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        %更新した地点が未探索領域であれば、そこを新規ゴール点とし、コンター展開を終了する。
                        if(maze_wall_search(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) ~=15)
                            new_goal = [contor_renew_square(tempn,2)-1,contor_renew_square(tempn,1)];
                            break
                        end
                    end
                end
            end
            %ゴール更新マスの更新とインデックスのクリア
            contor_renew_square = contor_renew_square_temp;
            contor_renew_square_temp = zeros(1024,2,'uint8');
            contor_renew_square_idx = contor_renew_square_idx_temp -1 ;
            contor_renew_square_idx_temp = uint8(1);
            
            %更新がない、もしくはゴールが設定されていれば終了
            if change_flag == uint8(0)  || new_goal(1) ~=0
                %disp(tempi)
                break;
            end
        end
        
    end


%%  make_map_find 壁情報から等高線MAPを生成
    function [contour_map,max_length] = make_map_find(maze_goal,l_goal_size,maze_wall,current_x,current_y)
        %入力 迷路縦サイズ,迷路横サイズ,ゴール座標,迷路情報(16進数)
        %出力 等高線map,最大経路長
        
        % 迷路パラメータ設定
        max_length = uint16(65535);
        
        %コンター更新マス保管用
        contor_renew_square = zeros(1024,2,'uint8'); %更新座標
        contor_renew_square_temp = zeros(1024,2,'uint8'); %更新座標更新用
        contor_renew_square_idx = uint8(1);%更新座標
        contor_renew_square_idx_temp = uint8(1);%更新座標更新用
        
        %MAPの初期化(すべての要素にmax_lengthを入力)
        %32マス分mapを保持
        %16bitにすべき
        contour_map = ones(32,32,'uint16');
        contour_map = contour_map * max_length;
        
        %ゴール座標に0を入力
        for temp = 1:1:l_goal_size
            contour_map(maze_goal(temp,2),maze_goal(temp,1)) = uint16(0);
            %初回の更新座標 = ゴール座標　を入力
            contor_renew_square(temp,:) = [maze_goal(temp,2),maze_goal(temp,1)];
            contor_renew_square_idx = uint8(temp);
        end
        
        
        
        
        for tempi = 0:1:max_length-1 %歩数カウントは0~max_length
            %map更新確認用フラグ
            change_flag = uint8(0);
            %更新された座標に対し、歩数mapを更新
            for tempn = 1:1:contor_renew_square_idx
                %北側
                %if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North)) == wall.nowall)
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),...
                        bitshift(uint8(1),g_direction.North)) == wall.nowall)
                    %北側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) == max_length
                        contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) = tempi+uint16(1);
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                    end
                end
                
                %東側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),...
                        bitshift(uint8(1),g_direction.East)) == wall.nowall)
                    %東側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) == max_length
                        contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = tempi+uint16(1);
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp + 1;
                    end
                end
                
                %南側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),...
                        bitshift(uint8(1),g_direction.South)) == wall.nowall)
                    %南側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) == max_length
                        contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) = tempi+uint16(1);
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp + 1;
                    end
                end
                
                %西側
                if (bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),...
                        bitshift(uint8(1),g_direction.West)) == wall.nowall)
                    %西側のMAPが更新されているか判断、されていなければ書き込み
                    if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) == max_length
                        contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = tempi+uint16(1);
                        change_flag = uint8(1);
                        %更新マスを更新
                        contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1];
                        %更新マス用インデックスを増加
                        contor_renew_square_idx_temp = contor_renew_square_idx_temp + 1;
                    end
                end
            end
            %ゴール更新マスの更新とインデックスのクリア
            contor_renew_square = contor_renew_square_temp;
            contor_renew_square_temp = zeros(1024,2,'uint8');
            contor_renew_square_idx = contor_renew_square_idx_temp -1 ;
            contor_renew_square_idx_temp = uint8(1);
            %更新がない、もしくは現在位置が更新されていれば終了
            if change_flag == uint8(0) ||  contour_map(current_y,current_x) ~= max_length
                disp(tempi)
                break;
            end
        end
    end

%% get_nextdir2 等高線mapから次に向かう方向を選択
    function [next_dir] = get_nextdir2(current_x,current_y,maze_wall,contour_map,max_length)
        % 入力 現在地x,y,壁情報,等高線map,最大経路長
        % 出力 次の進行方角
        
        %出力の初期化
        next_dir = uint8(0);
        
        little = max_length;
        
        %%進行方向選定
        %優先順位　北⇒東⇒南⇒西
        
        %北側の壁のありなし判定
        if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) == 0
            %北側の等高線mapが閾値より低ければ、
            if contour_map(current_y+1,current_x) < little
                %閾値を北側の等高map値に変更
                little = contour_map(current_y+1,current_x);
                %北側を進行方向に変更y
                next_dir = g_direction.North;
            end
        end
        
        %東側
        if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) == 0
            if contour_map(current_y,current_x+1) < little
                little = contour_map(current_y,current_x+1);
                next_dir = g_direction.East;
            end
        end
        
        
        %南側
        if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) == 0
            if contour_map(current_y-1,current_x) < little
                little = contour_map(current_y-1,current_x);
                next_dir = g_direction.South;
            end
        end
        
        %西側
        if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) == 0
            if contour_map(current_y,current_x-1) < little
                % little = contour_map(current_y,current_x-1);
                next_dir = g_direction.West;
            end
        end
    end


%% fust_run 最短経路走行
    function [] = fust_run(maze_wall,contour_map,maze_goal,max_length)
        %入力　壁情報,壁探索情報,等高線MAP,ゴール座標,最大経路長
        %出力
        
        %local変数宣言
        goal_flag = uint8(0);  %ゴール判定フラグ
        little = max_length; %進行方向選定用閾値
        tempi = uint8(0);
        
        %マウス位置表示用オブジェクト
        if coder.target('MATLAB')
            ax = gca;
            h = hgtransform('Parent',ax);
        end
        %マウスの初期位置設定
        current_x = uint8(1);
        current_y = uint8(1);
        
        previous_x = current_x;
        previous_y = current_y;
        
        
        current_dir = g_direction.North;
        next_dir = g_direction.North;
        search_start_x = current_x; %探索開始時x
        search_start_y = current_y; %探索開始時y
        
        %探索開始位置プロット
        if coder.target('MATLAB')
            hold on
            plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'ob','MarkerSize',10,'MarkerFaceColor','r','Parent',h);
            hold off
        end
        
        %     %足跡プロット
        %     hold on
        %     plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r');
        %     hold off
        %     drawnow limitrate nocallbacks
        
        while 1
            
            %現在位置がゴールか判定
            for tempi = 1:1:goal_size
                if (current_x == maze_goal(tempi,1)) && (current_y == maze_goal(tempi,2))
                    goal_flag = uint8(1);
                end
            end
            
            if goal_flag == 1
                break
            end
            
            %%進行方向選定
            %優先順位　北⇒東⇒南⇒西
            
            %北側の壁のありなし
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) == wall.nowall
                %北側の等高線mapが閾値より低ければ、
                if contour_map(current_y+1,current_x) < little
                    %閾値を北側の等高map値に変更
                    little = contour_map(current_y+1,current_x);
                    %北側を進行方向に変更y
                    next_dir = g_direction.North;
                end
            end
            
            %東側
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) == wall.nowall
                if contour_map(current_y,current_x+1) < little
                    little = contour_map(current_y,current_x+1);
                    next_dir = g_direction.East;
                end
            end
            
            %南側
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) == wall.nowall
                if contour_map(current_y-1,current_x) < little
                    little = contour_map(current_y-1,current_x);
                    next_dir = g_direction.South;
                end
            end
            
            %西側
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) == wall.nowall
                if contour_map(current_y,current_x-1) < little
                    little = contour_map(current_y,current_x-1);
                    next_dir = g_direction.West;
                end
            end
            
            
            
            %%現在方向と進行方向に応じた処理
            switch rem((4 + next_dir - current_dir),4)
                case l_direction.front
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("front")
                    
                case l_direction.right
                    [current_dir] = turn_clk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("right")
                    
                case l_direction.back
                    [current_dir] = turn_180deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("back")
                    
                case l_direction.left
                    [current_dir] = turn_conclk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("left")
                    
                otherwise
            end
            
            if coder.target('MATLAB')
                %for MATLAB
                %マウス描画位置更新
                m = makehgtform('translate',double(current_x-search_start_x)*9,double(current_y-search_start_y)*9,0);
                h.Matrix = m;
                %軌跡プロット
                hold on
                plot([double(previous_x)*9-4.5,double(current_x)*9-4.5],[double(previous_y)*9-4.5,double(current_y)*9-4.5]...
                    ,'Color','#D95319','LineWidth',3)
                %             plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r');
                hold off
                drawnow limitrate nocallbacks
            else
                %for code generation
            end
            
            previous_x = current_x;
            previous_y = current_y;
        end
    end

%% make_map_fustrun 最短走行用等高線MAPを生成
    function [contour_map,max_length] = make_map_fustrun(maze_goal,maze_wall,maze_wall_search)
        %未知壁の領域は仮想壁をおいて侵入しない。
        %入力 迷路縦サイズ,迷路横サイズ,ゴール座標,迷路情報(16進数),迷路探索情報(16進数)
        %出力 等高線map,最大経路長
        
        %コンター更新マス保管用
        contor_renew_square = zeros(1024,2,'uint8'); %更新座標
        contor_renew_square_temp = zeros(1024,2,'uint8'); %更新座標更新用
        contor_renew_square_idx = uint8(1);%更新座標
        contor_renew_square_idx_temp = uint8(1);%更新座標更新用
        
        %ローカル変数設定
        tempn=uint8(0);
        tempi=uint8(0);
        
        %パラメータ設定
        straight_weight = uint16(5);
        
        % 迷路パラメータ設定
        max_length = uint16(65535);
        
        %MAPの初期化(すべての要素にmax_lengthを入力)
        %32マス分mapを保持
        contour_map = ones(32,32,'uint16');
        contour_map = contour_map * max_length;
        
        %進行方向補完用変数定義
        move_dir_map = zeros(32,32,'uint8');
        
        %ゴール座標に
        % 歩数マップ：0を入力
        % 進行方向 : 1+2+4+8(東西南北すべて)=15
        % を入力
        for tempn = 1:1:goal_size
            contour_map(maze_goal(tempn,2),maze_goal(tempn,1)) = uint16(0);
            move_dir_map(maze_goal(tempn,2),maze_goal(tempn,1)) = bitshift(uint8(1),g_direction.North)...
                +bitshift(uint8(1),g_direction.East)...
                +bitshift(uint8(1),g_direction.South)...
                +bitshift(uint8(1),g_direction.West);
            %初回の更新座標 = ゴール座標　を入力
            contor_renew_square(tempn,:) = [maze_goal(tempn,2),maze_goal(tempn,1)];
            contor_renew_square_idx = uint8(tempn);
        end
        
        for tempi = 0:1:max_length-1 %更新確認用の歩数カウントは0~max_length
            
            change_flag = uint8(0); %更新フラグのクリア
            %検索した座標に対し、歩数mapを更新
            for tempn = 1:1:contor_renew_square_idx
                
                %北側
                
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.North))) == search.known
                    
                    %かつ進行方向が北向きである時
                    if logical(bitand(move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.North)))
                        %かつ北のマスが更新予定値よりも大きな値の場合
                        if contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+1
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(row(tempn)+1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                            %歩数MAP更新
                            contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+uint16(1);
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) = bitshift(uint8(1),g_direction.North);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                        
                        %かつ進行方向が北向きでないとき
                    else
                        %かつ北のマスの歩数MAP値が、更新予定値より大きい場合
                        if contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight
                            %歩数MAP更新(重みづけあり)
                            contour_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight;
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)) = bitshift(uint8(1),g_direction.North);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)+1,contor_renew_square(tempn,2)];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                    end
                end
                
                
                %東側
                
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.East))) == search.known
                    
                    %かつ進行方向が東向きである時
                    if logical(bitand(move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.East)))
                        %かつ東のマスが更新予定値よりも大きな値の場合
                        if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+1
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(row(tempn),col(tempn)+1) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                            %歩数MAP更新
                            contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+uint16(1);
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = bitshift(uint8(1),g_direction.East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                        
                        %かつ進行方向が東向きでないとき
                    else
                        %かつ東のマスの歩数MAP値が、更新予定値より大きい場合
                        if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = contour_refine_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+uint16(1);
                            %歩数MAP更新(重みづけあり)
                            contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight;
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1) = bitshift(uint8(1),g_direction.East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                    end
                end
                
                %南側
                
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.South))) == search.known
                    
                    %かつ進行方向が南向きである時
                    if logical(bitand(move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.South)))
                        %かつ南のマスが更新予定値よりも大きな値の場合
                        if contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+1
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(row(tempn)-1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                            %歩数MAP更新
                            contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+uint16(1);
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) = bitshift(uint8(1),g_direction.South);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                        
                        %かつ進行方向が南向きでないとき
                    else
                        %かつ南のマスの歩数MAP値が、更新予定値より大きい場合
                        if contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(row(tempn)-1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                            %歩数MAP更新(重みづけあり)
                            contour_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight;
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)) = bitshift(uint8(1),g_direction.South);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1)-1,contor_renew_square(tempn,2)];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                    end
                end
                
                %西側
                
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.West))) == search.known
                    
                    %かつ進行方向が西向きである時
                    if logical(bitand(move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)),bitshift(uint8(1),g_direction.West)))
                        %かつ北のマスが更新予定値よりも大きな値の場合
                        if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+1
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = contour_refine_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+uint16(1);
                            %歩数MAP更新
                            contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+uint16(1);
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = bitshift(uint8(1),g_direction.West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                            
                        end
                        
                        %かつ進行方向が西向きでないとき
                    else
                        %かつ北のマスの歩数MAP値が、更新予定値より大きい場合
                        if contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) > contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight
                            %                                 %更新確認用のMAP更新
                            %                                 contour_refine_map(row(tempn),col(tempn)-1) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                            %歩数MAP更新(重みづけあり)
                            contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = contour_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2))+straight_weight;
                            %移動方向MAP更新
                            move_dir_map(contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1) = bitshift(uint8(1),g_direction.West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新マスを更新
                            contor_renew_square_temp(contor_renew_square_idx_temp,:) = [contor_renew_square(tempn,1),contor_renew_square(tempn,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_square_idx_temp = contor_renew_square_idx_temp+1;
                        end
                    end
                end
            end
            %ゴール更新マスの更新とインデックスのクリア
            contor_renew_square = contor_renew_square_temp;
            contor_renew_square_temp = zeros(1024,2,'uint8');
            contor_renew_square_idx = contor_renew_square_idx_temp -1 ;
            contor_renew_square_idx_temp = uint8(1);
            %更新がなければ終了
            if change_flag == 0
                break;
            end
        end
    end

%% make_map_fustrun_diagonal 最短走行用等高線MAPを生成
    function [row_num_node,col_num_node,goal_num,start_num] = make_map_fustrun_diagonal(maze_goal,goal_size,maze_wall,maze_wall_search)
        %未知壁の領域は仮想壁をおいて侵入しない。
        %入力 迷路縦サイズ,迷路横サイズ,ゴール座標,迷路情報(16進数),迷路探索情報(16進数)
        %出力 等高線map,最大経路長
        
        %ローカル変数設定
        %コンター更新ノード(行)保管用
        contor_renew_node_row = zeros(1024,2,'uint8'); %更新座標
        contor_renew_node_row_temp = zeros(1024,2,'uint8'); %更新座標更新用
        contor_renew_node_row_idx = uint8(1);%更新座標
        contor_renew_node_row_idx_temp = uint8(1);%更新座標更新用
        %コンター更新ノード（列）保管用
        contor_renew_node_col = zeros(1024,2,'uint8'); %更新座標
        contor_renew_node_col_temp = zeros(1024,2,'uint8'); %更新座標更新用
        contor_renew_node_col_idx = uint8(1);%更新座標
        contor_renew_node_col_idx_temp = uint8(1);%更新座標更新用
        
        %パラメータ設定
        
        % 迷路パラメータ設定
        max_length = uint16(32*32);
        
        % ルートの重み設定
        weight_straight = uint16(6);
        weight_straight_harf = uint16(3);
        weight_diagonal = uint16(4);
        weight_turn = uint16(18);
        
        %MAPの初期化(すべてのノードにmax_lengthを入力)
        %歩数MAP
        row_num_node = ones(33,32,'uint16')*uint16(65535);
        col_num_node = ones(32,33,'uint16')*uint16(65535);
        % %更新用MAP
        % row_num_node_temp = ones(33,32,'uint16')*uint16(65535);
        % col_num_node_temp = ones(32,33,'uint16')*uint16(65535);
        %進行方向保持用ノード作成
        row_dir_node = zeros(33,32,'uint8');
        col_dir_node = zeros(32,33,'uint8');
        
        %ゴールセクションが確定している場合
        goal_num = uint16(0);
        start_num = uint16(65535);
        if goal_size == 1
            goal_section_l = maze_goal(1,:);
            
            %ゴールマスから、東西南北にマップを展開
            %北壁
            if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.North))
                %歩数更新
                row_num_node(goal_section_l(2)+1,goal_section_l(1)) = weight_straight_harf;
                %方向追加
                row_dir_node(goal_section_l(2)+1,goal_section_l(1)) ...
                    = bitor(row_dir_node(goal_section_l(2)+1,goal_section_l(1)),bitshift(uint8(1),g_d_direction.North));
                %更新ノードを更新
                contor_renew_node_row(contor_renew_node_row_idx,:) = [goal_section_l(2)+1,goal_section_l(1)];
                %更新マス用インデックスを増加
                contor_renew_node_row_idx = contor_renew_node_row_idx+1;
            end
            
            %東壁
            if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.East))
                %歩数更新
                col_num_node(goal_section_l(2),goal_section_l(1)+1) = weight_straight_harf;
                %方向追加
                col_dir_node(goal_section_l(2),goal_section_l(1)+1) ...
                    = bitor(col_dir_node(goal_section_l(2),goal_section_l(1)+1),bitshift(uint8(1),g_d_direction.East));
                %更新ノードを更新
                contor_renew_node_col(contor_renew_node_col_idx,:) = [goal_section_l(2),goal_section_l(1)+1];
                %更新マス用インデックスを増加
                contor_renew_node_col_idx = contor_renew_node_col_idx+1;
            end
            
            %南壁
            if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.South))
                %歩数更新
                row_num_node(goal_section_l(2),goal_section_l(1)) = weight_straight_harf;
                %方向追加
                row_dir_node(goal_section_l(2),goal_section_l(1)) ...
                    = bitor(row_dir_node(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_d_direction.South));
                %更新ノードを更新
                contor_renew_node_row(contor_renew_node_row_idx,:) = [goal_section_l(2),goal_section_l(1)];
                %更新マス用インデックスを増加
                contor_renew_node_row_idx = contor_renew_node_row_idx+1;
            end
            
            %西壁
            if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.West))
                %歩数更新
                col_num_node(goal_section_l(2),goal_section_l(1)) = weight_straight_harf;
                %方向追加
                col_dir_node(goal_section_l(2),goal_section_l(1)) ...
                    = bitor(col_dir_node(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_d_direction.West));
                %更新ノードを更新
                contor_renew_node_col(contor_renew_node_col_idx,:) = [goal_section_l(2),goal_section_l(1)];
                %更新マス用インデックスを増加
                contor_renew_node_col_idx = contor_renew_node_col_idx+1;
            end
            
            %ゴールセクションが確定していない場合
        else
            %ゴールノードに
            % 歩数：0を入力
            % 進行方向 : 壁がなければ全方向=0b11111111=255
            % を入力
            for n=1:1:goal_size
                
                %北壁
                if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.North))
                    %歩数更新
                    row_num_node(maze_goal(n,2)+1,maze_goal(n,1)) = 0;
                    %方向更新
                    row_dir_node(maze_goal(n,2)+1,maze_goal(n,1)) = 255;
                    %更新ノードを更新
                    contor_renew_node_row(contor_renew_node_row_idx,:) = [maze_goal(n,2)+1,maze_goal(n,1)];
                    %更新マス用インデックスを増加
                    contor_renew_node_row_idx = contor_renew_node_row_idx+1;
                end
                
                %東壁
                if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.East))
                    %歩数更新
                    col_num_node(maze_goal(n,2),maze_goal(n,1)+1) = 0;
                    %方向更新
                    col_dir_node(maze_goal(n,2),maze_goal(n,1)+1) = 255;
                    %更新ノードを更新
                    contor_renew_node_col(contor_renew_node_col_idx,:) = [maze_goal(n,2),maze_goal(n,1)+1];
                    %更新マス用インデックスを増加
                    contor_renew_node_col_idx = contor_renew_node_col_idx+1;
                end
                
                %南壁
                if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.South))
                    %歩数更新
                    row_num_node(maze_goal(n,2),maze_goal(n,1)) = 0;
                    %方向更新
                    row_dir_node(maze_goal(n,2),maze_goal(n,1)) = 255;
                    %更新ノードを更新
                    contor_renew_node_row(contor_renew_node_row_idx,:) = [maze_goal(n,2),maze_goal(n,1)];
                    %更新マス用インデックスを増加
                    contor_renew_node_row_idx = contor_renew_node_row_idx+1;
                end
                
                %西壁
                if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.West))
                    %歩数更新
                    col_num_node(maze_goal(n,2),maze_goal(n,1)) = 0;
                    %方向更新
                    col_dir_node(maze_goal(n,2),maze_goal(n,1)) = 255;
                    %更新ノードを更新
                    contor_renew_node_col(contor_renew_node_col_idx,:) = [maze_goal(n,2),maze_goal(n,1)];
                    %更新マス用インデックスを増加
                    contor_renew_node_col_idx = contor_renew_node_col_idx+1;
                end
                
            end
            %     %更新判定用変数(重みづけなしの歩数マップ)
            %     row_num_node_temp = row_num_node;
            %     col_num_node_temp = col_num_node;
            
        end
        
        
        for i = 0:1:max_length-1 %更新確認用の歩数カウントは0~max_length
            
            change_flag = uint8(0); %map更新確認用フラグ
            %Row_Edgeの処理[33行,32列]           
            %検索した座標に対し、歩数mapを更新
            for n = 1:1:contor_renew_node_row_idx-1                
                %北側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.North))) == search.known
                    %かつ進行方向が北向きである時
                    if logical(bitand(row_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North)))
                        %かつ北のノードが更新予定値よりも大きな値の場合
                        if row_num_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_straight
                            %歩数MAP更新
                            row_num_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_straight;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.North);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                            
                            %かつ北のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_straight
                            %移動方向を追加
                            row_dir_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) = bitor(row_dir_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North));
                        end
                        
                        %かつ進行方向が北向きでないとき
                    else
                        %かつ北のノードの歩数MAP値が、更新予定値より大きい場合
                        if row_num_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            row_num_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.North);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                            
                            %かつ北のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %移動方向を追加
                            row_dir_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)) = bitor(row_dir_node(contor_renew_node_row(n,1)+1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North));
                        end
                    end
                end
                
                %北東側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.East))) == search.known
                    %かつ進行方向が北東向きである時
                    if logical(bitand(row_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North_East)))
                        %かつ北東のノードが更新予定値よりも大きな値の場合
                        if col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %歩数MAP更新
                            col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) = bitshift(uint8(1),g_d_direction.North_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                             %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;                           
                                                        
                        %かつ北東のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) = bitor(col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1),bitshift(uint8(1),g_d_direction.North_East));
                        end
                        
                    %かつ進行方向が北東向きでないとき
                    else
                        %かつ北東のノードの歩数MAP値が、更新予定値より大きい場合
                        if col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) = bitshift(uint8(1),g_d_direction.North_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                             %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;         
                            
                        %かつ北東のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1) = bitor(col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)+1),bitshift(uint8(1),g_d_direction.North_East));
                        end
                    end
                end
                
                %東側は柱
                
                %南東側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.East))) == search.known
                    %かつ進行方向が南東向きである時
                    if logical(bitand(row_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South_East)))
                        %かつ南東のノードが更新予定値よりも大きな値の場合
                        if col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %歩数MAP更新
                            col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) = bitshift(uint8(1),g_d_direction.South_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;   
                            
                        %かつ南東のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) = bitor(col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1),bitshift(uint8(1),g_d_direction.South_East));
                        end
                        
                    %かつ進行方向が南東向きでないとき
                    else
                        %かつ南東のノードの歩数MAP値が、更新予定値より大きい場合
                        if col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) = bitshift(uint8(1),g_d_direction.South_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;   
                            
                            %かつ南東のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1) = bitor(col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)+1),bitshift(uint8(1),g_d_direction.South_East));
                        end
                    end
                end
                
                %南側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.South))) == search.known
                    %かつ進行方向が南向きである時
                    if logical(bitand(row_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South)))
                        %かつ南のノードが更新予定値よりも大きな値の場合
                        if row_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_straight
                            %歩数MAP更新
                            row_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_straight;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.South);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;   
                            
                        %かつ南のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_straight
                            %移動方向を追加
                            row_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitor(row_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South));
                        end
                        
                        %かつ進行方向が南向きでないとき
                    else
                        %かつ南のノードの歩数MAP値が、更新予定値より大きい場合
                        if row_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn

                            %歩数MAP更新(重みづけあり)
                            row_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.South);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;   

                        %かつ南のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %移動方向を追加
                            row_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitor(row_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South));
                        end
                    end
                end
                
                %南西側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.West))) == search.known
                    %かつ進行方向が南西向きである時
                    if logical(bitand(row_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South_West)))
                        %かつ南西のノードが更新予定値よりも大きな値の場合
                        if col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %歩数MAP更新
                            col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.South_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                            
                        %かつ南西のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitor(col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South_West));
                        end
                        
                    %かつ進行方向が南西向きでないとき
                    else
                        %かつ南西のノードの歩数MAP値が、更新予定値より大きい場合
                        if col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.South_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                            
                        %かつ南西のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)) = bitor(col_dir_node(contor_renew_node_row(n,1)-1,contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.South_West));
                        end
                    end
                end
                
                %北西側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_direction.West))) == search.known
                    %かつ進行方向が北西向きである時
                    if logical(bitand(row_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North_West)))
                        %かつ北西のノードが更新予定値よりも大きな値の場合
                        if col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %歩数MAP更新
                            col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.North_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                             %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1),contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                            
                        %かつ北西のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_diagonal
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) = bitor(col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North_West));
                        end
                        
                        %かつ進行方向が北西向きでないとき
                    else
                        %かつ北東のノードの歩数MAP値が、更新予定値より大きい場合
                        if col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) > row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) = row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) = bitshift(uint8(1),g_d_direction.North_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                             %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_row(n,1),contor_renew_node_row(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                            
                        %かつ北西のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) == row_num_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2))+weight_turn
                            %移動方向を追加
                            col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)) = bitor(col_dir_node(contor_renew_node_row(n,1),contor_renew_node_row(n,2)),bitshift(uint8(1),g_d_direction.North_West));
                        end
                    end
                end
            end
            
            %Col_Edgeの処理[32行,33列]
           
            %検索した座標に対し、歩数mapを更新
            for n = 1:1:contor_renew_node_col_idx-1
                
                %北側は壁
                
                %北東側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_direction.North))) == search.known
                    %かつ進行方向が北東向きである時
                    if logical(bitand(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.North_East)))
                        %かつ北東のノードが更新予定値よりも大きな値の場合
                        if row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %歩数MAP更新
                            row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) = bitshift(uint8(1),g_d_direction.North_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                        %かつ北東のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) = bitor(row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.North_East));
                        end
                        
                    %かつ進行方向が北東向きでないとき
                    else
                        %かつ北東のノードの歩数MAP値が、更新予定値より大きい場合
                        if row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) = bitshift(uint8(1),g_d_direction.North_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                            
                        %かつ北東のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)) = bitor(row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.North_East));
                        end
                    end
                end
                
                %東側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_direction.East))) == search.known
                    %かつ進行方向が東向きである時
                    if logical(bitand(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.East)))
                        %かつ東のノードが更新予定値よりも大きな値の場合
                        if col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_straight
                            %歩数MAP更新
                            col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_straight;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) = bitshift(uint8(1),g_d_direction.East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                            
                        %かつ東のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_straight
                            %移動方向を追加
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) = bitor(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1),bitshift(uint8(1),g_d_direction.East));
                        end
                        
                        %かつ進行方向が東向きでないとき
                    else
                        %かつ東のノードの歩数MAP値が、更新予定値より大きい場合
                        if col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) = bitshift(uint8(1),g_d_direction.East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                        %かつ東のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %移動方向を追加
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1) = bitor(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)+1),bitshift(uint8(1),g_d_direction.East));
                        end
                        
                    end
                end
                
                %南東側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_direction.South))) == search.known
                    %かつ進行方向が南東向きである時
                    if logical(bitand(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.South_East)))
                        %かつ南東のノードが更新予定値よりも大きな値の場合
                        if row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %歩数MAP更新
                            row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) = bitshift(uint8(1),g_d_direction.South_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                        %かつ南東のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) = bitor(row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.South_East));
                        end
                        
                        
                        %かつ進行方向が南東向きでないとき
                    else
                        %かつ南東のノードの歩数MAP値が、更新予定値より大きい場合
                        if row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) = bitshift(uint8(1),g_d_direction.South_East);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                        %かつ南東のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)) = bitor(row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.South_East));
                        end
                    end
                end
                
                %南側は柱
                
                %南西側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_direction.South))) == search.known
                    %かつ進行方向が南西向きである時
                    if logical(bitand(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.South_West)))
                        %かつ南西のノードが更新予定値よりも大きな値の場合
                        if row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %歩数MAP更新
                            row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitshift(uint8(1),g_d_direction.South_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                        %かつ南西のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitor(row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_d_direction.South_West));
                        end
                        
                        %かつ進行方向が南西向きでないとき
                    else
                        %かつ南西のノードの歩数MAP値が、更新予定値より大きい場合
                        if row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitshift(uint8(1),g_d_direction.South_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                        %かつ南西のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitor(row_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_d_direction.South_West));
                        end
                    end
                end
                
                %西側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_direction.West))) == search.known
                    %かつ進行方向が西向きである時
                    if logical(bitand(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.West)))
                        %かつ西のノードが更新予定値よりも大きな値の場合
                        if col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_straight
                            %歩数MAP更新
                            col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_straight;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitshift(uint8(1),g_d_direction.West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                        %かつ西のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_straight
                            %移動方向を追加
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitor(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_d_direction.West));
                        end
                        
                    %かつ進行方向が西向きでないとき
                    else
                        %かつ西のノードの歩数MAP値が、更新予定値より大きい場合
                        if col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn;
                            %移動方向MAP更新
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitshift(uint8(1),g_d_direction.West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                            %更新ノードを更新
                            contor_renew_node_col_temp(contor_renew_node_col_idx_temp,:) = [contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_node_col_idx_temp = contor_renew_node_col_idx_temp+1;
                            %かつ西のノードが更新予定値と同じ場合
                        elseif col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %移動方向を追加
                            col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1) = bitor(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_d_direction.West));
                        end
                    end
                end
                
                %北西側
                %壁が無い & 探索済みであるとき
                if logical(bitand(maze_wall(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(contor_renew_node_col(n,1),contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_direction.North))) == search.known
                    %かつ進行方向が北西向きである時
                    if logical(bitand(col_dir_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2)),bitshift(uint8(1),g_d_direction.North_West)))
                        %かつ北西のノードが更新予定値よりも大きな値の場合
                        if row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %歩数MAP更新
                            row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) = bitshift(uint8(1),g_d_direction.North_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                             %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                            
                        %かつ北西のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_diagonal
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) = bitor(row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_d_direction.North_West));
                        end
                        
                        %かつ進行方向が北西向きでないとき
                    else
                        %かつ北西のノードの歩数MAP値が、更新予定値より大きい場合
                        if row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) > col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %歩数MAP更新(重みづけあり)
                            row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) = col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn;
                            %移動方向MAP更新
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) = bitshift(uint8(1),g_d_direction.North_West);
                            %更新フラグを立てる
                            change_flag = uint8(1);
                             %更新ノードを更新
                            contor_renew_node_row_temp(contor_renew_node_row_idx_temp,:) = [contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1];
                            %更新マス用インデックスを増加
                            contor_renew_node_row_idx_temp = contor_renew_node_row_idx_temp+1;
                            %かつ北西のノードが更新予定値と同じ場合
                        elseif row_num_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) == col_num_node(contor_renew_node_col(n,1),contor_renew_node_col(n,2))+weight_turn
                            %移動方向を追加
                            row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1) = bitor(row_dir_node(contor_renew_node_col(n,1)+1,contor_renew_node_col(n,2)-1),bitshift(uint8(1),g_d_direction.North_West));
                        end
                    end
                end
            end
            
            %ゴール更新ノードの更新とインデックスのクリア
            contor_renew_node_col = contor_renew_node_col_temp;
            contor_renew_node_col_temp = zeros(1024,2,'uint8');
            contor_renew_node_col_idx = contor_renew_node_col_idx_temp;
            contor_renew_node_col_idx_temp = uint8(1);
            contor_renew_node_row = contor_renew_node_row_temp;
            contor_renew_node_row_temp = zeros(1024,2,'uint8');
            contor_renew_node_row_idx = contor_renew_node_row_idx_temp;
            contor_renew_node_row_idx_temp = uint8(1);
            
            %更新がなければ終了(スタート地点の歩数マップを更新)
            if change_flag == 0
                start_num = row_num_node(2,1) + weight_straight_harf;
                break;
            end
        end
    end


%% decide_goal_node_dir ゴールノード、および方向の確定
% 斜めのコンターマップから、ゴールとなるノードと、ゴール時の進入角度を確定する。
    function  [goal_node,goal_matrix_dir,goal_dir] = decide_goal_node_dir(maze_goal,goal_size,row_num_node,col_num_node)
        
        %スタートノード,方向を設定
        current_matrix_dir = matrix_dir.Row; %スタートノードは行方向
        current_node = uint8([2,1]);%スタートマスの北のノード
        next_matrix_dir = matrix_dir.Row; %進行方向先のノード方向（仮）
        next_node =uint8([2,1]);%進行方向先のノード座標
        current_dir_dgnd = g_d_direction.North;%進行方向（最初の仮の値は北向き）
        map_min = uint16(65535);
        while 1
            
            goal_flag = uint8(0);
            for i = 1:1:goal_size
                %現在のノードが行方向の時
                if current_matrix_dir == matrix_dir.Row
                    if (maze_goal(i,1) == current_node(2)) && ... %x座標の一致
                            (maze_goal(i,2) == current_node(1) || maze_goal(i,2)+1 == current_node(1))%y座標の一致
                        %進行方向先に壁があれば(マップ値が65535であれば)、進行方向を変更する（斜め侵入時）
                        %北東
                        if current_dir_dgnd == g_d_direction.North_East...
                                && col_num_node(current_node(1),current_node(2)+1) == 65535
                            current_dir_dgnd = g_d_direction.North;
                            %南東
                        elseif current_dir_dgnd == g_d_direction.South_East...
                                && col_num_node(current_node(1)-1,current_node(2)+1) == 65535
                            current_dir_dgnd = g_d_direction.South;
                            %南西
                        elseif current_dir_dgnd == g_d_direction.South_West...
                                && col_num_node(current_node(1)-1,current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.South;
                            %北西
                        elseif current_dir_dgnd == g_d_direction.North_West...
                                && col_num_node(current_node(1),current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.North;
                        end
                        
                        %フラグ
                        goal_flag = uint8(1);
                    end
                    %現在のノードが列方向の時
                else
                    if (maze_goal(i,1) == current_node(2) || maze_goal(i,1)+1 == current_node(2)) && ... %x座標の一致
                            (maze_goal(i,2) == current_node(1))%y座標の一致
                        %進行方向先に壁があれば(マップ値が65535であれば)、進行方向を変更する（斜め侵入時）
                        %北東
                        if current_dir_dgnd == g_d_direction.North_East...
                                && row_num_node(current_node(1)+1,current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.East;
                            %南東
                        elseif current_dir_dgnd == g_d_direction.South_East...
                                && row_num_node(current_node(1),current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.East;
                            %南西
                        elseif current_dir_dgnd == g_d_direction.South_West...
                                && row_num_node(current_node(1),current_node(2)-1) == 65535
                            current_dir_dgnd = g_d_direction.West;
                            %北西
                        elseif current_dir_dgnd == g_d_direction.North_West...
                                && row_num_node(current_node(1)+1,current_node(2)-1) == 65535
                            current_dir_dgnd = g_d_direction.West;
                        end
                        %フラグ
                        goal_flag = uint8(1);
                    end
                end
            end
            
            %             disp("current_node")
            %             disp(current_node)
            %             disp("current_matrix_dir")
            %             disp(current_matrix_dir)
            %             disp("current_dir_dgnd")
            %             disp(current_dir_dgnd)
            %ゴールノード判定の時
            %現在のノードをゴールノードとし、
            %現在の方向をゴール時の方向とする。
            if goal_flag == 1
                goal_node = current_node
                goal_matrix_dir = current_matrix_dir
                goal_dir = current_dir_dgnd
                
                %
                
                break
                
                %ゴールノードでない時
            else
                
                %現在のノードの方向から優先的に進行方向を確定
                for k = 0:7
                    temp = rem(current_dir_dgnd + k,8);
                    %現在のノードが行方向の時
                    if current_matrix_dir == matrix_dir.Row
                        if temp == g_d_direction.North
                            if row_num_node(current_node(1)+1,current_node(2)) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1)+1,current_node(2));
                                %現在ノードの進行方向を北向きに
                                current_dir_dgnd = g_d_direction.North;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Row;
                                next_node = [current_node(1)+1,current_node(2)];
                            end
                        elseif temp == g_d_direction.North_East
                            if col_num_node(current_node(1),current_node(2)+1) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1),current_node(2)+1);
                                %現在ノードの進行方向を北向きに
                                current_dir_dgnd = g_d_direction.North_East;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)+1];
                            end
                        elseif temp == g_d_direction.East
                            %柱
                        elseif temp == g_d_direction.South_East
                            if col_num_node(current_node(1)-1,current_node(2)+1) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1)-1,current_node(2)+1);
                                %現在ノードの進行方向を北向きに
                                current_dir_dgnd = g_d_direction.South_East;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Col;
                                next_node = [current_node(1)-1,current_node(2)+1];
                            end
                        elseif temp == g_d_direction.South
                            if row_num_node(current_node(1)-1,current_node(2)) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1)-1,current_node(2));
                                %現在ノードの進行方向を北向きに
                                current_dir_dgnd = g_d_direction.South;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Row;
                                next_node = [current_node(1)-1,current_node(2)];
                            end
                        elseif temp == g_d_direction.South_West
                            if col_num_node(current_node(1)-1,current_node(2)) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1)-1,current_node(2));
                                %現在ノードの進行方向を北向きに
                                current_dir_dgnd = g_d_direction.South_West;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Col;
                                next_node = [current_node(1)-1,current_node(2)];
                            end
                        elseif temp == g_d_direction.West
                            %柱
                        elseif temp == g_d_direction.North_West
                            if col_num_node(current_node(1),current_node(2)) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1),current_node(2));
                                %現在ノードの進行方向を北向きに
                                current_dir_dgnd = g_d_direction.North_West;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)];
                            end
                        end
                        %現在のノードが列方向の時
                    else
                        if temp == g_d_direction.North
                            %柱
                        elseif temp == g_d_direction.North_East
                            if row_num_node(current_node(1)+1,current_node(2)) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1)+1,current_node(2));
                                %現在ノードの進行方向を北東向きに
                                current_dir_dgnd = g_d_direction.North_East;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Row;
                                next_node = [current_node(1)+1,current_node(2)];
                            end
                        elseif temp == g_d_direction.East
                            if col_num_node(current_node(1),current_node(2)+1) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1),current_node(2)+1);
                                %現在ノードの進行方向を東向きに
                                current_dir_dgnd = g_d_direction.East;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)+1];
                            end
                        elseif temp == g_d_direction.South_East
                            if row_num_node(current_node(1),current_node(2)) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1),current_node(2));
                                %現在ノードの進行方向を南東向きに
                                current_dir_dgnd = g_d_direction.South_East;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Row;
                                next_node = [current_node(1),current_node(2)];
                            end
                        elseif temp == g_d_direction.South
                            %柱
                        elseif temp == g_d_direction.South_West
                            if row_num_node(current_node(1),current_node(2)-1) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1),current_node(2)-1);
                                %現在ノードの進行方向を南西向きに
                                current_dir_dgnd = g_d_direction.South_West;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Row;
                                next_node = [current_node(1),current_node(2)-1];
                            end
                        elseif temp == g_d_direction.West
                            if col_num_node(current_node(1),current_node(2)-1) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1),current_node(2)-1);
                                %現在ノードの進行方向を西向きに
                                current_dir_dgnd = g_d_direction.West;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)-1];
                            end
                        elseif temp == g_d_direction.North_West
                            if row_num_node(current_node(1)+1,current_node(2)-1) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1)+1,current_node(2)-1);
                                %現在ノードの進行方向を北西向きに
                                current_dir_dgnd = g_d_direction.North_West;
                                %進行方向先の座標、行列の方向を更新
                                next_matrix_dir = matrix_dir.Row;
                                next_node = [current_node(1)+1,current_node(2)-1];
                            end
                        end
                        
                    end
                    
                end
                
                current_node = next_node;
                current_matrix_dir = next_matrix_dir;
                
            end
        end
    end
%% decide_goal_section ゴールマスの確定
% 確定されたゴールのノードと、ゴール時の進入角度から、
% ゴールマスを確定する。
    function[goal_section,goal_node2,goal_matrix_dir2]=decide_goal_section(maze_goal,goal_node,goal_matrix_dir,goal_dir)
        
        goal_section = uint8([1,1]);%(y,x)
        goal_node2 = uint8([1,1]);
        goal_matrix_dir2 = matrix_dir.Row;
        
        if goal_dir == g_d_direction.North
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            end
            %列方向は柱なのでなし
        elseif goal_dir == g_d_direction.North_East
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            else
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.East
            %行方向は柱なのでなし
            if goal_matrix_dir == matrix_dir.Col
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.South_East
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)-2)
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            else
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.South
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2),goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            end
        elseif goal_dir == g_d_direction.South_West
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            else
                if goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)-2,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.West
            %行方向は柱なのでなし
            if goal_matrix_dir == matrix_dir.Col
                if goal_judge(maze_goal,goal_node(2)-2,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.North_West
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)-1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            else
                if goal_judge(maze_goal,goal_node(2)-2,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)-2,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
                
            end
        end
        
        
        %ゴール判定関数
        function[result] = goal_judge(maze_goal,x,y)
            %入力座標の配列を作成
            temp = [ones(9,1,'uint8')*x,ones(9,1,'uint8')*y];
            %ゴール座標と比較
            temp1 = logical(maze_goal == temp);
            %x,yともに一致するか確認、一致なら1を返す
            result = max(temp1(:,1).*temp1(:,2));
            
        end
    end

%% make_route_diagonal 斜め有での最短ルート生成、走行
    function[] = make_route_diagonal(row_num_node,col_num_node,goal_section,goal_node2,goal_node_property)
        
        %スタートノードの初期化
        current_node = [uint8(1),uint8(1)];%初期マスの南のノード
        current_node_property = matrix_dir.Row; %南のノードの属性は行方向
        current_move_dir = g_d_direction.North; %初期の進行方向は北
        current_move_mode = move_dir_property.straight; %初期の進行方向属性は直進（斜めでない）
        straight_count = uint8(0);%直進用のカウンタ
        
        %初回のみ次のノードを固定
        next_node = [uint8(2),uint8(1)];%初期マスの北のノード
        next_node_property = matrix_dir.Row; %北のノードの属性は行方向
        
        %基準ノード座標を次のノードに
        %基準ノードの移動方向、モードを現在のノードに設定
        ref_node = next_node;
        ref_node_property = next_node_property;
        ref_move_dir = current_move_dir;
        ref_move_mode = current_move_mode;
        
        %ゴールフラグがたつまでループ
        goal_flag = 0;
        
        %斜め込みの進行方法選択
        [next_move_dir,next_node,next_node_property]...
            =get_next_dir_diagonal(row_num_node,col_num_node,ref_move_dir,ref_node,ref_node_property,goal_node2,goal_node_property,goal_section);
        
        
        while(1)
            
            %         disp(["next_move_dir=",num2str(next_move_dir)])
            %         disp(["ref_move_dir=",num2str(ref_move_dir)])
            
            %基準ノードから見て、進行方向が同一のとき
            if ref_move_dir == next_move_dir
                %             disp("直進")
                straight_count = straight_count+uint8(1);%直進カウンタをインクリメント
                %基準ノードを移動する。
                ref_node = next_node;
                ref_node_property = next_node_property;
                ref_move_dir = next_move_dir;
                %基準ノードがゴールであるか判定
                if (isequal(ref_node,goal_node2) && (ref_node_property == goal_node_property))...
                        || (ref_node_property == matrix_dir.section && goal_section(2)==ref_node(1) && goal_section(1)==ref_node(2))
                    %現在位置がノードである時、ゴール進入時のパターンを決定する。
                    if (isequal(ref_node,goal_node2) && (ref_node_property == goal_node_property))
                        %ゴールの場合、ゴール進入時のパターンを決定する。
                        [next_move_dir,next_node,next_node_property]...
                            =get_next_dir_diagonal(row_num_node,col_num_node,ref_move_dir,ref_node,ref_node_property,goal_node2,goal_node_property,goal_section);
                        %直進の場合（直進侵入）
                        if ref_move_dir == next_move_dir
                            %ゴール分カウンタを増加
                            straight_count = straight_count+uint8(1);
                            %現在ノードから直進カウンタ分移動する関数。
                            [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                                = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                            %                         disp("ゴール直線侵入")
                            %                         disp(current_node)
                            %ターンの場合（斜め侵入）
                            %45度ターンのみ想定(一つ先の移動方向でターンの種類が決定)
                        else
                            %                         disp("ゴール時直進前")
                            %                         disp(current_node)
                            %直進カウンタがあれば移動
                            if straight_count > 0
                                %軌跡をプロット
                                if coder.target('MATLAB')
                                    straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                                end
                                %現在ノードから直進カウンタ分移動する関数。
                                [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                                    = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                            end
                            %                         disp("ゴール時直進後")
                            %                         disp(current_node)
                            %進行方向のバッファをクリア
                            move_dir_buffer = zeros(3,1);
                            %1つ先までの進行方向から、ターンのパターンを決定
                            %現在進行方向からの相対的な移動方向をバッファ
                            move_dir_buffer(1) = bitand(int8(next_move_dir)-int8(current_move_dir),7);
                            %ターンの種類を判定する
                            [turn_pattern_num] = get_turn_pattern_num(move_dir_buffer,ref_move_mode);
                            %ターンの軌跡を描画する
                            if coder.target('MATLAB')
                                slalom_plot(current_node,current_node_property,current_move_dir,current_move_mode,turn_pattern_num);
                            end
                            %パターンが決まらなかった場合、エラー
                            if turn_pattern_num == 0
                                if coder.target('MATLAB')
                                    %                                 error('パターンが見つかりませんでした。(ゴール時)')
                                    error('The pattern was not found.(At goal)')
                                end
                            end
                            %パターンに応じた移動処理
                            if turn_pattern_num == turn_pattern.r_45
                                if coder.target('MATLAB')
                                    disp("right45deg")
                                end
                                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                                    = turn_r_45(current_node,current_node_property,current_move_dir,current_move_mode);
                                
                            elseif turn_pattern_num == turn_pattern.l_45
                                if coder.target('MATLAB')
                                    disp("left45deg")
                                end
                                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                                    = turn_l_45(current_node,current_node_property,current_move_dir,current_move_mode);
                            else
                                if coder.target('MATLAB')
                                    error("It is an unexpected turn pattern (when entering the goal)")
                                end
                            end
                        end
                        %参照位置がセクションであるとき
                    else
                        %直進カウンタがあれば、移動する。
                        %                     disp("ゴール時直進（セクション）")
                        if straight_count > 0
                            %軌跡をプロット
                            if coder.target('MATLAB')
                                straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                            end
                            %現在ノードから直進カウンタ分移動する関数。
                            [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                                = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                        end
                    end
                    %ゴール処理がおわったらフラグを立てる
                    %                 disp("ゴール後")
                    %                 disp(straight_count)
                    %                 disp(current_node)
                    goal_flag = 1;
                end
                
                %基準ノードから見て、進行方向が異なる(曲がる)とき
            else
                %             disp("ターン")
                %直進カウンタあるとき
                if straight_count > 0
                    %軌跡をプロット
                    if coder.target('MATLAB')
                        straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                    end
                    %現在ノードから直進カウンタ分移動する関数。
                    [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                        = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                    %                 disp("ターン前直進カウンタ")
                    %                 disp(straight_count)
                    %                 disp(current_node)
                end
                
                %進行方向のバッファをクリア
                move_dir_buffer = zeros(3,1);
                %3つ先までの進行方向から、ターンのパターンを決定
                for i = 1:1:3
                    %現在進行方向からの相対的な移動方向をバッファ
                    %                 disp(["current_move_dir",num2str(current_move_dir)])
                    %                 disp(["next_move_dir",num2str(next_move_dir)])
                    move_dir_buffer(i) = bitand(int8(next_move_dir)-int8(current_move_dir),7);
                    %ターンの種類を判定する
                    [turn_pattern_num] = get_turn_pattern_num(move_dir_buffer,ref_move_mode);
                    
                    %パターンが確定していれば終了
                    if turn_pattern_num ~= 0
                        %パターンの軌跡を描画
                        if coder.target('MATLAB')
                            slalom_plot(current_node,current_node_property,current_move_dir,current_move_mode,turn_pattern_num);
                        end
                        break;
                    else
                        %次の進行方向を決定する
                        [next_move_dir,next_node,next_node_property]=...
                            get_next_dir_diagonal(row_num_node,col_num_node,next_move_dir,next_node,next_node_property,goal_node2,goal_node_property,goal_section);
                    end
                    %3回目でパターンが決まらなかった場合、エラー
                    if turn_pattern_num == 0 && i == 3
                        if coder.target('MATLAB')
                            error('The pattern was not found.')
                        end
                    end
                end
                
                %パターンに応じて移動
                if turn_pattern_num == turn_pattern.r_45
                    if coder.target('MATLAB')
                        disp("right45deg")
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_r_45(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.l_45
                    if coder.target('MATLAB')
                        disp("left45deg")
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_l_45(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.r_90
                    if coder.target('MATLAB')
                        if current_move_mode == move_dir_property.straight
                            disp("right90deg")
                        elseif current_move_mode == move_dir_property.diagonal
                            disp("rightV90deg")
                        end
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_r_90(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.l_90
                    if coder.target('MATLAB')
                        if current_move_mode == move_dir_property.straight
                            disp("left90deg")
                        elseif current_move_mode == move_dir_property.diagonal
                            disp("leftV90deg")
                        end
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_l_90(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.r_135
                    if coder.target('MATLAB')
                        disp("right135deg")
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_r_135(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.l_135
                    if coder.target('MATLAB')
                        disp("left135deg")
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_l_135(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.r_180
                    if coder.target('MATLAB')
                        disp("right180deg")
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_r_180(current_node,current_node_property,current_move_dir,current_move_mode);
                    
                elseif turn_pattern_num == turn_pattern.l_180
                    if coder.target('MATLAB')
                        disp("left180deg")
                    end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                        = turn_l_180(current_node,current_node_property,current_move_dir,current_move_mode);
                end
                %             disp("ターン終了時、ノード")
                %             disp(current_node)
                %             disp(goal_node2)
                %移動後、ゴールを判定
                if isequal(current_node,goal_node2) && (current_node_property == goal_node_property)
                    goal_flag = 1;
                end
                
                %基準ノードを移動
                ref_node = next_node;
                ref_node_property = next_node_property;
                ref_move_dir = current_move_dir;
                ref_move_mode = current_move_mode;
                
            end
            
            %ゴールフラグが立っていれば終了
            if goal_flag == 1
                break;
            end
            
            %次の移動方向を取得
            %斜め込みの進行方法選択
            [next_move_dir,next_node,next_node_property]...
                =get_next_dir_diagonal(row_num_node,col_num_node,ref_move_dir,ref_node,ref_node_property,goal_node2,goal_node_property,goal_section);
            %         disp("次進行方向")
            %         disp(next_move_dir)
        end
        
        %パターンを判定する関数
        function [turn_pattern_num] = get_turn_pattern_num(move_dir_buffer,ref_move_mode)
            
            %旋回パターン番号の初期化
            turn_pattern_num = turn_pattern.default;
            
            %直進時
            if ref_move_mode == move_dir_property.straight
                %次が45度まがるとき(右折パターン)
                if move_dir_buffer(1) == 1
                    if move_dir_buffer(2) == 1
                        turn_pattern_num = turn_pattern.r_45;
                    elseif move_dir_buffer(2) == 2
                        turn_pattern_num = turn_pattern.r_90;
                    elseif move_dir_buffer(2) == 3
                        if move_dir_buffer(3) == 3
                            turn_pattern_num = turn_pattern.r_135;
                        elseif move_dir_buffer(3) == 4
                            turn_pattern_num = turn_pattern.r_180;
                        end
                    end
                    %次が-45度まがるとき(左折パターン)
                elseif move_dir_buffer(1) == 7
                    if move_dir_buffer(2) == 7
                        turn_pattern_num = turn_pattern.l_45;
                    elseif move_dir_buffer(2) == 6
                        turn_pattern_num = turn_pattern.l_90;
                    elseif move_dir_buffer(2) == 5
                        if move_dir_buffer(3) == 5
                            turn_pattern_num = turn_pattern.l_135;
                        elseif move_dir_buffer(3) == 4
                            turn_pattern_num = turn_pattern.l_180;
                        end
                    end
                end
                
                %斜めの時
            elseif ref_move_mode == move_dir_property.diagonal
                %右折パターン
                if move_dir_buffer(1) == 1
                    turn_pattern_num = turn_pattern.r_45;
                elseif move_dir_buffer(1) == 2
                    if move_dir_buffer(2) == 2
                        turn_pattern_num = turn_pattern.r_90;
                    elseif move_dir_buffer(2) == 3
                        turn_pattern_num = turn_pattern.r_135;
                    end
                    %左折パターン
                elseif move_dir_buffer(1) == 7
                    turn_pattern_num = turn_pattern.l_45;
                elseif move_dir_buffer(1) == 6
                    if move_dir_buffer(2) == 6
                        turn_pattern_num = turn_pattern.l_90;
                    elseif move_dir_buffer(2) == 5
                        turn_pattern_num = turn_pattern.l_135;
                    end
                end
                
            else
                if coder.target('MATLAB')
                    error('ref move mode is unexpected')
                end
            end
        end
    end
%% get_next_dir_diagonal 斜め有での進行方向,行先取得
    function [next_dir,next_node,next_node_property]=get_next_dir_diagonal(row_num_node,col_num_node,current_move_dir,current_node,current_matrix_dir,goal_node2,goal_matrix_dir2,goal_section)
        
        %出力変数定義
        next_dir = g_d_direction.North;
        next_node =uint8( [1,1]);
        next_node_property = matrix_dir.Row;
        
        
        %現在のエッジはゴールノードか
        if isequal(current_node,goal_node2) && current_matrix_dir == goal_matrix_dir2
            %ゴールノードの場合
            %ゴールノードが行方向の場合
            if goal_matrix_dir2 == matrix_dir.Row
                if goal_section(2) == goal_node2(1) && goal_section(1) == goal_node2(2)
                    next_dir = g_d_direction.North;
                    next_node = goal_node2;
                    next_node_property = matrix_dir.section;
                else
                    next_dir = g_d_direction.South;
                    next_node = [goal_node2(1)-1,goal_node2(2)];
                    next_node_property = matrix_dir.section;
                end
            else
                %ゴールノードが列方向の場合
                if goal_section(2) == goal_node2(1) && goal_section(1) == goal_node2(2)
                    next_dir = g_d_direction.East;
                    next_node = [goal_node2(1),goal_node2(2)];
                    next_node_property = matrix_dir.section;
                else
                    next_dir = g_d_direction.West;
                    next_node = [goal_node2(1),goal_node2(2)-1];
                    next_node_property = matrix_dir.section;
                end
            end
        else
            %ゴールノードでない場合
            %閾値を定義
            map_min = uint16(65535);
            %現在のノードの方向から優先的に進行方向を確定
            for k = 0:7
                temp = rem(current_move_dir + k,8);
                %現在のノードが行方向の時
                if current_matrix_dir == matrix_dir.Row
                    if temp == g_d_direction.North
                        if row_num_node(current_node(1)+1,current_node(2)) < map_min
                            %最小値を更新
                            map_min = row_num_node(current_node(1)+1,current_node(2));
                            %現在ノードの進行方向を北向きに
                            next_dir = g_d_direction.North;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Row;
                            next_node = [current_node(1)+1,current_node(2)];
                        end
                    elseif temp == g_d_direction.North_East
                        if col_num_node(current_node(1),current_node(2)+1) < map_min
                            %最小値を更新
                            map_min = col_num_node(current_node(1),current_node(2)+1);
                            %現在ノードの進行方向を東北向きに
                            next_dir = g_d_direction.North_East;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Col;
                            next_node = [current_node(1),current_node(2)+1];
                        end
                    elseif temp == g_d_direction.East
                        %柱
                    elseif temp == g_d_direction.South_East
                        if col_num_node(current_node(1)-1,current_node(2)+1) < map_min
                            %最小値を更新
                            map_min = col_num_node(current_node(1)-1,current_node(2)+1);
                            %現在ノードの進行方向を南東向きに
                            next_dir = g_d_direction.South_East;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Col;
                            next_node = [current_node(1)-1,current_node(2)+1];
                        end
                    elseif temp == g_d_direction.South
                        if row_num_node(current_node(1)-1,current_node(2)) < map_min
                            %最小値を更新
                            map_min = row_num_node(current_node(1)-1,current_node(2));
                            %現在ノードの進行方向を南向きに
                            next_dir = g_d_direction.South;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Row;
                            next_node = [current_node(1)-1,current_node(2)];
                        end
                    elseif temp == g_d_direction.South_West
                        if col_num_node(current_node(1)-1,current_node(2)) < map_min
                            %最小値を更新
                            map_min = col_num_node(current_node(1)-1,current_node(2));
                            %現在ノードの進行方向を南西向きに
                            next_dir = g_d_direction.South_West;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Col;
                            next_node = [current_node(1)-1,current_node(2)];
                        end
                    elseif temp == g_d_direction.West
                        %柱
                    elseif temp == g_d_direction.North_West
                        if col_num_node(current_node(1),current_node(2)) < map_min
                            %最小値を更新
                            map_min = col_num_node(current_node(1),current_node(2));
                            %現在ノードの進行方向を北西向きに
                            next_dir = g_d_direction.North_West;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Col;
                            next_node = [current_node(1),current_node(2)];
                        end
                    end
                    %現在のノードが行方向の時
                else
                    if temp == g_d_direction.North
                        %柱
                    elseif temp == g_d_direction.North_East
                        if row_num_node(current_node(1)+1,current_node(2)) < map_min
                            %最小値を更新
                            map_min = row_num_node(current_node(1)+1,current_node(2));
                            %現在ノードの進行方向を北東向きに
                            next_dir = g_d_direction.North_East;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Row;
                            next_node = [current_node(1)+1,current_node(2)];
                        end
                    elseif temp == g_d_direction.East
                        if col_num_node(current_node(1),current_node(2)+1) < map_min
                            %最小値を更新
                            map_min = col_num_node(current_node(1),current_node(2)+1);
                            %現在ノードの進行方向を東向きに
                            next_dir = g_d_direction.East;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Col;
                            next_node = [current_node(1),current_node(2)+1];
                        end
                    elseif temp == g_d_direction.South_East
                        if row_num_node(current_node(1),current_node(2)) < map_min
                            %最小値を更新
                            map_min = row_num_node(current_node(1),current_node(2));
                            %現在ノードの進行方向を南東向きに
                            next_dir = g_d_direction.South_East;
                            %進行方向先の座標、行列の方向を更新
                            next_node_property = matrix_dir.Row;
                            next_node = [current_node(1),current_node(2)];
                        end
                    elseif temp == g_d_direction.South
                        %柱
                    elseif temp == g_d_direction.South_West
                        if current_node(2)-1 > 0
                            if row_num_node(current_node(1),current_node(2)-1) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1),current_node(2)-1);
                                %現在ノードの進行方向を南西向きに
                                next_dir = g_d_direction.South_West;
                                %進行方向先の座標、行列の方向を更新
                                next_node_property = matrix_dir.Row;
                                next_node = [current_node(1),current_node(2)-1];
                            end
                        end
                    elseif temp == g_d_direction.West
                        if current_node(2)-1 > 0
                            if col_num_node(current_node(1),current_node(2)-1) < map_min
                                %最小値を更新
                                map_min = col_num_node(current_node(1),current_node(2)-1);
                                %現在ノードの進行方向を西向きに
                                next_dir = g_d_direction.West;
                                %進行方向先の座標、行列の方向を更新
                                next_node_property = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)-1];
                            end
                        end
                    elseif temp == g_d_direction.North_West
                        if current_node(2)-1 > 0
                            if row_num_node(current_node(1)+1,current_node(2)-1) < map_min
                                %最小値を更新
                                map_min = row_num_node(current_node(1)+1,current_node(2)-1);
                                %現在ノードの進行方向を北西向きに
                                next_dir = g_d_direction.North_West;
                                %進行方向先の座標、行列の方向を更新
                                next_node_property = matrix_dir.Row;
                                next_node = [current_node(1)+1,current_node(2)-1];
                            end
                        end
                    end
                    
                end
                
            end
            
        end
    end

%% 移動用関数
% 直進
    function[current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
            = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count)
        
        %直進時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+straight_count,current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['North',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1),current_node(2)+straight_count];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['East',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-straight_count,current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['South',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1),current_node(2)-straight_count];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['West',num2str(straight_count),'square Go straight'])
                end
            else
                if coder.target('MATLAB')
                    error("Unexpected movement direction")
                end
            end
            %斜め直進のとき
        elseif current_move_mode == move_dir_property.diagonal
            %直進カウンタを2で割った商とあまり、その合計を計算
            %(移動先ノード座標の一般化用)
            temp_quotient = idivide(straight_count,2);
            temp_remainder = rem(straight_count,2);
            temp_qr = temp_quotient+temp_remainder;
            
            if current_move_dir == g_d_direction.North_East
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)+temp_quotient,current_node(2)+temp_qr];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.North_East;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)+temp_qr,current_node(2)+temp_quotient];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.North_East;
                    current_move_mode = move_dir_property.diagonal;
                else
                    if coder.target('MATLAB')
                        error("Unexpected node attribute")
                    end
                end
                if coder.target('MATLAB')
                    disp(['North East',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.South_East
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)-temp_qr,current_node(2)+temp_qr];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.South_East;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)-temp_quotient,current_node(2)+temp_quotient];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.South_East;
                    current_move_mode = move_dir_property.diagonal;
                else
                    if coder.target('MATLAB')
                        error("Unexpected node attribute")
                    end
                end
                if coder.target('MATLAB')
                    disp(['South East',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.South_West
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)-temp_qr,current_node(2)-temp_quotient];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.South_West;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)-temp_quotient,current_node(2)-temp_qr];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.South_West;
                    current_move_mode = move_dir_property.diagonal;
                else
                    if coder.target('MATLAB')
                        error("Unexpected node attribute")
                    end
                end
                if coder.target('MATLAB')
                    disp(['South West',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.North_West
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)+temp_quotient,current_node(2)-temp_quotient];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.North_West;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)+temp_qr,current_node(2)-temp_qr];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.North_West;
                    current_move_mode = move_dir_property.diagonal;
                else
                    if coder.target('MATLAB')
                        error("Unexpected node attribute")
                    end
                end
                if coder.target('MATLAB')
                    disp(['Northwest',num2str(straight_count),'node straight'])
                end
            end
        else
            if coder.target('MATLAB')
                disp("Unexpected operating mode")
            end
        end
        %移動完了時、直進カウンタをクリア
        straight_count = uint8(0);
    end
% 右45度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_45(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)-2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_45_straight)')
                end
            end
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1),current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_45_diagonal)')
                end
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 左45度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_45(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1),current_node(2)-2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (l_45_straight)')
                end
            end
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1),current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (l_45_diagonal)')
                end
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 右90度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_90(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)+2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_90)')
                end
            end
            %斜めパターンの時（V90）
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_V90)')
                end
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 左90度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_90(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1),current_node(2)-2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (l_90)')
                end
            end
            %斜めパターンの時（V90）
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction(r_V90)')
                end
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 右135度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_135(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction(r_135)')
                end
            end
            %斜めパターンの時
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_135_diagonal)')
                end
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 左135度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_135(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction(l_135)')
                end
            end
            %斜めパターンの時
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction(l_135_diagonal)')
                end
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 右180度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_180(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_180)')
                end
            end
            %斜めパターンの時
        elseif current_move_mode == move_dir_property.diagonal
            if coder.target('MATLAB')
                error('Unexpected traveling direction (r_180_diagonal)')
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

% 左180度
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_180(current_node,current_node_property,current_move_dir,current_move_mode)
        %直進パターンの時
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
            else
                if coder.target('MATLAB')
                    error('Unexpected traveling direction (l_180)')
                end
            end
            %斜めパターンの時
        elseif current_move_mode == move_dir_property.diagonal
            if coder.target('MATLAB')
                error('Unexpected traveling direction (l_180_diagonal)')
            end
        else
            if coder.target('MATLAB')
                error('Unexpected progress mode')
            end
        end
        
    end

end


