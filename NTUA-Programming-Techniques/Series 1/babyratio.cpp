
#ifndef CONTEST
#include "babyratio.hpp"
#endif
#include<iostream>
#include<cmath>

using namespace std;

rational::rational (int n, int d) {
  nom=n; den=d;
}

rational rational::add (rational r) {
  int ar,par;
  ar= nom*r.den + den*r.nom;
  par= den*r.den;
  rational temp(ar,par);
  return temp;
}

rational rational::sub (rational r) {
  int ar,par;
  ar= nom*r.den - den*r.nom;
  par= den*r.den;
  rational temp(ar,par);
  return temp;
}

rational rational::mul (rational r) {
  int ar,par;
  ar= nom*r.nom;
  par= den*r.den;
  rational temp(ar,par);
  return temp;
}

rational rational::div (rational r) {
  int ar,par;
  ar= nom*r.den;
  par= den*r.nom;
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


void rational::print (){
  int x = gcd(abs(nom), abs(den)) ;
/*  if (nom>=0 && den<0)
    cout<< nom*(-1)/x<<"/"<<den*(-1)/x;
  else if (nom<=0 && den<0)
    cout<< nom*(-1)/x<<"/"<<den*(-1)/x;*/
  if (den<0)
    cout<< nom*(-1)/x<<"/"<<den*(-1)/x;
  else
    cout << nom/x <<"/"<<den/x ;
}

/*
   int main() {
   rational a(0, -3);
   rational b(-4, -5);
   rational c(5, 6);
   a.add(b).sub(c).print();
   a.mul(b).print();
   cout << endl;
   a.print();
   cout << " should still be 1/2" << endl;
   }*/

