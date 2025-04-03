#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	//priority_queue<int> pq;
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i = 1;i <= n;i ++){
		int op;cin>>op;
		if(op == 1){
			int x;cin>>x;
			pq.push(x);
		}
		else if(op == 2) cout<<pq.top()<<endl;
		else if(op == 3) pq.pop();
	}
	
	return 0;
}