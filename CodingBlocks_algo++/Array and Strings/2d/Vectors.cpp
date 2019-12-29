#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
     // Remove an element from the back
    v.pop_back();
    sort(v.begin(),v.end());
    // print the elements
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
   
   
    
   
    return 0;

}
