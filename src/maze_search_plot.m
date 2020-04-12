%% maze_search_plot �T���󋵂�����

    function [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,maze_step_size)
    %���� ���H�T����,���H�s�����T�C�Y,���H������T�C�Y,���H��}�X�̃T�C�Y
    %�o�� �T���󋵂�Z���ɂ���surface

    global maze_fig;
    
    figure(maze_fig);
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
