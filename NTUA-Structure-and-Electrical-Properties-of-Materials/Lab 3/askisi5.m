E = linspace(0.35, 0.75, 10);
a = E - 0.55;
b = 8.617*(10.^(-5))* 350;
c = 1.+ e.^(a/b);
Fermi = 1.0./c;
plot(E, Fermi)
grid on
ylabel('F(E)');
xlabel('E - Ef(eV)');
