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
	void addEdge(int v, int w){
		adj[v].push_back(w);
	}
	int countPaths(int s, int d){
		int count=0;
		countUtil(s,d,count);
		return count;
	}
	void countUtil(int s,int d,int &count){
		if(s==d)
			count++;
		else{
			list<int>::iterator it;
			
			for(it=adj[s].begin();it!=adj[s].end();it++){
				countUtil(*it,d,count);	
			}
		}
	}

};

int main(){
	 Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(2, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 4); 
  
    int s = 0, d = 3; 
    cout << g.countPaths(s, d); 
}
