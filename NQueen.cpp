#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
int **arr;
int ans=0;

bool canplace(int row,int column){
	int i,j;
	for(int i=0;i<N;i++){
		if(arr[i][column]==1)
			return false;
		if(arr[row][i]==1)
			return false;
	}
	i=row;
	j=column;
	while(i<N && j>=0){
		if(arr[i][j]==1)
			return false;
		i++;
		j--;
	}
	i=row;
	j=column;
	while(i>=0 && j<N){
		if(arr[i][j]==1)
			return false;
		i--;
		j++;
	}
	i=row;
	j=column;
	while(i<N && j<N){
		if(arr[i][j]==1)
			return false;
		i++;
		j++;
	}
	i=row;
	j=column;
	while(i>=0 && j>=0){
		if(arr[i][j]==1)
			return false;
		i--;
		j--;
	}
	
	return true;
}

void func(int row){
    
	if(row > N-1)
		{
		   	ans++;
			return;
		}
	for(int i=0;i<N;i++){
		if(canplace(row,i)){
		    
			arr[row][i]=1;
			func(row+1);
			arr[row][i]=0;
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
			arr[i][j]=0;
		}
	}
	func(0);
	cout<<ans;
	return 0;
}