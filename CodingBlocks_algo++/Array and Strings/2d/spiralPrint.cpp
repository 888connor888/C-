#include <iostream>
#include<iostream>
using namespace std;

void initMatrix(int mat[][10],int R,int C){
	int value=1;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			mat[i][j]=value++;
		}
	}
}

void spiralPrint(int a[][10],int R,int C){
	int startRow=0,endRow=R-1,startCol=0,endCol=C-1;
	while(startRow<=endRow && startCol<=endCol){

		//Print start row first
		for(int i=startCol;i<=endCol;i++){
			cout<<a[startRow][i]<<" ";
		}
		startRow++;

		//Print endCol

        for(int j=startRow;j<=endRow;j++){
        	cout<<a[j][endCol]<<" ";
        }
        endCol--;


		//Print endRow
        if(endRow>startRow){
		for(int i=endCol;i>=startCol;i--){
			cout<<a[endRow][i]<<" ";
		}
		endRow--;
		 }


		//Print startCol
		if(startCol<endCol){
		for(int j=endRow;j>=startRow;j--){
			cout<<a[j][startCol]<<" ";
		}
		startCol++;
		}

	}
}

int main(){
	int R,C;
	cin>>R>>C;
	int mat[10][10];
	initMatrix(mat,R,C);
	//cout<<"Enter the Key element to search for:";
	//cin>>Key;
	//staircaseSearch(mat,R,C,Key);
	for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
         cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
    }
	spiralPrint(mat,R,C);


}
