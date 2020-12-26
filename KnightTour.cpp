#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
int **arr;
int z;

int x[8] = {-1,-1,1,1,-2,-2,2,2};
int y[8] = {2,-2,2,-2,1,-1,1,-1};

bool isfull(int x){
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         if(arr[i][j]==-1)
    //             return false;
    //     }
    // }
    if(N*N == x) return 1;
    return 0;
}

bool canplace(int row,int column){
    
    if(row > N-1 || row < 0 || column > N-1 || column < 0 || arr[row][column]!=-1)
        return false;
    
    else
       return true;
}

void prt(){
	for(int i=0 ; i < N;i++){
		for(int j=0;j<N;j++) cout << arr[i][j];
		cout << "\n";
	}
	cout<<"\n";
}

void func(int row, int column,int v){
	// prt();
    if(isfull(v)){
    	prt();
    	return ;
    }
	for(int i=0;i<8 ;i++){
		if(canplace(row+x[i],column+y[i])){
			arr[row+x[i]][column+y[i]]=v;
			func(row+x[i],column+y[i],v+1);
			arr[row+x[i]][column+y[i]]=-1;
		}
	}
}

int main() {
	int n;
	cin >> n;
	N = n;
	arr	= new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];
	for(int i=0;i < n; i++){
		for(int j=0;j < n; j++){
			arr[i][j]=-1;
		}
	}
	z=0;
	arr[0][0]=0;
	func(0,0,1);
	return 0;
}