%% maze_search_plot TõļšĀ»

    function [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,maze_step_size)
    %üĶ ĄHTõóµ,ĄHsūüTCY,ĄHńūüTCY,ĄHź}XĢTCY
    %oĶ TõóµšZ²ÉąĀsurface

    hold on
    [x,y] = meshgrid(0:1:maze_col_size-1,0:1:maze_row_size-1);

    x=x.*maze_step_size;
    y=y.*maze_step_size;
    z = logical(bitand(maze_wall_search,1))+logical(bitand(maze_wall_search,2))+logical(bitand(maze_wall_search,4))+logical(bitand(maze_wall_search,8)); 
    z = z(1:maze_col_size,1:maze_row_size);
    z(maze_col_size,maze_row_size) = 0;

    search_surf = surf(x,y,z,'EdgeColor','none','FaceColor','flat','FaceAlpha',0.4);
    hold off


    end
