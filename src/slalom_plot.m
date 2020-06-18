function [] =slalom_plot(current_node,current_node_property,current_move_dir,current_move_mode,slalom_num)

global maze_fig_ax;
global matrix_dir;
global g_d_direction;
global move_dir_property;
global turn_pattern;

%注意
%迷路プロットはcm単位、軌跡データはm単位なので、変換が必要


%スラロームデータの保存先をパスに追加
current_dir = cd; %作業ディレクトリのパスを取得
addpath(strcat(current_dir,'/スラローム軌跡データ'),'-end')

%ベースとなる各パターンのスラローム軌跡を回転、移動させ
%所望の軌跡となるように変換する（原点周りにて）
hold on
%右45度
if slalom_num == turn_pattern.r_45
    load("fust_run_45 .mat","mouse_x","mouse_y")
    %スタートを(0,0に調整)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;

    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
%         set(t,'Matrix',Rz)
        
    %進行方向が斜めの場合
    elseif current_move_mode == move_dir_property.diagonal
        %パターン反転処理
        adjust_x = adjust_x-4.5;
        adjust_y = adjust_y-9;
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        Rz1 = makehgtform('axisrotate',[1 1 0],pi);
        Rz2 = makehgtform('zrotate',3*(pi/4)+(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
%         set(t,'Matrix',Rz)
    end
%左45度
elseif slalom_num == turn_pattern.l_45
    load("fust_run_45 .mat","mouse_x","mouse_y")
    %スタートを(0,0に調整)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz1 = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
        Rz2 = makehgtform('yrotate',pi);
        Rz = Rz1*Rz2;
%         set(t,'Matrix',Rz)
        
    %進行方向が斜めの場合
    elseif current_move_mode == move_dir_property.diagonal
        %パターン反転処理
        adjust_x = adjust_x-4.5;
        adjust_y = adjust_y-9;
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        Rz = makehgtform('zrotate',-3/4*pi-(pi/4)*double(current_move_dir));
%         set(t,'Matrix',Rz)
    end
    
%右90度
elseif slalom_num == turn_pattern.r_90
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        load("fust_run_90 .mat","mouse_x","mouse_y")
        %スタートを(0,0に調整)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y+0.045)*100;
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','r');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
    %進行方向が斜めの場合
    elseif current_move_mode == move_dir_property.diagonal
        load("fust_run_v90 .mat","mouse_x","mouse_y")
        %スタートを(0,0に調整)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y)*100;
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','m');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz = makehgtform('zrotate',-(pi/4)*(double(current_move_dir)-1));
    end
    
%左90度
elseif slalom_num == turn_pattern.l_90
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        load("fust_run_90 .mat","mouse_x","mouse_y")
        %スタートを(0,0に調整)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y+0.045)*100;
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','r');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz1 = makehgtform('yrotate',pi);
        Rz2 = makehgtform('zrotate',(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
    %進行方向が斜めの場合
    elseif current_move_mode == move_dir_property.diagonal
        load("fust_run_v90 .mat","mouse_x","mouse_y")
        %スタートを(0,0に調整)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y)*100;
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','m');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz1 = makehgtform('yrotate',pi); 
        Rz2 = makehgtform('zrotate',(pi/4)*(double(current_move_dir)-7));
        Rz = Rz1*Rz2;
    end
    
%右135度
elseif slalom_num == turn_pattern.r_135
    load("fust_run_135 .mat","mouse_x","mouse_y")
    %スタートを(0,0に調整)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
    %進行方向が斜めの場合
    elseif current_move_mode == move_dir_property.diagonal
        adjust_x = adjust_x-9;
        adjust_y = adjust_y-4.5;
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz1 = makehgtform('axisrotate',[1 1 0],pi);
        Rz2 = makehgtform('zrotate',-3*(pi/4)+(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
    end
%左135度
elseif slalom_num == turn_pattern.l_135
    load("fust_run_135 .mat","mouse_x","mouse_y")
    %スタートを(0,0に調整)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz1 = makehgtform('yrotate',pi);
        Rz2 = makehgtform('zrotate',(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;       
    %進行方向が斜めの場合
    elseif current_move_mode == move_dir_property.diagonal
        adjust_x = adjust_x-9;
        adjust_y = adjust_y-4.5;
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz = makehgtform('zrotate',-1/4*pi-(pi/4)*double(current_move_dir));
    end
%右180度
elseif slalom_num == turn_pattern.r_180
    load("fust_run_180 .mat","mouse_x","mouse_y")
    %スタートを(0,0に調整)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','c');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
    end
    
%左180度
elseif slalom_num == turn_pattern.l_180
    load("fust_run_180 .mat","mouse_x","mouse_y")
    %スタートを(0,0に調整)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %進行方向が直進の場合
    if current_move_mode == move_dir_property.straight
        %回転させるオブジェクトを作成
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','c');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %移動方向に応じて回転角度を変更
        Rz1 = makehgtform('yrotate',pi);
        Rz2 = makehgtform('zrotate',(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
    end
    
end    
%作成した軌跡を現在ノードの位置、移動方向から定まる描画開始位置に移動
%直進時
 if current_move_mode == move_dir_property.straight
     %移動方向に描画位置を対応させる
     if current_move_dir == g_d_direction.North
         Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     elseif current_move_dir == g_d_direction.East
         Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     elseif current_move_dir == g_d_direction.South
         Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 -4.5+double(current_node(1)-1)*9 0]);   
     elseif current_move_dir == g_d_direction.West
         Txy = makehgtform('translate',[-4.5+double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     end
     set(t,'Matrix',Txy*Rz)
%斜めの時
 elseif current_move_mode == move_dir_property.diagonal
     %ノード属性から、プロット開始位置を変更
     if current_node_property == matrix_dir.Row
        Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 double(current_node(1)-1)*9 0]);
     elseif current_node_property == matrix_dir.Col
        Txy = makehgtform('translate',[double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     end
     set(t,'Matrix',Txy*Rz)
 end
    


hold off
end