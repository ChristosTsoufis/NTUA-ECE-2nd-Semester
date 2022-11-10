
#include<iostream>  
#include<algorithm>  
#include<vector>  

using namespace std;  

class Graph {  
  public:  
    int siz;  
    int **adj;  
    int *visited,*prev;  
    int visit=0;  
    int telos=0;  
    bool iscycle=false;  

    Graph(int V){  
      visited = new int[V];  
      prev = new int[V];  
      for(int i=0;i<V;i++){  
        visited[i]=0;  
        prev[i]=0;  
      }  

      siz=V;  
      adj = new int*[V];  
      for(int i = 0; i < V; i++) {  
        adj[i] = new int[V];  
        for(int j=0;j<V;j++)  
          adj[i][j]=0;  
      }  
    }  

    ~Graph(){  
      for(int i = 0; i < siz; ++i) {  
        delete [] adj[i];  
      }  
      delete [] adj;  
    }  

    void addEdge(int u, int v){  
      adj[u][v]=1;  
    }  

    void dfs(int u,vector<int> &path){  
      if(iscycle) return;  
      visit++;  
      visited[u]=1;  
      for(int i=0;i<siz;i++){  
        if(iscycle)     return;  
        if((visited[i]==1)&&(adj[u][i]==1)&&(binary_search(path.begin(),path.end(),i))){  
          telos=path.size();  
          iscycle=true;  
          return;  
        }  
        if((visited[i]==0)&&(adj[u][i]==1)){  
          path.push_back(i);  
          dfs(i,path);  
        }  
      }  
      if(iscycle)     return;  
      path.pop_back();  
    }  

    bool cycle(vector<int> &path) {  
      while(visit<siz){  
        for(int i=0;i<siz;i++){  
          if(visited[i]==0){  
            path.clear();  
            path.push_back(i);  
            dfs(i, path);  
            path.erase(path.begin(),path.begin()+telos);  
            if(iscycle) return true;  
          }  
        }  
      }  
      return false;  
    }  

};  

#ifndef CONTEST  

int main() {  
  int V, E;  
  cin >> V >> E;  
  Graph g(V);  

  for (int i = 0; i < E; ++i) {  
    int u, v;  
    cin >> u >> v;  
    g.addEdge(u, v);  
  }  

  vector<int> path;  
  bool c = g.cycle(path);  

  if (c) {  
    cout << "CYCLE: ";  
    for (int i = 0; i < path.size(); ++i)  
      cout << path[i] << (i == path.size()-1 ? "\n" : " ");  
  } else {  
    cout << "NO CYCLE" << endl;  
  }  

}  
#endif

