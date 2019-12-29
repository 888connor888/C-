#include<iostream>
using namespace std;

void readMatrix(int mat[][10],int R,int C){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>mat[i][j];
		}
	}
}
void printMatrix(int mat[][10],int R,int C){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	int R,C;
	cin>>R>>C;
	int mat[10][10];
	readMatrix(mat,R,C);
	printMatrix(mat,R,C);
}