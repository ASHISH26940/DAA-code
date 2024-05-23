#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct knap{
    int profit;
    int weight;
    double ratio;
};

bool compare(knap a,knap b)
{
   return a.profit>b.profit;
}

void knsp(knap arr[],int W,int n)
{
    double tP=0.0;
    double rW=W;
    vector<double> fraction(n,0.0);
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<rW)
        {
            tP+=arr[i].profit;
            rW-=arr[i].weight;
            fraction[i]=1.0;
        }else if(rW>0){
            fraction[i]=rW/arr[i].weight;
            tP+=fraction[i]*arr[i].profit;
            cout<<"Take the item : "<<fraction[i]*arr[i].profit<<" profit of the item : "<<char(i+'A')<<endl;
            rW=0;
        }
    }
    cout<<"Total profit : "<<tP<<endl;
    cout<<"The fractions of items taken are: {";
    for(int i=0;i<n;i++)
    {
        cout<<fraction[i];
        if(i!=n-1)
        {
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}


void display(knap arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout <<"item "<<char(i+'A')<< "(" << arr[i].profit << ", " << arr[i].weight << ", " << arr[i].ratio << ")" << "\t";
    }
    cout << endl;
}

int main()
{
    int n,W;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    knap arr[n];

    cout << "Enter the profits for each item: ";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].profit;
    }

    cout<<"Enter theweights for each items : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].weight;
        arr[i].ratio=arr[i].profit/arr[i].weight;
    }

    sort(arr,arr+n,compare);

    display(arr,n);

    knsp(arr,W,n);

    return 0;
}
