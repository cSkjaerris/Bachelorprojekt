clear all
clc

plotType = "InventoryMultiple";
extension = ".txt";
yParamName1 = 'soldAtTime_x_';
yParamName2 = 'lostAtTime_x_';
yParamName3 = 'restockAtTime_x_';

data= readtable(plotType+extension, 'Delimiter', ' ');

figure('Position', [1, 1, 800,600]);
x = data{:,{'x'}};
yLess = data{:,{yParamName1}};
yEqual = data{:,{yParamName2}};
yGreat = data{:,{yParamName3}};
plot(x,yLess,'b-',x,yEqual,'k-',x,yGreat,'r-', 'linewidth', 5);
xlabel('Time');
ylabel('');
title('Inventory Simulator multiple expressions');
legend('Sold products as function of time', 'Lost sales as function of time', 'Restockings as function of time')
grid on