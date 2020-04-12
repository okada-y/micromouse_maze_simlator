clearvars
close all
clc
%% �p�X��`
currentdir = cd;
addpath(strcat(currentdir,'/src'),'-end')

%% �f�o�b�O���[�h��`
    global maze_data_get_debug;
    maze_data_get_debug = 0;

%% mode��`
    r_mode.search = uint8(0);
    r_mode.fust_run = uint8(1);

%% ���H�f�[�^�擾
 [maze_row_size,maze_col_size,maze_row_data,maze_col_data] = maze_data_get;
 maze_row_size = uint8(maze_row_size);
 maze_col_size = uint8(maze_col_size);

 maze_data_to_serial(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% ���H���v���b�g

%�v���b�g����figure,axis���`
global maze_fig;
global maze_fig_ax;
maze_fig_ax = gca;
maze_fig = gcf;

maze_fig.Position = [2108,301,670,548];

%%
maze_data_plot(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% ���H�p�����[�^�ݒ�
maze_goal = uint8(zeros(9,2));
goal_size = uint8(4);%�S�[���T�C�Y����͂���
goal_x = 10;%�S�[��������x���W
goal_y = 10;%�S�[��������y���W
goal_size_d = double(goal_size);

%�S�[�����W����
for i = 1:sqrt(goal_size_d)
    for l = 1:sqrt(goal_size_d)
        maze_goal((l-1)*sqrt(goal_size_d)+i,:) = [goal_x+(i-1),goal_y+(l-1)];
    end
end

%% �ǃZ���T�l�����l����(C�R�[�h�����p)
%�ǃZ���TAD�l�i�[�ϐ�
global wall_sensor_front;
global wall_sensor_right;
global wall_sensor_left;
%�ǃZ���T臒l
global wall_sensor_front_th;
global wall_sensor_right_th;
global wall_sensor_left_th;

wall_sensor_front = int16(0);
wall_sensor_right = int16(0);
wall_sensor_left = int16(0);
wall_sensor_front_th = int16(0);
wall_sensor_right_th = int16(0);
wall_sensor_left_th = int16(0);

%% �����@�ŒT��

%% ���H��񏉊���
[maze_wall,maze_wall_search] = maze_init(maze_row_size,maze_col_size);
maze_wall_plotall(maze_row_size,maze_col_size,maze_wall);

%% ���[�h��`
run_mode = r_mode.search;
[maze_wall,maze_wall_search] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,maze_goal,goal_size,run_mode);


%% 

%% �T���������ƂɍŒZ���s

%���[�h��`
run_mode = r_mode.fust_run;
maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,maze_goal,goal_size,run_mode);

%% �S�ǂ����m�Ƃ����ŒZ���s

% %% ������MAP���쐬
% [contour_map,max_length] = make_map(maze_row_size,maze_col_size,maze_goal,maze_sirial);
% %% �������}�b�v���v���b�g 
% contor_fig = figure;
% [x,y]=meshgrid(0.5:1:15.5,0.5:1:15.5);
% surf(x,y,contour_map,'Marker','.','MarkerSize',10,'FaceColor','none','EdgeColor','interp')
% colorbar
% view(2)
% %% �ŒZ�o�H�Z�o
% figure(map_fig);
% fust_run(maze_sirial,contour_map,maze_goal,max_length);




