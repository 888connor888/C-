#include<iostream>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int max=x^y,a[y-x];
	int subSets=(1<<(y-x)) -1;
	int count=0;
	while(x<=y){
       a[count]=x;
       x++;
	}
	for(int i=0;i<subSets;i++){
		int countBits=__builtin_popcount(i);
		int b[2]={0};
		if(countBits==2){
          for(int j=0;j<=63;j++){
          	if(i&(1<<j){
               
	        }      
	      }
	    }
	} 
	
	
	cout<<max<<endl;
}