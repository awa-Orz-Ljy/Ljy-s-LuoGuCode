#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;

ll a[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++){
		if(i > 1)cout<<" ";
		cout<<a[i];
	}
	return 0;
}