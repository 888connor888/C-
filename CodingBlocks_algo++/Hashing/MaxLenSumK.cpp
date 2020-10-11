#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int LongestSumK(vector<int> v,int k){
	unordered_map<int,int> prefix;
	int sum = 0,max_length = 0;
	prefix.insert(make_pair(sum,-1));
	for(int i = 0;i<v.size();i++){
		sum += v[i];
		if(prefix.find(sum-k)!=prefix.end()){
			max_length = max(max_length,(i-prefix[sum-k]));
		}
		else{
			prefix[sum] = i;
		}
	}
    return max_length;
}

int main(){
	#ifndef ONLINE_JUDGE
	  freopen("Input.txt", "r", stdin);
	  freopen("Output.txt", "w", stdout);
    #endif
    vector<int> v;
    int no,k;
    cin>>k;
    while(scanf("%d",&no)!=EOF){
    	v.push_back(no);
    }
    // cout<<LargestSubarray(v)<<endl;
    // cout<<LongestSumK(v,k)<<endl;
    cout<<LongestConsecutiveSubsequence(v)<<endl;
	return 0;
}