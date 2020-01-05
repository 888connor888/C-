
/* say,input:N=1000000000 and M=10101,i=2,j=6
       output: 10001010100
*/


#include<iostream>
using namespace std;

int clearRangeItoJ(int n,int i,int j){
    int a=((~0)<<(j+1));
    int b=((1<<i)-1);
    int mask= (a|b) ;
    return (n&mask); 
}

int replaceBits(int n,int m,int i,int j){
	int n_=clearRangeItoJ(n,i,j);
	return (n|(m<<i));
}



int main(){
	int n,m,i,j;
	cin>>n>>m>>i>>j;
	cout<<"The new formed number is:"<<replaceBits(n,m,i,j)<<endl;


}