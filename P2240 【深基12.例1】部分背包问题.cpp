#include<bits/stdc++.h>
using namespace std;
struct node{//定义结构体 
    double w;//重量 
    double v;//价值 
    double p;//性价比 
}a[105];

bool cmp(node a,node b){
    return a.p >b.p;//性价比从大到小排序 
}
int main(){
	int n;double sum = 0,c;
    cin>>n>>c;
    for(int i=1;i<=n;++i){
        cin>>a[i].w>>a[i].v;
        a[i].p=a[i].v/a[i].w;//性价比=价格/重量 
    }
    //排序左闭右开，上面的a[]是1到n，a表示下标0
    sort(a+1,a+n+1,cmp);//将性价比排序 
    for(int i=1;i<=n;++i){
        if(c>=a[i].w){//金币的重量小于或等于背包的承重量
            c-=a[i].w;//装上该堆金币后背包的剩余承重量 
            sum+=a[i].v;//金币的价值 
        }
		else{
            sum+=c*a[i].p;//如果装不下就分割金币 
            break;
        }
    }
    printf("%.2f",sum);//保留小数点后两位输出
	return 0; 
}
