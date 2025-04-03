#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
const ll inf = 4e18;
ll a[N],prefix[N],dp[N][N];
//因为区间长度为1的不用合并，区间长度从2开始
//len-1是因为i作为开头，区间为len的框框移动len个单位，以此确定j为i + len - 1 
//k就是在长度里面去遍历，i是开头，j是结尾
//两个子堆合成的代价+两个子堆拿来合成的代价
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//堆数
	int n;cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	for(int i = 1;i <= n;i ++)prefix[i] = prefix[i - 1] + a[i];
	//区间dp
	for(int len = 2;len <= n;len ++){
		for(int i = 1,j = i + len - 1;j <= n;i ++,j ++){
			dp[i][j] = inf;
			//这里起点是i
			for(int k = i;k < j;k ++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
			}
		}
	}	
	cout<<dp[1][n]<<'\n';
	return 0;
}