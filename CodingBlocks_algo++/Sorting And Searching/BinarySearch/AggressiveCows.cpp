#include<iostream>
#include<algorithm>
using namespace std;

bool canPlace(int a[],int n,int min_step,int c){
  int last_cow = a[0]; // place the first cow at first stall
  int cnt=1;
  for(int i=1;i<n;i++){
    if(a[i]-last_cow>=min_step){// min_step is minimum distance b/w two cows
      last_cow = a[i];
      cnt += 1;
      if(cnt==c){
        return true;
      }
    }
  }
  return false;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
  #endif
  int n,c,a[100000];
  cin>>n>>c;
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  int s=0,e=a[n-1]-a[0];
  int ans;
  while(s<=e){
    int mid = (s+e)/2;
    bool cowsRakPaye = canPlace(a,n,mid,c);
    if(cowsRakPaye){
      ans=mid;
      s=mid+1;
    }
    else e=mid-1;
  }
  cout<<ans;
  return 0;
}