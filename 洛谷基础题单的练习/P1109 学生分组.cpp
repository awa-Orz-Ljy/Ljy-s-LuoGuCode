#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,maxsum=0,minsum=0,sum=0;cin>>n;
    //人数和界限，人数是n个r数组的值，j数组是01下标，全部都初始化为零 
    int r[n]={0},j[2]={0};
    //输入各组人数
    for(int i=0;i<n;i++){
        cin>>r[i];
        sum+=r[i];
    }    
    //输入界限
    cin>>j[0]>>j[1];
    //超出界限的话
    if(sum<(j[0]*n)||sum>(j[1]*n))
//  if((sum/n)<j[0] or (sum/n)>j[1])
    {
        cout<<"-1";
        return 0;
    }
    //未超出
    else{
        for(int i=0;i<n;i++){
        	//大于上限的操作次数
            if(r[i]>j[1])    maxsum+=(r[i]-j[1]);
            //小于下限的操作次数
            if(r[i]<j[0])    minsum+=(j[0]-r[i]);
        }
    }
    cout<<max(maxsum,minsum);
}