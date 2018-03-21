#include <iostream>
#include <list>

#include <limits.h>

   

class Graph
{
    int vert;    
    std::list<int> *adj; 
    bool Cyclic(int in,bool visited[], int parent);
public:
    Graph(int vert);
    void edge(int uu,int ww);
    bool isTree();
};
Graph::Graph(int  vert)
{
    this->vert =vert;
    adj = new std::list<int>[vert+1];
}
bool Graph::Cyclic(int in,bool visited[], int parent){
  visited[in] = true;
  std::list<int>::iterator i;
    for (i = adj[in].begin(); i != adj[in].end(); ++i)
    {
      if (!visited[*i])
        {
           if (Cyclic(*i, visited, in))
              return true;
        }
		else if (*i!= parent){
           return true;
           
	   }
    }
    return false;
}
void Graph::edge( int uu,int vv){
   adj[uu].push_back(vv);
  adj[vv].push_back(uu); 
}
bool Graph::isTree(){
   bool *visited = new bool[vert+1];
    for (int i = 0; i < vert+1; i++){
		visited[i] = false;
	}
    if (Cyclic(1, visited, -1)){
			return false;
	}
     for (int u = 1; u< vert+1;u++){
        if (!visited[u])
	   return false;
	}
	return true;
}
int main(){	
	int nodes, edges, u, v;
	std::cin>>nodes;
	std::cin>>edges;
    Graph graph(nodes);
    for(int i = 0;i<edges;i++){
		std::cin>>u;
		std::cin>>v;
		graph.edge(u, v);
	}
    if(graph.isTree()) 
		std::cout << "YES\n";
	else
        std::cout <<"NO\n";
}
