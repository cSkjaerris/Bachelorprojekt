clear all
clc

plotType = "ArgosTimeAtSteps";
extension = ".txt";

data = readtable(plotType+extension, 'Delimiter', ' ');

y1ParamName = 'timeAtsteps_x_';

figure('Position', [1, 1, 800,600]);
x = data{:,{'x'}};
y1 = data{:,{y1ParamName}};

plot(x,y1,'k-','linewidth', 5);
xlabel('Steps');
ylabel('Time');
title('Argos Time at steps');
legend('Time as a function of steps')
grid on