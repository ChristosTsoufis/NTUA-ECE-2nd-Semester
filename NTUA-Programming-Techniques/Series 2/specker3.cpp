/*Player::Player(const string &n) {
  player_name = n;
}

Player::~Player() {
  player_name.clear();
}

ostream &operator<<(ostream &out, const Player &player) {
  out << player.getType() << " player " << player.player_name;
  return out;
}
*/
class Game {
  private:
    int game_heaps, game_players, current_heap, current_player;
    int *heap_coins;
    Player **players_list;

  public:
    Game(int heaps, int players) {
      heap_coins= new int [heaps];
      game_heaps = heaps;
      game_players = players;
      current_heap = 0;
      current_player = 0;
      players_list = new Player*[players];
    }
    ~Game() {
      delete[] heap_coins;
      delete[] players_list;
    }
    void addHeap(int coins) throw(logic_error) {
      if (current_heap > game_heaps)
        throw logic_error("heaps full with coins");
      else if (coins < 0)
        throw logic_error("Coins must be a positive number"); 
      else {
        heap_coins[current_heap++] = coins;
      }
    }
    void addPlayer(Player *player) throw(logic_error) {
      if (current_player > game_players)
        throw logic_error("All players added");
      else {
        players_list[current_player++] = player;
      }
    }
    void play(ostream &out) throw(logic_error) {
      if ((current_player != game_players) && (current_heap != game_heaps)) {
        throw logic_error("added all heaps and players?");
      } else {
        int i = 0;
        State currentState(game_heaps, heap_coins);
        while (!currentState.winning()) {
          out << "State: " << currentState << endl;
          out << *players_list[i % game_players] << " "
            << players_list[i % game_players]->play(currentState) << endl;
          currentState.next(
              players_list[i % game_players]->play(currentState));

          i++;
        }
        out << "State: " << currentState << endl;
        i--;
        out << *players_list[i % game_players] << " wins" << endl;
      }
    }
};

/*
int main() {
  Game specker(6, 5);
  specker.addHeap(10);
  specker.addHeap(20);
  specker.addHeap(17);
  specker.addHeap(17);
  specker.addHeap(17);
  specker.addHeap(17);

  specker.addPlayer(new GreedyPlayer("Alan"));
  specker.addPlayer(new SneakyPlayer("Tom"));
  specker.addPlayer(new SpartanPlayer("Mary"));
  specker.addPlayer(new RighteousPlayer("Robin"));

  specker.addPlayer(new pt18a038("Stavros"));
  specker.play(cout);

}*/
