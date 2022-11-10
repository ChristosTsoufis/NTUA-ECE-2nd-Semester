x=linspace(0, 3.*pi, 100);
y1=sin(x);
y2=x.^(-0.04);
y3=cos(4.*x);
plot(x,y1,x,y2,'--',x,y3,'m');
grid on
legend('sinx','x^{-0.04}', 'cos(4x)');
xlabel('aksonas x');
ylabel('aksonas y');
title ('Pollapla graphs');