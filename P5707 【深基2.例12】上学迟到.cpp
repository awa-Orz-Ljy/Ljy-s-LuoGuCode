#include<bits/stdc++.h>
using namespace std;
int main(){
	double s,v;
	int t,x,y,h,m;cin>>s>>v;
	//用的时间
	t = ceil(s/v) + 10;
	//总共的时间
	x = 60*(24 + 8);
	//减去得到开始时间点
	y = x - t;
	//超过24h的要归零
	if(y > 24*60)y -= 24*60;
	//开始格式化输出
	h = y/60;
	m = y%60;
	if(h < 10)
		if(m < 10)
			cout<<"0"<<h<<":"<<"0"<<m;
		else 
			cout<<"0"<<h<<":"<<m;
	else
		if(m < 10)
			cout<<h<<":"<<"0"<<m;
		else 
			cout<<h<<":"<<m;	
	
	return 0;
}