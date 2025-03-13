#include<bits/stdc++.h>
using namespace std;
//父节点数组
const int N = 1e5 + 10;
int fat[N];
//查
int find(int node){
	return fat[node] = (fat[node] == node?node:find(fat[node]));
}
//并
void unionn(int r1,int r2){
	fat[r2] = r1;
}

int main(){
	int n,m,p;cin>>n>>m>>p;
	int f1 = 0,f2 = 0,n1,n2;
	//该集合只有祖先节点,先处理n个人
	for(int i = 1;i <= n;i ++)fat[i] = i;
	//再处理m对关系,关系中的人用n1和n2表示
	for(int i = 1;i <= m;i ++){
		cin>>n1>>n2;
		f1 = find(n1);f2 = find(n2);
		//路径压缩，让下一次找节点更轻松
		if(f1 != f2)unionn(f1,f2);
	}
	//最后的p个询问
	int c1,c2;
	for(int i = 1;i <= p;i ++){
		cin>>c1>>c2;
		if(find(c1) == find(c2))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


