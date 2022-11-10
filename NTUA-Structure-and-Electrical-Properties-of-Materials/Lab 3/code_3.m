%Dimioyrgia pollaplwn grafimatwn se 1 me aksones kai titlo
x=0:0.01:2;
y1=e.^(-6.*x);
y2=sin(50.*x);
y3=1./(1.+e.^x);
plot(x,y1,x,y2,'--',x,y3,'g');
%to '--' kanei diakekomeno to grafima
%to '4' dinei sto sygkekrimeno grafima to xroma magenta
grid on
legend('e^{-6x}','sin(50x)','1/(1+e^x)');
%me tin legend asntistoixoume ta grafimata tou plot se parartima
xlabel('aksonas x');
ylabel('aksonas y');
title('Pollapla graphs');