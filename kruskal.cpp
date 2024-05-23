#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
struct Edge{
	int vertex1;
	int vertex2;
	int weight;
};
int noe =0;
Edge e[100];
int n;

void readGraph(){
	fstream infile;
	infile.open("kruskal.txt",ios::in);
	if(!infile){
		cout<<("\nError to open the file\n");
		exit(1);
	}
	infile>>n;
	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){
			int w;
			infile>>w;
			if(w!=0){
				e[noe].vertex1=j;
				e[noe].vertex2=i;
				e[noe++].weight=w;
			}
		}
	}
	infile.close();
}

void bubblesort(){
	for(int i=0;i<noe-1;++i){
		for(int j=0;j<noe-i-1;++j){
			if(e[j].weight>e[j+1].weight){
				Edge temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}
}
void showGraph(){
	for(int i=0;i<noe;++i){
		printf("(%c , %c)-->%d\n",e[i].vertex1+'A',e[i].vertex2+'A',e[i].weight);
	}
}

int parent[100];
void makeSet(int v){
	parent[v]=-1;
}
int find(int v){
	while(parent[v]>=0) v=parent[v];
		return v;
}
void showParent(){
	for(int i=0;i<n;++i){
		printf("parent[%d]= %d\n",i,parent[i]);
	}
}
void simpleUnion(int i,int j){
	parent[j]=i;	
}
int treeEdge[100][2];
int no_tree_edge=0;
int cost=0;
void mst_Kruskal(){
	for(int i=0;i<n;++i)
		makeSet(i);
		showParent();
		bubblesort();
		for(int i=0;i<noe;++i){
			int u=find(e[i].vertex1);
			int v=find(e[i].vertex2);
			printf("%c %c \n",u+'A',v+'A');
			if(u!=v){
				simpleUnion(u,v);
				treeEdge[no_tree_edge][0]=e[i].vertex1;
				treeEdge[no_tree_edge++][1]=e[i].vertex2;
				cost+=e[i].weight;
			}
		}
}
void showTree(){
	for(int i=0;i<no_tree_edge;++i)
		printf("(%c,%c)\t",treeEdge[i][0]+'A',treeEdge[i][1]+'A');
	cout<<"\n Total cost = "<<cost;
}
int main(){
	readGraph();
	//showGraph();
	bubblesort();
	showGraph();
	mst_Kruskal();
	cout<<"The edges in consideration:\n";
	showTree();
return 0;
}

