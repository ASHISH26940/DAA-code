#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

int graph[10][10];
int n;

void readGraph( )
{
    fstream inFile;
    inFile.open("graphs.txt",ios::in);

    if(!inFile)
    {
        cout<<("\nError to open the file\n");
		exit(1);
    }
    inFile>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            inFile>>graph[i][j];
        }
    }
    inFile.close();
}

void show()
{
    cout<<"The graph is : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d",graph[i][j]);
        }
        printf("\n");
    }
}

int minKey(int key[],bool mstSet[])
{
    int min=INT_MAX,minIdx;
    for(int i=0;i<n;i++)
    {
        if(mstSet[i]==false && key[i]<min)
        {
            min=key[i];
            minIdx=i;
        }
    }
    return minIdx;
}

void printMst(int res[])
{
    int minCost=0;
    cout<<"Edge \t  Weight"<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<res[i]<<"-"<<i<<"\t"<<graph[i][res[i]]<<endl;
        minCost+=graph[i][res[i]];
    }
    cout<<"Mincost : "<<minCost<<endl;
}

void prims()
{
    int res[n];
    int key[n];
    bool mstSet[n];

    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    res[0]=-1;

    for(int i=0;i<n-1;i++)
    {
        int u=minKey(key,mstSet);

        mstSet[i]=true;

        for(int j=0;j<n;j++)
        {
            if( graph[u][j] && mstSet[j]==false && graph[u][j]<key[j])
            {
                res[j]=u;
                key[j]=graph[u][j];
            }
        }
    }
    printMst(res);
}



int main()
{
    readGraph();
    show();
    prims();
    show();
    return 0;
}