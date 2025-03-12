#include<bits/stdc++.h>
using namespace std;
string a;
const int N = 1e7;
int c[N],d,e,f,g,sum,ans;
int main()
{
	cin>>d>>a>>f;
    for(int x=0;x<a.size();x++){
    	//分界线
    	//该位的数字，先乘上原来进制的位权，再乘上原来位置的数字，即a[x]-'0'
        if(a[x]<'A'){
            e=pow(d,a.size()-x-1);
            e*=(a[x]-'0');
            sum+=e;
        }
        else{
            e=pow(d,a.size()-x-1);
            //A的位置表示10
            e*=(a[x]-'A'+10);
            sum+=e;
        }
    }
    //十进制再转换为f进制，用除数取余法
    while(sum>0){
    	//取余
        c[g++]=sum%f;
        //下一位，更高位
        sum/=f;
    }
    //倒着输出
    for(int x=g-1;x>=0;x--){
    	//设置了一个起点
        if(c[x]>=10)printf("%c",c[x]+'A'-10);
        //小于10的话就不用了
        else printf("%d",c[x]);
    }
    return 0;
}