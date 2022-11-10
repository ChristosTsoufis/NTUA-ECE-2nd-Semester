
#include <iostream>
#include <cmath>

using namespace std;

class Polynomial
{
  protected:
    class Term
    {
      public:
        Term *next;
        int exponent, coefficient;

        Term(int exp, int coeff, Term *n)
          : exponent(exp), coefficient(coeff), next(n) {}
    };

  public:
    Polynomial() {};
    Polynomial(const Polynomial &p) { (*this) = p; }
    ~Polynomial() { eradicatePolynomial(); }

    Polynomial & operator = (const Polynomial &p)
    {
      if (this == &p) return (*this);
      Term *t = p.top;
      eradicatePolynomial();

      while (t)
      {
        addTerm(t->exponent, t->coefficient);
        t = t->next;
      }

      return (*this);
    }

    void addTerm(int exponent, int coefficient)
    {
      if (!coefficient) return;
      if (!top) { top = new Term(exponent, coefficient, NULL); return; }

      Term *t[2] = { top, NULL };
      while (t[0])
      {
        if (exponent > t[0]->exponent)
        { 
          if (t[0] != top) t[1]->next = new Term(exponent, coefficient, t[0]);
          else top = new Term(exponent, coefficient, t[0]);
          break;
        }
        else if (t[0]->exponent == exponent) 
        { 
          t[0]->coefficient += coefficient;
          if (!t[0]->coefficient)
          {
            if (t[0] != top) t[1]->next = t[0]->next;
            else top = t[0]->next;
            delete t[0];
          }
          break;
        }
        else if (!t[0]->next) { t[0]->next = new Term(exponent, coefficient, NULL); break; }
        t[1] = t[0];
        t[0] = t[0]->next;
      }
    }

    double evaluate(double x)
    {
      double res = 0; Term *t = top;

      while (t)
      {
        res += t->coefficient * pow(x, t->exponent);
        t = t->next;
      }

      return res;
    }

    friend Polynomial operator + (const Polynomial &lhs, const Polynomial &rhs)
    { 
      Polynomial r;
      Term *t[2] = { lhs.top, rhs.top };

      for (int i = 0; i < 2; i++)
        while (t[i]) { r.addTerm(t[i]->exponent, t[i]->coefficient); t[i] = t[i]->next; }

      return r;
    }

    friend Polynomial operator * (const Polynomial &lhs, const Polynomial &rhs)
    {
      Polynomial r;
      Term *t[2] = { lhs.top, rhs.top };
      if (!t[0] || !t[1]) return r;

      while (t[0])
      {
        t[1] = rhs.top;

        while (t[1])
        {
          r.addTerm(t[0]->exponent + t[1]->exponent, t[0]->coefficient * t[1]->coefficient);
          t[1] = t[1]->next;
        }

        t[0] = t[0]->next;
      }
      return r;
    }

    friend ostream & operator << (ostream &out, const Polynomial &p)
    {
      Term *t = p.top;
      if (!t) { out << "0"; return out; }

      while (t)
      {
        if (t == p.top && t->coefficient < 0) out << "- ";
        else if (t != p.top) out << (t->coefficient < 0 ? " - " : " + ");

        if (!(t->exponent > 0 && abs(t->coefficient) == 1)) out << abs(t->coefficient);
        if (t->exponent) out << "x";
        if (t->exponent > 1 || t->exponent < 0) out << "^" << t->exponent;

        t = t->next;
      }
      return out;
    }

  private:
    void eradicatePolynomial()
    {
      Term* t[2] = { top, NULL };
      while (t[0])
      {
        t[1] = t[0]->next;
        delete t[0];
        t[0] = t[1];
      }
      top = NULL;
    }

    Term *top = NULL;
};

/*
int main()
{
  Polynomial p;
  p.addTerm(1, 3);
  p.addTerm(1, -3);

  Polynomial q(p);
  q.addTerm(1, -3);

  cout << "P(x) = " << p << endl;
  cout << "P(1) = " << p.evaluate(1) << endl;
  cout << "Q(x) = " << q << endl;
  cout << "Q(1) = " << q.evaluate(1) << endl;
  cout << "(P+Q)(x) = " << p+q << endl;
  cout << "(P*Q)(x) = " << p*q << endl;

  return 0;
}
*/

