#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int k;
	cin>>k;
	while(k--){
        char num1[100],num2[100];
		cin>>num1>>num2;
		for(int i=0;i<strlen(num1);i++){
			if(num1[i]==num2[i]) cout<<0;
			else cout<<1;
		}
		cout<<endl;
	}
	return 0;
}