
#ifndef CONTEST
#endif
#include <iostream>

using namespace std;

template <typename T>
class stack {

  private:
    int counter;
    int tempsize;
    T *data;


  public:

    stack (int size) {
      counter=0;
      tempsize=size;
      data= new T[tempsize];
    };

    stack (const stack &s) {
      data= new T[s.tempsize];
      counter=s.counter;
      tempsize=s.tempsize;
      for (int i=0;i<s.counter;i++)
        data[i]=s.data[i];
    };

    ~stack () {

      delete []data;
    };

    const stack & operator = (const stack &s) {
      delete []data;
      data= new T[s.tempsize];
      counter=s.counter;
      tempsize=s.tempsize;
      for (int i=0;i<s.counter;i++)
        data[i]=s.data[i];
      return *this;
    };

    bool empty () {
      return(counter==0);

    };

    void push (const T &x) {
      data[counter]=x;
      counter++;
    };

    T pop () {
      counter--;
      return data[counter];
    };

    int size () {
      return(counter);
    };

    friend ostream & operator << (ostream &out, const stack &s) {
      out<<"[";
      if(s.counter>0)
        out<<s.data[0];
      for(int i=1;i<s.counter;i++){
        out<<", "<<s.data[i];
      }
      out<<"]";
      return out;
    };
};
