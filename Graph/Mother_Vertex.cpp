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
	void addEdge(int v, int m){
		adj[v].push_back(m);
	}
	void DFSUtil(int v, bool visited[]){
		visited[v]=true;
		list<int>::iterator it;
		for(it = adj[v].begin(); it!=adj[v].end(); it++){
			if(!visited[*it]){
				DFSUtil(*it,visited);
			}
		}
	}
	bool findMother(){
	
	bool visited[v]={false};
	int last = 0;
	for(int i=0;i<v;i++){
	
		if(visited[i]==false){
			DFSUtil(i, visited);
			last = i;
		}
	}
	
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	
	DFSUtil(last, visited);
	for(int i=0;i<v; i++)
		if(visited[i]==false)
			return false;
	cout<<"Mother Vertex is " << last ;			
	return true;
	
	}

};
int main(){
	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
	g.findMother();	
}
