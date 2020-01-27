#include<iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n){
	// check col
	for(int row=0;row<i;row++){
		if(board[row][j]==1){
			return false;
		}
	}

	// You can check for Left Diagonal
	int x=i;
	int y=j;

	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	// Check for the Right Diagonal
	x=i;
    y=j;

	while(x>=0 && y<n){
		if(board[x][y]==1){
			return false;
		}
        x--;
        y++;
	}

	// position is safe
	return true;
}

bool solve_N_Queen(int board[][10],int i,int n){
	// Base Case
	if(i==n){
		// You have successfully placed queens in n rows(0,...,n-1)
		//print the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout<<" Q ";
				}
				else{
					cout<<" _ ";
				}
			}
			cout<<endl;
		}
		// In the base case if we return false then we will get all possible configurations of N_Queens.
		return false;
	}

	//Recursive Case
	/* Try to place a queen in the current row 
	and call on the remaining part which will br solved by recursion*/
    for(int j=0;j<n;j++){
    	// I have to check if i,j th position is safe to place the queen or not
    	if(isSafe(board,i,j,n)){
    		// Place the queen
    		board[i][j]=1;
    		bool nextQueenRakhParahe = solve_N_Queen(board,i+1,n);
    		if(nextQueenRakhParahe){
    			return true;
    		}
    		// flow of control here means i,j is not right.
    		board[i][j]=0; // Backetrack
    	}
    }
    // You tried for all positions in the current row but could'nt place a queen.
    return false;
}

int main(){
	int n;
	cin>>n;
	int board[10][10]={0};

	solve_N_Queen(board,0,n);

}