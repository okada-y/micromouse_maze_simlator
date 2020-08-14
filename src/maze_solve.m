function[maze_wall,maze_wall_search,contour_map,row_num_node,col_num_node] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,maze_goal,run_mode)%#codegen

%maze_solve ���@�ł̖��H�T���֐�
%���� ���H�Ǐ��,���H�T�����,���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,
%�o�� �Ǐ��,�T�����

%C����֐��C���N���[�h
 if coder.target('MATLAB')
 else
     coder.updateBuildInfo('addSourceFiles','C:\work\matlab\maze_sim_git\src\C_src\matlab_movement.c');
     coder.cinclude('C:\work\matlab\maze_sim_git\src\C_src\matlab_movement.h');
     coder.updateBuildInfo('addSourceFiles','C:\work\matlab\maze_sim_git\src\C_src\matlab_IR_sensor.c');
     coder.cinclude('C:\work\matlab\maze_sim_git\src\C_src\matlab_IR_sensor.h');
 end
 
%���[�J���ϐ���` 
stop_flg = uint8(0);    % �S�[�����X�g�b�v�t���O(0:�ړ��p���@1:�X�g�b�v)
start_flg = uint8(0);   % �X�^�[�g�t���O(0:���쒆�@1:��~����̈ړ��J�n)
goal_after_flg = uint8(0);  %�S�[������t���O(0:�S�[������łȂ��@1:�S�[������)
wall_flg = uint8(0);    %�ǃt���O(1:�O�A2:�E�A�i4:���)�A8:��)

% �O���[�o���ϐ��錾
global maze_fig;
global g_direction;
% global maze_goal;
global matrix_dir;
global g_d_direction;
global l_direction;
global move_dir_property;
global turn_pattern;

%���[�J���ϐ��錾
new_goal = uint8(zeros(9,2));
new_goal_size = uint8(1); 
contour_map = zeros(32,32,'uint16');
row_num_node = ones(33,32,'uint16')*uint16(65535);
col_num_node = ones(32,33,'uint16')*uint16(65535);
goal_section = [0,0];

%�m�[�h�̑�����`
%0:�s����, 1:�����,�@2:�Z�N�V�����i�}�X�j
matrix_dir = struct('Row',uint8(0),'Col',uint8(1),'section',uint8(2));

%��Ε��p��`
g_direction = struct('North',uint8(0),'East',uint8(1),'South',uint8(2),'West',uint8(3));
%�΂ߍ��݂̐�Ε��p��`
g_d_direction = struct('North',uint8(0),'North_East',uint8(1),'East',uint8(2),'South_East',uint8(3),...
                        'South',uint8(4),'South_West',uint8(5),'West',uint8(6),'North_West',uint8(7));

%�}�E�X������`
l_direction = struct('front',uint8(0),'right',uint8(1),'back',uint8(2),'left',uint8(3));

%�ړ�����������`
%���ior�΂�
move_dir_property = struct('straight',uint8(0),'diagonal',uint8(1));

%�p�^�[���ԍ���`
turn_pattern = struct('default',uint8(0),'r_45',uint8(1),'l_45',uint8(2),'r_90',uint8(3),'l_90',uint8(4),'r_135',uint8(5),'l_135',uint8(6),'r_180',uint8(7),'l_180',uint8(8));

%�Ǐ���`
wall = struct('nowall',uint8(0),'wall',uint8(1));

%�T������`
search = struct('unknown',uint8(0),'known',uint8(1));

%���s���[�h��`
r_mode = struct('search',uint8(0),'fust_run',uint8(1),'fust_run_diagonal',uint8(2));

%% �T��
if run_mode == r_mode.search

    %�}�E�X�̏����ʒu�ݒ�
    current_x = uint8(1);
    current_y = uint8(1);
    current_dir = g_direction.North;
         
    if coder.target('MATLAB')
        %for MATLAB
        %���H�T���󋵂�\���\�ʂ��쐬
        [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        %�}�E�X�ʒu�\���p�I�u�W�F�N�g������
        [h] = hgtransform_init;
        %�T���J�n�ʒu�v���b�g
        figure(maze_fig);
        hold on
        plot(current_x * 9 -4.5,current_y * 9 -4.5,'ob','MarkerFaceColor','b','Parent',h);
        hold off
    else
       %for C gen
    end
    
    %��}�X�O�i
     [current_x,current_y] = move_step(current_x,current_y,current_dir);  
     
    %�S�[�����v���b�g
    goal_plot(goal_size,maze_goal);
    
    %�e�t���O���`
    start_flg = uint8(1);%��~����
    stop_flg = uint8(1);%��~���������{����
    goal_after_flg = uint8(0);%�S�[������t���O�̓N���A

    %�����@�ɂ��T��
    [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map]...
        = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,maze_goal,goal_size,start_flg,stop_flg,goal_after_flg);

    %�ЂƂ܂ÃS�[��(��~)
    %�e�t���O���`
    start_flg = uint8(1);%��~����
    stop_flg = uint8(0);%��~���������{���Ȃ�
    goal_after_flg = uint8(1);%�S�[������t���O�����Ă�i������ǂ���ł��悢)
    
    %�S�[�������ׂĒT��
    while 1
        search_flag = uint8(0);
        for N=1:1:goal_size
             I = maze_wall_search(maze_goal(N,2),maze_goal(N,1));
             if I ~= 15
                new_goal(1,:) = uint8([maze_goal(N,1),maze_goal(N,2)]);
                search_flag = uint8(1);
                break
             end        
        end
        if search_flag == 1
            [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map]...
                = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,new_goal,coder.ignoreConst(new_goal_size),start_flg,stop_flg,goal_after_flg);
            goal_after_flg = uint8(1);%�S�[������t���O�����Ă�
        else
            break
        end

    end
    
    %���T���}�X���Ȃ��Ȃ�܂ŁB
    % ���n�_�����ԋ߂����T���}�X��T��

    while 1

        %���T���̃}�X�𒊏o
        maze_wall_search_temp = ~logical(maze_wall_search == 15);
        %���T���}�X�̌��ݒn�i�S�[���j����̋����𒊏o
        contour_map_temp = uint16(maze_wall_search_temp) .* contour_map;
        %�T����������uint16�̏����(�V�����S�[����min�Ō��肵�����̂ŁB)
        contour_map_temp(contour_map_temp == 0) =  65535;
              
        %���T���}�X�̂����A���ݒn�����ԋ߂��}�X�̗v�f�ԍ��𒊏o
        num_temp = uint16(find(contour_map_temp == min(contour_map_temp,[],'all'),1));
        %�s�ԍ��𒊏o(32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂�)
        row_temp = uint8(rem(num_temp(1)-1,32)+1);
        %��ԍ��𒊏o(32�Ŋ������Ƃ��̏�)
        col_temp = uint8(idivide(num_temp(1)-1,32)+1);
        
        if(contour_map_temp(row_temp,col_temp) == 65535)
            %���T���}�X��������Ȃ��Ƃ��A��~���������{
            if ~coder.target('MATLAB')
                coder.ceval('m_goal_movement',start_flg,wall_flg,uint8(move_dir_property.straight));
            end
            break
           
        else 
            new_goal(1,:) = [col_temp,row_temp];
            new_goal_size = uint8(1);
            %�S�[�����v���b�g             
            goal_plot(new_goal_size,new_goal);
            
            [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map]...
                = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,new_goal,coder.ignoreConst(new_goal_size),start_flg,stop_flg,goal_after_flg);
            goal_after_flg = uint8(1);%�S�[������t���O�����Ă�
        end
     end       
        
    
    %�X�^�[�g��ړI�n�Ƃ��đ����@�ōĒT��
    %�e�t���O���`
    start_flg = uint8(1);%��~����
    stop_flg = uint8(1);%��~���������{����
    goal_after_flg = uint8(1);%�S�[������t���O�����Ă�i������ǂ���ł��悢)
    
    new_goal(1,:) = uint8([1,1]);
     [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map]...
         = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,coder.ignoreConst(new_goal),coder.ignoreConst(new_goal_size),start_flg,stop_flg,goal_after_flg);
    
        if coder.target('MATLAB')
        %for MATLAB
        %�T����������
         maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        else
        %for code generation
        end    

end

%% �ŒZ���s
if run_mode == r_mode.fust_run
    %�T���������Ƃɓ�����MAP�𐶐�
    [contour_map,max_length] = make_map_fustrun(maze_row_size,maze_col_size,maze_goal,maze_wall,maze_wall_search);
    
    %�R���^�[�}�b�v�̕`��
    if coder.target('MATLAB')
        for l = 1:32
            for j = 1:32
                text((j-1)*9+4.5,(l-1)*9+4.5,string(contour_map(l,j)),'HorizontalAlignment','center');
            end
        end
    end
    
    %�ŒZ�������s
    fust_run(maze_wall,contour_map,maze_goal,max_length)
end

%% �΂߂ł̍ŒZ���s

if run_mode == r_mode.fust_run_diagonal
   %�ŒZ�o�H����
   %�S�[���}�X�̃m�[�h�����ׂăS�[���m�[�h�Ƃ��A�}�b�v����
   [row_num_node,col_num_node,goal_num,start_num] = make_map_fustrun_diagonal(maze_goal,goal_size,maze_wall,maze_wall_search);

%�S�[���t�߂̃��[�g�œK���̂��߁A�}�b�v�Đ���
       %�X�^�[�g����S�[���m�[�h�܂ŁA���[�g�������A�S�[���m�[�h�A�������m��
       [goal_node,goal_matrix_dir,goal_dir]=decide_goal_node_dir(maze_goal,goal_size,row_num_node,col_num_node);
       %�m�肳�ꂽ�S�[���m�[�h�A��������S�[���}�X�A�m�[�h���Ē�`
       [goal_section,goal_node2,goal_matrix_dir2]=decide_goal_section(maze_goal,goal_node,goal_matrix_dir,goal_dir);
       %�m�肳�ꂽ�S�[���}�X����A�ēx�}�b�v�𐶐�
       goal_section = [goal_section(2),goal_section(1)];%x,y�ɕϊ�
       [row_num_node,col_num_node,goal_num,start_num] = make_map_fustrun_diagonal(goal_section,1,maze_wall,maze_wall_search);
        
       
       
%     if coder.target('MATLAB')   
%         %�����}�b�v�v���b�g(�ǂ̕����͂Ȃ�)
%         hold on
%         %�Z�N�V��������(�S�[���A�X�^�[�g�̂�)
%         text((goal_section(1)-1)*9+4.5,(goal_section(2)-1)*9+4.5,string(goal_num),'HorizontalAlignment','center');
%         text(4.5,4.5,string(start_num),'HorizontalAlignment','center');
%         %�G�b�W����
%         %row_node
%         for l = 1:33
%             for j = 1:32
%                 if row_num_node(l,j) ~= 65535
%                     text((j-1)*9+4.5,(l-1)*9,string(row_num_node(l,j)),'HorizontalAlignment','center');
%                 end
%             end
%         end 
% 
%         %col_node
%         for l = 1:32
%             for j = 1:33
%                 if col_num_node(l,j) ~= 65535
%                     text((j-1)*9,(l-1)*9+4.5,string(col_num_node(l,j)),'HorizontalAlignment','center');
%                 end
%             end
%         end    
%         hold off
%     end
    
    %�������ꂽMAP�����ƂɍŒZ���s
    make_route_diagonal(row_num_node,col_num_node,goal_section,goal_node2,goal_matrix_dir2);
   
    
end


%% search_adachi �����@�ł̒T��
function [current_x,current_y,current_dir,maze_wall,maze_wall_search,contour_map]...
            = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,exploration_goal,l_goal_size,start_flg,stop_flg,goal_after_flg) %#codegen
    %���́@���݈ʒux,y,���ݕ���,���H�s�����T�C�Y,���H������T�C�Y,���H�Ǐ��,���H�ǂ̒T�����,�S�[�����W
    %�o��  ���݈ʒux,y,���ݕ���,�Ǐ��,�T�����

    %local�ϐ��錾
    goal_flg = uint8(0); %�S�[������t���O
    
%     search_start_x = current_x %�T���J�n��x
%     search_start_y = current_y %�T���J�n��y
      search_start_x = uint8(1);
      search_start_y = uint8(1);
        while 1
            %�Ǐ��擾
            %���񓮍쎞�A�������̓S�[������͕Ǐ����X�V���Ȃ�
            if start_flg ~= 1 || goal_after_flg ~= 1
            [maze_wall,maze_wall_search] = wall_set(maze_row_size,maze_col_size,current_x,current_y,current_dir,maze_wall,maze_wall_search);
            else
                %���񓮍�A�������̓S�[������̂Ƃ�
                start_flg = uint8(0);%�X�^�[�g����t���O���N���A
                goal_after_flg= uint8(0);%�S�[������t���O���N���A
            end
            
            
            if coder.target('MATLAB')
                 maze_wall_plot(maze_wall,current_x,current_y,maze_row_size,maze_col_size);
            end
    
            
            % ������MAP����
            % [contour_map,max_length] = make_map2(maze_row_size,maze_col_size,maze_goal,maze_wall);
              [contour_map,max_l] = make_map_find(maze_row_size,maze_col_size,exploration_goal,l_goal_size,maze_wall);
              
            %���݈ʒu���S�[��������
            for i = 1:1:l_goal_size
                if (current_x == exploration_goal(i,1)) && (current_y == exploration_goal(i,2))
                    goal_flg = uint8(1);
                 end
            end

            %�S�[��������
            if goal_flg == 1
                if stop_flg == 1 %�S�[������~�t���O�������Ă���Ƃ�
                    %��~��������{
                    if ~coder.target('MATLAB')
                        coder.ceval('m_goal_movement',start_flg,wall_flg,uint8(move_dir_property.straight));                
                    end
                end
                %�S�[������~�t���O�������Ă��Ȃ���΁A���삳�����܂܏I��
                break        
            end
              
           % �i�s�����I��
            %�D�揇�ʁ@�k�˓��˓�ː�
             [next_dir] = get_nextdir2(current_x,current_y,maze_wall,contour_map,max_l);

           % ���ݕ����Ɛi�s�����ɉ���������
            switch rem((4 + next_dir - current_dir),4)
                case l_direction.front
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("front")
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_front',start_flg,wall_flg,uint8(move_dir_property.straight));
                        %�ǃt���O���N���A
                        wall_flg = uint8(0);
                    end
                case l_direction.right
                    [current_dir] = turn_clk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("right")
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_right',start_flg,wall_flg,uint8(move_dir_property.straight));
                        %�ǃt���O���N���A
                        wall_flg = uint8(0);
                    end                 

                case l_direction.back
                    [current_dir] = turn_180deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("back")
                    %�ǃt���O���N���A
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_back',start_flg,wall_flg,uint8(move_dir_property.straight));
                        %�ǃt���O���N���A
                        wall_flg = uint8(0);
                    end             

                case l_direction.left
                    [current_dir] = turn_conclk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("left")
                    %�ǃt���O���N���A
                    if ~coder.target('MATLAB')
                        coder.ceval('m_move_left',start_flg,wall_flg,uint8(move_dir_property.straight));
                        %�ǃt���O���N���A
                        wall_flg = uint8(0);
                    end             

                otherwise
            end

            if coder.target('MATLAB')
                %for MATLAB
                %�I�u�W�F�N�g�ʒu�X�V
                hgtransform_update(h,current_x,current_y,search_start_x,search_start_y,9);
                %�T���󋵂̍X�V
                maze_search_plot_update(search_surf,maze_wall_search,maze_col_size,maze_row_size);
                drawnow limitrate nocallbacks
                %pause(0.01)
            else
                %for code generation
            end
        end

%         
%     if coder.target('MATLAB')
%         %for MATLAB    
%         %�T���I����,�}�[�J�[���ǂ���������
%         %m = makehgtform('translate',50*9,50*9,0);
%         %h.Matrix = m;
%         %�ʂ̎�ނ̃}�[�J�[�����u��
%         hold on
%         plot(current_x * 9 -4.5,current_y * 9 -4.5,'-ob');
%         hold off
%         %�T���󋵃v���b�g�𓧖���
%         serface_transparency(search_surf);
%         drawnow
%     else
%         %for code generation
%     end


end


%% move_step ��}�X�O�i����֐�
function [current_x,current_y] = move_step(current_x,current_y,current_dir)
%���� ���݈ʒux,y,���ݕ���
%�o�� ���݈ʒux,y

    %�k�Ɉ�}�X
    if current_dir == g_direction.North
        current_y = current_y+1;
        %disp("north_step")
    end

    %���Ɉ�}�X
    if current_dir == g_direction.East
        current_x = current_x+1;
         %disp("east_step")
    end

    %��Ɉ�}�X
    if current_dir == g_direction.South
        current_y = current_y-1;
         %disp("south_step")
    end

    %���Ɉ�}�X
    if current_dir == g_direction.West
        current_x = current_x-1;
        %disp("west_step")
    end

end

%% turn_180deg 180�x�^�[������֐�
    function [current_dir] = turn_180deg(current_dir)
    %���� ���ݕ���
    %�o�� ���ݕ���

        current_dir = rem((4+current_dir)-2,4);  

    end

%% turn_clk_90deg ���v�����90�x�^�[������֐� 
    function[current_dir]= turn_clk_90deg(current_dir)  
    %���� ���ݕ���
    %�o�� ���ݕ���

        current_dir = rem((4+current_dir)+1,4); 

    end

%% turn_conclk_90deg �����v�����90�x���֐� 
    function[current_dir]= turn_conclk_90deg(current_dir)  
    %���́@���ݕ���
    %�o�́@���ݕ���
        current_dir = rem((4+current_dir) - 1,4);  

    end 

%%  wall_set �Ǐ��擾
function [maze_wall,maze_wall_search] = wall_set(maze_row_size,maze_col_size,current_x,current_y,current_dir,maze_wall,maze_wall_search)
    %matlab��ł͉摜����擾�����Ǐ����Q�Ƃ���B
    %����:�摜���瓾�����H���,���H�s�����ǖ���,���H������ǖ���, 
    %     ���ݒn���Wx,y,���ݐi�s����,���H�Ǐ��,���H�ǒT�����            
    %�o��:���H�Ǐ��,���H�ǒT����� 

    %�O���[�o���ϐ�(matlab�ł͖��H�f�[�^���AC�ł͕ǃZ���T�l���Q��)
        %for matlab
        global maze_serial;
        %for C gen
        %�ǃZ���T臒l
        global wall_sensor_front_th;
        global wall_sensor_right_th;
        global wall_sensor_left_th;
        
        
    %���[�J���ϐ��錾
    wall_write = uint8(zeros(1,4));%�Ǐ�񏑂����ݗp�o�b�t�@(N,E,S,W)
    serch_write = uint8(zeros(1,4));%�T����񏑂����ݗp�o�b�t�@(N,E,S,W)
    %�ǃZ���TAD�l�i�[�ϐ�
    wall_sensor_front = int16(0);
    wall_sensor_right = int16(0);
    wall_sensor_left = int16(0);
    
    %�}�E�X�̕����Ɋ�Â��Ǐ��擾
    %�}�E�X�̕����Ɛ�Ε����̍�=�}�E�X�̕����ƂȂ邱�Ƃ𗘗p���A
    %��Ίp�x�Ɛ������Ƃ�B
    
    %�O���̕ǔ���
    if coder.target('MATLAB')
        %for matlab
        %���m�̖��H�������ƂɁA�ǂ̗L���𔻒�
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),current_dir) ) %��[���̎����s
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %�Z���T�l�擾
        wall_sensor_front = coder.ceval('m_get_front_sensor');
        %�Z���T�l�����ƂɁA�ǂ̗L���𔻒�
        if int16(wall_sensor_front) > int16(wall_sensor_front_th)
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
            %�ǃt���O�Z�b�g
            wall_flg = bitor(wall_flg,1,'uint8');
        end
        
    end    
    %�T������X�V
    serch_write(uint8(1),rem(current_dir,4)+uint8(1)) = search.known;

    %�E�ǔ���
    if coder.target('MATLAB')
        %for matlab
        %���m�̖��H�������ƂɁA�ǂ̗L���𔻒�
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+1,4)) )
            wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %�Z���T�l�擾
        wall_sensor_right = coder.ceval('m_get_right_sensor');
        %�Z���T�l�����ƂɁA�ǂ̗L���𔻒�
        if int16(wall_sensor_right) > int16(wall_sensor_right_th)
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
            %�ǃt���O�Z�b�g
            wall_flg = bitor(wall_flg,2,'uint8');
        end
    end    
    %�T������X�V
    serch_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = search.known;

    %����͏��𓾂邱�Ƃ��ł��Ȃ��̂ŏ������Ȃ��B

    %���ǔ���
    if coder.target('MATLAB')
        %for matlab
        %���m�̖��H�������ƂɁA�ǂ̗L���𔻒�
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+3,4)) )
            wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %�Z���T�l�擾
        wall_sensor_left = coder.ceval('m_get_left_sensor');
        %�Z���T�l�����ƂɁA�ǂ̗L���𔻒�
        if int16(wall_sensor_left) > int16(wall_sensor_left_th)
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
            %�ǃt���O�Z�b�g
            wall_flg = bitor(wall_flg,8,'uint8');
        end
    end
    %�T������X�V
    serch_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = search.known;

%�����܂�

    %�Ǐ��,�T���������
    %�k��
    maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North) * wall_write(1,g_direction.North+1));
    maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.North) * serch_write(1,g_direction.North+1));
    
    %����
    maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East) * wall_write(1,g_direction.East+1));
    maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.East) * serch_write(1,g_direction.East+1));
    
    %�쑤
    maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South) * wall_write(1,g_direction.South+1));
    maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.South) * serch_write(1,g_direction.South+1));
    %����
    maze_wall(current_y,current_x) = bitor(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West) * wall_write(1,g_direction.West+1));
    maze_wall_search(current_y,current_x) = bitor(maze_wall_search(current_y,current_x),bitshift(uint8(1),g_direction.West) * serch_write(1,g_direction.West+1));

    %�ׂ荇���}�X�̏��ɂ�����
    %�k���̃}�X�̓쑤�̕Ǐ��
    if current_y < maze_row_size-1
        maze_wall(current_y+1,current_x) = bitor(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.South) * wall_write(1,g_direction.North+1));
        maze_wall_search(current_y+1,current_x) = bitor(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.South) * serch_write(1,g_direction.North+1));
    end
    %�����̃}�X�̐����̕Ǐ��
    if current_x < maze_col_size-1
        maze_wall(current_y,current_x+1) = bitor(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.West) * wall_write(1,g_direction.East+1));
        maze_wall_search(current_y,current_x+1) = bitor(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.West) * serch_write(1,g_direction.East+1));
    end    

    %�쑤�̃}�X�̖k���̕Ǐ��
    if current_y > 1
        maze_wall(current_y-1,current_x) = bitor(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.North) * wall_write(1,g_direction.South+1));
        maze_wall_search(current_y-1,current_x) = bitor(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.North) * serch_write(1,g_direction.South+1));
    end

    %�����̃}�X�̓����̕Ǐ��
    if current_x > 1
        maze_wall(current_y,current_x-1) = bitor(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.East) * wall_write(1,g_direction.West+1));
        maze_wall_search(current_y,current_x-1) = bitor(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.East) * serch_write(1,g_direction.West+1));
    end

    %���ݒn���S�[���łȂ��ꍇ
    tempx  = logical(maze_goal(1:end,1) == current_x);
    tempy  = logical(maze_goal(1:end,2) == current_y);
    temp = ~max(tempx .* tempy);
    if(temp)

    %���ɑ΂��A3�����T���ς݂��A���ׂĕǂ��Ȃ��ꍇ�A����������̕ǂ��m�肳����B
        %�k,���ɕǂ��Ȃ��ꍇ
        if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))...
                && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))

            %�k�̃}�X�̓����T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.East))...
                    && (bitand(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))
                %���̃}�X�̖k�̕ǂ��m��A�T���ς݂Ƃ���B
                    maze_wall(current_y,current_x+1) = bitor(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.North));
                    maze_wall_search(current_y,current_x+1) = bitor(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.North));
                %�ׂ荇���}�X�i���k�}�X�j�̓�̕ǂ��m��
                    maze_wall(current_y+1,current_x+1) = bitor(maze_wall(current_y+1,current_x+1),bitshift(uint8(1),g_direction.South));
                    maze_wall_search(current_y+1,current_x+1) = bitor(maze_wall_search(current_y+1,current_x+1),bitshift(uint8(1),g_direction.South));
            end
            %���̃}�X�̖k���T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.North))...
                    && (bitand(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))
              %�k�̃}�X�̓��̕ǂ��m��A�T���ς݂Ƃ���B
                    maze_wall(current_y+1,current_x) = bitor(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.East));
                    maze_wall_search(current_y+1,current_x) = bitor(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.East));
                %�ׂ荇���}�X�i���k�}�X�j�̐��̕ǂ��m��
                    maze_wall(current_y+1,current_x+1) = bitor(maze_wall(current_y+1,current_x+1),bitshift(uint8(1),g_direction.West));
                    maze_wall_search(current_y+1,current_x+1) = bitor(maze_wall_search(current_y+1,current_x+1),bitshift(uint8(1),g_direction.West));
            end


        end

        %�k,���ɕǂ��Ȃ��ꍇ
         if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North))...
                && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))
            %�k�̃}�X�̐����T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.West))...
                && (bitand(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))
                %���̃}�X�̖k�̕ǂ��m��A�T���ς݂Ƃ���B
                maze_wall(current_y,current_x-1) = bitor(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.North));
                maze_wall_search(current_y,current_x-1) = bitor(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.North));
                %�ׂ荇���}�X�i�k���}�X�j�̓�̕ǂ��m��
                maze_wall(current_y+1,current_x-1) = bitor(maze_wall(current_y+1,current_x-1),bitshift(uint8(1),g_direction.South));
                maze_wall_search(current_y+1,current_x-1) = bitor(maze_wall_search(current_y+1,current_x-1),bitshift(uint8(1),g_direction.South));
            end

            %���̃}�X�̖k���T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.North))...
                && (bitand(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.North)) ~= bitshift(uint8(1),g_direction.North)) 
                %�k�̃}�X�̐��̕ǂ��m��A�T���ς݂Ƃ���B
                maze_wall(current_y+1,current_x) = bitor(maze_wall(current_y+1,current_x),bitshift(uint8(1),g_direction.West));
                maze_wall_search(current_y+1,current_x) = bitor(maze_wall_search(current_y+1,current_x),bitshift(uint8(1),g_direction.West));
                %�ׂ荇���}�X�i�k���}�X�j�̓��̕ǂ��m��
                maze_wall(current_y+1,current_x-1) = bitor(maze_wall(current_y+1,current_x-1),bitshift(uint8(1),g_direction.East));
                maze_wall_search(current_y+1,current_x-1) = bitor(maze_wall_search(current_y+1,current_x-1),bitshift(uint8(1),g_direction.East));
             end
         end

        %��,���ɕǂ��Ȃ��ꍇ
         if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East))...
            && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South))
            %��̃}�X�̓����T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.East))...
                && (bitand(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.East)) ~= bitshift(uint8(1),g_direction.East)) 
                %���̃}�X�̓�̕ǂ��m��A�T���ς݂Ƃ���B
                maze_wall(current_y,current_x+1) = bitor(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.South));
                maze_wall_search(current_y,current_x+1) = bitor(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.South));
                %�ׂ荇���}�X�i�쓌�}�X�j�̖k�̕ǂ��m��
                maze_wall(current_y-1,current_x+1) = bitor(maze_wall(current_y-1,current_x+1),bitshift(uint8(1),g_direction.North));
                maze_wall_search(current_y-1,current_x+1) = bitor(maze_wall_search(current_y-1,current_x+1),bitshift(uint8(1),g_direction.North));
            end
            %���̃}�X�̓삪�T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y,current_x+1),bitshift(uint8(1),g_direction.South))...
                && (bitand(maze_wall(current_y,current_x+1),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South)) 
                %��̃}�X�̓��̕ǂ��m��A�T���ς݂Ƃ���B
                maze_wall(current_y-1,current_x) = bitor(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.East));
                maze_wall_search(current_y-1,current_x) = bitor(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.East));
                %�ׂ荇���}�X�i�쓌�}�X�j�̐��̕ǂ��m��B�T���ς݂Ƃ���
                maze_wall(current_y-1,current_x+1) = bitor(maze_wall(current_y-1,current_x+1),bitshift(uint8(1),g_direction.West));
                maze_wall_search(current_y-1,current_x+1) = bitor(maze_wall_search(current_y-1,current_x+1),bitshift(uint8(1),g_direction.West));
             end
         end

        %��,���ɕǂ��Ȃ��ꍇ
        if (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West))...
            && (bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South))
            %��̃}�X�̐����T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.West))...
                && (bitand(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.West)) ~= bitshift(uint8(1),g_direction.West)) 
                %���̃}�X�̓�̕ǂ��m��A�T���ς݂Ƃ���B
                maze_wall(current_y,current_x-1) = bitor(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.South));
                maze_wall_search(current_y,current_x-1) = bitor(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.South));
                %�ׂ荇���}�X�i�쐼�}�X�j�̖k�̕ǂ��m��B�T���ς݂Ƃ���
                maze_wall(current_y-1,current_x-1) = bitor(maze_wall(current_y-1,current_x-1),bitshift(uint8(1),g_direction.North));
                maze_wall_search(current_y-1,current_x-1) = bitor(maze_wall_search(current_y-1,current_x-1),bitshift(uint8(1),g_direction.North));
            end
            %���̃}�X�̓삪�T���ς݁@���@�ǂ��Ȃ��Ƃ�
            if bitand(maze_wall_search(current_y,current_x-1),bitshift(uint8(1),g_direction.South))...
                && (bitand(maze_wall(current_y,current_x-1),bitshift(uint8(1),g_direction.South)) ~= bitshift(uint8(1),g_direction.South)) 
                %��̃}�X�̐��̕ǂ��m��A�T���ς݂Ƃ���B
                maze_wall(current_y-1,current_x) = bitor(maze_wall(current_y-1,current_x),bitshift(uint8(1),g_direction.West));
                maze_wall_search(current_y-1,current_x) = bitor(maze_wall_search(current_y-1,current_x),bitshift(uint8(1),g_direction.West));
                %�ׂ荇���}�X�i�쐼�}�X�j�̓��̕ǂ��m��B�T���ς݂Ƃ���
                maze_wall(current_y-1,current_x-1) = bitor(maze_wall(current_y-1,current_x-1),bitshift(uint8(1),g_direction.East));
                maze_wall_search(current_y-1,current_x-1) = bitor(maze_wall_search(current_y-1,current_x-1),bitshift(uint8(1),g_direction.East));
            end
        end
    end
end
%%  make_map_find �Ǐ�񂩂瓙����MAP�𐶐�
    function [contour_map,max_length] = make_map_find(maze_row_size,maze_col_size,maze_goal,l_goal_size,maze_wall)
    %���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��)
    %�o�� ������map,�ő�o�H��


    % ���H�p�����[�^�ݒ�
    max_length = uint16(65535);

    %MAP�̏�����(���ׂĂ̗v�f��max_length�����)
    %32�}�X��map��ێ�
    %16bit�ɂ��ׂ�
    contour_map = ones(32,32,'uint16');
    contour_map = contour_map * max_length;

    %�S�[�����W��0�����
    for temp = 1:1:l_goal_size
        contour_map(maze_goal(temp,2),maze_goal(temp,1)) = uint16(0);
    end


    while 1
        change_flag = uint8(0); %map�X�V�m�F�p�t���O

        for tempi = 0:1:max_length-1 %�����J�E���g��0~max_length
                %�������m�肵�Ă�����W������
                %�ŏ���0,�X�V����A���������}�X�����X�������Ă���
                num_temp = uint16(find(contour_map == tempi));
                 %32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂�
                row = uint8(rem(num_temp-1,32)+1);
                 %��ԍ�:32�Ŋ������Ƃ��̏�
                col = uint8(idivide(num_temp-1,32)+1);
                 %���������}�X�̐�
                row_size = uint8(numel(row));
                
                %�X�V�}�X��������Ȃ���ΏI��
                if row_size == uint8(0)
                    break;
                end
                                
                %�����������W�ɑ΂��A����map���X�V
                for tempn = 1:1:row_size
                    %�k��
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North)) == wall.nowall)
                        %�k����MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn)+1,col(tempn)) == max_length 
                        contour_map(row(tempn)+1,col(tempn)) = tempi+uint16(1);
                        change_flag = uint8(1);
                        end
                    end

                    %����
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East)) == wall.nowall)
                        %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn),col(tempn)+1) == max_length 
                        contour_map(row(tempn),col(tempn)+1) = tempi+uint16(1);
                        change_flag = uint8(1);
                        end
                    end

                    %�쑤
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South)) == wall.nowall)
                        %�쑤��MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn)-1,col(tempn)) == max_length 
                        contour_map(row(tempn)-1,col(tempn)) = tempi+uint16(1);
                        change_flag = uint8(1);
                        end
                    end

                    %����
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West)) == wall.nowall)
                        %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn),col(tempn)-1) == max_length 
                        contour_map(row(tempn),col(tempn)-1) = tempi+uint16(1);
                        change_flag = uint8(1);
                        end
                    end
                end    
        end
        
    %�X�V���Ȃ���ΏI��    
        if change_flag == uint8(0)
            break;
        end

    end


    end

%% get_nextdir2 ������map���玟�Ɍ�����������I��
    function [next_dir] = get_nextdir2(current_x,current_y,maze_wall,contour_map,max_length)
    % ���� ���ݒnx,y,�Ǐ��,������map,�ő�o�H��
    % �o�� ���̐i�s���p

            %�o�͂̏�����
            next_dir = uint8(0);
                
            little = max_length;

            %%�i�s�����I��
            %�D�揇�ʁ@�k�˓��˓�ː�

            %�k���̕ǂ̂���Ȃ�����
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) == 0 
                %�k���̓�����map��臒l���Ⴏ��΁A
                if contour_map(current_y+1,current_x) < little
                    %臒l��k���̓���map�l�ɕύX
                    little = contour_map(current_y+1,current_x);
                    %�k����i�s�����ɕύXy
                    next_dir = g_direction.North;
                end
            end

            %����
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) == 0 
                if contour_map(current_y,current_x+1) < little
                    little = contour_map(current_y,current_x+1);
                    next_dir = g_direction.East;
                end
            end


            %�쑤
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) == 0 
                if contour_map(current_y-1,current_x) < little
                    little = contour_map(current_y-1,current_x);
                    next_dir = g_direction.South;
                end
            end

            %����
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) == 0 
                if contour_map(current_y,current_x-1) < little
                    % little = contour_map(current_y,current_x-1);
                    next_dir = g_direction.West;
                end
            end



    end
%% fust_run �ŒZ�o�H���o
    function [] = fust_run(maze_wall,contour_map,maze_goal,max_length)
    %���́@�Ǐ��,�ǒT�����,������MAP,�S�[�����W,�ő�o�H��
    %�o��  

    %local�ϐ��錾
    goal_flag = uint8(0);  %�S�[������t���O
    little = max_length; %�i�s�����I��p臒l
    tempi = uint8(0);
    
    %�}�E�X�ʒu�\���p�I�u�W�F�N�g
    if coder.target('MATLAB')
        ax = gca;
        h = hgtransform('Parent',ax);
    end
    %�}�E�X�̏����ʒu�ݒ�
    current_x = uint8(1);
    current_y = uint8(1);
    
    previous_x = current_x;
    previous_y = current_y;
    
        
    current_dir = g_direction.North;
    next_dir = g_direction.North;
    search_start_x = current_x; %�T���J�n��x
    search_start_y = current_y; %�T���J�n��y

    %�T���J�n�ʒu�v���b�g
        if coder.target('MATLAB')
            hold on
            plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'ob','MarkerSize',10,'MarkerFaceColor','r','Parent',h);
            hold off
        end

%     %���Ճv���b�g
%     hold on
%     plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r');
%     hold off
%     drawnow limitrate nocallbacks

    while 1

            %���݈ʒu���S�[��������
            for tempi = 1:1:goal_size
                if (current_x == maze_goal(tempi,1)) && (current_y == maze_goal(tempi,2))
                    goal_flag = uint8(1);
                 end
            end

            if goal_flag == 1
                break        
            end

            %%�i�s�����I��
            %�D�揇�ʁ@�k�˓��˓�ː�

            %�k���̕ǂ̂���Ȃ�
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.North)) == wall.nowall
                %�k���̓�����map��臒l���Ⴏ��΁A
                if contour_map(current_y+1,current_x) < little
                    %臒l��k���̓���map�l�ɕύX
                    little = contour_map(current_y+1,current_x);
                    %�k����i�s�����ɕύXy
                    next_dir = g_direction.North;
                end
            end

            %����
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.East)) == wall.nowall
                if contour_map(current_y,current_x+1) < little
                    little = contour_map(current_y,current_x+1);
                    next_dir = g_direction.East;
                end
            end

            %�쑤
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.South)) == wall.nowall 
                if contour_map(current_y-1,current_x) < little
                    little = contour_map(current_y-1,current_x);
                    next_dir = g_direction.South;
                end
            end

            %����
            if bitand(maze_wall(current_y,current_x),bitshift(uint8(1),g_direction.West)) == wall.nowall
                if contour_map(current_y,current_x-1) < little
                    little = contour_map(current_y,current_x-1);
                    next_dir = g_direction.West;
                end
            end



            %%���ݕ����Ɛi�s�����ɉ���������
            switch rem((4 + next_dir - current_dir),4)
                case l_direction.front
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("front")

                case l_direction.right
                    [current_dir] = turn_clk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("right")

                case l_direction.back
                    [current_dir] = turn_180deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("back")

                case l_direction.left
                    [current_dir] = turn_conclk_90deg(current_dir);
                    [current_x,current_y] = move_step(current_x,current_y,current_dir);
                    %disp("left")

                otherwise
            end
            
        if coder.target('MATLAB')
        %for MATLAB    
        %�}�E�X�`��ʒu�X�V
            m = makehgtform('translate',double(current_x-search_start_x)*9,double(current_y-search_start_y)*9,0);
            h.Matrix = m;
            %�O�Ճv���b�g
            hold on
            plot([double(previous_x)*9-4.5,double(current_x)*9-4.5],[double(previous_y)*9-4.5,double(current_y)*9-4.5]...
                ,'Color','#D95319','LineWidth',3)
%             plot(double(current_x) * 9 -4.5,double(current_y) * 9 -4.5,'.r');
            hold off
            pause(0.01)
            drawnow limitrate nocallbacks
        else
        %for code generation
        end
        
        previous_x = current_x;
        previous_y = current_y;
    end
end

%% make_map_fustrun �ŒZ���s�p������MAP�𐶐�
function [contour_map,max_length] = make_map_fustrun(maze_row_size,maze_col_size,maze_goal,maze_wall,maze_wall_search)
%���m�ǂ̗̈�͉��z�ǂ������ĐN�����Ȃ��B
%���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��),���H�T�����(16�i��)
%�o�� ������map,�ő�o�H��

%���[�J���ϐ��ݒ�
tempn=uint8(0);
tempi=uint8(0);

%�p�����[�^�ݒ�
straight_weight = uint16(5);

    % ���H�p�����[�^�ݒ�
    max_length = uint16(65535);

    %MAP�̏�����(���ׂĂ̗v�f��max_length�����)
    %32�}�X��map��ێ�
    contour_map = ones(32,32,'uint16');
    contour_map = contour_map * max_length;
       
    %�i�s�����⊮�p�ϐ���`
    move_dir_map = zeros(32,32,'uint8'); 
    
    %�S�[�����W��
    % �����}�b�v�F0�����
    % �i�s���� : 1+2+4+8(������k���ׂ�)=15
    % �����
    for tempn = 1:1:goal_size
        contour_map(maze_goal(tempn,2),maze_goal(tempn,1)) = uint16(0);
        move_dir_map(maze_goal(tempn,2),maze_goal(tempn,1)) = bitshift(uint8(1),g_direction.North)...
                                                               +bitshift(uint8(1),g_direction.East)...
                                                               +bitshift(uint8(1),g_direction.South)...
                                                               +bitshift(uint8(1),g_direction.West);
    end
    
   %�X�V����p�ϐ�(�d�݂Â��Ȃ��̕����}�b�v)
   contour_refine_map = contour_map;

    while 1
        change_flag = uint8(0); %map�X�V�m�F�p�t���O

        for tempi = 0:1:max_length-1 %�X�V�m�F�p�̕����J�E���g��0~max_length
               
                %�������m�肵�Ă�����W������
                %�ŏ���0,�X�V����A���������}�X�����X�������Ă���
                num_temp = uint16(find(contour_refine_map == tempi));
                 %32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂�
                row = uint8(rem(num_temp-1,32)+1);
                 %��ԍ�:32�Ŋ������Ƃ��̏�
                col = uint8(idivide(num_temp-1,32)+1);
                 %���������}�X�̐�
                row_size = uint16(numel(row));

                %�����������W�ɑ΂��A����map���X�V
                for tempn = 1:1:row_size
                    
                    %�k��
                    
                    %�ǂ����� & �T���ς݂ł���Ƃ�
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North))) == search.known
                        
                        %���i�s�������k�����ł��鎞
                        if logical(bitand(move_dir_map(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North)))
                            %���k�̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ
                            if contour_map(row(tempn)+1,col(tempn)) > contour_map(row(tempn),col(tempn))+1
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn)+1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V
                                contour_map(row(tempn)+1,col(tempn)) = contour_map(row(tempn),col(tempn))+uint16(1);
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn)+1,col(tempn)) = bitshift(uint8(1),g_direction.North);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                            
                        %���i�s�������k�����łȂ��Ƃ�    
                        else
                            %���k�̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                            if contour_map(row(tempn)+1,col(tempn)) > contour_map(row(tempn),col(tempn))+straight_weight     
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn)+1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V(�d�݂Â�����)
                                contour_map(row(tempn)+1,col(tempn)) = contour_map(row(tempn),col(tempn))+straight_weight;
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn)+1,col(tempn)) = bitshift(uint8(1),g_direction.North);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                        end
                    end
                    
                    
                    %����
                    
                    %�ǂ����� & �T���ς݂ł���Ƃ�
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East))) == search.known
                        
                        %���i�s�������������ł��鎞
                        if logical(bitand(move_dir_map(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East)))
                            %�����̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ
                            if contour_map(row(tempn),col(tempn)+1) > contour_map(row(tempn),col(tempn))+1
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn),col(tempn)+1) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V
                                contour_map(row(tempn),col(tempn)+1) = contour_map(row(tempn),col(tempn))+uint16(1);
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn),col(tempn)+1) = bitshift(uint8(1),g_direction.East);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                            
                        %���i�s�������������łȂ��Ƃ�    
                        else
                            %�����̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                            if contour_map(row(tempn),col(tempn)+1) > contour_map(row(tempn),col(tempn))+straight_weight     
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn),col(tempn)+1) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V(�d�݂Â�����)
                                contour_map(row(tempn),col(tempn)+1) = contour_map(row(tempn),col(tempn))+straight_weight;
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn),col(tempn)+1) = bitshift(uint8(1),g_direction.East);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                        end
                    end
                    
                    %�쑤
                    
                    %�ǂ����� & �T���ς݂ł���Ƃ�
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South))) == search.known
                        
                        %���i�s������������ł��鎞
                        if logical(bitand(move_dir_map(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South)))
                            %����̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ
                            if contour_map(row(tempn)-1,col(tempn)) > contour_map(row(tempn),col(tempn))+1
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn)-1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V
                                contour_map(row(tempn)-1,col(tempn)) = contour_map(row(tempn),col(tempn))+uint16(1);
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn)-1,col(tempn)) = bitshift(uint8(1),g_direction.South);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                            
                        %���i�s������������łȂ��Ƃ�    
                        else
                            %����̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                            if contour_map(row(tempn)-1,col(tempn)) > contour_map(row(tempn),col(tempn))+straight_weight     
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn)-1,col(tempn)) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V(�d�݂Â�����)
                                contour_map(row(tempn)-1,col(tempn)) = contour_map(row(tempn),col(tempn))+straight_weight;
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn)-1,col(tempn)) = bitshift(uint8(1),g_direction.South);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                        end
                    end
                                        
                    %����
                    
                    %�ǂ����� & �T���ς݂ł���Ƃ�
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West))) == search.known
                        
                        %���i�s�������������ł��鎞
                        if logical(bitand(move_dir_map(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West)))
                            %���k�̃}�X���X�V�\��l�����傫�Ȓl�̏ꍇ
                            if contour_map(row(tempn),col(tempn)-1) > contour_map(row(tempn),col(tempn))+1
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn),col(tempn)-1) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V
                                contour_map(row(tempn),col(tempn)-1) = contour_map(row(tempn),col(tempn))+uint16(1);
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn),col(tempn)-1) = bitshift(uint8(1),g_direction.West);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                            
                        %���i�s�������������łȂ��Ƃ�    
                        else
                            %���k�̃}�X�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                            if contour_map(row(tempn),col(tempn)-1) > contour_map(row(tempn),col(tempn))+straight_weight     
                                %�X�V�m�F�p��MAP�X�V
                                contour_refine_map(row(tempn),col(tempn)-1) = contour_refine_map(row(tempn),col(tempn))+uint16(1);
                                %����MAP�X�V(�d�݂Â�����)
                                contour_map(row(tempn),col(tempn)-1) = contour_map(row(tempn),col(tempn))+straight_weight;
                                %�ړ�����MAP�X�V
                                move_dir_map(row(tempn),col(tempn)-1) = bitshift(uint8(1),g_direction.West);
                                %�X�V�t���O�𗧂Ă�
                                change_flag = uint8(1);
                            end
                        end
                    end
                end    
        end
    %�X�V���Ȃ���ΏI��    
        if change_flag == 0
            break;
        end

    end


end

%% make_map_fustrun_diagonal �ŒZ���s�p������MAP�𐶐�
function [row_num_node,col_num_node,goal_num,start_num] = make_map_fustrun_diagonal(maze_goal,goal_size,maze_wall,maze_wall_search)
%���m�ǂ̗̈�͉��z�ǂ������ĐN�����Ȃ��B
%���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��),���H�T�����(16�i��)
%�o�� ������map,�ő�o�H��

%���[�J���ϐ��ݒ�

%�p�����[�^�ݒ�

    % ���H�p�����[�^�ݒ�
    max_length = uint16(32*32);

    % ���[�g�̏d�ݐݒ�
    weight_straight = uint16(6);
    weight_straight_harf = uint16(3);
    weight_diagonal = uint16(4);
    weight_turn = uint16(18);
    
    %MAP�̏�����(���ׂẴm�[�h��max_length�����)
    %����MAP
    row_num_node = ones(33,32,'uint16')*uint16(65535);
    col_num_node = ones(32,33,'uint16')*uint16(65535);
    %�X�V�pMAP
    row_num_node_temp = ones(33,32,'uint16')*uint16(65535);
    col_num_node_temp = ones(32,33,'uint16')*uint16(65535);
    %�i�s�����ێ��p�m�[�h�쐬
    row_dir_node = zeros(33,32,'uint8');
    col_dir_node = zeros(32,33,'uint8');
    
    %�S�[���Z�N�V�������m�肵�Ă���ꍇ
    goal_num = uint16(0);
    start_num = uint16(65535);
    if goal_size == 1
        goal_section_l = maze_goal(1,:);
        
        %�S�[���}�X����A������k�Ƀ}�b�v��W�J
        %�k��
        if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.North))
            %�����X�V
            row_num_node(goal_section_l(2)+1,goal_section_l(1)) = weight_straight_harf;
            %�����ǉ�
            row_dir_node(goal_section_l(2)+1,goal_section_l(1)) ...
                = bitor(row_dir_node(goal_section_l(2)+1,goal_section_l(1)),bitshift(uint8(1),g_d_direction.North));
            %�X�V�pMAP�X�V
            row_num_node_temp(goal_section_l(2)+1,goal_section_l(1)) = 0;
        end
        
        %����
        if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.East))
            %�����X�V
            col_num_node(goal_section_l(2),goal_section_l(1)+1) = weight_straight_harf;
            %�����ǉ�
            col_dir_node(goal_section_l(2),goal_section_l(1)+1) ...
                = bitor(col_dir_node(goal_section_l(2),goal_section_l(1)+1),bitshift(uint8(1),g_d_direction.East));
            %�X�V�pMAP�X�V
            col_num_node_temp(goal_section_l(2),goal_section_l(1)+1) = 0;
        end
        
        %���
        if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.South))
            %�����X�V
            row_num_node(goal_section_l(2),goal_section_l(1)) = weight_straight_harf;
            %�����ǉ�
            row_dir_node(goal_section_l(2),goal_section_l(1)) ...
                = bitor(row_dir_node(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_d_direction.South));
            %�X�V�pMAP�X�V
            row_num_node_temp(goal_section_l(2),goal_section_l(1)) = 0;
        end
        
        %����
        if ~bitand(maze_wall(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_direction.West))
            %�����X�V
            col_num_node(goal_section_l(2),goal_section_l(1)) = weight_straight_harf;
            %�����ǉ�
            col_dir_node(goal_section_l(2),goal_section_l(1)) ...
                = bitor(col_dir_node(goal_section_l(2),goal_section_l(1)),bitshift(uint8(1),g_d_direction.West));
            %�X�V�pMAP�X�V
            col_num_node_temp(goal_section_l(2),goal_section_l(1)) = 0;
        end
        
    %�S�[���Z�N�V�������m�肵�Ă��Ȃ��ꍇ    
    else    
        %�S�[���m�[�h��
        % �����F0�����
        % �i�s���� : �ǂ��Ȃ���ΑS����=0b11111111=255
        % �����
        for n=1:1:goal_size

            %�k��
            if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.North))
                %�����X�V
                row_num_node(maze_goal(n,2)+1,maze_goal(n,1)) = 0;
                %�����X�V
                row_dir_node(maze_goal(n,2)+1,maze_goal(n,1)) = 255;
            end

            %����
            if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.East))
                %�����X�V
                col_num_node(maze_goal(n,2),maze_goal(n,1)+1) = 0;
                %�����X�V
                col_dir_node(maze_goal(n,2),maze_goal(n,1)+1) = 255;
            end 

            %���
            if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.South))
                %�����X�V
                row_num_node(maze_goal(n,2),maze_goal(n,1)) = 0;
                %�����X�V
                row_dir_node(maze_goal(n,2),maze_goal(n,1)) = 255;
            end 

            %����
            if ~bitand(maze_wall(maze_goal(n,2),maze_goal(n,1)),bitshift(uint8(1),g_direction.West))
                %�����X�V
                col_num_node(maze_goal(n,2),maze_goal(n,1)) = 0;
                %�����X�V
                col_dir_node(maze_goal(n,2),maze_goal(n,1)) = 255;
            end

        end
        %�X�V����p�ϐ�(�d�݂Â��Ȃ��̕����}�b�v)
        row_num_node_temp = row_num_node;
        col_num_node_temp = col_num_node; 
    end

    while 1
        change_flag = uint8(0); %map�X�V�m�F�p�t���O
        for i = 0:1:max_length-1 %�X�V�m�F�p�̕����J�E���g��0~max_length
              
            %Row_Edge�̏���[33�s,32��]
            %�������m�肵�Ă�����W������
            %�ŏ���0,�X�V����A���������}�X�����X�������Ă���
            num_temp = uint16(find(row_num_node_temp == i));
            %33�s�Ȃ̂ŁA�s�ԍ�:33�Ŋ��������܂�
            row = uint16(rem(num_temp-1,33)+1);
            %��ԍ�:33�Ŋ������Ƃ��̏�
            col = uint16(idivide(num_temp-1,33)+1);
            %���������}�X�̐�
            row_size = uint16(numel(row));

            %�����������W�ɑ΂��A����map���X�V
            for n = 1:1:row_size

                %�k��
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)),bitshift(uint8(1),g_direction.North))) == search.known
                    %���i�s�������k�����ł��鎞
                    if logical(bitand(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North)))
                        %���k�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if row_num_node(row(n)+1,col(n)) > row_num_node(row(n),col(n))+weight_straight
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)+1,col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            row_num_node(row(n)+1,col(n)) = row_num_node(row(n),col(n))+weight_straight;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)+1,col(n)) = bitshift(uint8(1),g_d_direction.North);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)+1,col(n)) == row_num_node(row(n),col(n))+weight_straight
                            %�ړ�������ǉ�
                            row_dir_node(row(n)+1,col(n)) = bitor(row_dir_node(row(n)+1,col(n)),bitshift(uint8(1),g_d_direction.North));
                        end
                        
                    %���i�s�������k�����łȂ��Ƃ�    
                    else
                        %���k�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if row_num_node(row(n)+1,col(n)) > row_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)+1,col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            row_num_node(row(n)+1,col(n)) = row_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)+1,col(n)) = bitshift(uint8(1),g_d_direction.North);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)+1,col(n)) == row_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            row_dir_node(row(n)+1,col(n)) = bitor(row_dir_node(row(n)+1,col(n)),bitshift(uint8(1),g_d_direction.North));
                        end
                    end
                end

                %�k����
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)),bitshift(uint8(1),g_direction.East))) == search.known
                    %���i�s�������k�������ł��鎞
                    if logical(bitand(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North_East)))
                        %���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if col_num_node(row(n),col(n)+1) > row_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)+1) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            col_num_node(row(n),col(n)+1) = row_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)+1) = bitshift(uint8(1),g_d_direction.North_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)+1) == row_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)+1) = bitor(col_dir_node(row(n),col(n)+1),bitshift(uint8(1),g_d_direction.North_East));
                        end

                    %���i�s�������k�������łȂ��Ƃ�    
                    else
                        %���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if col_num_node(row(n),col(n)+1) > row_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)+1) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            col_num_node(row(n),col(n)+1) = row_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)+1) = bitshift(uint8(1),g_d_direction.North_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)+1) == row_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)+1) = bitor(col_dir_node(row(n),col(n)+1),bitshift(uint8(1),g_d_direction.North_East));
                        end
                    end
                end

                %�����͒�

                %�쓌��
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n)-1,col(n)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n)-1,col(n)),bitshift(uint8(1),g_direction.East))) == search.known
                    %���i�s�������쓌�����ł��鎞
                    if logical(bitand(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South_East)))
                        %���쓌�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if col_num_node(row(n)-1,col(n)+1) > row_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n)-1,col(n)+1) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            col_num_node(row(n)-1,col(n)+1) = row_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n)-1,col(n)+1) = bitshift(uint8(1),g_d_direction.South_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n)-1,col(n)+1) == row_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            col_dir_node(row(n)-1,col(n)+1) = bitor(col_dir_node(row(n)-1,col(n)+1),bitshift(uint8(1),g_d_direction.South_East));
                        end


                    %���i�s�������쓌�����łȂ��Ƃ�    
                    else
                        %���쓌�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if col_num_node(row(n)-1,col(n)+1) > row_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n)-1,col(n)+1) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            col_num_node(row(n)-1,col(n)+1) = row_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n)-1,col(n)+1) = bitshift(uint8(1),g_d_direction.South_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n)-1,col(n)+1) == row_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            col_dir_node(row(n)-1,col(n)+1) = bitor(col_dir_node(row(n)-1,col(n)+1),bitshift(uint8(1),g_d_direction.South_East));
                        end
                    end
                end

                %�쑤
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n)-1,col(n)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n)-1,col(n)),bitshift(uint8(1),g_direction.South))) == search.known
                    %���i�s������������ł��鎞
                    if logical(bitand(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South)))
                        %����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if row_num_node(row(n)-1,col(n)) > row_num_node(row(n),col(n))+weight_straight
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)-1,col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            row_num_node(row(n)-1,col(n)) = row_num_node(row(n),col(n))+weight_straight;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)-1,col(n)) = bitshift(uint8(1),g_d_direction.South);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %����̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)-1,col(n)) == row_num_node(row(n),col(n))+weight_straight
                            %�ړ�������ǉ�
                            row_dir_node(row(n)-1,col(n)) = bitor(row_dir_node(row(n)-1,col(n)),bitshift(uint8(1),g_d_direction.South));
                        end

                    %���i�s������������łȂ��Ƃ�    
                    else
                        %����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if row_num_node(row(n)-1,col(n)) > row_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)-1,col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            row_num_node(row(n)-1,col(n)) = row_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)-1,col(n)) = bitshift(uint8(1),g_d_direction.South);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %����̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)-1,col(n)) == row_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            row_dir_node(row(n)-1,col(n)) = bitor(row_dir_node(row(n)-1,col(n)),bitshift(uint8(1),g_d_direction.South));
                        end
                    end
                end

                %�쐼��
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n)-1,col(n)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n)-1,col(n)),bitshift(uint8(1),g_direction.West))) == search.known
                    %���i�s�������쐼�����ł��鎞
                    if logical(bitand(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South_West)))
                        %���쐼�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if col_num_node(row(n)-1,col(n)) > row_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n)-1,col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            col_num_node(row(n)-1,col(n)) = row_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n)-1,col(n)) = bitshift(uint8(1),g_d_direction.South_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n)-1,col(n)) == row_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            col_dir_node(row(n)-1,col(n)) = bitor(col_dir_node(row(n)-1,col(n)),bitshift(uint8(1),g_d_direction.South_West));
                        end

                    %���i�s�������쐼�����łȂ��Ƃ�    
                    else
                        %���쐼�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if col_num_node(row(n)-1,col(n)) > row_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n)-1,col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            col_num_node(row(n)-1,col(n)) = row_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n)-1,col(n)) = bitshift(uint8(1),g_d_direction.South_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n)-1,col(n)) == row_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            col_dir_node(row(n)-1,col(n)) = bitor(col_dir_node(row(n)-1,col(n)),bitshift(uint8(1),g_d_direction.South_West));
                        end
                    end
                end

                %�k����
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)),bitshift(uint8(1),g_direction.West))) == search.known
                    %���i�s�������k�������ł��鎞
                    if logical(bitand(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North_West)))
                        %���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if col_num_node(row(n),col(n)) > row_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            col_num_node(row(n),col(n)) = row_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)) = bitshift(uint8(1),g_d_direction.North_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)) == row_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)) = bitor(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North_West));
                        end

                    %���i�s�������k�������łȂ��Ƃ�    
                    else
                        %���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if col_num_node(row(n),col(n)) > row_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)) = row_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            col_num_node(row(n),col(n)) = row_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)) = bitshift(uint8(1),g_d_direction.North_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)) == row_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)) = bitor(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North_West));
                        end
                    end
                end
            end  
            
            %Col_Edge�̏���[32�s,33��]
            %�������m�肵�Ă�����W������
            %�ŏ���0,�X�V����A���������}�X�����X�������Ă���
            num_temp = uint16(find(col_num_node_temp == i));
            %32�s�Ȃ̂ŁA�s�ԍ�:32�Ŋ��������܂�
            row = uint16(rem(num_temp-1,32)+1);
            %��ԍ�:32�Ŋ������Ƃ��̏�
            col = uint16(idivide(num_temp-1,32)+1);
            %���������}�X�̐�
            row_size = uint16(numel(row));
            
            %�����������W�ɑ΂��A����map���X�V
            for n = 1:1:row_size

                %�k���͕�
                
                %�k����
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)),bitshift(uint8(1),g_direction.North))) == search.known
                    %���i�s�������k�������ł��鎞
                    if logical(bitand(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North_East)))
                        %���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if row_num_node(row(n)+1,col(n)) > col_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)+1,col(n)) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            row_num_node(row(n)+1,col(n)) = col_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)+1,col(n)) = bitshift(uint8(1),g_d_direction.North_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)+1,col(n)) == col_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            row_dir_node(row(n)+1,col(n)) = bitor(row_dir_node(row(n)+1,col(n)),bitshift(uint8(1),g_d_direction.North_East));
                        end

                    %���i�s�������k�������łȂ��Ƃ�    
                    else
                        %���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if row_num_node(row(n)+1,col(n)) > col_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)+1,col(n)) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            row_num_node(row(n)+1,col(n)) = col_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)+1,col(n)) = bitshift(uint8(1),g_d_direction.North_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)+1,col(n)) == col_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            row_dir_node(row(n)+1,col(n)) = bitor(row_dir_node(row(n)+1,col(n)),bitshift(uint8(1),g_d_direction.North_East));
                        end
                    end
                end

                %����
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)),bitshift(uint8(1),g_direction.East))) == search.known
                    %���i�s�������������ł��鎞
                    if logical(bitand(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.East)))
                        %�����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if col_num_node(row(n),col(n)+1) > col_num_node(row(n),col(n))+weight_straight
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)+1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            col_num_node(row(n),col(n)+1) = col_num_node(row(n),col(n))+weight_straight;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)+1) = bitshift(uint8(1),g_d_direction.East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %�����̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)+1) == col_num_node(row(n),col(n))+weight_straight
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)+1) = bitor(col_dir_node(row(n),col(n)+1),bitshift(uint8(1),g_d_direction.East));
                        end

                    %���i�s�������������łȂ��Ƃ�    
                    else
                        %�����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if col_num_node(row(n),col(n)+1) > col_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)+1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            col_num_node(row(n),col(n)+1) = col_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)+1) = bitshift(uint8(1),g_d_direction.East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %�����̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)+1) == col_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)+1) = bitor(col_dir_node(row(n),col(n)+1),bitshift(uint8(1),g_d_direction.East));
                        end

                    end
                end

                %�쓌��
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)),bitshift(uint8(1),g_direction.South))) == search.known
                    %���i�s�������쓌�����ł��鎞
                    if logical(bitand(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South_East)))
                        %���쓌�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if row_num_node(row(n),col(n)) > col_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n),col(n)) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            row_num_node(row(n),col(n)) = col_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n),col(n)) = bitshift(uint8(1),g_d_direction.South_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n),col(n)) == col_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            row_dir_node(row(n),col(n)) = bitor(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South_East));
                        end


                    %���i�s�������쓌�����łȂ��Ƃ�    
                    else
                        %���쓌�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if row_num_node(row(n),col(n)) > col_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n),col(n)) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            row_num_node(row(n),col(n)) = col_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n),col(n)) = bitshift(uint8(1),g_d_direction.South_East);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쓌�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n),col(n)) == col_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            row_dir_node(row(n),col(n)) = bitor(row_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South_East));
                        end
                    end
                end
                
                %�쑤�͒�
                
                %�쐼��
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)-1),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)-1),bitshift(uint8(1),g_direction.South))) == search.known
                    %���i�s�������쐼�����ł��鎞
                    if logical(bitand(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.South_West)))
                        %���쐼�̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if row_num_node(row(n),col(n)-1) > col_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n),col(n)-1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            row_num_node(row(n),col(n)-1) = col_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n),col(n)-1) = bitshift(uint8(1),g_d_direction.South_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n),col(n)-1) == col_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            row_dir_node(row(n),col(n)-1) = bitor(row_dir_node(row(n),col(n)-1),bitshift(uint8(1),g_d_direction.South_West));
                        end

                    %���i�s�������쐼�����łȂ��Ƃ�    
                    else
                        %���쐼�̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if row_num_node(row(n),col(n)-1) > col_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n),col(n)-1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            row_num_node(row(n),col(n)-1) = col_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n),col(n)-1) = bitshift(uint8(1),g_d_direction.South_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���쐼�̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n),col(n)-1) == col_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            row_dir_node(row(n),col(n)-1) = bitor(row_dir_node(row(n),col(n)-1),bitshift(uint8(1),g_d_direction.South_West));
                        end
                    end
                end
                
                %����
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)-1),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)-1),bitshift(uint8(1),g_direction.West))) == search.known
                    %���i�s�������������ł��鎞
                    if logical(bitand(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.West)))
                        %�����̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if col_num_node(row(n),col(n)-1) > col_num_node(row(n),col(n))+weight_straight
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)-1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            col_num_node(row(n),col(n)-1) = col_num_node(row(n),col(n))+weight_straight;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)-1) = bitshift(uint8(1),g_d_direction.West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %�����̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)-1) == col_num_node(row(n),col(n))+weight_straight
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)-1) = bitor(col_dir_node(row(n),col(n)-1),bitshift(uint8(1),g_d_direction.West));
                        end

                    %���i�s�������������łȂ��Ƃ�    
                    else
                        %�����̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if col_num_node(row(n),col(n)-1) > col_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            col_num_node_temp(row(n),col(n)-1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            col_num_node(row(n),col(n)-1) = col_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            col_dir_node(row(n),col(n)-1) = bitshift(uint8(1),g_d_direction.West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %�����̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif col_num_node(row(n),col(n)-1) == col_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            col_dir_node(row(n),col(n)-1) = bitor(col_dir_node(row(n),col(n)-1),bitshift(uint8(1),g_d_direction.West));
                        end
                    end
                end

                %�k����
                %�ǂ����� & �T���ς݂ł���Ƃ�
                if logical(bitand(maze_wall(row(n),col(n)-1),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                        && logical(bitand(maze_wall_search(row(n),col(n)-1),bitshift(uint8(1),g_direction.North))) == search.known
                    %���i�s�������k�������ł��鎞
                    if logical(bitand(col_dir_node(row(n),col(n)),bitshift(uint8(1),g_d_direction.North_West)))
                        %���k���̃m�[�h���X�V�\��l�����傫�Ȓl�̏ꍇ
                        if row_num_node(row(n)+1,col(n)-1) > col_num_node(row(n),col(n))+weight_diagonal
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)+1,col(n)-1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V
                            row_num_node(row(n)+1,col(n)-1) = col_num_node(row(n),col(n))+weight_diagonal;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)+1,col(n)-1) = bitshift(uint8(1),g_d_direction.North_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)+1,col(n)-1) == col_num_node(row(n),col(n))+weight_diagonal
                            %�ړ�������ǉ�
                            row_dir_node(row(n)+1,col(n)-1) = bitor(row_dir_node(row(n)+1,col(n)-1),bitshift(uint8(1),g_d_direction.North_West));
                        end

                    %���i�s�������k�������łȂ��Ƃ�    
                    else
                        %���k���̃m�[�h�̕���MAP�l���A�X�V�\��l���傫���ꍇ
                        if row_num_node(row(n)+1,col(n)-1) > col_num_node(row(n),col(n))+weight_turn   
                            %�X�V�m�F�p��MAP�X�V
                            row_num_node_temp(row(n)+1,col(n)-1) = col_num_node_temp(row(n),col(n))+1;
                            %����MAP�X�V(�d�݂Â�����)
                            row_num_node(row(n)+1,col(n)-1) = col_num_node(row(n),col(n))+weight_turn;
                            %�ړ�����MAP�X�V
                            row_dir_node(row(n)+1,col(n)-1) = bitshift(uint8(1),g_d_direction.North_West);
                            %�X�V�t���O�𗧂Ă�
                            change_flag = uint8(1);
                        %���k���̃m�[�h���X�V�\��l�Ɠ����ꍇ
                        elseif row_num_node(row(n)+1,col(n)-1) == col_num_node(row(n),col(n))+weight_turn
                            %�ړ�������ǉ�
                            row_dir_node(row(n)+1,col(n)-1) = bitor(row_dir_node(row(n)+1,col(n)-1),bitshift(uint8(1),g_d_direction.North_West));
                        end
                    end
                end
            end
        end
        %�X�V���Ȃ���ΏI��(�X�^�[�g�n�_�̕����}�b�v���X�V)    
        if change_flag == 0
            start_num = row_num_node(2,1) + weight_straight_harf;
            break;
        end    
    end   
end

%% decide_goal_node_dir �S�[���m�[�h�A����ѕ����̊m��
% �΂߂̃R���^�[�}�b�v����A�S�[���ƂȂ�m�[�h�ƁA�S�[�����̐i���p�x���m�肷��B
    function  [goal_node,goal_matrix_dir,goal_dir] = decide_goal_node_dir(maze_goal,goal_size,row_num_node,col_num_node) 
        
        %�X�^�[�g�m�[�h,������ݒ�
        current_matrix_dir = matrix_dir.Row; %�X�^�[�g�m�[�h�͍s����
        current_node = uint8([2,1]);%�X�^�[�g�}�X�̖k�̃m�[�h
        next_matrix_dir = matrix_dir.Row; %�i�s������̃m�[�h�����i���j
        next_node =uint8([2,1]);%�i�s������̃m�[�h���W
        current_dir_dgnd = g_d_direction.North;%�i�s�����i�ŏ��̉��̒l�͖k�����j
        map_min = uint16(65535);
        while 1

            goal_flag = uint8(0);
            for i = 1:1:goal_size
                %���݂̃m�[�h���s�����̎�
                if current_matrix_dir == matrix_dir.Row  
                    if (maze_goal(i,1) == current_node(2)) && ... %x���W�̈�v
                            (maze_goal(i,2) == current_node(1) || maze_goal(i,2)+1 == current_node(1))%y���W�̈�v
                        %�i�s������ɕǂ������(�}�b�v�l��65535�ł����)�A�i�s������ύX����i�΂ߐN�����j
                        %�k��
                        if current_dir_dgnd == g_d_direction.North_East...
                                && col_num_node(current_node(1),current_node(2)+1) == 65535
                            current_dir_dgnd = g_d_direction.North;
                        %�쓌
                        elseif current_dir_dgnd == g_d_direction.South_East...
                                && col_num_node(current_node(1)-1,current_node(2)+1) == 65535
                            current_dir_dgnd = g_d_direction.South;
                        %�쐼
                        elseif current_dir_dgnd == g_d_direction.South_West...
                                && col_num_node(current_node(1)-1,current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.South;
                        %�k��
                        elseif current_dir_dgnd == g_d_direction.North_West...
                                && col_num_node(current_node(1),current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.North;                            
                        end
                        
                        %�t���O
                        goal_flag = uint8(1);
                    end
                %���݂̃m�[�h��������̎�
                else
                    if (maze_goal(i,1) == current_node(2) || maze_goal(i,1)+1 == current_node(2)) && ... %x���W�̈�v
                            (maze_goal(i,2) == current_node(1))%y���W�̈�v
                        %�i�s������ɕǂ������(�}�b�v�l��65535�ł����)�A�i�s������ύX����i�΂ߐN�����j
                        %�k��
                        if current_dir_dgnd == g_d_direction.North_East...
                                && row_num_node(current_node(1)+1,current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.East;
                        %�쓌
                        elseif current_dir_dgnd == g_d_direction.South_East...
                                && row_num_node(current_node(1),current_node(2)) == 65535
                            current_dir_dgnd = g_d_direction.East;
                        %�쐼
                        elseif current_dir_dgnd == g_d_direction.South_West...
                                && row_num_node(current_node(1),current_node(2)-1) == 65535
                            current_dir_dgnd = g_d_direction.West;
                        %�k��
                        elseif current_dir_dgnd == g_d_direction.North_West...
                                && row_num_node(current_node(1)+1,current_node(2)-1) == 65535
                            current_dir_dgnd = g_d_direction.West;                            
                        end
                        %�t���O
                        goal_flag = uint8(1);
                    end
                end
            end
            
%             disp("current_node")
%             disp(current_node)
%             disp("current_matrix_dir")
%             disp(current_matrix_dir)
%             disp("current_dir_dgnd")
%             disp(current_dir_dgnd)
            %�S�[���m�[�h����̎�
            %���݂̃m�[�h���S�[���m�[�h�Ƃ��A
            %���݂̕������S�[�����̕����Ƃ���B
            if goal_flag == 1
                goal_node = current_node
                goal_matrix_dir = current_matrix_dir
                goal_dir = current_dir_dgnd
                
                %
                
                break

            %�S�[���m�[�h�łȂ���    
            else

            %���݂̃m�[�h�̕�������D��I�ɐi�s�������m��
                for k = 0:7
                    temp = rem(current_dir_dgnd + k,8);
                    %���݂̃m�[�h���s�����̎�
                    if current_matrix_dir == matrix_dir.Row
                            if temp == g_d_direction.North
                                if row_num_node(current_node(1)+1,current_node(2)) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1)+1,current_node(2));
                                    %���݃m�[�h�̐i�s������k������
                                    current_dir_dgnd = g_d_direction.North;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Row;
                                    next_node = [current_node(1)+1,current_node(2)];
                                end
                            elseif temp == g_d_direction.North_East
                                if col_num_node(current_node(1),current_node(2)+1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1),current_node(2)+1);
                                    %���݃m�[�h�̐i�s������k������
                                    current_dir_dgnd = g_d_direction.North_East;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Col;
                                    next_node = [current_node(1),current_node(2)+1];
                                end
                            elseif temp == g_d_direction.East
                                %��
                            elseif temp == g_d_direction.South_East
                                if col_num_node(current_node(1)-1,current_node(2)+1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1)-1,current_node(2)+1);
                                    %���݃m�[�h�̐i�s������k������
                                    current_dir_dgnd = g_d_direction.South_East;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Col;
                                    next_node = [current_node(1)-1,current_node(2)+1];
                                end
                            elseif temp == g_d_direction.South
                                if row_num_node(current_node(1)-1,current_node(2)) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1)-1,current_node(2));
                                    %���݃m�[�h�̐i�s������k������
                                    current_dir_dgnd = g_d_direction.South;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Row;
                                    next_node = [current_node(1)-1,current_node(2)];
                                end
                            elseif temp == g_d_direction.South_West
                                if col_num_node(current_node(1)-1,current_node(2)) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1)-1,current_node(2));
                                    %���݃m�[�h�̐i�s������k������
                                    current_dir_dgnd = g_d_direction.South_West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Col;
                                    next_node = [current_node(1)-1,current_node(2)];
                                end
                            elseif temp == g_d_direction.West
                                %��
                            elseif temp == g_d_direction.North_West        
                                if col_num_node(current_node(1),current_node(2)) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1),current_node(2));
                                    %���݃m�[�h�̐i�s������k������
                                    current_dir_dgnd = g_d_direction.North_West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Col;
                                    next_node = [current_node(1),current_node(2)];
                                end                        
                            end
                    %���݂̃m�[�h��������̎�        
                    else
                            if temp == g_d_direction.North
                            %��
                            elseif temp == g_d_direction.North_East
                                if row_num_node(current_node(1)+1,current_node(2)) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1)+1,current_node(2));
                                    %���݃m�[�h�̐i�s������k��������
                                    current_dir_dgnd = g_d_direction.North_East;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Row;
                                    next_node = [current_node(1)+1,current_node(2)];
                                end
                            elseif temp == g_d_direction.East
                                if col_num_node(current_node(1),current_node(2)+1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1),current_node(2)+1);
                                    %���݃m�[�h�̐i�s�����𓌌�����
                                    current_dir_dgnd = g_d_direction.East;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Col;
                                    next_node = [current_node(1),current_node(2)+1];
                                end
                            elseif temp == g_d_direction.South_East
                                if row_num_node(current_node(1),current_node(2)) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1),current_node(2));
                                    %���݃m�[�h�̐i�s������쓌������
                                    current_dir_dgnd = g_d_direction.South_East;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Row;
                                    next_node = [current_node(1),current_node(2)];
                                end
                            elseif temp == g_d_direction.South
                                %��
                            elseif temp == g_d_direction.South_West
                                if row_num_node(current_node(1),current_node(2)-1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1),current_node(2)-1);
                                    %���݃m�[�h�̐i�s������쐼������
                                    current_dir_dgnd = g_d_direction.South_West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Row;
                                    next_node = [current_node(1),current_node(2)-1];
                                end
                            elseif temp == g_d_direction.West
                                if col_num_node(current_node(1),current_node(2)-1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1),current_node(2)-1);
                                    %���݃m�[�h�̐i�s�����𐼌�����
                                    current_dir_dgnd = g_d_direction.West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Col;
                                    next_node = [current_node(1),current_node(2)-1];
                                end
                            elseif temp == g_d_direction.North_West
                                if row_num_node(current_node(1)+1,current_node(2)-1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1)+1,current_node(2)-1);
                                    %���݃m�[�h�̐i�s������k��������
                                    current_dir_dgnd = g_d_direction.North_West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_matrix_dir = matrix_dir.Row;
                                    next_node = [current_node(1)+1,current_node(2)-1];
                                end
                            end

                    end

                end

            current_node = next_node;
            current_matrix_dir = next_matrix_dir;

            end
        end
    end
%% decide_goal_section �S�[���}�X�̊m��
% �m�肳�ꂽ�S�[���̃m�[�h�ƁA�S�[�����̐i���p�x����A
% �S�[���}�X���m�肷��B
    function[goal_section,goal_node2,goal_matrix_dir2]=decide_goal_section(maze_goal,goal_node,goal_matrix_dir,goal_dir)
        
        goal_section = uint8([1,1]);%(y,x)
        goal_node2 = uint8([1,1]);
        goal_matrix_dir2 = matrix_dir.Row;
        
        if goal_dir == g_d_direction.North
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            end
            %������͒��Ȃ̂łȂ�
        elseif goal_dir == g_d_direction.North_East
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Row;                    
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;  
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;    
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;  
                end
            else
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;      
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;   
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;   
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;   
                end
            end
        elseif goal_dir == g_d_direction.East
            %�s�����͒��Ȃ̂łȂ�
            if goal_matrix_dir == matrix_dir.Col
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.South_East
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)-2)
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            else
                if goal_judge(maze_goal,goal_node(2)+1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;                    
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;                        
                elseif goal_judge(maze_goal,goal_node(2)+1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)+1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)+1];
                    goal_matrix_dir2 = matrix_dir.Col;                        
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end
        elseif goal_dir == g_d_direction.South
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2),goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                end
            end
        elseif goal_dir == g_d_direction.South_West
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;                    
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;    
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;                      
                else
                    goal_section = [goal_node(1)-1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;  
                end
            else
                if goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-2)
                    goal_section = [goal_node(1)-2,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)-1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1)-1)
                    goal_section = [goal_node(1)-1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row; 
                elseif goal_judge(maze_goal,goal_node(2)-2,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;                    
                else
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;                     
                end
            end
        elseif goal_dir == g_d_direction.West
            %�s�����͒��Ȃ̂łȂ�
            if goal_matrix_dir == matrix_dir.Col
                if goal_judge(maze_goal,goal_node(2)-2,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
            end  
        elseif goal_dir == g_d_direction.North_West
            if goal_matrix_dir == matrix_dir.Row
                if goal_judge(maze_goal,goal_node(2)-1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2),goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;
                else
                    goal_section = [goal_node(1),goal_node(2)];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Row;                    
                end
            else
                if goal_judge(maze_goal,goal_node(2)-2,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                elseif goal_judge(maze_goal,goal_node(2)-1,goal_node(1)+1)
                    goal_section = [goal_node(1)+1,goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1)+1,goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Row;
                elseif goal_judge(maze_goal,goal_node(2)-2,goal_node(1))
                    goal_section = [goal_node(1),goal_node(2)-2];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)-1];
                    goal_matrix_dir2 = matrix_dir.Col;
                else
                    goal_section = [goal_node(1),goal_node(2)-1];%(y,x)
                    goal_node2 = [goal_node(1),goal_node(2)];
                    goal_matrix_dir2 = matrix_dir.Col;
                end
                
            end
        end
        
        
        %�S�[������֐�
        function[result] = goal_judge(maze_goal,x,y)
            %���͍��W�̔z����쐬
            temp = [ones(9,1,'uint8')*x,ones(9,1,'uint8')*y];
            %�S�[�����W�Ɣ�r
            temp1 = logical(maze_goal == temp);
            %x,y�Ƃ��Ɉ�v���邩�m�F�A��v�Ȃ�1��Ԃ�
            result = max(temp1(:,1).*temp1(:,2));
            
        end
    end

%% make_route_diagonal �΂ߗL�ł̍ŒZ���[�g�����A���s
    function[] = make_route_diagonal(row_num_node,col_num_node,goal_section,goal_node2,goal_node_property)
       
    %�X�^�[�g�m�[�h�̏�����
    current_node = [uint8(1),uint8(1)];%�����}�X�̓�̃m�[�h
    current_node_property = matrix_dir.Row; %��̃m�[�h�̑����͍s����
    current_move_dir = g_d_direction.North; %�����̐i�s�����͖k
    current_move_mode = move_dir_property.straight; %�����̐i�s���������͒��i�i�΂߂łȂ��j
    straight_count = uint8(0);%���i�p�̃J�E���^
    
    %����̂ݎ��̃m�[�h���Œ�
    next_node = [uint8(2),uint8(1)];%�����}�X�̖k�̃m�[�h
    next_node_property = matrix_dir.Row; %�k�̃m�[�h�̑����͍s����
    
    %��m�[�h���W�����̃m�[�h��
    %��m�[�h�̈ړ������A���[�h�����݂̃m�[�h�ɐݒ�
    ref_node = next_node;
    ref_node_property = next_node_property;
    ref_move_dir = current_move_dir;
    ref_move_mode = current_move_mode;
    
    %�S�[���t���O�����܂Ń��[�v
    goal_flag = 0;
    
    %�΂ߍ��݂̐i�s���@�I��
    [next_move_dir,next_node,next_node_property]...
       =get_next_dir_diagonal(row_num_node,col_num_node,ref_move_dir,ref_node,ref_node_property,goal_node2,goal_node_property,goal_section);

    
    while(1)
       
%         disp(["next_move_dir=",num2str(next_move_dir)])
%         disp(["ref_move_dir=",num2str(ref_move_dir)])
        
        %��m�[�h���猩�āA�i�s����������̂Ƃ�
        if ref_move_dir == next_move_dir
%             disp("���i")
            straight_count = straight_count+uint8(1);%���i�J�E���^���C���N�������g
            %��m�[�h���ړ�����B
            ref_node = next_node;
            ref_node_property = next_node_property;
            ref_move_dir = next_move_dir;
            %��m�[�h���S�[���ł��邩����
            if (isequal(ref_node,goal_node2) && (ref_node_property == goal_node_property))...
                    || (ref_node_property == matrix_dir.section && goal_section(2)==ref_node(1) && goal_section(1)==ref_node(2))
                %���݈ʒu���m�[�h�ł��鎞�A�S�[���i�����̃p�^�[�������肷��B
                if (isequal(ref_node,goal_node2) && (ref_node_property == goal_node_property))
                    %�S�[���̏ꍇ�A�S�[���i�����̃p�^�[�������肷��B
                    [next_move_dir,next_node,next_node_property]...
                          =get_next_dir_diagonal(row_num_node,col_num_node,ref_move_dir,ref_node,ref_node_property,goal_node2,goal_node_property,goal_section);
                    %���i�̏ꍇ�i���i�N���j
                    if ref_move_dir == next_move_dir
                        %�S�[�����J�E���^�𑝉�
                        straight_count = straight_count+uint8(1);
                        %���݃m�[�h���璼�i�J�E���^���ړ�����֐��B
                        [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                          = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
%                         disp("�S�[�������N��")
%                         disp(current_node)
                    %�^�[���̏ꍇ�i�΂ߐN���j
                    %45�x�^�[���̂ݑz��(���̈ړ������Ń^�[���̎�ނ�����)
                    else
%                         disp("�S�[�������i�O")
%                         disp(current_node)
                        %���i�J�E���^������Έړ�
                        if straight_count > 0
                            %�O�Ղ��v���b�g
                            if coder.target('MATLAB')
                                straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);  
                            end
                            %���݃m�[�h���璼�i�J�E���^���ړ�����֐��B
                            [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                                = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                        end
%                         disp("�S�[�������i��")
%                         disp(current_node)
                        %�i�s�����̃o�b�t�@���N���A
                        move_dir_buffer = zeros(3,1);
                        %1��܂ł̐i�s��������A�^�[���̃p�^�[��������
                        %���ݐi�s��������̑��ΓI�Ȉړ��������o�b�t�@
                        move_dir_buffer(1) = bitand(int8(next_move_dir)-int8(current_move_dir),7);
                        %�^�[���̎�ނ𔻒肷��
                        [turn_pattern_num] = get_turn_pattern_num(move_dir_buffer,ref_move_mode);
                        %�^�[���̋O�Ղ�`�悷��
                        if coder.target('MATLAB')
                            slalom_plot(current_node,current_node_property,current_move_dir,current_move_mode,turn_pattern_num);
                        end
                        %�p�^�[�������܂�Ȃ������ꍇ�A�G���[
                        if turn_pattern_num == 0
                            if coder.target('MATLAB')
%                                 error('�p�^�[����������܂���ł����B(�S�[����)')
                                    error('The pattern was not found.(At goal)')
                            end
                        end
                        %�p�^�[���ɉ������ړ�����
                        if turn_pattern_num == turn_pattern.r_45
                             if coder.target('MATLAB')
                                disp("right45deg")
                             end
                            [current_node,current_node_property,current_move_dir,current_move_mode] ...
                                = turn_r_45(current_node,current_node_property,current_move_dir,current_move_mode);

                        elseif turn_pattern_num == turn_pattern.l_45
                            if coder.target('MATLAB')
                                disp("left45deg")
                            end
                            [current_node,current_node_property,current_move_dir,current_move_mode] ...
                                = turn_l_45(current_node,current_node_property,current_move_dir,current_move_mode);
                        else
                            if coder.target('MATLAB')
                                error("It is an unexpected turn pattern (when entering the goal)")
                            end
                        end
                    end
                %�Q�ƈʒu���Z�N�V�����ł���Ƃ�
                else
                    %���i�J�E���^������΁A�ړ�����B
%                     disp("�S�[�������i�i�Z�N�V�����j")
                    if straight_count > 0
                        %�O�Ղ��v���b�g
                        if coder.target('MATLAB')
                            straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                        end
                        %���݃m�[�h���璼�i�J�E���^���ړ�����֐��B
                        [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                            = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
                    end
                end
                %�S�[�����������������t���O�𗧂Ă�
%                 disp("�S�[����")
%                 disp(straight_count)
%                 disp(current_node)
                goal_flag = 1;
            end
            
        %��m�[�h���猩�āA�i�s�������قȂ�(�Ȃ���)�Ƃ�
        else
%             disp("�^�[��")
            %���i�J�E���^����Ƃ�
            if straight_count > 0
                %�O�Ղ��v���b�g
                if coder.target('MATLAB')
                    straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);     
                end
                %���݃m�[�h���璼�i�J�E���^���ړ�����֐��B
                [current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
                    = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count);
%                 disp("�^�[���O���i�J�E���^")
%                 disp(straight_count)
%                 disp(current_node)
            end
            
            %�i�s�����̃o�b�t�@���N���A
            move_dir_buffer = zeros(3,1);
            %3��܂ł̐i�s��������A�^�[���̃p�^�[��������
            for i = 1:1:3
                %���ݐi�s��������̑��ΓI�Ȉړ��������o�b�t�@
%                 disp(["current_move_dir",num2str(current_move_dir)])
%                 disp(["next_move_dir",num2str(next_move_dir)])
                move_dir_buffer(i) = bitand(int8(next_move_dir)-int8(current_move_dir),7);
                %�^�[���̎�ނ𔻒肷��
                [turn_pattern_num] = get_turn_pattern_num(move_dir_buffer,ref_move_mode);

                %�p�^�[�����m�肵�Ă���ΏI��
                if turn_pattern_num ~= 0
                    %�p�^�[���̋O�Ղ�`��
                    if coder.target('MATLAB')
                        slalom_plot(current_node,current_node_property,current_move_dir,current_move_mode,turn_pattern_num);
                    end
                    break;
                else
                    %���̐i�s���������肷��
                    [next_move_dir,next_node,next_node_property]=...
                        get_next_dir_diagonal(row_num_node,col_num_node,next_move_dir,next_node,next_node_property,goal_node2,goal_node_property,goal_section);
                end
                %3��ڂŃp�^�[�������܂�Ȃ������ꍇ�A�G���[
                if turn_pattern_num == 0 && i == 3
                    if coder.target('MATLAB') 
                        error('The pattern was not found.')
                    end
                end
            end
            
            %�p�^�[���ɉ����Ĉړ�
            if turn_pattern_num == turn_pattern.r_45
                if coder.target('MATLAB')
                    disp("right45deg")
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_r_45(current_node,current_node_property,current_move_dir,current_move_mode);
            
            elseif turn_pattern_num == turn_pattern.l_45
                if coder.target('MATLAB')
                    disp("left45deg")
                end
                    [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_l_45(current_node,current_node_property,current_move_dir,current_move_mode);
            
            elseif turn_pattern_num == turn_pattern.r_90
                if coder.target('MATLAB')
                    if current_move_mode == move_dir_property.straight
                        disp("right90deg")
                    elseif current_move_mode == move_dir_property.diagonal
                        disp("rightV90deg")
                    end
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_r_90(current_node,current_node_property,current_move_dir,current_move_mode);
                
            elseif turn_pattern_num == turn_pattern.l_90
                if coder.target('MATLAB')
                    if current_move_mode == move_dir_property.straight
                        disp("left90deg")
                    elseif current_move_mode == move_dir_property.diagonal
                        disp("leftV90deg")
                    end
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_l_90(current_node,current_node_property,current_move_dir,current_move_mode);
            
            elseif turn_pattern_num == turn_pattern.r_135
                if coder.target('MATLAB')
                    disp("right135deg")
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_r_135(current_node,current_node_property,current_move_dir,current_move_mode);                
            
            elseif turn_pattern_num == turn_pattern.l_135
                if coder.target('MATLAB')
                    disp("left135deg")
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_l_135(current_node,current_node_property,current_move_dir,current_move_mode); 
                
            elseif turn_pattern_num == turn_pattern.r_180  
                if coder.target('MATLAB')
                    disp("right180deg")
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_r_180(current_node,current_node_property,current_move_dir,current_move_mode); 
                
            elseif turn_pattern_num == turn_pattern.l_180
                if coder.target('MATLAB')
                    disp("left180deg")
                end
                [current_node,current_node_property,current_move_dir,current_move_mode] ...
                    = turn_l_180(current_node,current_node_property,current_move_dir,current_move_mode);                 
            end
%             disp("�^�[���I�����A�m�[�h")
%             disp(current_node)
%             disp(goal_node2)
            %�ړ���A�S�[���𔻒�
            if isequal(current_node,goal_node2) && (current_node_property == goal_node_property)
                goal_flag = 1;
            end
            
            %��m�[�h���ړ�
            ref_node = next_node;
            ref_node_property = next_node_property;
            ref_move_dir = current_move_dir;
            ref_move_mode = current_move_mode;

        end
        
        %�S�[���t���O�������Ă���ΏI��
        if goal_flag == 1
            break;
        end
        
        %���̈ړ��������擾
        %�΂ߍ��݂̐i�s���@�I��
        [next_move_dir,next_node,next_node_property]...
            =get_next_dir_diagonal(row_num_node,col_num_node,ref_move_dir,ref_node,ref_node_property,goal_node2,goal_node_property,goal_section);
%         disp("���i�s����")
%         disp(next_move_dir)
    end
    
    %�p�^�[���𔻒肷��֐�
        function [turn_pattern_num] = get_turn_pattern_num(move_dir_buffer,ref_move_mode)
            
            %����p�^�[���ԍ��̏�����
            turn_pattern_num = turn_pattern.default;

            %���i��
            if ref_move_mode == move_dir_property.straight
                %����45�x�܂���Ƃ�(�E�܃p�^�[��)
                if move_dir_buffer(1) == 1
                    if move_dir_buffer(2) == 1
                        turn_pattern_num = turn_pattern.r_45;
                    elseif move_dir_buffer(2) == 2
                        turn_pattern_num = turn_pattern.r_90;
                    elseif move_dir_buffer(2) == 3
                        if move_dir_buffer(3) == 3
                            turn_pattern_num = turn_pattern.r_135;
                        elseif move_dir_buffer(3) == 4 
                            turn_pattern_num = turn_pattern.r_180;
                        end
                    end
                %����-45�x�܂���Ƃ�(���܃p�^�[��)    
                elseif move_dir_buffer(1) == 7
                    if move_dir_buffer(2) == 7
                        turn_pattern_num = turn_pattern.l_45;
                    elseif move_dir_buffer(2) == 6
                        turn_pattern_num = turn_pattern.l_90;
                    elseif move_dir_buffer(2) == 5
                        if move_dir_buffer(3) == 5
                            turn_pattern_num = turn_pattern.l_135;
                        elseif move_dir_buffer(3) == 4 
                            turn_pattern_num = turn_pattern.l_180;
                        end
                    end 
                end
            
            %�΂߂̎�
            elseif ref_move_mode == move_dir_property.diagonal
                %�E�܃p�^�[��
                if move_dir_buffer(1) == 1
                    turn_pattern_num = turn_pattern.r_45;
                elseif move_dir_buffer(1) == 2
                    if move_dir_buffer(2) == 2
                       turn_pattern_num = turn_pattern.r_90; 
                    elseif move_dir_buffer(2) == 3
                       turn_pattern_num = turn_pattern.r_135; 
                    end
                %���܃p�^�[��    
                elseif move_dir_buffer(1) == 7
                        turn_pattern_num = turn_pattern.l_45;
                elseif move_dir_buffer(1) == 6
                    if move_dir_buffer(2) == 6
                       turn_pattern_num = turn_pattern.l_90; 
                    elseif move_dir_buffer(2) == 5
                       turn_pattern_num = turn_pattern.l_135; 
                    end
                end
                
            else
                if coder.target('MATLAB')
                    error('ref move mode is unexpected')
                end     
            end
        end
end
%% get_next_dir_diagonal �΂ߗL�ł̐i�s����,�s��擾
    function [next_dir,next_node,next_node_property]=get_next_dir_diagonal(row_num_node,col_num_node,current_move_dir,current_node,current_matrix_dir,goal_node2,goal_matrix_dir2,goal_section)
 
        %�o�͕ϐ���`
        next_dir = g_d_direction.North;
        next_node =uint8( [1,1]);
        next_node_property = matrix_dir.Row;
        
        
        %���݂̃G�b�W�̓S�[���m�[�h��
        if isequal(current_node,goal_node2) && current_matrix_dir == goal_matrix_dir2
        %�S�[���m�[�h�̏ꍇ
            %�S�[���m�[�h���s�����̏ꍇ
            if goal_matrix_dir2 == matrix_dir.Row
                if goal_section(2) == goal_node2(1) && goal_section(1) == goal_node2(2)
                    next_dir = g_d_direction.North;
                    next_node = goal_node2;
                    next_node_property = matrix_dir.section;
                else
                    next_dir = g_d_direction.South;
                    next_node = [goal_node2(1)-1,goal_node2(2)];
                    next_node_property = matrix_dir.section;
                end
            else
            %�S�[���m�[�h��������̏ꍇ
                if goal_section(2) == goal_node2(1) && goal_section(1) == goal_node2(2)
                    next_dir = g_d_direction.East;
                    next_node = [goal_node2(1),goal_node2(2)];
                    next_node_property = matrix_dir.section;                    
                else
                    next_dir = g_d_direction.West;
                    next_node = [goal_node2(1),goal_node2(2)-1];
                    next_node_property = matrix_dir.section;  
                end
            end
        else
        %�S�[���m�[�h�łȂ��ꍇ
            %臒l���`
            map_min = uint16(65535);
            %���݂̃m�[�h�̕�������D��I�ɐi�s�������m��
            for k = 0:7
                temp = rem(current_move_dir + k,8);
                %���݂̃m�[�h���s�����̎�
                if current_matrix_dir == matrix_dir.Row
                        if temp == g_d_direction.North
                            if row_num_node(current_node(1)+1,current_node(2)) < map_min
                                %�ŏ��l���X�V
                                map_min = row_num_node(current_node(1)+1,current_node(2));
                                %���݃m�[�h�̐i�s������k������
                                next_dir = g_d_direction.North;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Row;
                                next_node = [current_node(1)+1,current_node(2)];
                            end
                        elseif temp == g_d_direction.North_East
                            if col_num_node(current_node(1),current_node(2)+1) < map_min
                                %�ŏ��l���X�V
                                map_min = col_num_node(current_node(1),current_node(2)+1);
                                %���݃m�[�h�̐i�s�����𓌖k������
                                next_dir = g_d_direction.North_East;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)+1];
                            end
                        elseif temp == g_d_direction.East
                            %��
                        elseif temp == g_d_direction.South_East
                            if col_num_node(current_node(1)-1,current_node(2)+1) < map_min
                                %�ŏ��l���X�V
                                map_min = col_num_node(current_node(1)-1,current_node(2)+1);
                                %���݃m�[�h�̐i�s������쓌������
                                next_dir = g_d_direction.South_East;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Col;
                                next_node = [current_node(1)-1,current_node(2)+1];
                            end
                        elseif temp == g_d_direction.South
                            if row_num_node(current_node(1)-1,current_node(2)) < map_min
                                %�ŏ��l���X�V
                                map_min = row_num_node(current_node(1)-1,current_node(2));
                                %���݃m�[�h�̐i�s������������
                                next_dir = g_d_direction.South;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Row;
                                next_node = [current_node(1)-1,current_node(2)];
                            end
                        elseif temp == g_d_direction.South_West
                            if col_num_node(current_node(1)-1,current_node(2)) < map_min
                                %�ŏ��l���X�V
                                map_min = col_num_node(current_node(1)-1,current_node(2));
                                %���݃m�[�h�̐i�s������쐼������
                                next_dir = g_d_direction.South_West;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Col;
                                next_node = [current_node(1)-1,current_node(2)];
                            end
                        elseif temp == g_d_direction.West
                            %��
                        elseif temp == g_d_direction.North_West        
                            if col_num_node(current_node(1),current_node(2)) < map_min
                                %�ŏ��l���X�V
                                map_min = col_num_node(current_node(1),current_node(2));
                                %���݃m�[�h�̐i�s������k��������
                                next_dir = g_d_direction.North_West;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)];
                            end                        
                        end
                %���݂̃m�[�h���s�����̎�        
                else
                        if temp == g_d_direction.North
                        %��
                        elseif temp == g_d_direction.North_East
                            if row_num_node(current_node(1)+1,current_node(2)) < map_min
                                %�ŏ��l���X�V
                                map_min = row_num_node(current_node(1)+1,current_node(2));
                                %���݃m�[�h�̐i�s������k��������
                                next_dir = g_d_direction.North_East;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Row;
                                next_node = [current_node(1)+1,current_node(2)];
                            end
                        elseif temp == g_d_direction.East
                            if col_num_node(current_node(1),current_node(2)+1) < map_min
                                %�ŏ��l���X�V
                                map_min = col_num_node(current_node(1),current_node(2)+1);
                                %���݃m�[�h�̐i�s�����𓌌�����
                                next_dir = g_d_direction.East;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Col;
                                next_node = [current_node(1),current_node(2)+1];
                            end
                        elseif temp == g_d_direction.South_East
                            if row_num_node(current_node(1),current_node(2)) < map_min
                                %�ŏ��l���X�V
                                map_min = row_num_node(current_node(1),current_node(2));
                                %���݃m�[�h�̐i�s������쓌������
                                next_dir = g_d_direction.South_East;
                                %�i�s������̍��W�A�s��̕������X�V
                                next_node_property = matrix_dir.Row;
                                next_node = [current_node(1),current_node(2)];
                            end
                        elseif temp == g_d_direction.South
                            %��
                        elseif temp == g_d_direction.South_West
                            if current_node(2)-1 > 0
                                if row_num_node(current_node(1),current_node(2)-1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1),current_node(2)-1);
                                    %���݃m�[�h�̐i�s������쐼������
                                    next_dir = g_d_direction.South_West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_node_property = matrix_dir.Row;
                                    next_node = [current_node(1),current_node(2)-1];
                                end
                            end
                        elseif temp == g_d_direction.West
                            if current_node(2)-1 > 0
                                if col_num_node(current_node(1),current_node(2)-1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = col_num_node(current_node(1),current_node(2)-1);
                                    %���݃m�[�h�̐i�s�����𐼌�����
                                    next_dir = g_d_direction.West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_node_property = matrix_dir.Col;
                                    next_node = [current_node(1),current_node(2)-1];
                                end
                            end
                        elseif temp == g_d_direction.North_West
                            if current_node(2)-1 > 0
                                if row_num_node(current_node(1)+1,current_node(2)-1) < map_min
                                    %�ŏ��l���X�V
                                    map_min = row_num_node(current_node(1)+1,current_node(2)-1);
                                    %���݃m�[�h�̐i�s������k��������
                                    next_dir = g_d_direction.North_West;
                                    %�i�s������̍��W�A�s��̕������X�V
                                    next_node_property = matrix_dir.Row;
                                    next_node = [current_node(1)+1,current_node(2)-1];
                                end
                            end
                        end

                end

            end

        end
    end

%% �ړ��p�֐�
% ���i
    function[current_node,current_node_property,current_move_dir,current_move_mode,straight_count]...
            = move_straight(current_node,current_node_property,current_move_dir,current_move_mode,straight_count)
        
        %���i��
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+straight_count,current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['North',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1),current_node(2)+straight_count];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['East',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-straight_count,current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['South',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1),current_node(2)-straight_count];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                if coder.target('MATLAB')
                    disp(['West',num2str(straight_count),'square Go straight'])
                end
            else
                if coder.target('MATLAB')
                    error("Unexpected movement direction")
                end
            end
        %�΂ߒ��i�̂Ƃ�    
        elseif current_move_mode == move_dir_property.diagonal
            %���i�J�E���^��2�Ŋ��������Ƃ��܂�A���̍��v���v�Z
            %(�ړ���m�[�h���W�̈�ʉ��p)
            temp_quotient = idivide(straight_count,2);
            temp_remainder = rem(straight_count,2);
            temp_qr = temp_quotient+temp_remainder;
            
            if current_move_dir == g_d_direction.North_East
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)+temp_quotient,current_node(2)+temp_qr];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.North_East;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)+temp_qr,current_node(2)+temp_quotient];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.North_East;
                    current_move_mode = move_dir_property.diagonal;
                else
                     if coder.target('MATLAB')
                        error("Unexpected node attribute")
                     end
                end
                 if coder.target('MATLAB')
                     disp(['North East',num2str(straight_count),'node straight'])
                 end
            elseif current_move_dir == g_d_direction.South_East
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)-temp_qr,current_node(2)+temp_qr];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.South_East;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)-temp_quotient,current_node(2)+temp_quotient];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.South_East;
                    current_move_mode = move_dir_property.diagonal;
                else
                     if coder.target('MATLAB')
                        error("Unexpected node attribute")
                     end
                end
                if coder.target('MATLAB')
                    disp(['South East',num2str(straight_count),'node straight'])
                end
            elseif current_move_dir == g_d_direction.South_West
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)-temp_qr,current_node(2)-temp_quotient];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.South_West;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)-temp_quotient,current_node(2)-temp_qr];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.South_West;
                    current_move_mode = move_dir_property.diagonal;
                else
                     if coder.target('MATLAB')
                        error("Unexpected node attribute")
                     end
                end
                 if coder.target('MATLAB')
                     disp(['South West',num2str(straight_count),'node straight'])
                 end
            elseif current_move_dir == g_d_direction.North_West
                if current_node_property == matrix_dir.Row
                    current_node = [current_node(1)+temp_quotient,current_node(2)-temp_quotient];
                    current_node_property = current_node_property+temp_remainder;
                    current_move_dir = g_d_direction.North_West;
                    current_move_mode = move_dir_property.diagonal;
                    
                elseif current_node_property == matrix_dir.Col
                    current_node = [current_node(1)+temp_qr,current_node(2)-temp_qr];
                    current_node_property = current_node_property-temp_remainder;
                    current_move_dir = g_d_direction.North_West;
                    current_move_mode = move_dir_property.diagonal;
                else
                     if coder.target('MATLAB')
                          error("Unexpected node attribute")
                     end
                end
                 if coder.target('MATLAB')
                   disp(['Northwest',num2str(straight_count),'node straight'])
                 end
            end
        else
             if coder.target('MATLAB')
                disp("Unexpected operating mode")
             end
        end
        %�ړ��������A���i�J�E���^���N���A
        straight_count = uint8(0);
    end
% �E45�x
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_45(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)-2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_45_straight)')
                 end
            end
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1),current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight; 
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_45_diagonal)')
                 end
            end
        else
             if coder.target('MATLAB')
                 error('Unexpected progress mode')
             end
        end
    
    end

% ��45�x
    function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_45(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1),current_node(2)-2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
            else
                 if coder.target('MATLAB')
                   error('Unexpected traveling direction (l_45_straight)')
                 end
            end
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1),current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight; 
            else
                 if coder.target('MATLAB')
                     error('Unexpected traveling direction (l_45_diagonal)')
                 end
            end
        else
             if coder.target('MATLAB')
                 error('Unexpected progress mode')
             end
        end
    
    end

% �E90�x
   function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_90(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)+2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_90)')
                 end
            end
        %�΂߃p�^�[���̎��iV90�j    
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal; 
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal; 
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal; 
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal; 
            else
                 if coder.target('MATLAB')
                     error('Unexpected traveling direction (r_V90)')
                 end
            end
        else
             if coder.target('MATLAB')
                 error('Unexpected progress mode')
             end
        end
    
   end

% ��90�x
   function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_90(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-2,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1),current_node(2)-2];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction (l_90)')
                 end
            end
        %�΂߃p�^�[���̎��iV90�j    
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal; 
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal; 
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal; 
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal; 
            else
                 if coder.target('MATLAB')
                     error('Unexpected traveling direction(r_V90)')
                 end
            end
        else
             if coder.target('MATLAB')
                error('Unexpected progress mode')
             end
        end
    
   end

% �E135�x
   function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_135(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction(r_135)')
                 end
            end
        %�΂߃p�^�[���̎�    
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight; 
            else
                 if coder.target('MATLAB')
                     error('Unexpected traveling direction (r_135_diagonal)')
                 end
            end
        else
             if coder.target('MATLAB')
                error('Unexpected progress mode')
             end
        end
    
   end

% ��135�x
   function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_135(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.North_West;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North_East;
                current_move_mode = move_dir_property.diagonal;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.South_East;
                current_move_mode = move_dir_property.diagonal;
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction(l_135)')
                 end
            end
        %�΂߃p�^�[���̎� 
        elseif current_move_mode == move_dir_property.diagonal
            if current_move_dir == g_d_direction.North_East
                current_node = [current_node(1)+1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_East
                current_node = [current_node(1),current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.South_West
                current_node = [current_node(1)-1,current_node(2)];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight; 
                
            elseif current_move_dir == g_d_direction.North_West
                current_node = [current_node(1),current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight; 
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction(l_135_diagonal)')
                 end
            end
        else
             if coder.target('MATLAB')
                error('Unexpected progress mode')
             end
        end
    
   end

% �E180�x
   function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_r_180(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
            else
                 if coder.target('MATLAB')
                    error('Unexpected traveling direction (r_180)')
                 end
            end
        %�΂߃p�^�[���̎�    
        elseif current_move_mode == move_dir_property.diagonal
             if coder.target('MATLAB')
                error('Unexpected traveling direction (r_180_diagonal)')
             end
        else
             if coder.target('MATLAB')
                 error('Unexpected progress mode')
             end
        end
    
   end

% ��180�x
   function [current_node,current_node_property,current_move_dir,current_move_mode] ...
            = turn_l_180(current_node,current_node_property,current_move_dir,current_move_mode)
        %���i�p�^�[���̎�
        if current_move_mode == move_dir_property.straight
            if current_move_dir == g_d_direction.North
                current_node = [current_node(1)+1,current_node(2)-1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.South;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.East
                current_node = [current_node(1)+1,current_node(2)+1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.West;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.South
                current_node = [current_node(1)-1,current_node(2)+1];
                current_node_property = matrix_dir.Row;
                current_move_dir = g_d_direction.North;
                current_move_mode = move_dir_property.straight;
                
            elseif current_move_dir == g_d_direction.West
                current_node = [current_node(1)-1,current_node(2)-1];
                current_node_property = matrix_dir.Col;
                current_move_dir = g_d_direction.East;
                current_move_mode = move_dir_property.straight;
            else
                 if coder.target('MATLAB')
                     error('Unexpected traveling direction (l_180)')
                 end
            end
        %�΂߃p�^�[���̎� 
        elseif current_move_mode == move_dir_property.diagonal
             if coder.target('MATLAB')
                 error('Unexpected traveling direction (l_180_diagonal)')
             end
        else
             if coder.target('MATLAB')
                    error('Unexpected progress mode')
             end
        end
    
   end

end


