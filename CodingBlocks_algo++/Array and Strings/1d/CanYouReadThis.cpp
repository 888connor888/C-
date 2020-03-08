#include<iostream>
using namespace std;

int main(){
	char string[1001];
	cin>>string;
	int i = 0;
	while(string[i] != '\0'){
			cout<<string[i];
			if(string[i+1]>='A' && string[i+1]<='Z'){
				cout<<endl;
			}
            i++;
	}
	return 0;
}