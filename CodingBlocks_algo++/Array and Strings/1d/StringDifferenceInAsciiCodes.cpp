#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char S[1000];
	cin>>S;

	for(int i=0;i<strlen(S);i++){
		cout<<S[i];
        if(i==strlen(S)-1)
        break;
		cout<<int(S[i+1]-S[i]);
	}
	return 0;
}