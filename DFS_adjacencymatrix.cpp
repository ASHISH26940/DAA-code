#include<iostream>
#include<fstream>
#define max 10
using namespace std;
int n,graph[100][100];

void readGraph(){
	fstream infile;
	infile.open("bd_fs.txt",ios::in);
	if(!infile){
		cout<<"Error openning the file."<<endl;
		exit(1);
	}
	infile>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
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
class Stack{
	int arr[max];
	int top;
	public:
		Stack(){
			top=-1;
		}
		void push(int item){
			arr[++top]=item;
		}
		void pop(){
			top--;
		}
		int peek(){
			return arr[top];
		}
		int isEmpty(){
			if(top==-1)
				return 1;
			return 0;
		}
		int isFull(){
			if(top==max-1)
				return 1;
		}
};
int visited[max]={0};
void DFS(int v){
	Stack s;
	s.push(v);
	visited[v]=1;
	cout<<"========="<<endl;
	cout<<"  DFS "<<endl;
	cout<<"========="<<endl;
	while(!s.isEmpty()){
		int u=s.peek();
		s.pop();
		printf("%3c",u+'A');
		for(int i=0;i<n;++i){
			if(graph[u][i]==1){
				if(visited[i]==0){
					s.push(i);
					visited[i]=1;
				}
			}
		}
	}
	
}
int main(){
	readGraph();
	showGraph();
	DFS(0);
	return 0;
}
