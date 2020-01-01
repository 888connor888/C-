#include<iostream>
using namespace std;

bool isOdd(int n){
	return (n&1);
}

int getBit(int n,int i){
    int mask=(1<<i);
    int bit = (n&mask)>0? 1:0;
    return bit;
}

int setBit(int n,int i){
     int mask=(1<<i);
     int ans= n|mask;
     return ans;
}

void clearBit(int &n,int i){
     int mask=~(1<<i);
     n= n & mask;
}

void updateBit(int &n,int i,int v){
     int mask=~(1<<i);
     int cleared_no=n&mask;
     n=cleared_no|(v<<i);//
}

int clearLastBits(int n,int i){
    // clear from position i+1.. i is exactly the no. of bits getting cleared.
    int mask = (-1<<i+1);
    return (n&mask);
}

int clearRangeItoJ(int n,int i,int j){
    int a=((~0)<<(j+1));
    int b=((1<<i)-1);
    int mask= (a|b) ;
    return (n&mask); 
}

int main(){
int n=31;
int i,j;
cin>>i>>j;
// cout<<getBit(n,i);
//n=setBit(n,i);
//cout<<"Ans "<<n;
//clearBit(n,i);
//updateBit(n,2,0);
//updateBit(n,3,1);
//cout<<n;
// clear bits
//cout<<clearLastBits(n,i);
// clear bits in range
cout<<clearRangeItoJ(n,i,j);
}