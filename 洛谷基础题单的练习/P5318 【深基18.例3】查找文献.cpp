/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> G[MAXN];
bool visited[MAXN];
int n,m;
queue<int> q;

//x指当前所在的节点，cur指已遍历过的节点个数
void dfs(int x,int cur){
	//标记以避免重复访问
	visited[x] = true;
	cout<<x<<" ";
	if(cur == n)return;
	for (int i = 0;i < G[x].size();i ++)
	//记得要判断是否遍历过
		if(!visited[G[x][i]])dfs(G[x][i],cur+1);
}

void bfs(int x) {
	//记得一定要清空
	memset(visited,false,sizeof(visited));
	//再来标记
	visited[x] = true;
	q.push(x);
	while(!q.empty()){
		int v = q.front();
		//记得要弹出，否则会一直在第一层遍历
		q.pop();
		cout<<v<<" ";  
		for(int i = 0;i < G[v].size();i ++){
			if(!visited[G[v][i]]){
				visited[G[v][i]] = true;
				//记得要入队
				q.push(G[v][i]);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= m;i ++){
		int u,v;cin>>u>>v;
		//标准邻接表建有向图,push_back之前都要在循环里面输入参数
		G[u].push_back(v);
	}
	for(int i=1;i <= n;i ++)sort(G[i].begin(),G[i].end());//标准vector排序
	dfs(1, 0);
	cout << endl;
	bfs(1);
	cout << endl;
	return 0;//完结撒花！
}