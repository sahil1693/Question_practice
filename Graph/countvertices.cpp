#include<iostream>
#include<list>
#include<climits>
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
		 adj[w].push_back(v); 
	}
	int BFS(int s,int level){
		bool visited[v]={false};
		list<int> queue;
		queue.push_back(s);
		queue.push_back(-65535);
		list<int>::iterator it;
		int min=-65535,count=0,levelcount=0;
		visited[s]=true;
		while(!queue.empty()){
			
			s=queue.front();
			queue.pop_front();
			if(level==levelcount && s!=min){
				count++;
			}
			if(s==min)
			{
				levelcount++;
				if(!queue.empty()){
					queue.push_back(min);
				}
			}
			else{
			for(it=adj[s].begin();it!=adj[s].end();it++){
				if(!visited[*it]){
					visited[*it]=true;
					queue.push_back(*it);
				}
			}
			}
		}
		return count;
	}
};

int main(){
	   Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 2; 
  
    cout << g.BFS(0, level); 
}
