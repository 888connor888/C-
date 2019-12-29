#include<iostream>
using namespace std;

void readMatrix(int mat[][10],int R,int C){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>mat[i][j];
		}
	}
}

void staircaseSearch(int mat[][10],int R,int C,int Key){
	int i=0,j=C-1;
	// Start from mat[0][C-1]
	while(i<R && j>=0){
		if(mat[i][j]==Key){
			cout<<"The indexes of the key are:"<<i<<" "<<j<<endl;
			return;
		}
		else if(mat[i][j]>Key){
			j--;
		}
		else{
			i++;
		}	
	}
	cout<<"The element does'nt belong here"<<endl;
	return;
}

int main(){
	int R,C;
	cin>>R>>C;
	int mat[10][10];
	readMatrix(mat,R,C);
	cout<<"Enter the Key element to search for:";
	cin>>Key;
	staircaseSearch(mat,R,C,Key);


}