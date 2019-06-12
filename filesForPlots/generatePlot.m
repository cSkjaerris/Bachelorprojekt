clear all
clc

plotType = "InventoryStockAtTime";
sizes = ["Less", "Equal", "Great"];
extension = ".txt";
yParamName = 'stockAtTime_x_';


% for lost at time, stock at time, daily demand is changed

% for sold at time, target and reorder interval is changed
dataLess = readtable(plotType+sizes(1)+extension, 'Delimiter', ' ');
dataEqual = readtable(plotType+sizes(2)+extension, 'Delimiter', ' ');
dataGreat = readtable(plotType+sizes(3)+extension, 'Delimiter', ' ');

figure('Position', [1, 1, 800,600]);
x = dataLess{:,{'x'}};
yLess = dataLess{:,{yParamName}};
yEqual = dataEqual{:,{yParamName}};
yGreat = dataGreat{:,{yParamName}};
plot(x,yLess,'b-',x,yEqual,'k-',x,yGreat,'r-', 'linewidth', 5);
xlabel('Time');
ylabel('Average stock');
title('Average stock over time');
legend('Daily sales ranging 1-10', 'Daily sales ranging 5-15', 'Daily sales ranging 10-20')
grid on