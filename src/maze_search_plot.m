%% maze_search_plot 探索状況を可視化

    function [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,maze_step_size)
    %入力 迷路探索状況,迷路行方向サイズ,迷路列方向サイズ,迷路一マスのサイズ
    %出力 探索状況をZ軸にもつsurface

%     global maze_fig;
%     
%     figure(maze_fig);
    hold on
    [x,y] = meshgrid(0:1:maze_col_size-1,0:1:maze_row_size-1);

    x=double(x).*maze_step_size;
    y=double(y).*maze_step_size;
    z = logical(bitand(maze_wall_search,1))+logical(bitand(maze_wall_search,2))+logical(bitand(maze_wall_search,4))+logical(bitand(maze_wall_search,8)); 
    z = z(1:maze_col_size-1,1:maze_row_size-1);
    z(maze_col_size,maze_row_size) = 0;

    search_surf = surf(x,y,z,'EdgeColor','none','FaceColor','flat','FaceAlpha',0.4);
    hold off


    end
