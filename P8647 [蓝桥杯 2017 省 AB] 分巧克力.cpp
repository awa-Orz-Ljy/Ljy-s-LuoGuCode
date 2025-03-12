#include<bits/stdc++.h>
using namespace std;
const N = 1e5 + 10;
int n,a[N],b[N],k;

bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=(a[i]/x)*(b[i]/x);
	return cnt>=k;//符合块数要求
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int l=1,r=100000;
	while(l<r){
		int mid=(l+r+1)/2;//+1防止死循环
		if(check(mid)) l=mid;//cnt≥k，答案太大，缩小区间到右边
		else r=mid-1; //答案太小，缩小区间到左边，且mid不用
	}
	cout<<l;
    return 0;
}