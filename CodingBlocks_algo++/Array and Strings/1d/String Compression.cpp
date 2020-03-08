#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char S[100];
	cin>>S;
	int count = 1;
	cout<<S[0];
	for(int i=1;i<strlen(S);i++){
		if(S[i]==S[i-1]){
			count++;
		}
		else{
			cout<<count<<S[i];
			count = 1;

		}
	}
    cout<<count;
	return 0;
}