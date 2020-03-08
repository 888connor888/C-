/*#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int k;
	char str[100000];
	cin>>k;
	cin>>str;
    while(k--){
	for(int i=1;i<strlen(str);i++){
		if(str[i]!=str[0])
		str[i] = str[0];
	}
	int count = 0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]==str[0])
			count++;
		else
			break;
	}
	cout<<count<<endl;
	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define SQ(a) (a)*(a)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long int 
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    int k;
    cin >> k;
    string str;
    cin >> str;
    int freq[2] = {0};
    ll n = str.length();
    ll ans = 0, left = 0;
    for (ll i = 0; i < n; i++)
    {
        char temp = str[i];
        freq[temp - 'a']++;
        if (min(freq[0], freq[1]) > k)
        {
            freq[str[left] - 'a']--;
            left++;
        }
        else 
            ans++;
    }
    cout << ans << endl;
    return 0;
}