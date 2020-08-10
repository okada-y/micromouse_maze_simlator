%% 迷路ログ取得

maze_log


%% ログをプロット
close all

%プロット形式整え
maze_fig_ax = gca;
maze_fig = gcf;
maze_step =  9;
maze_x_size = double(maze_x_size);
maze_y_size = double(maze_y_size);

[poleX,poleY] = meshgrid(0:maze_step:(maze_y_size-1)*maze_step,0:maze_step:(maze_x_size-1)*maze_step);
plot(poleX,poleY,'s','MarkerSize',5,...
    'MarkerEdgeColor',[0 0 0],...
    'MarkerFaceColor',[0.5 0.5 0.5]);
xlim([0 (maze_y_size-1)*maze_step])
ylim([0 (maze_x_size-1)*maze_step])
xticks(0:maze_step/2:(maze_y_size-1)*maze_step)
yticks(0:maze_step/2:(maze_x_size-1)*maze_step)
xticklabels({})
yticklabels({})
pbaspect([1 1 1])
grid on

maze_fig_ax.TickLength = [0.0 0.0];

%ログデータプロット
maze_wall_plotall(maze_y_size,maze_x_size,maze_wall_data);
maze_search_plot(maze_search_data,maze_y_size,maze_x_size,9)

%% ログから、経路算出
maze_goal = maze_goal_col;
[maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall_data,maze_search_data,maze_y_size,maze_x_size,maze_goal_size,maze_goal,1);
