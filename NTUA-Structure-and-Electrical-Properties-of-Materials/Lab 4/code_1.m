Lp=sqrt(17).*(10.^(4.5))
x=linspace(0,(Lp+0.003),1000)
Pno=(10.^5).*(10.^6)
Pn0=(10.^12).*(10.^6)
y=Pno.+((Pn0.-Pno).*e.^(-x./Lp))
plot(x,y)