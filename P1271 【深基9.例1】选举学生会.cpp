#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;cin>>n>>m;
	vector<int> a(m);
	for(int i = 0;i < m;i ++)cin>>a[i];
	//用vector吧还是
	sort(a.begin(),a.end());
	for(int i = 0;i < m;i ++)cout<<a[i]<<" ";
	return 0;
}