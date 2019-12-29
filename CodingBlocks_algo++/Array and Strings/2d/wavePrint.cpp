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

void wavePrint(int mat[][10],int R,int C){
    // Iterate over columns
    for(int j=0;j<C;j++){
        // you can for odd and even columns
        if(j&1){
        	// odd column (as & of a binary odd no. gives 001)
            for(int i=R-1;i>=0;i--)
                cout<<mat[i][j]<<"\t";
        }
        else{
        	// even column
            for(int i=0;i<C;i++)
               cout<<mat[i][j]<<"\t";
        }
    }
}

int main(){
	int R,C;
	cin>>R>>C;
	int mat[10][10];
	readMatrix(mat,R,C);
	//printMatrix(mat,R,C);
	wavePrint(mat,R,C);
	// The output of wave print is supposed to be in a single line
	return 0;
}