function [] =straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count)

global matrix_dir;
global g_d_direction;
global move_dir_property;


%注意
%迷路プロットはcm単位、軌跡データはm単位なので、変換が必要
%quiver(x,y,u,v)

%行ノードの場合
if current_node_property == matrix_dir.Row
    %ベクトルの位置を定義
    x = double(current_node(2)-1)*9+4.5;
    y = double(current_node(1)-1)*9;
    %直進の場合     
    if current_move_mode == move_dir_property.straight
        %進行方向に応じて、ベクトル位置を調整
        if current_move_dir == g_d_direction.North
            y = y+4.5;
        elseif current_move_dir == g_d_direction.South
            y = y-4.5;
        end
        %ベクトルの大きさを定義
        vec_mag = 9*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);        
    %斜めの場合
    else
        %ベクトルの大きさを定義
        vec_mag = 9/sqrt(2)*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);    
    end
    
%列ノードの場合
elseif current_node_property == matrix_dir.Col
    %ベクトルの位置を定義
    x = double(current_node(2)-1)*9;
    y = double(current_node(1)-1)*9+4.5;
    %直進の場合     
    if current_move_mode == move_dir_property.straight
        %進行方向に応じて、ベクトル位置を調整
        if current_move_dir == g_d_direction.East
            x = x+4.5;
        elseif current_move_dir == g_d_direction.West
            x = x-4.5;
        end
        %ベクトルの大きさを定義
        vec_mag = 9*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);        
    %斜めの場合
    else
        %ベクトルの大きさを定義
        vec_mag = 9/sqrt(2)*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);    
    end
else
    error("想定していない行列属性です。（直線プロット）")
end
hold on
quiver(x,y,u,v,'AutoScale','off','LineWidth',2,'Color','k','MaxHeadSize',0.5)
hold off
end