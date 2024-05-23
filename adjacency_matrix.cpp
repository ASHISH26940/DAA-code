#include<iostream>
#include<fstream>
using namespace std;
int main(){
	fstream infile;
	infile.open("a.txt",ios::in);
//	int n,graph[100][100];
	infile>>n;
	if (!infile) {
        cout << "Error opening the file." << endl;
        exit(1);
    }
	int count=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			infile>>graph[i][j];
		}
	}
	cout<<"The adjacency matrix is:"<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<graph[i][j]<<" ";
		}
			cout<<endl;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(graph[i][j]==1){
				count++;
			}
		}
	}
	cout<<"The total degree of vertices: "<<count<<endl;
	cout<<"The total number of edges: "<<count/2<<endl;
	for(int i=1;i<=n;++i){
		cout<<"The adjacent vertex of "<<char(i+64)<<" is : ";
		for(int j=1;j<=n;++j){
			if(graph[i][j]==1)
				cout<<char(j+64)<<" ";
		}
		cout<<endl;
	}
	infile.close();
return 0;
}
