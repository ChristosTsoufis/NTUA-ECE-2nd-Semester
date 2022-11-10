E=linspace(0.35,0.75,100);
a=E-0.55;
b=8.617*(10.^(-5))*350;
c=1.0./(1.+e.^(a/b));

plot(E,c);

grid on
legend('Fermi');
xlabel('E-Ef (eV)');
ylabel('F(E)');
title('Fermi-Dirac');