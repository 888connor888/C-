#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int LengthSubArray(vector<int> v){
	unordered_map<int,int> m;
	int sum = 0,max_length=0;
	for(int i=0;i<v.size();i++){
		sum += v[i];
		if(v[i]==0 and max_length == 0){
			max_length = 1;
		}
		if(sum == 0){
			max_length = i + 1;
		}
		if(m.find(sum)!=m.end()){
			max_length = max((i - m[sum]),max_length); 
		}
		else{
			m[sum]=i;
		}
	}
	return max_length;
}

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("In.txt", "r", stdin);
	  freopen("Out.txt", "w", stdout);
    #endif
    vector<int> v;
    int no;
    while(scanf("%d",&no)!=EOF){
    	v.push_back(no);
    }
    cout<<" Lenght "<<LengthSubArray(v)<<endl;
	return 0;
}