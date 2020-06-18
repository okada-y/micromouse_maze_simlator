%% �T�������Ǐ��(�V���A��)���v���b�g����֐�
 function [] = maze_wall_plot(maze_wall,current_x,current_y,maze_row_size,maze_col_size)
 %���� �T���Ǐ��,���ݒlx,y
 %�o�� 
    maze_step =  9;
    
    
%   global maze_fig; 
%   figure(maze_fig);
    %���ݒn�̕Ǐ����m�F
    wall_plot(maze_wall,current_x,current_y,maze_step)
    
    %����p�^�[���ɂ����āA�ׂ荇���}�X�̕ǂ��m�肷��̂ŁA�אڂ���}�X���X�V����B   
        
    %�k�̃}�X
    if current_y < maze_row_size -1
        wall_plot(maze_wall,current_x,current_y+1,maze_step)
    end
    %���̃}�X
    if current_x < maze_col_size -1
        wall_plot(maze_wall,current_x+1,current_y,maze_step)
    end
    %��̃}�X
    if current_y > 1
        wall_plot(maze_wall,current_x,current_y-1,maze_step)
    end
    %���̃}�X
    if current_x > 1
        wall_plot(maze_wall,current_x-1,current_y,maze_step)
    end

 end
    
 function wall_plot(wall,x,y,step)

    global g_direction;
    i = uint16(y);
    n = uint16(x);

    hold on
    %�k�Ǐ��v���b�g
    if bitand(wall(i,n),bitshift(1,g_direction.North)) 
        plot([n-1,n].*step,[i,i].*step,'r','LineWidth',2)
    end
    %���Ǐ��v���b�g
    if bitand(wall(i,n),bitshift(1,g_direction.East)) 
        plot([n,n].*step,[i-1,i].*step,'r','LineWidth',2)
    end
    %��Ǐ��v���b�g
    if bitand(wall(i,n),bitshift(1,g_direction.South)) 
        plot([n-1,n].*step,[i-1,i-1].*step,'r','LineWidth',2)
    end
    %���Ǐ��v���b�g
    if bitand(wall(i,n),bitshift(1,g_direction.West)) 
        plot([n-1,n-1].*step,[i-1,i].*step,'r','LineWidth',2)
    end
    hold off
 end
