#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;
int kmp[MAXN];
int la,lb,j; 
char a[MAXN],b[MAXN];
int main()
{
    cin>>a + 1;
    cin>>b + 1;
    la=strlen(a+1);
    lb=strlen(b+1);
    //kmp是前缀表数组，先对子串b对子串b，因为长度为1，前后缀的数值为0，随跳过
    for (int i = 2;i <= lb;i ++){   
	   while(j&&b[j + 1]!=b[i]) j = kmp[j];//不相等，改变j以回溯
       if(b[j + 1] == b[i]){//相等的话
       	j ++;   //匹配长度（j）+1 
        kmp[i] = j;//更新前缀表
       }
    }
    j=0;
    //利用前缀表进行匹配，子串b对主串a
    for(int i = 1;i <= la;i ++){
		while(j>0&&b[j + 1] != a[i]) j = kmp[j];//不相等，回溯
    	if(b[j + 1] == a[i]) j ++;//相等，匹配长度+1
      	if(j == lb){//全部匹配结束
      	cout<<i - lb + 1<<endl;//主串用i输出位置
      	j = kmp[j];//某段匹配成功，回溯以寻找下一个片段出现的地方
      }
	}
    for(int i = 1;i <= lb;i ++)
    cout<<kmp[i]<<" ";//输出前缀表
    return 0;
}