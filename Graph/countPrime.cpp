
#include <bits/stdc++.h> 
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
	int bfs(int s,int end){
		int visited[v];
		memset(visited,0,sizeof(visited));
		visited[s]=1;
		list<int> queue;
		queue.push_back(s);
		list<int>::iterator it;
		while(!queue.empty()){
		
			int p=queue.front();
			queue.pop_front();
			
			for(it=adj[p].begin(); it!=adj[p].end(); it++){
				if(!visited[*it]){
					visited[*it] = visited[p] +1;
					queue.push_back(*it);
				}
				if(*it==end){
					return visited[*it] -1;
				}
			}
		}
		
	}
};
bool compare(int n1,int n2){
	string s1=to_string(n1);
	string s2=to_string(n2);
	int c=0;
	if(s1[0]!=s2[0])
		c++;
	if(s1[1]!=s2[1])
		c++;
	if(s1[2]!=s2[2])
		c++;
	if(s1[3]!=s2[3])
		c++;
	return (c==1);
}
void putPrime(vector<int> &V){

	int n=9999;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	
	for(int p=2;p*p<=n;p++){
		
		if(prime[p]==true){
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(int p=1000;p<=n;p++)
		if(prime[p])
			V.push_back(p);
	
}

int shortestPath(int num1, int num2){
	vector<int> pset;
	putPrime(pset);
	Graph g(pset.size());
	
	for(int i=0;i<pset.size();i++)
		for(int j=i+1; j<pset.size(); j++)
			if(compare(pset[i],pset[j]))
				g.addEdge(i,j);
				
				
	int in1,in2;
	//cout<<pset.size();
	for(int i=0; i<pset.size(); i++){
		if(pset[i]==num1)
			in1=i;
	}
	for(int i=0; i<pset.size(); i++){
		if(pset[i]==num2)
			in2=i;
	}
	
	return g.bfs(in1,in2);
}

int main() 
{ 
    int num1 = 1033, num2 = 8179; 
    cout << shortestPath(num1, num2); 
    return 0; 
} 
