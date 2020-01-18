#include<iostream>
using namespace std;

char spellings[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void print_num(int n){
	if(n==0){
		return;
	}
	print_num(n/10);
    cout<<spellings[n%10]<<" ";
}

int main(){
	int n;
	cin>>n;
	print_num(n);
	return 0;
}