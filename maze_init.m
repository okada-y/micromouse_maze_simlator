function[maze_wall,maze_wall_search]=maze_init(maze_row_size,maze_col_size)
%maze_init 迷路情報の初期化
%入力 迷路横サイズ, 迷路縦サイズ 
%出力 迷路壁情報,迷路壁探索済み情報

%方角定義
t_direction.North = uint8(0);
t_direction.East = uint8(1);
t_direction.South = uint8(2);
t_direction.West = uint8(3);


%迷路情報、探索済情報初期化
% maze_wall = uint8(zeros(maze_col_size-1,maze_row_size-1));
% maze_wall_search = uint8(zeros(maze_col_size-1,maze_row_size-1));
 maze_wall = uint8(zeros(32,32));
 maze_wall_search = uint8(zeros(32,32));

%既知となる外周4辺の壁情報を入力、探索済みとする。
for i = 1:1:maze_row_size-1
    for n = 1:1:maze_col_size-1
        %北側
        if i == maze_row_size-1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.North));   
        end
        
        %東側
        if n == maze_col_size-1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.East));
        end
        
        %南側
        if i == 1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.South));
        end
        
        %西側
        if n == 1
            maze_wall(i,n) = bitor(maze_wall(i,n),bitshift(uint8(1),t_direction.West));
        end
    end
end

%スタート時の壁は|_|となっているので、あらかじめ入力
%スタートマスから見て東側
maze_wall(1,1) = bitor(maze_wall(1,1),bitshift(uint8(1),t_direction.East));

%スタートマスの一マス東側のマスから見て西側
maze_wall(1,2) = bitor(maze_wall(1,2),bitshift(uint8(1),t_direction.West));

%以上の壁情報は探索済みとする
maze_wall_search(:,:) = maze_wall(:,:);

%座標(1,1)の北側、(2,1)の南側は壁がないことがわかっているので探索済みとする。
maze_wall_search(1,1) = bitor(maze_wall(1,1),bitshift(uint8(1),t_direction.North)); 
maze_wall_search(2,1) = bitor(maze_wall(2,1),bitshift(uint8(1),t_direction.South)); 

end