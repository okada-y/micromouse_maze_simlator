function [] = maze_search_plot_update(search_surf,maze_wall_search,maze_col_size,maze_row_size)
%maze_search_plot_update �T���󋵂�\��surface���X�V
%���� �Ώۂ�suraface,�T����,�s�����T�C�Y,������T�C�Y
%�o�� �Ώۂ�surface
 z = logical(bitand(maze_wall_search,1))+logical(bitand(maze_wall_search,2))+logical(bitand(maze_wall_search,4))+logical(bitand(maze_wall_search,8)); 
 z = z(1:maze_col_size-1,1:maze_row_size-1);
 z(maze_col_size,maze_row_size) = 0;
 search_surf.ZData = z; 
end

