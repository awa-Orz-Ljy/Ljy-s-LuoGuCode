#include<bits/stdc++.h>
using namespace std;

vector<int> stu;

int main(){
	int n,m,x;cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>x;
		stu.push_back(x);
	}
	while(m --){
		int idx;cin>>idx;
		cout<<stu[idx - 1]<<endl;
	}
	return 0;
}