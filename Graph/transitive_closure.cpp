#include<iostream>
#include<list>

using namespace std;

class Graph{
	int v;
	list<int> *adj;
	bool **ts;
	
	public:
	Graph(int v){
		this->v=v;
		adj=new list<int>[v];
		ts=new bool* [v];
		for(int i=0;i<v;i++){
			ts[i]=new bool[v];
		}
	}
	void addEdge(int v, int m){
		adj[v].push_back(m);
	}
	
	void DFSUtil(int s, int t){
		ts[s][t]=true;
		list<int>::iterator i; 
	    for (i = adj[t].begin(); i != adj[t].end(); ++i) 
    	    if (ts[s][*i] == false) 
    	        DFSUtil(s, *i); 
	
	}
	void tClosure(){
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				ts[i][j]=false;
		
		for(int i=0;i<v;i++){
			DFSUtil(i,i);
		}
				
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++)
				cout<<ts[i][j]<< " ";
			cout<<endl;
		}
	}
};
int main(){
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
	g.tClosure();
}

