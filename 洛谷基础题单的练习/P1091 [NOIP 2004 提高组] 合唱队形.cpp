#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int dp1[N],dp2[N],a[N];
int ans = -1;

int main(){
	int n;cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	//最长上升子序列长度
	for(int i = 1;i <= n;i ++){
		for(int j = 0;j < i;j ++){
			//接上，所以要+1
			if(a[j] < a[i])dp1[i] = max(dp1[i],dp1[j] + 1); 
		}
	}
	//最长下降子序列长度
	for(int i = n;i > 0;i --){
		for(int j = n + 1;j > i;j --){
			//接上，所以要+1
			if(a[j] < a[i])dp2[i] = max(dp2[i],dp2[j] + 1); 
		}
		//更新队列的长度
		for(int i = 1;i <= n;i ++)ans = max(dp1[i] + dp2[i] - 1,ans);
	}
	cout<<n - ans;
	return 0;
}