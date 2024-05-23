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

class Stack
{
    int top;
    int a[max];
public:
    Stack()
    {
        top=-1;
    }
    void push(int item){
        a[++top]=item;
    }
    void pop()
    {
        top--;
    }
    int peek()
    {
        return a[top];
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
int vis[max]={0};
void BFS(int v)
{
    Stack s;
    s.push(v);
    vis[v]=1;
    while(!s.isEmpty())
    {
        int temp=s.peek();
        s.pop();
        printf("%3c",temp+'A');
        for(int i=0;i<n;++i)
        {
            if(graph[temp][i]==1 && vis[i]==1)
            {
                s.push(i);
                vis[i]=1;
            }
        }
    }
}