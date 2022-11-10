x=0:0.01:2;
y1=e.^(-6.*x);
y2=sin(50.*x);
a = e.^x;
b = 1 + a;
y3=1./ b;
plot(x,y1,x,y2,'--',x,y3,'g');
grid on
legend('e^{-6x}','sin50x', '1/(1 + e^x)');
xlabel('aksonas x');
ylabel('aksonas y');
title ('Pollapla graphs');