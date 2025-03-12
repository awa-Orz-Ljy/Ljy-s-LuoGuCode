#include<bits/stdc++.h>
using namespace std;

int tmp,n;
struct zu{
	int ab;
	int ui;
}a[200];

bool cmp(zu x,zu y){
	return x.ab > y.ab;
}

int main(){
	cin>>tmp;n = pow(2,tmp);
	for(int i = 1;i <= n;i ++){
		cin>>a[i].ab;
		a[i].ui = i;
	}
	sort(a + 1,a + n/2 + 1,cmp);
	sort(a + n/2 + 1,a + n + 1,cmp);
	//排序以后第一个为最大值
	//题目要的是输出亚军
	if(a[1].ab > a[n/2 + 1].ab)cout<<a[n/2 + 1].ui;
	else cout<<a[1].ui;
	return 0;
}
//线段树解法？
/*
#include<iostream>
#include<cstring>
#include<algorithm> //比赛的时候闲的没事打了一堆头文件
#include<cmath>
#include<iomanip> 

#include<bits/stdc++.h>
using namespace std;


struct jiegouti{  //真·结构体
 	int power,id;  //power——能力值，id——国家序号
}; 


jiegouti maxt(jiegouti a,jiegouti b){  //返回两个结构体里能力值更大的那个
	return a.power>b.power?a:b;
}


jiegouti mint(jiegouti a,jiegouti b){ //返回两个结构体里能力值更小的那个
	return a.power<b.power?a:b;
}


jiegouti a[150],tree[600];  //a——数据，tree——线段树（一般为了防爆，线段树都是开数组的4倍空间）



void build(int node,int start,int end){ //建树函数
	//叶节点，返回
	if(start==end){  
		tree[node]=a[start];
		return;
	}
	//左右子树、中点
	int lnode=node*2;  
	int rnode=node*2+1;
	int mid=(start+end)/2;
	 //两边递归建树
	build(lnode,start,mid); 
	build(rnode,mid+1,end);
	//父节点是左右子节点里更大的;
	tree[node]=maxt(tree[lnode],tree[rnode])  
}



int main(){
	int n;  //输入
	cin>>n;
	for(int i=1;i<=(1<<n);i++){  //1<<n就是2的n次方啦！（这样比pow函数更快哦！）
		cin>>a[i].power;  //输入，赋值，很简单
		a[i].id=i;	
	}
	build(1,1,(1<<n)); //建树（根节点是1，整棵树从1到2的n次方）
	//默认tree[1]是冠军了
	cout<<mint(tree[2],tree[3]).id; //从tree[2],tree[3]里找个小的就是亚军，输出它的序号
	return 0;
}
*/