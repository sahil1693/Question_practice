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
		adj[m].push_back(v);
	}
	void levelBFS(int s){
		cout<<"Node " << " Node"<<endl;
		bool visited[v]={false};
		list<int> queue;
		visited[s]=true;
		int min=-65535;
		queue.push_back(s);
		queue.push_back(min);
		int level=0;
		while(!queue.empty()){
			s=queue.front();
			queue.pop_front();
			if(s!=min){
				cout<<s<<" "<<level<<endl;
			} 
			if(s==min){
				if(!queue.empty())
					queue.push_back(min);
				level++;
				
			}
			else{
				list<int>::iterator it;
				for(it=adj[s].begin();it!=adj[s].end();it++){
					if(visited[*it]==false){
						visited[*it]=true;
						queue.push_back(*it);
					}
				}
			}
			
		}
	}
	
};
int main(){
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(2,5);
	g.addEdge(2,6);
	g.addEdge(6,7);
	
	g.levelBFS(0);
}
