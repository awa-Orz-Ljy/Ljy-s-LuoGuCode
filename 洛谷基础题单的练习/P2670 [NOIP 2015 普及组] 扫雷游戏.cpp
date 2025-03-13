#include<bits/stdc++.h>
using namespace std;
int n,m,ans[102][102];
char a[102][102];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){//如果本身是地雷就输出
				cout<<'*';
				continue;
			}
			if(a[i-1][j]=='*')ans[i][j]++;//上
			if(a[i+1][j]=='*')ans[i][j]++;//下
			if(a[i][j-1]=='*')ans[i][j]++;//左
			if(a[i][j+1]=='*')ans[i][j]++;//右
			if(a[i-1][j-1]=='*')ans[i][j]++;//左上
			if(a[i-1][j+1]=='*')ans[i][j]++;//右上
			if(a[i+1][j-1]=='*')ans[i][j]++;//左下
			if(a[i+1][j+1]=='*')ans[i][j]++;//右下
			cout<<ans[i][j];
		}cout<<'\n';
	}
	return 0;
}