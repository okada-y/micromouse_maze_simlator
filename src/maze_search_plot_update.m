function [] = maze_search_plot_update(search_surf,maze_wall_search,maze_col_size,maze_row_size)
%maze_search_plot_update 探索状況を表すsurfaceを更新
%入力 対象のsuraface,探索状況,行方向サイズ,列方向サイズ
%出力 対象のsurface
 z = logical(bitand(maze_wall_search,1))+logical(bitand(maze_wall_search,2))+logical(bitand(maze_wall_search,4))+logical(bitand(maze_wall_search,8)); 
 z = z(1:maze_col_size-1,1:maze_row_size-1);
 z(maze_col_size,maze_row_size) = 0;
 search_surf.ZData = z; 
end

