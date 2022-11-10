
class Move {
  private:
    int sha, sca, tha, tca;
  public:
    // Take sc coins from heap sh and put tc coins to heap th.
    Move(int sh, int sc, int th, int tc){
      sha=sh; sca=sc; tha=th; tca=tc;
    }
    int getSource() const{
      return sha;
    }
    int getSourceCoins() const{
      return sca;
    }
    int getTarget() const{
      return tha;
    }
    int getTargetCoins() const{
      return tca;
    }
    friend ostream & operator << (ostream &out, const Move &move){
      out<<"takes "<<move.getSourceCoins()<<" coins from heap "<<move.getSource()<<" and puts ";
      if (move.getTargetCoins()>0)
        out<<move.getTargetCoins()<<" coins to heap "<<move.getTarget();
      else
        out<<"nothing";
      return out;
    }
};

class State {
  private:
    int ha;
    int *ca;
  public:
    // State with h heaps, where the i-th heap starts with c[i] coins.
    State(int h, const int c[]){
      ha=h;
      ca= new int[ha];
      for(int i=0;i<ha;i++){
        ca[i]=c[i];
      }
    }
    ~State(){
      delete [] ca;
    }
    void next(const Move &move) throw(logic_error){
      if((move.getSourceCoins()>getCoins(move.getSource())))
        throw logic_error("not enough coins");
      else if((move.getSource()<0) || (move.getSource()>=ha)) 
        throw logic_error("invalid ha");
      else if((move.getTarget()>=ha) || (move.getTarget()<0))
        throw logic_error("invalid ha");
      else if(move.getTargetCoins()>=move.getSourceCoins())
        throw logic_error("invalid ha");        
      else{ 
        ca[move.getSource()]-=move.getSourceCoins();
        ca[move.getTarget()]+=move.getTargetCoins(); }
    }
    bool winning() const{
      for(int i=0;i<ha;i++){
        if(ca[i]>0)
          return false;
      }
      return true;
    }
    int getHeaps() const{
      return ha;
    }
    int getCoins(int h) const throw(logic_error){
      if(h<0 || h>=ha)
        throw logic_error("invalid something");
      return ca[h];
    }
    friend ostream & operator << (ostream &out, const State &state){
      for (int i=0;i<state.getHeaps();i++){
        out<<state.getCoins(i);
        if(i!=(state.getHeaps() - 1))
          out<< ", ";
      }
      return out;
    }
};

