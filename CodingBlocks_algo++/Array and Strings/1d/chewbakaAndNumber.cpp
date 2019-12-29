#include<iostream>
using namespace std;
int main(){
	char number[10];
	int digit=0;
    cin>>number;
    int i=0;
    if(number[i]=='9'){
    	i++;
    }
    // Iterate over the remaing chars
    for(;number[i]!='\0';i++){
        digit=number[i]-'0';// convert char to int to perform arthmatic operations
        if(digit>=5){
        	digit= 9 - digit;
        	number[i]= digit + '0';// convert int to char
        }

    }
    cout<<number<<endl;


}
