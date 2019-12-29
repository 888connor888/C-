#include<iostream>
using namespace std;
int factorial(int num){
	if(num==1){
		return 1;
	}
	else{
	return num*factorial(num-1);
    }
}
int combination(int n,int r){
	return factorial(n)/(factorial(r)*factorial(n-r));
}
int main(){
	cout<<combination(5,2)<<endl;
}