#include <iostream>
#include<climits>
using namespace std;

#define max 20

int M[max][max];
int S[max][max];

void pop(int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else{
        printf("(");
        pop(i,S[i][j]);
        pop(S[i][j]+1,j);
        printf(")");
    }
}

void matrixchain(int P[],int n,int M[][max],int S[][max]){
    for(int i=1;i<=n;i++)
    {
        M[i][i]=0;
    }

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<n-len+1;i++)
        {
            int j=i+len-1;
            M[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int cost=M[i][k]+M[k][j]+P[i-1]*P[j]*P[k];
                if(cost<M[i][j])
                {
                    M[i][j]=cost;
                    S[i][j]=k;
                }
            }
        }
    }
}

void printM(int n, int M[][max]) {
    cout << "M table for the chain matrix multiplication\n";
    cout << "===========================================\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << M[i][j] << "\t";
        }
        cout << "\n";
    }
}

void printS(int n, int S[][max]) {
    cout << "S table for the chain matrix multiplication\n";
    cout << "===========================================\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << S[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    int P[MAX_SIZE];

    cout << "Enter the number of matrices: ";
    cin >> n;
    cout<<"====================================================================================================================\n";
	cout<<"Remember the number of elements in  the p array is always 1 greater than the number of matrices u give as an input\n";
	cout<<"====================================================================================================================\n";
    cout << "Enter the dimensions of matrices (space-separated): ";
    for (int i = 0; i <= n; ++i) {
        cin >> P[i];
    }

    matrixchain(P, n, M, S);
    
    cout << "\nMinimum cost of multiplication is: " << M[1][n] << endl;
    cout << "Optimal Parenthesization: ";
    pop(1, n);
    cout << endl;

    cout << "\nM Table:\n";
    printM(n, M);

    cout << "\nS Table:\n";
    printS(n, S);

    return 0;
}
