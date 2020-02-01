#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number){
	// Checking along the row and column
	for(int x=0;x<n;x++){
		if(mat[x][j]==number || mat[i][x]==number){
			return false;
		}
	}

	// checking in the sub-grid
    int rn= sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++){ // sx + rn is the length of the sub-grid.
    	for(int y=sy;y<sy+rn;y++){
    		if(mat[x][y]==number){
    			return false;
    		}
    	}
    }

    // Finally 
    return true;
}

bool solvesudoku(int mat[][9],int i,int j,int n){ 
	// Base Case
	if(i==n){
		// Print the Matrix
        for(int x=0;x<n;x++){
        	for(int y=0;y<n;y++){
        		cout<<mat[x][y]<<" ";
        	}
        	cout<<endl;
        }
		return true;
	}

    // Recursive cases
	// Case row end
	if(j==n){
		return solvesudoku(mat,i+1,0,n);
	}
	// skip the pre filled cells
	if(mat[i][j]!=0){
		return solvesudoku(mat,i,j+1,n);
	}
    // Fill the current cell with possible options
    for(int number=1;number<=n;number++){
    	if(canPlace(mat,i,j,n,number)){
    		// Assume
    		mat[i][j]=number;

    		bool couldwesolve= solvesudoku(mat,i,j+1,n);
    		if(couldwesolve==true){
    			return true;
    		}
    	}
    }
    // Backtrack here
    mat[i][j]=0;
    return false;
}


int main(){
	int mat[9][9]=
	{
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}

	};
    solvesudoku(mat,0,0,9);
    return 0;
}