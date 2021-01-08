%% ���H���O�擾

addpath('C:\Users\���c �חT\OneDrive\�}�C�N���}�E�X\02_�J����\matlab\logger')   
addpath('./src')   
maze_log


%% ���O���v���b�g
close all
%% ���H���v���b�g

%�v���b�g����figure,axis���`
global maze_fig;
global maze_fig_ax;


%�v���b�g�`������
maze_fig_ax = gca;
set(maze_fig_ax,'color','none','NextPlot','add');
maze_fig = gcf;
%figure�̏o�͈ʒu
maze_fig.Position = [2,42,958,954];
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

%���O�f�[�^�v���b�g
maze_wall_plotall(maze_y_size,maze_x_size,maze_wall_data);
maze_search_plot(maze_search_data,maze_y_size,maze_x_size,9);

%% ���O����A�o�H�Z�o
maze_goal = maze_goal_col;
%���[�h��`
%% mode��`
%���s���[�h(run_mode_1)
run_mode1.search = uint8(0);
run_mode1.fust_run = uint8(1);
%�T�����[�h(run_mode_2)
run_mode_2_search.adachi = uint8(0);
run_mode_2_search.all = uint8(1);
run_mode_2_search.short = uint8(2);
run_mode_2_fust.straight = uint8(0);
run_mode_2_fust.diagonal = uint8(1);
%���[�h�I��
run_mode1_flg = run_mode1.fust_run;
run_mode2_flg = run_mode_2_fust.diagonal;

[maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall_data,maze_search_data,maze_y_size,maze_x_size,maze_goal_size,maze_goal,run_mode1_flg,run_mode2_flg);
   