#include<iostream>
using namespace std;

void SubSets(char *input,char *output,int i,int j){
	// Base Case
	if(input[i]=='\0'){
		output[j]='\0';
		cout<<output<<endl;
		return;
	}

	// Recursive Case
	// 1.Include current character
	output[j]=input[i];
	SubSets(input,output,i+1,j+1);
	// 2.Exclude the current character
	SubSets(input,output,i+1,j);
}

int main(){
	char input[100];
	cin>>input;
	char output[100];
    SubSets(input,output,0,0);
	return 0;
}