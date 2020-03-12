function[maze_wall,maze_wall_search] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,maze_goal,goal_size,run_mode)%#codegen
%maze_solve 実機での迷路探索関数
%入力 迷路壁情報,迷路探索情報,迷路縦サイズ,迷路横サイズ,ゴール座標,
%出力 壁情報,探索情報

%ローカル変数宣言
new_goal = uint8(zeros(9,2));
new_goal_size = uint8(1); 

%絶対方角定義
g_direction = struct('North',uint8(0),'East',uint8(1),'South',uint8(2),'West',uint8(3));

%マウス方向定義
l_direction = struct('front',uint8(0),'right',uint8(1),'back',uint8(2),'left',uint8(3));

%壁情報定義
wall = struct('nowall',uint8(0),'wall',uint8(1));

%探索情報定義
search = struct('unknown',uint8(0),'known',uint8(1));

%走行モード定義
r_mode = struct('search',uint8(0),'fust_run',uint8(1));

%探索時
if run_mode == r_mode.search

    %マウスの初期位置設定
    current_x = uint8(1);
    current_y = uint8(1);
    current_dir = g_direction.North;
      
    %一マス前進
     [current_x,current_y] = move_step(current_x,current_y,current_dir);

    %足立法による探索
    [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
        = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,maze_goal,goal_size);

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
        [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
            = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,new_goal,coder.ignoreConst(new_goal_size));
        else
            break
        end

    end
    
    %スタートを目的地として足立法で再探索
    new_goal(1,:) = uint8([1,1]);
     [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
         = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,coder.ignoreConst(new_goal),coder.ignoreConst(new_goal_size));
    
        if coder.target('MATLAB')
        %for MATLAB
        %探索情報を可視化
         maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        else
        %for code generation
        end    


end

if run_mode == r_mode.fust_run
    %探索情報をもとに等高線MAPを生成
    [contour_map,max_length] = make_map_fustrun(maze_row_size,maze_col_size,maze_goal,maze_wall,maze_wall_search);
    
    %最短距離走行
    fust_run(maze_wall,contour_map,maze_goal,max_length)


end

%% search_adachi 足立法での探索
function [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
            = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,maze_goal,l_goal_size) %#codegen
    %入力　現在位置x,y,現在方向,迷路行方向サイズ,迷路列方向サイズ,迷路壁情報,迷路壁の探索情報,ゴール座標
    %出力  現在位置x,y,現在方向,壁情報,探索情報

    %local変数宣言
    goal_flag = uint8(0);
    search_start_x = current_x; %探索開始時x
    search_start_y = current_y; %探索開始時y
    
    if coder.target('MATLAB')
        %for MATLAB
        %迷路探索状況を表す表面を作成
        [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        %マウス位置表示用オブジェクト初期化
        [h] = hgtransform_init;
        %探索開始位置プロット
        hold on
        plot(current_x * 9 -4.5,current_y * 9 -4.5,'ob','MarkerFaceColor','b','Parent',h);
        hold off
    else
       %for C gen
    end
    
        while 1
            %壁情報取得
            [maze_wall,maze_wall_search] = wall_set(maze_row_size,maze_col_size,current_x,current_y,current_dir,maze_wall,maze_wall_search);
            
            if coder.target('MATLAB')
            maze_wall_plot(maze_wall,current_x,current_y);
            drawnow limitrate nocallbacks
            end
            
            %現在位置がゴールか判定
            for i = 1:1:l_goal_size
                if (current_x == maze_goal(i,1)) && (current_y == maze_goal(i,2))
                    goal_flag = uint8(1);
                 end
            end


            if goal_flag == 1
                break        
            end

            % 等高線MAP生成
            % [contour_map,max_length] = make_map2(maze_row_size,maze_col_size,maze_goal,maze_wall);
              [cmap,max_l] = make_map_find(maze_row_size,maze_col_size,maze_goal,l_goal_size,maze_wall);
           % 進行方向選定
            %優先順位　北⇒東⇒南⇒西
             [next_dir] = get_nextdir2(current_x,current_y,maze_wall,cmap,max_l);

           % 現在方向と進行方向に応じた処理
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
                %オブジェクト位置更新
                hgtransform_update(h,current_x,current_y,search_start_x,search_start_y,9);
                %探索状況の更新
                maze_search_plot_update(search_surf,maze_wall_search,maze_col_size,maze_row_size);
                drawnow
            else
                %for code generation
            end
        end

        
    if coder.target('MATLAB')
        %for MATLAB    
        %探索終了時,マーカーをどこか遠くに
        %m = makehgtform('translate',50*9,50*9,0);
        %h.Matrix = m;
        %別の種類のマーカーを仮置き
        hold on
        plot(current_x * 9 -4.5,current_y * 9 -4.5,'-ob');
        hold off
        %探索状況プロットを透明化
        serface_transparency(search_surf);
        drawnow
    else
        %for code generation
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
        %壁センサAD値格納変数
        global wall_sensor_front;
        global wall_sensor_right;
        global wall_sensor_left;
        %壁センサ閾値
        global wall_sensor_front_th;
        global wall_sensor_right_th;
        global wall_sensor_left_th;
    %ローカル変数宣言
    wall_write = uint8(zeros(1,4));%壁情報書き込み用バッファ(N,E,S,W)
    serch_write = uint8(zeros(1,4));%探索情報書き込み用バッファ(N,E,S,W)


    %マウスの方向に基づく壁情報取得
    %マウスの方向と絶対方向の差=マウスの方向となることを利用し、
    %絶対角度と整合をとる。
    
    
% 実機はここをセンサ値に対応させる 
    
    %センサ値取得(要手直し)
    %ここまで
    
    %前方の壁判定
    if coder.target('MATLAB')
        %for matlab
        %画像から得た既知の迷路情報をもとに、壁の有無を判定
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),current_dir) ) %非ゼロの時実行
            %壁情報取得
            wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %センサ値をもとに、壁の有無を判定
        if int16(wall_sensor_front) > int16(wall_sensor_front_th)
            %壁情報取得
            wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
        end
        
    end    
    %探索情報取更新
    serch_write(uint8(1),rem(current_dir,4)+uint8(1)) = search.known;

    %右壁判定
    if coder.target('MATLAB')
        %for matlab
        %画像から得た既知の迷路情報をもとに、壁の有無を判定
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+1,4)) )
            wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %センサ値をもとに、壁の有無を判定
        if int16(wall_sensor_right) > int16(wall_sensor_right_th)
            %壁情報取得
            wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
        end
    end    
    %探索情報取更新
    serch_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = search.known;

    %後方は情報を得ることができないので処理しない。

    %左壁判定
    if coder.target('MATLAB')
        %for matlab
        %画像から得た既知の迷路情報をもとに、壁の有無を判定
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+3,4)) )
            wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %センサ値をもとに、壁の有無を判定
        if int16(wall_sensor_left) > int16(wall_sensor_left_th)
            %壁情報取得
            wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
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


    end
%%  make_map_find 壁情報から等高線MAPを生成
    function [contour_map,max_length] = make_map_find(maze_row_size,maze_col_size,maze_goal,l_goal_size,maze_wall)
    %入力 迷路縦サイズ,迷路横サイズ,ゴール座標,迷路情報(16進数)
    %出力 等高線map,最大経路長


    % 迷路パラメータ設定
    max_length = uint8((maze_col_size-1)*(maze_row_size-1));

    %MAPの初期化(すべての要素にmax_lengthを入力)
    %32マス分mapを保持
    %16bitにすべき
    contour_map = ones(32,32,'uint8');
    contour_map = contour_map * max_length;

    %ゴール座標に0を入力
    for temp = 1:1:l_goal_size
        contour_map(maze_goal(temp,2),maze_goal(temp,1)) = 0;
    end


    while 1
        change_flag = uint8(0); %map更新確認用フラグ

        for tempi = 0:1:max_length-1 %歩数カウントは0~max_length
                %歩数が確定している座標を検索
                %最初は0,更新され、増加したマスを次々検索していく
                num_temp = uint16(find(contour_map == tempi));
                 %32行なので、行番号:32で割ったあまり
                row = uint8(rem(num_temp-1,32)+1);
                 %列番号:32で割ったときの商
                col = uint8(idivide(num_temp-1,32)+1);
                 %見つかったマスの数
                row_size = uint8(numel(row));
                
                %更新マスが見つからなければ終了
                if row_size == uint8(0)
                    break;
                end
                                
                %検索した座標に対し、歩数mapを更新
                for tempn = 1:1:row_size
                    %北側
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North)) == wall.nowall)
                        %北側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn)+1,col(tempn)) == max_length 
                        contour_map(row(tempn)+1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %東側
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East)) == wall.nowall)
                        %東側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn),col(tempn)+1) == max_length 
                        contour_map(row(tempn),col(tempn)+1) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %南側
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South)) == wall.nowall)
                        %南側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn)-1,col(tempn)) == max_length 
                        contour_map(row(tempn)-1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %西側
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West)) == wall.nowall)
                        %西側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn),col(tempn)-1) == max_length 
                        contour_map(row(tempn),col(tempn)-1) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end
                end    
        end
        
    %更新がなければ終了    
        if change_flag == uint8(0)
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


%% 探索した壁情報(シリアル)をプロットする関数
    function [] = maze_wall_plot(maze_wall,current_x,current_y)
    %入力 探索壁情報,現在値x,y
    %出力 
    
    maze_step =  9;
    hold on

    %現在地の壁情報を確認

    i = uint16(current_y);
    n = uint16(current_x);

        %北壁情報プロット
           if bitand(maze_wall(i,n),bitshift(1,g_direction.North)) 
               plot([n-1,n].*maze_step,[i,i].*maze_step,'r','LineWidth',2)
           end
           %東壁情報プロット
           if bitand(maze_wall(i,n),bitshift(1,g_direction.East)) 
               plot([n,n].*maze_step,[i-1,i].*maze_step,'r','LineWidth',2)
           end
           %南壁情報プロット
           if bitand(maze_wall(i,n),bitshift(1,g_direction.South)) 
               plot([n-1,n].*maze_step,[i-1,i-1].*maze_step,'r','LineWidth',2)
           end
           %西壁情報プロット
           if bitand(maze_wall(i,n),bitshift(1,g_direction.West)) 
               plot([n-1,n-1].*maze_step,[i-1,i].*maze_step,'r','LineWidth',2)
           end

    hold off

    end

%% fust_run 最短経路導出
    function [] = fust_run(maze_wall,contour_map,maze_goal,max_length)
    %入力　壁情報,壁探索情報,等高線MAP,ゴール座標,最大経路長
    %出力  

    %local変数宣言
    goal_flag = uint8(0);  %ゴール判定フラグ
    little = max_length; %進行方向選定用閾値
    tempi = uint8(0);
    
    %マウス位置表示用オブジェクト
    ax = gca;
    h = hgtransform('Parent',ax);

    %マウスの初期位置設定
    current_x = uint8(1);
    current_y = uint8(1);
    current_dir = g_direction.North;
    next_dir = g_direction.North;
    search_start_x = current_x; %探索開始時x
    search_start_y = current_y; %探索開始時y

    %探索開始位置プロット
    hold on
    plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'ob','MarkerFaceColor','r','Parent',h);
    hold off

    %足跡プロット
    hold on
    plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r');
    hold off
    drawnow limitrate nocallbacks

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
            %足跡プロット
            hold on
            plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r');
            hold off
            %pause(0.2)
            drawnow limitrate nocallbacks
        else
        %for code generation
        end
    end
end

%% make_map_fustrun 最短走行用等高線MAPを生成
function [contour_map,max_length] = make_map_fustrun(maze_row_size,maze_col_size,maze_goal,maze_wall,maze_wall_search)
%未知壁の領域は仮想壁をおいて侵入しない。
%入力 迷路縦サイズ,迷路横サイズ,ゴール座標,迷路情報(16進数),迷路探索情報(16進数)
%出力 等高線map,最大経路長

%ローカル変数設定
tempn=uint8(0);
tempi=uint8(0);

    % 迷路パラメータ設定
    max_length = uint8((maze_col_size-1)*(maze_row_size-1));

    %MAPの初期化(すべての要素にmax_lengthを入力)
    %MAPの初期化(すべての要素にmax_lengthを入力)
    %32マス分mapを保持
    contour_map = ones(32,32,'uint8');
    contour_map = contour_map * max_length;
    
    %ゴール座標に0を入力
    for tempn = 1:1:goal_size
        contour_map(maze_goal(tempn,2),maze_goal(tempn,1)) = 0;
    end


    while 1
        change_flag = uint8(0); %map更新確認用フラグ

        for tempi = 0:1:max_length-1 %歩数カウントは0~max_length
               
                %歩数が確定している座標を検索
                %最初は0,更新され、増加したマスを次々検索していく
                num_temp = uint16(find(contour_map == tempi));
                 %32行なので、行番号:32で割ったあまり
                row = uint8(rem(num_temp-1,32)+1);
                 %列番号:32で割ったときの商
                col = uint8(idivide(num_temp-1,32)+1);
                 %見つかったマスの数
                row_size = uint16(numel(row));

                %検索した座標に対し、歩数mapを更新
                for tempn = 1:1:row_size
                    %北側
                    %壁が無い & 探索済みであるとき
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North))) == search.known
                        %北側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn)+1,col(tempn)) == max_length 
                        contour_map(row(tempn)+1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %東側
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East))) == search.known
                        %東側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn),col(tempn)+1) == max_length 
                        contour_map(row(tempn),col(tempn)+1) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %南側
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South))) == search.known
                        %南側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn)-1,col(tempn)) == max_length 
                        contour_map(row(tempn)-1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %西側
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West))) == search.known
                        %西側のMAPが更新されているか判断、されていなければ書き込み
                        if contour_map(row(tempn),col(tempn)-1) == max_length 
                        contour_map(row(tempn),col(tempn)-1) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end
                end    
        end
    %更新がなければ終了    
        if change_flag == 0
            break;
        end

    end


end


end



