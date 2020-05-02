#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	public:
	Graph(int v){
		this->v=v;
		adj= new list<int>[v];
	
	}
	void addEdge(int v, int w){
		adj[v].push_back(w);
	}
	void BFS(int s){
	
		bool *visited = new bool[v];
		
		for(int i=0; i<v; i++)
			visited[i]=false;
			
		list<int> queue;
		
		visited[s]=true;
		queue.push_back(s);
		list<int>::iterator i;
		
		while(!queue.empty()){
		
			s=queue.front();
			cout<< s << " ";
			queue.pop_front();
			
			for(i = adj[s].begin(); i!=adj[s].end(); ++i){
			
				if(!visited[*i]){
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
	}	
};
int main(){
	
	   Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
	
	g.BFS(0);
	return 0;

}

