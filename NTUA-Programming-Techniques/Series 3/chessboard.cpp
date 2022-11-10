
#include <iostream>  
#include <stdexcept>  
#include <iomanip>  
using namespace std;  

class ChessBoardArray {  
  protected:  
    class Row {  
      public:  
        Row(ChessBoardArray &a, int i) : chBArr(a), row(i) {}  

        int & operator [] (int i) const {  
          return chBArr.select(row, i);  
        }  
      private:  
        ChessBoardArray & chBArr;  
        int row;  
    };  

    class ConstRow {  
      public:  
        ConstRow(const ChessBoardArray &a, int i) : chBArr(a), row(i) {}  

        int operator [] (int i) const {  
          return chBArr.select(row, i);  
        }  

      private:  
        const ChessBoardArray &chBArr;  
        int const row;  
    };  

    int length, station;  
    int *data;  

    unsigned int loc(int i, int j) const throw(out_of_range) {  
      int di = i - station, dj = j - station;  
      if (di < 0 || di >= length || dj < 0 || dj >= length || (di + dj) % 2 != 0) throw out_of_range("invalid index");  
      return (di * length + dj) / 2;  

    }  

  public:  
    ChessBoardArray(unsigned size = 0, unsigned base = 0)  
      : length(size), station(base) {  
        if (length % 2 == 0) {  
          data = new int[length*length/2];  
          for (int i = 0; i < length*length/2; i++)  
            data[i] = 0;  
        }  
        else {  
          data = new int[length*length/2 + 1];  
          for (int i = 0; i < length*length/2 + 1; i++)  
            data[i] = 0;  
        }  
      }  

    ChessBoardArray(const ChessBoardArray &a)  
      : station(a.station), length(a.length) {  
        if (a.length % 2 == 0) {  
          data = new int[a.length*a.length/2];  
          for (int i = 0; i < a.length*a.length/2; i++)  
            data[i] = a.data[i];  
        }  
        else {  
          data = new int[a.length*a.length/2 + 1];  
          for (int i = 0; i < a.length*a.length/2 + 1; i++)  
            data[i] = a.data[i];  
        }  
      }  

    ~ChessBoardArray() {  
      delete[] data;  
    }  

    ChessBoardArray & operator = (const ChessBoardArray &a) {  
      delete[] data;  
      station = a.station;  
      length = a.length;  
      if (a.length % 2 == 0) {  
        data = new int[a.length*a.length/2];  
        for (int i = 0; i < a.length*a.length/2; i++)  
          data[i] = a.data[i];  
      }  
      else {  
        data = new int[a.length*a.length/2 + 1];  
        for (int i = 0; i < a.length*a.length/2 + 1; i++)  
          data[i] = a.data[i];  
      }  

      return *this;  
    }  

    int & select(int i, int j) {  
      return data[loc(i, j)];  
    }  

    int select(int i, int j) const {  
      return data[loc(i, j)];  
    }  

    const Row operator [] (int i) {  
      return Row(*this, i);  
    }  

    const ConstRow operator [] (int i) const {  
      return ConstRow(*this, i);  
    }  

    friend ostream & operator << (ostream &out, const ChessBoardArray &a) {  
      for (int i = a.station; i < a.station + a.length; i++) {  
        for (int j = a.station; j < a.station + a.length; j++) {  
          try { out << setw(4) << a.data[a.loc(i, j)]; }  
          catch (out_of_range &a) { out << setw(4) << 0; }  
        }  
        out << endl;  
      }  
      return out;  
    }  

};

