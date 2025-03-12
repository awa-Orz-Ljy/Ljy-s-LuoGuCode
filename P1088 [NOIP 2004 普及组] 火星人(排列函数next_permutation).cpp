#include<bits/stdc++.h>
using namespace std;
int a[10001],n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//生成下一个字典序较大的序列，所以循环可以解决
	while(m--)next_permutation(a+1,a+n+1);//枚举到第 m 个全排列 
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";//输出第 m 个全排列 
    return 0; 
}
/*
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    vector<int> arr = {1, 2, 3};
    do {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
    return 0;
}
*/