#include<iostream>
using namespace std;

void preProcess(int **arr,int **aux,int N,int M){
	 // Copy first row of mat[][] to aux[][] 
   for (int i=0; i<N; i++) 
      aux[0][i] = arr[0][i]; 
  
   // Do column wise sum 
   for (int i=1; i<M; i++) 
      for (int j=0; j<N; j++) 
         aux[i][j] = arr[i][j] + aux[i-1][j]; 
  
   // Do row wise sum 
   for (int i=0; i<M; i++) 
      for (int j=1; j<N; j++) 
         aux[i][j] += aux[i][j-1]; 
}

int sumQuery(int **aux,int tli,int tlj,int bri,int brj){
    int v=aux[bri][brj];
    int p=aux[tli-1][brj];
    int q=aux[bri][tlj-1];
    int r=aux[tli-1][tlj-1];
    // Initialize res with prefix of (bri,brj)
    int res=v;
    if(tli>0){
    	res=res-p;
    }
    if(tlj>0){
        res=res-q;
    }
    if(tli>0 && tlj>0){
    	res=res+r;
    }
    return res;
}


int main(int argc,char *argv[]){
	int n,m;
	cin>>n>>m;
	int **arr= new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[m];
	}
	int **aux= new int*[n];
	for(int i=0;i<n;i++){
		aux[i]=new int[m];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			aux[i][j]=0;
		}
	}
	preProcess(arr,aux,n,m);

	cout<<"The sum of sub matrix is:"<<sumQuery(aux,1,2,3,3)<<endl;

	return 0;
}