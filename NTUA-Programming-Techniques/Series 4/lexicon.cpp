
#include <iostream>
#include <string>
#include <stack>

using namespace std;
struct word
{
  word(const string &str) : data(str) {}
  word(const string &str, unsigned c, word *_l, word *_r) : data(str), count(c), l(_l), r(_r) {}
  unsigned count = 0;
  word *l = 0, *r = 0;
  string data;
};

class lexicon
{
  public:
    ~lexicon() { destroy(root); if (root) delete root; }

    void insert(const string &s, unsigned count = 1)
    {
      int d = 0; par = root;
      word* &r = traverse(d, root, s);

      if (d != -1) r->count += count;
      else r = new word(s, count, 0, 0);
    }

    int lookup(const string &s)
    {
      int d = 0; word* r = traverse(d, root, s);
      return r ? r->count : 0;
    }

    int depth(const string &s)
    {
      int d = 0; traverse(d, root, s);
      return d + 1;
    }

    void replace(const string &s1, const string &s2)
    {
      int depth = 0, count;
      word* one = traverse(depth, root, s1);
      if (!one) return;

      count = one->count;

      if (one->r && one->l)
      {
        word *t1 = one->l;
        word *t2 = one;
        while (t1->r) { t2 = t1; t1 = t1->r; }
        one->data = t1->data;
        one->count = t1->count;
        delete t1;
        t2 == one ? t2->l = NULL : t2->r = NULL;
      }
      else
      {
        word *n = one->r ? one->r : one->l;
        if (one == root) root = n;
        else par->l == one ? par->l = n : par->r = n;

        delete one;
      }

      insert(s2, count);
    }

    friend ostream & operator << (ostream &out, const lexicon &l)
    {
      stack<word*> s;
      word* c =  l.root;
      s.push(c);

      while (!s.empty())
      {
        if (c != NULL && c->l != NULL) { c = c->l; s.push(c); }
        else
        {
          c = s.top();
          out << c->data << " " << c->count << endl;
          s.pop();
          c = c->r;
          if (c) s.push(c);
        }
      }

      return out;
    }

  private:
    word*& traverse(int &d, word* &c, const string &tar)
    {
      if (!c) { d = -1;  return root; }
      if (tar == c->data) return c;

      word* &n = tar > c->data ? c->r : c->l; par = c;
      if (!n) { d = -1; return n; }
      return traverse(++d, n, tar);
    }

    void destroy(word* ptr)
    {
      if (!ptr) return;
      if (ptr->l) { destroy(ptr->l); delete ptr->l; }
      if (ptr->r) { destroy(ptr->r); delete ptr->r; }
    }

    word *root = NULL, *par;
};

/*
int main()
{
  lexicon l;
  l.insert("the");
  l.insert("boy");
  l.insert("and");
  l.insert("the");
  l.insert("wolf");

  l.replace("and", "dummy");
  l.replace("boy", "dummy");
  l.replace("the", "dummy");
  cout << l << "asdnkmashjkas wolf  " << l.depth("wolf") << "dummy  " << l.depth("dummy") << endl;

  system("PAUSE");
  return 0;
}
*/

