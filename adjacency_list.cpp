#include<iostream>
#include<fstream>
using namespace std;
int n;
int graph[100][100];
struct Node{
	int vertex;
	Node *next;
};
struct Node *head[10]={NULL};
void insert(int i,int j){
	Node *curr=new Node;
	curr->vertex=j;
	curr->next=NULL;
	if(head[i]==NULL){
		head[i]=curr;
		return;	
	}
	else{
		Node *temp=head[i];
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=curr;
	}	
}
void createadjacentlist(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(graph[i][j]==1){
				insert(i,j);
			}
		}
	}	
}
void displaylist(){
	for(int i=0;i<n;++i){
		Node *temp=head[i];
		cout<<"The adjacent vertex of "<<char(i+'A')<<" is :";
		while(temp!=NULL){
			cout<<char(temp->vertex +'A')<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}
void readGraph(){
	fstream infile;
	infile.open("a.txt",ios::in);
	if(!infile){
		cout<<"Error openning the file"<<endl;
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
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
int numdegree(){
	int count=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(graph[i][j]==1)
				count++;
		}
	}
	return count;
}
int main(){
	readGraph();
	showGraph();
	int p=numdegree();
	cout<<"The total degree of vertices :"<<p<<endl;
	cout<<"The total no of edges :"<<p/2<<endl;
	createadjacentlist();
	displaylist();
	return 0;
	
}
