#include<iostream>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void PrintKeypadStrings(char *input,char *output,int i,int j){
	// Base Case
    if(input[i]=='\0'){
    	output[i]='\0';
    	cout<<output<<endl;
    	return;
    }

    // Recursive Case
    int digit=input[i]-'0';
    if(digit==1||digit==0){
    	PrintKeypadStrings(input,output,i+1,j+1);
    }
    for(int k=0;keypad[digit][k]!=0;k++){
    	output[j]=keypad[digit][k];
    	PrintKeypadStrings(input,output,i+1,j+1);
    }
}

int main(){
	char input[100];
	char output[100];
	cin>>input;

	PrintKeypadStrings(input,output,0,0);
    return 0;
}