#include<iostream>
#include<fstream>
#define max 100
using namespace std;
int n,graph[10][10];
void readGraph(){
	fstream infile;
	infile.open("bd_fs.txt",ios::in);
	if(!infile){
		cout<<"Error openning the file "<<endl;
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
class Queue{
	int arr[max];
	int front;
	int rear;
	public:
		Queue(){
			front=rear=-1;
		}
		int isEmpty(){
			if(front==rear)
				return 1;
			return 0;
		}
		int isFull(){
			if(rear==max-1){
				return 1;
			}
		}
		void insert(int item){
			rear++;
			arr[rear]=item;
		}
		void del(){
			front++;
		}
		int peek(){
			return arr[front+1];
		}
};
int visited[max]={0};
void BFS(int v){
	Queue q;
	q.insert(v);
	visited[v]=1;
	cout<<"============"<<endl;
	cout<<"   BFS  "<<endl;
	cout<<"============"<<endl;
	while(!q.isEmpty()){
		int u=q.peek();
		q.del();
		printf("%3c",u+'A');
		for(int i=0;i<n;++i){
			if(graph[u][i]==1){
				if(visited[i]==0){
					q.insert(i);
					visited[i]=1;
				}
			}
		}
	}	
}
int main(){
	readGraph();
	showGraph();
	BFS(0);
	return 0;
}
