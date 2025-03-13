#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
int a[MAX];

int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0'||c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >='0'&&c <= '9'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x*f;
}

int main(){
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++)a[i] = read();
	while(m --){
		int x = read();
		//返回的索引减去数组起始的地址罢了
		int ans = lower_bound(a + 1,a + n + 1,x) - a;
		if(x != a[ans])printf("-1 ");
		else printf("%d ",ans);
	}
	return  0;
}