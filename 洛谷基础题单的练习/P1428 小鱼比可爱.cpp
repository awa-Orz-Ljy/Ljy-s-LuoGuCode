#include<bits/stdc++.h>
using namespace std;
//为什么在主函数里面定义数组不行捏
//因为未初始化
int a[101],b[101];
int main(){
	int n;cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	for(int i = 1;i <= n;i ++){
		for(int j = i;j >= 1;j --){
			if(a[j] < a[i]) b[i] ++;
		}
	}
	for(int i = 1;i <= n;i ++)cout<<b[i]<<" ";
	return 0;
}