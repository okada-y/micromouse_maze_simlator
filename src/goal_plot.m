function [] = goal_plot(goal_size,maze_goal)

for i = 1:goal_size
    hold on
    plot(double(maze_goal(i,1))*9-4.5,double(maze_goal(i,2))*9-4.5,'--ob','MarkerSize',10)
    hold off
end


end