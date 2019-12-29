
// check whether two strings are permutations of each other.

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


bool checkString(char *a,char *b){
	int l1=strlen(a);
	int l2=strlen(b);
	int freq[26]={0};
	if(l1!=l2)
		return false;
	// Iterate over a
    for(int i=0;i<26;i++)
	    freq[a[i]-'a']++;
	// Iterate over b
	for(int j=0;j<26;j++)
		freq[b[j]-'a']--;
	// Finally check if the freq are all zero
	for(int i=0;i<26;i++){
		if(freq[i]==0)
	    	return false;
		}
	return true;
	
}

int main(){
	char a[100],b[100];
	cin>>a>>b;
	if(checkString(a,b))
		cout<<"The strings are Permutations of each other"<<endl;
	else
		cout<<"NO!"<<endl;
	return 0;
}