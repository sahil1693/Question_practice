#include<iostream>
#include<vector>
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
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool DFSUtil(int s, vector<bool> &visited, vector<int> &vdegree, int k){
	
		visited[s]=true;
		list<int>::iterator it;
		
		for(it=adj[s].begin();it!=adj[s].end();it++){
			if(vdegree[s] < k)
				vdegree[*it]--;
			if(!visited[*it]){
				if(DFSUtil(*it,visited,vdegree,k)){
					vdegree[v]--;
				}
			}
		}
		return vdegree[s] < k;
	}
	void printCores(int k){
		
		vector<bool> visited(v,false);
		
		int min=65535;
		int start;
		vector<int> vdegree(v);
		
		for(int i=0; i<v; i++){
		
			vdegree[i] = adj[i].size();
			
			if (vdegree[i] < min)
			{
				min=vdegree[i];
				start=i;
			}
		}	
		DFSUtil(start,visited,vdegree,k);
		
		for(int i=0; i<v; i++){
		
			if(vdegree[i] >= k){
			
				cout<<"\n["<<i<<"]";
				list<int>::iterator it;
				for(it=adj[i].begin();it!=adj[i].end(); it++)
					if(vdegree[*it] >=k)
						cout<<" -> "<<*it;
			}
		}
	}
	
};
int main(){

	int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.printCores(k); 
  
    cout << endl << endl; 
}
