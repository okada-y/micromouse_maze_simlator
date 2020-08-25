function[maze_wall,maze_wall_search]=maze_init(maze_row_size,maze_col_size)
%maze_init ���H���̏�����
%���� ���H���T�C�Y, ���H�c�T�C�Y 
%�o�� ���H�Ǐ��,���H�ǒT���ςݏ��

%���p��`
t_direction.North = uint8(0);
t_direction.East = uint8(1);
t_direction.South = uint8(2);
t_direction.West = uint8(3);


%���H���A�T���Ϗ�񏉊���
% maze_wall = uint8(zeros(maze_col_size-1,maze_row_size-1));
% maze_wall_search = uint8(zeros(maze_col_size-1,maze_row_size-1));
 maze_wall = uint8(zeros(32,32));
 maze_wall_search = uint8(zeros(32,32));

%���m�ƂȂ�O��4�ӂ̕Ǐ�����́A�T���ς݂Ƃ���B
for i = 1:1:maze_row_size-1
    for n = 1:1:maze_col_size-1
        %�k��
        if i == maze_row_size-1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.North));   
        end
        
        %����
        if n == maze_col_size-1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.East));
        end
        
        %�쑤
        if i == 1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.South));
        end
        
        %����
        if n == 1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.West));
        end
    end
end

%�X�^�[�g���̕ǂ�|_|�ƂȂ��Ă���̂ŁA���炩���ߓ���
%�X�^�[�g�}�X���猩�ē���
maze_wall(1,1) = bitor(maze_wall(1,1),bitshift(uint8(1),t_direction.East));

%�X�^�[�g�}�X�̈�}�X�����̃}�X���猩�Đ���
maze_wall(1,2) = bitor(maze_wall(1,2),bitshift(uint8(1),t_direction.West));

%�ȏ�̕Ǐ��͒T���ς݂Ƃ���
maze_wall_search(:,:) = maze_wall(:,:);

%���W(1,1)�̖k���A(2,1)�̓쑤�͕ǂ��Ȃ����Ƃ��킩���Ă���̂ŒT���ς݂Ƃ���B
maze_wall_search(1,1) = bitor(maze_wall(1,1),bitshift(uint8(1),t_direction.North)); 
maze_wall_search(2,1) = bitor(maze_wall(2,1),bitshift(uint8(1),t_direction.South)); 

%���H��32�}�X�����̎��A�T�C�Y�ȏ�͈̔͂́A�T���s�v�i�s�j�̂��߁A�T���ς݂Ƃ���B
if maze_col_size < 32
    maze_wall_search(1:32,maze_col_size:32) = uint8(15);
end
if maze_row_size < 32
    maze_wall_search(maze_row_size:32,:) = uint8(15);
end


end