#include<iostream>
#include<list>
#include<vector>
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
		adj[v].push_back(m);
	}
	void DFSUtil(int u, vector<bool> &visited){
		visited[u]=true;
		list<int> ::iterator it;
		
		for(it=adj[u].begin();it!=adj[u].end();it++){
			if(visited[*it]==false)
				DFSUtil(*it,visited);
		}
	}
	int countTrees(){
	
		vector<bool> visited(v,false);
		
		int res=0;
		
		for(int i=0;i<v;i++){
			if(visited[i]==false){
				DFSUtil(i,visited);
				res++;
			}
		}
		return res;
	}
};
int main(){
	Graph g(7);
	g.addEdge(0,0);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.addEdge(5,5);
	g.addEdge(5,6);
	cout<<"No of Trees are" <<g.countTrees();
}
