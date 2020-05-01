#include<iostream>
#include<list>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	public:
	Graph(int v){
	
	this->v=v;
	adj=new list<int>[v];
	}
	void addEdge(int v,int m){
	adj[v].push_back(m);
	}
	void DFSUtil(int v, bool visited[]) 
	{ 
	    visited[v] = true; 
    	cout << v << " "; 
 		list<int>::iterator i; 
 		   for (i = adj[v].begin(); i != adj[v].end(); ++i) 
 		       if (!visited[*i]) 
    	        DFSUtil(*i, visited); 
	} 
	void dfs(int s){
	
		bool *visited=new bool[v];
		for(int i=0; i<v; i++)
			visited[i]=false;
		DFSUtil(s,visited);
	}

};
int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	
	g.dfs(2);
}
