#include<iostream>
#include<cstring>
using namespace std;

void magical_park(char park[][100],int M,int N,int K,int S){
	// Pyush can cross the maze
	bool success = true ;

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			char ch = park[i][j];

			if(S<K){
				success = false;
				break;
			}
			if(ch=='.') S -= 2;
			else if(ch=='*') S += 5;
			else break;

			// we also loose 1 for traversing right except for last column
			if(j!= N-1) S--;
		}
	}

	if(success) cout<<"Yes"<<endl<<S<<endl;
	else cout<<"No"<<endl;
}



int main(){
	int N,M,K,S;
	cin>>M>>N>>K>>S;
	char ParK[100][100];
	for(int i=0;i<N;i++)
		cin>>ParK[i];
	magical_park(ParK,M,N,K,S);
	return 0;
}