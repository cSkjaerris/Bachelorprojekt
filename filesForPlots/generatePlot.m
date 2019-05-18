clear all
clc

plotType = "BankSizeAtTime";
sizes = ["Less", "Equal", "Great"];
extension = ".txt";
yParamName = 'sizeAtTime_x_';


% for lost at time, stock at time, daily demand is changed

% for sold at time, target and reorder interval is changed
dataLess = readtable(plotType+sizes(1)+extension, 'Delimiter', ' ');
dataEqual = readtable(plotType+sizes(2)+extension, 'Delimiter', ' ');
dataGreat = readtable(plotType+sizes(3)+extension, 'Delimiter', ' ');

figure;
x = dataLess{:,{'x'}};
yLess = dataLess{:,{yParamName}};
yEqual = dataEqual{:,{yParamName}};
yGreat = dataGreat{:,{yParamName}};
plot(x,yLess,'b-',x,yEqual,'g-',x,yGreat,'r-');
xlabel('Time');
ylabel('Queue size');
title('Average queue size over time');
legend('Arrival rate lower than desk', 'Arrival rate equal to desk', 'Arrival rate greater than desk')
grid on