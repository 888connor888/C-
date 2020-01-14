#include<iostream>
using namespace std;

#define N 30
#define M 30

int  MatrixSearch(int a[N][M],int n,int m,int Key){
	//Initially
	int row=0,column=m-1;
	while(column>=0 && row<n){
		if(a[row][column]==Key){
			return 1;
		}
		else if(a[row][column]>Key){
			column--;
		}
		else{
			row++;
		}
	}
	return 0;
}

int main(){
	int n,m;
	int a[N][M];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int Key;
	cin>>Key;
	cout<<MatrixSearch(a,n,m,Key)<<endl;
    return 0;
}