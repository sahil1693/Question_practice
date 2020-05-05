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
	void heightBFS(int s){
		cout<<"Height of the tree is ";
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
				//cout<<s<<" "<<level<<endl;
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
		cout<<level-1;
	}
	
};
int main(){
	int n=8;
	int arr[]={-1,0,0,0,3,1,1,2};
	Graph g(n);
	int start=0;
	for(int i=0;i<n;i++){
		if(arr[i]==-1)
			start=i;
		else
			g.addEdge(i,arr[i]);
	}
	
	g.heightBFS(start);
}
