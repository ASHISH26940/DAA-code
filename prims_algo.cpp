#include<iostream>
#include<climits>
#include<fstream>
using namespace std;
int graph[10][10];
int n;

void readGraph(){
	fstream infile;
	infile.open("prim.txt",ios::in);
	if(!infile){
		cout<<("\nError to open the file\n");
		exit(1);
	}
	infile>>n;
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			infile>>graph[i][j];
		}
	}
	infile.close();	
}
void showGraph(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%3d",graph[i][j]);
		}
		printf("\n");
	}
}
int minkey(int key[],bool mstSet[]){
	int min=INT_MAX,min_index;
	for(int i=0;i<n;++i){
		if(mstSet[i]==false && key[i]<min){
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}
void printMST(int parent[]){
	int mincost=0;
	cout<<"Edge\t Weight\n";
	for(int i=1;i<n;++i){
		cout<<parent[i]<<"-"<<i<<"\t  "<<graph[i][parent[i]]<<"\n";
		mincost+=graph[i][parent[i]];
	}
	cout<<"Mincost: "<<mincost<<"\n";
}
void primMST(){
	int parent[n];
	int key[n];
	bool mstSet[n];
	for(int i=0;i<n;++i){
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(int count=0;count<n-1;++count){
		int u=minkey(key,mstSet);
		mstSet[u]=true;
		for(int v=0;v<n;++v){
			if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v]){
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	printMST(parent);
}
int main(){
	readGraph();
	showGraph();
	primMST();
	return 0;
}
