function[maze_wall,maze_wall_search] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,maze_goal,goal_size,run_mode)%#codegen
%maze_solve ���@�ł̖��H�T���֐�
%���� ���H�Ǐ��,���H�T�����,���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,
%�o�� �Ǐ��,�T�����

%���[�J���ϐ��錾
new_goal = uint8(zeros(9,2));
new_goal_size = uint8(1); 

%��Ε��p��`
g_direction = struct('North',uint8(0),'East',uint8(1),'South',uint8(2),'West',uint8(3));

%�}�E�X������`
l_direction = struct('front',uint8(0),'right',uint8(1),'back',uint8(2),'left',uint8(3));

%�Ǐ���`
wall = struct('nowall',uint8(0),'wall',uint8(1));

%�T������`
search = struct('unknown',uint8(0),'known',uint8(1));

%���s���[�h��`
r_mode = struct('search',uint8(0),'fust_run',uint8(1));

%�T����
if run_mode == r_mode.search

    %�}�E�X�̏����ʒu�ݒ�
    current_x = uint8(1);
    current_y = uint8(1);
    current_dir = g_direction.North;
      
    %��}�X�O�i
     [current_x,current_y] = move_step(current_x,current_y,current_dir);

    %�����@�ɂ��T��
    [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
        = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,maze_goal,goal_size);

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
        [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
            = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,new_goal,coder.ignoreConst(new_goal_size));
        else
            break
        end

    end
    
    %�X�^�[�g��ړI�n�Ƃ��đ����@�ōĒT��
    new_goal(1,:) = uint8([1,1]);
     [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
         = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,coder.ignoreConst(new_goal),coder.ignoreConst(new_goal_size));
    
        if coder.target('MATLAB')
        %for MATLAB
        %�T����������
         maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        else
        %for code generation
        end    


end

if run_mode == r_mode.fust_run
    %�T���������Ƃɓ�����MAP�𐶐�
    [contour_map,max_length] = make_map_fustrun(maze_row_size,maze_col_size,maze_goal,maze_wall,maze_wall_search);
    
    %�ŒZ�������s
    fust_run(maze_wall,contour_map,maze_goal,max_length)


end

%% search_adachi �����@�ł̒T��
function [current_x,current_y,current_dir,maze_wall,maze_wall_search]...
            = search_adachi(current_x,current_y,current_dir,maze_row_size,maze_col_size,maze_wall,maze_wall_search,maze_goal,l_goal_size) %#codegen
    %���́@���݈ʒux,y,���ݕ���,���H�s�����T�C�Y,���H������T�C�Y,���H�Ǐ��,���H�ǂ̒T�����,�S�[�����W
    %�o��  ���݈ʒux,y,���ݕ���,�Ǐ��,�T�����

    %local�ϐ��錾
    goal_flag = uint8(0);
    search_start_x = current_x; %�T���J�n��x
    search_start_y = current_y; %�T���J�n��y
    
    if coder.target('MATLAB')
        %for MATLAB
        %���H�T���󋵂�\���\�ʂ��쐬
        [search_surf] = maze_search_plot(maze_wall_search,maze_row_size,maze_col_size,9);
        %�}�E�X�ʒu�\���p�I�u�W�F�N�g������
        [h] = hgtransform_init;
        %�T���J�n�ʒu�v���b�g
        hold on
        plot(current_x * 9 -4.5,current_y * 9 -4.5,'ob','MarkerFaceColor','b','Parent',h);
        hold off
    else
       %for C gen
    end
    
        while 1
            %�Ǐ��擾
            [maze_wall,maze_wall_search] = wall_set(maze_row_size,maze_col_size,current_x,current_y,current_dir,maze_wall,maze_wall_search);
            
            if coder.target('MATLAB')
            maze_wall_plot(maze_wall,current_x,current_y);
            drawnow limitrate nocallbacks
            end
            
            %���݈ʒu���S�[��������
            for i = 1:1:l_goal_size
                if (current_x == maze_goal(i,1)) && (current_y == maze_goal(i,2))
                    goal_flag = uint8(1);
                 end
            end


            if goal_flag == 1
                break        
            end

            % ������MAP����
            % [contour_map,max_length] = make_map2(maze_row_size,maze_col_size,maze_goal,maze_wall);
              [cmap,max_l] = make_map_find(maze_row_size,maze_col_size,maze_goal,l_goal_size,maze_wall);
           % �i�s�����I��
            %�D�揇�ʁ@�k�˓��˓�ː�
             [next_dir] = get_nextdir2(current_x,current_y,maze_wall,cmap,max_l);

           % ���ݕ����Ɛi�s�����ɉ���������
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
                %�I�u�W�F�N�g�ʒu�X�V
                hgtransform_update(h,current_x,current_y,search_start_x,search_start_y,9);
                %�T���󋵂̍X�V
                maze_search_plot_update(search_surf,maze_wall_search,maze_col_size,maze_row_size);
                drawnow
            else
                %for code generation
            end
        end

        
    if coder.target('MATLAB')
        %for MATLAB    
        %�T���I����,�}�[�J�[���ǂ���������
        %m = makehgtform('translate',50*9,50*9,0);
        %h.Matrix = m;
        %�ʂ̎�ނ̃}�[�J�[�����u��
        hold on
        plot(current_x * 9 -4.5,current_y * 9 -4.5,'-ob');
        hold off
        %�T���󋵃v���b�g�𓧖���
        serface_transparency(search_surf);
        drawnow
    else
        %for code generation
    end


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
        %�ǃZ���TAD�l�i�[�ϐ�
        global wall_sensor_front;
        global wall_sensor_right;
        global wall_sensor_left;
        %�ǃZ���T臒l
        global wall_sensor_front_th;
        global wall_sensor_right_th;
        global wall_sensor_left_th;
    %���[�J���ϐ��錾
    wall_write = uint8(zeros(1,4));%�Ǐ�񏑂����ݗp�o�b�t�@(N,E,S,W)
    serch_write = uint8(zeros(1,4));%�T����񏑂����ݗp�o�b�t�@(N,E,S,W)


    %�}�E�X�̕����Ɋ�Â��Ǐ��擾
    %�}�E�X�̕����Ɛ�Ε����̍�=�}�E�X�̕����ƂȂ邱�Ƃ𗘗p���A
    %��Ίp�x�Ɛ������Ƃ�B
    
    
% ���@�͂������Z���T�l�ɑΉ������� 
    
    %�Z���T�l�擾(�v�蒼��)
    %�����܂�
    
    %�O���̕ǔ���
    if coder.target('MATLAB')
        %for matlab
        %�摜���瓾�����m�̖��H�������ƂɁA�ǂ̗L���𔻒�
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),current_dir) ) %��[���̎����s
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %�Z���T�l�����ƂɁA�ǂ̗L���𔻒�
        if int16(wall_sensor_front) > int16(wall_sensor_front_th)
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir,4)+uint8(1)) = wall.wall;
        end
        
    end    
    %�T������X�V
    serch_write(uint8(1),rem(current_dir,4)+uint8(1)) = search.known;

    %�E�ǔ���
    if coder.target('MATLAB')
        %for matlab
        %�摜���瓾�����m�̖��H�������ƂɁA�ǂ̗L���𔻒�
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+1,4)) )
            wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %�Z���T�l�����ƂɁA�ǂ̗L���𔻒�
        if int16(wall_sensor_right) > int16(wall_sensor_right_th)
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = wall.wall;
        end
    end    
    %�T������X�V
    serch_write(uint8(1),rem(current_dir+1,4)+uint8(1)) = search.known;

    %����͏��𓾂邱�Ƃ��ł��Ȃ��̂ŏ������Ȃ��B

    %���ǔ���
    if coder.target('MATLAB')
        %for matlab
        %�摜���瓾�����m�̖��H�������ƂɁA�ǂ̗L���𔻒�
        if bitand(maze_serial(current_y,current_x),bitshift(uint8(1),rem(current_dir+3,4)) )
            wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
        end
    else
        %for Cgen
        %�Z���T�l�����ƂɁA�ǂ̗L���𔻒�
        if int16(wall_sensor_left) > int16(wall_sensor_left_th)
            %�Ǐ��擾
            wall_write(uint8(1),rem(current_dir+3,4)+uint8(1)) = wall.wall;
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


    end
%%  make_map_find �Ǐ�񂩂瓙����MAP�𐶐�
    function [contour_map,max_length] = make_map_find(maze_row_size,maze_col_size,maze_goal,l_goal_size,maze_wall)
    %���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W,���H���(16�i��)
    %�o�� ������map,�ő�o�H��


    % ���H�p�����[�^�ݒ�
    max_length = uint8((maze_col_size-1)*(maze_row_size-1));

    %MAP�̏�����(���ׂĂ̗v�f��max_length�����)
    %32�}�X��map��ێ�
    %16bit�ɂ��ׂ�
    contour_map = ones(32,32,'uint8');
    contour_map = contour_map * max_length;

    %�S�[�����W��0�����
    for temp = 1:1:l_goal_size
        contour_map(maze_goal(temp,2),maze_goal(temp,1)) = 0;
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
                        contour_map(row(tempn)+1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %����
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East)) == wall.nowall)
                        %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn),col(tempn)+1) == max_length 
                        contour_map(row(tempn),col(tempn)+1) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %�쑤
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South)) == wall.nowall)
                        %�쑤��MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn)-1,col(tempn)) == max_length 
                        contour_map(row(tempn)-1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %����
                    if (bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West)) == wall.nowall)
                        %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn),col(tempn)-1) == max_length 
                        contour_map(row(tempn),col(tempn)-1) = tempi+1;
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


%% �T�������Ǐ��(�V���A��)���v���b�g����֐�
    function [] = maze_wall_plot(maze_wall,current_x,current_y)
    %���� �T���Ǐ��,���ݒlx,y
    %�o�� 
    
    maze_step =  9;
    hold on

    %���ݒn�̕Ǐ����m�F

    i = current_y;
    n = current_x;

        %�k�Ǐ��v���b�g
           if bitand(maze_wall(i,n),bitshift(1,g_direction.North)) 
               plot([n-1,n].*maze_step,[i,i].*maze_step,'r','LineWidth',2)
           end
           %���Ǐ��v���b�g
           if bitand(maze_wall(i,n),bitshift(1,g_direction.East)) 
               plot([n,n].*maze_step,[i-1,i].*maze_step,'r','LineWidth',2)
           end
           %��Ǐ��v���b�g
           if bitand(maze_wall(i,n),bitshift(1,g_direction.South)) 
               plot([n-1,n].*maze_step,[i-1,i-1].*maze_step,'r','LineWidth',2)
           end
           %���Ǐ��v���b�g
           if bitand(maze_wall(i,n),bitshift(1,g_direction.West)) 
               plot([n-1,n-1].*maze_step,[i-1,i].*maze_step,'r','LineWidth',2)
           end

    hold off

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
    ax = gca;
    h = hgtransform('Parent',ax);

    %�}�E�X�̏����ʒu�ݒ�
    current_x = uint8(1);
    current_y = uint8(1);
    current_dir = g_direction.North;
    next_dir = g_direction.North;
    search_start_x = current_x; %�T���J�n��x
    search_start_y = current_y; %�T���J�n��y

    %�T���J�n�ʒu�v���b�g
    hold on
    plot(current_x * 9 -4.5,current_y * 9 -4.5,'ob','MarkerFaceColor','r','Parent',h);
    hold off

    %���Ճv���b�g
    hold on
    plot(current_x * 9 -4.5,current_y * 9 -4.5,'.r');
    hold off
    drawnow limitrate nocallbacks

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
            m = makehgtform('translate',(current_x-search_start_x)*9,(current_y-search_start_y)*9,0);
            h.Matrix = m;
            %���Ճv���b�g
            hold on
            plot(current_x * 9 -4.5,current_y * 9 -4.5,'.r');
            hold off
            %pause(0.2)
            drawnow limitrate nocallbacks
        else
        %for code generation
        end
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

    % ���H�p�����[�^�ݒ�
    max_length = uint8((maze_col_size-1)*(maze_row_size-1));

    %MAP�̏�����(���ׂĂ̗v�f��max_length�����)
    %MAP�̏�����(���ׂĂ̗v�f��max_length�����)
    %32�}�X��map��ێ�
    contour_map = ones(32,32,'uint8');
    contour_map = contour_map * max_length;
    
    %�S�[�����W��0�����
    for tempn = 1:1:goal_size
        contour_map(maze_goal(tempn,2),maze_goal(tempn,1)) = 0;
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
                row_size = uint16(numel(row));

                %�����������W�ɑ΂��A����map���X�V
                for tempn = 1:1:row_size
                    %�k��
                    %�ǂ����� & �T���ς݂ł���Ƃ�
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.North))) == search.known
                        %�k����MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn)+1,col(tempn)) == max_length 
                        contour_map(row(tempn)+1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %����
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.East))) == search.known
                        %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn),col(tempn)+1) == max_length 
                        contour_map(row(tempn),col(tempn)+1) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %�쑤
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.South))) == search.known
                        %�쑤��MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn)-1,col(tempn)) == max_length 
                        contour_map(row(tempn)-1,col(tempn)) = tempi+1;
                        change_flag = uint8(1);
                        end
                    end

                    %����
                    if logical(bitand(maze_wall(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West))) == wall.nowall...
                            && logical(bitand(maze_wall_search(row(tempn),col(tempn)),bitshift(uint8(1),g_direction.West))) == search.known
                        %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                        if contour_map(row(tempn),col(tempn)-1) == max_length 
                        contour_map(row(tempn),col(tempn)-1) = tempi+1;
                        change_flag = uint8(1);
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


end


