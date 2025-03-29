#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100;

ll a[N],dp[N][N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;cin>>n>>m;
	//dp[0][0] = 1表示不使用任何花摆0盆花的方案数为1，作为动态规划的初始状态
	dp[0][0] = 1;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	//线性dp,第i种花放了j盆，k用来遍历，所以前者取1后者都要
	// 外层循环 i 从 1 到 n，代表依次考虑使用前 1 种、前 2 种、...、前 n 种花来摆花
    // 因为要从第一种花开始考虑，所以 i 从 1 开始
    
    // 中层循环 j 从 0 到 m，代表使用前 i 种花摆 0 盆、1 盆、...、m 盆花的不同情况
    // 可以摆 0 盆花，所以 j 从 0 开始
    
    // 内层循环 k 从 0 到 min(j, a[i])，代表第 i 种花摆放的盆数
    // 第 i 种花可以不摆（k = 0），也可以摆 1 盆、2 盆、...，最多摆 min(j, a[i]) 盆
    // 这里取 min(j, a[i]) 是因为总盆数不能超过 j，且不能超过第 i 种花的最大可摆放盆数 a[i]
	for(int i = 1;i <= n;i ++){
		for(ll j = 0;j <= m;j ++){
			for(int k = 0;k <= min(j,a[i]);k ++){
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]);
			}
		}
	}
	// 最终结果为使用 n 种花摆 m 盆花的方案数
	cout<<dp[n][m]<<endl;
	
	return 0;
}