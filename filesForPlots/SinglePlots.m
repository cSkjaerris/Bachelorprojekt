clear all
clc

plotType = "BankTimeIndependant";
extension = ".txt";

data = readtable(plotType+extension, 'Delimiter', ' ');

y1ParamName = 'timeAtArrived_x_';
y2ParamName = 'timeAtServed_x_';

figure;
x = data{:,{'x'}};
y1 = data{:,{y1ParamName}};
y2 = data{:,{y2ParamName}};

plot(x,y1,'b-',x,y2,'r-');
xlabel('Number');
ylabel('Time');
title('Validating rate works as it should on independant variables');
legend('Time as a function of arrivals', 'Time as a function of served')
grid on