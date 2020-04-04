#include<iostream>
#include<cstring>
using namespace std;

bool Check_CB_number(int num){
	int list[] = {2,3,5,7,11,13,17,19,23,29};
	if(num==1||num==0){
		return false;
	}
	for(int i=0;i<10;i++){
		if(num%list[i]!=0) return true;
		else return false;
	}  
}

int main(){
	char num[17];
	int string_size;
	cin>>string_size>>num;
	
}