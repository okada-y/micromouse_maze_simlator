%% 探索した壁情報(シリアル)をプロットする関数
 function [] = maze_wall_plot(maze_wall,current_x,current_y,maze_row_size,maze_col_size)
 %入力 探索壁情報,現在値x,y
 %出力 
    maze_step =  9;
    
    
%   global maze_fig; 
%   figure(maze_fig);
    %現在地の壁情報を確認
    wall_plot(maze_wall,current_x,current_y,maze_step)
    
    %あるパターンにおいて、隣り合うマスの壁も確定するので、隣接するマスも更新する。   
        
    %北のマス
    if current_y < maze_row_size -1
        wall_plot(maze_wall,current_x,current_y+1,maze_step)
    end
    %東のマス
    if current_x < maze_col_size -1
        wall_plot(maze_wall,current_x+1,current_y,maze_step)
    end
    %南のマス
    if current_y > 1
        wall_plot(maze_wall,current_x,current_y-1,maze_step)
    end
    %西のマス
    if current_x > 1
        wall_plot(maze_wall,current_x-1,current_y,maze_step)
    end

 end
    
 function wall_plot(wall,x,y,step)

    global g_direction;
    i = uint16(y);
    n = uint16(x);

    hold on
    %北壁情報プロット
    if bitand(wall(i,n),bitshift(1,g_direction.North)) 
        plot([n-1,n].*step,[i,i].*step,'r','LineWidth',2)
    end
    %東壁情報プロット
    if bitand(wall(i,n),bitshift(1,g_direction.East)) 
        plot([n,n].*step,[i-1,i].*step,'r','LineWidth',2)
    end
    %南壁情報プロット
    if bitand(wall(i,n),bitshift(1,g_direction.South)) 
        plot([n-1,n].*step,[i-1,i-1].*step,'r','LineWidth',2)
    end
    %西壁情報プロット
    if bitand(wall(i,n),bitshift(1,g_direction.West)) 
        plot([n-1,n-1].*step,[i-1,i].*step,'r','LineWidth',2)
    end
    hold off
 end
