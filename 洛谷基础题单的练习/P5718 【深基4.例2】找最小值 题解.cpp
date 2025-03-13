#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[1001];cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	//首先，用户可能对数组的索引和指针操作不太熟悉。
	//在C++中，数组名代表数组的首地址，所以a是指向第一个元素的指针，即a[0]。
	//当使用a+1时，这相当于指向a[1]的指针。同样，a+n+1是指向a[n]后面的位置，
	//因为sort函数的结束参数是开区间，不包含这个位置。
	sort(a+1,a+n+1);
	cout<<a[1];
	return 0;
}