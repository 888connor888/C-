#include<iostream>
#include<cstring>
using namespace std;

char* mystrtok(char str[],char delim){
	static char* input=NULL;
	if(str!=NULL){
		input=str;
	}
    if(input==NULL){
        return NULL;
    }
	char *output= new char[strlen(input)+1];// +1 for \0
    int i;
	for( i=0;input[i]!='\0';i++){
		if(input[i]!=delim){
			output[i]=input[i];
		}
		else{
			// you are at delim
			output[i]='\0';
			input=input+i+1;
			return output;
		}
	}
	// out of the loop
	output[i]='\0';
	input=NULL;
	return output;
}


int main(){
    char str[]=" Hi, I am teaching about strings,in c++";
    char *ptr=strtok(str," ,");
    //cout<<ptr<<endl;
    while(ptr!=NULL){
        cout<<ptr<<endl;
        ptr=strtok(NULL," ,");
    }
    char *ptr2=mystrtok("Hello Coding Blocks",' ');
    //cout<<ptr<<endl;
    while(ptr!=NULL){
        cout<<ptr2<<endl;
        ptr2=mystrtok(NULL,' ');
    }
}