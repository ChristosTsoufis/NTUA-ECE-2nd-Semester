#include <iostream>
#include <cmath>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;


rational::rational (int n, int d) {
  nom=n; den=d;
}


rational operator + (const rational &x, const rational &y) {
  int ar,par;
  ar= x.nom*y.den + x.den*y.nom;
  par= x.den*y.den;
  rational temp(ar,par);
  return temp;

}

rational operator - (const rational &x, const rational &y) {
  int ar,par;
  ar= x.nom*y.den - x.den*y.nom;
  par= x.den*y.den;
  rational temp(ar,par);
  return temp;
}


rational operator * (const rational &x, const rational &y){
  int ar,par;
  ar= x.nom*y.nom;
  par= x.den*y.den;
  rational temp(ar,par);
  return temp;
}

rational operator / (const rational &x, const rational &y){
  int ar,par;
  ar= x.nom*y.den;
  par= x.den*y.nom;
  rational temp(ar,par);
  return temp;
}

int rational::gcd (int a, int b){
  if (a==0 || b==0)
    return a+b;
  else if (a > b)
    return gcd(a%b, b);
  else
    return gcd(a, b%a);
}

std::ostream & operator << (std::ostream &out, const rational &x){
  int d = rational::gcd(abs(x.nom), abs(x.den)) ;
 /* if (x.nom>=0 && x.den<0)
    out<< x.nom*(-1)/d<<"/"<<x.den*(-1)/d;
  else if (x.nom<=0 && x.den<0)
    out<< x.nom*(-1)/d<<"/"<<dem*(-1)/d;*/
  if (x.den<0)
    out<< x.nom*(-1)/d<<"/"<<x.den*(-1)/d;
  else
    out << x.nom/d <<"/"<<x.den/d ;
  return out ;
}
/*
int main() {
  rational a(1, 2);
  rational b(3, 4);
  rational c(5, 6);
  cout << a + b - c << endl;
  cout << a << " should still be 1/2" << endl;
}
*/
