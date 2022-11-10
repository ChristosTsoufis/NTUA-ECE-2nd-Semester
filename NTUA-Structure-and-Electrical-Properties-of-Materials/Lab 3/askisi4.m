T=linspace(0, 800, 100);
Eg1 = 1.17.-(((4.73.*10.^(-4))*T.^2)./(T.+636));
Eg2 = 1.52.-(((5.4.*10.^(-4))*T.^2)./(T.+204));

plot(T, Eg1, T, Eg2)
grid on
legend('Si', 'GaAs');
xlabel('T(K)');
ylabel('BANDGAP Eg (eV)');
