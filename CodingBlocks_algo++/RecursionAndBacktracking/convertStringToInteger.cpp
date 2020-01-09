#include<bits/stdc++.h>
using namespace std;

int convertString(char *s,int n){
	if(n==1){
      return 0;
	}
	return    (s[0]-'0')*pow(10,n-2) + convertString(s+1,n-1);
}

int main(){
	char s[]={'1','2','3','4','5','\0'};
	int n=sizeof(s)/sizeof(char);
	cout<<convertString(s,n)<<endl;
	return 0;
}