#include<bits/stdc++.h>
using namespace std;
int a[1200][1200];
int main(){
	int n,s = 1;cin>>n;
	a[0][0] = 1;
	//递归次数n
	for(int i = 0;i < n;i ++,s *= 2){
		//复制子矩阵到右边和下边
		for(int j = 0;j < s;j ++){
			for(int k = 0;k < s;k ++){
				a[j][k + s] = a[j + s][k] = a[j][k];
			}
		}
	}
	//倒序输出
	for(int i = s - 1;i >= 0;i --){
		for(int j = s - 1;j >= 0;j --){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}