clear all
clc

plotType = "BankTimeIndependant";
extension = ".txt";

data = readtable(plotType+extension, 'Delimiter', ' ');

y1ParamName = 'timeAtArrived_x_';
y2ParamName = 'timeAtServed_x_';

figure('Position', [1, 1, 800,600]);
x = data{:,{'x'}};
y1 = data{:,{y1ParamName}};
y2 = data{:,{y2ParamName}};

plot(x,y1,'b-',x,y2,'r-','linewidth', 5);
xlabel('Number');
ylabel('Time');
title('Validating rate works');
legend('Time as a function of arrivals', 'Time as a function of served')
grid on