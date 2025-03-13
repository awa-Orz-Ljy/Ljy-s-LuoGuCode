#include<bits/stdc++.h>
using namespace std;
int a[101],n;
int main(){
	for(int i = 1;;i ++){
		cin>>a[i];
		if(a[i] == 0)break;
		n = i;
	}
	
	for(int j = n;j >= 1;j --)cout<<a[j]<<" ";
}
//*我提交的是解法二


1:手打栈
#include<iostream>
using namespace std;
int a[101];//如果你的第一个数存储在a[1]里,一定要多开一两个空间 ，以防越界访问
int top=0,c;
int main(){
	while(1){
		cin>>c;
		if(c==0) break;
		a[++top]=c;
		
		或者写成：
		top++;
		a[top]=c;
		个人比较喜欢压码……
		
	}
	while(top!=0){
		cout<<a[top--]<<" ";
		
		或者写成：
		cout<<a[top];
		top--;
		
	}
	return 0;
} 


2:vector
#include<iostream>
#include<vector>//STL vector的头文件
using namespace std;
vector<int> a;//定义一个int型的vector 
int c;//STL可以完全不用担心数组大小的问题,这个和string类似 
int main(){
	while(1){//有时候也可以巧用死循环 
		cin>>c;
		if(c==0) break;//终止条件 
		a.push_back(c);//将括号里的元素压入vector尾部 
	}
	while(!a.empty()){
		cout<<a.back()<<" ";//.back()是一个返回vector尾部元素的函数 
		a.pop_back();//删除vector尾部的元素
	}
    
    //这一部分输出程序也可以写成：
    //for(int i=a.size()-1;i>=0;i--){//a.size()返回a中元素的个数
    //    cout<<a[i]<<" ";
    // }
    //要注意vector是从a[0]开始存储a.size()个元素，要当心越界访问
    
	return 0;
} 


3:stack
#include<iostream>
#include<stack>//STL stack的头文件
using namespace std;
stack<int> a;//定义一个int型的stack 
int c;
int main(){
	while(1){
		cin>>c;
		if(c==0) break;
		a.push(c);//将括号里的元素压入stack顶部 
	}
	while(!a.empty()){
		cout<<a.top()<<" ";//.top()是一个返回stack顶部元素的函数 
		a.pop();//删除stack顶部的元素 
	}
	return 0;
} 


*//