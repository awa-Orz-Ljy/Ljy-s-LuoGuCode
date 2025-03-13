#include<bits/stdc++.h>
using namespace std;
string a,b;
vector<int> A,B;
//- 逆序存储的原因：方便从低位开始相加，按位处理。
vector<int> add(vector<int> &A,vector<int> &B){
	vector<int> C;
	int t = 0;// 进位值，初始为0
	for(int i = 0;i < max(A.size(),B.size());i ++){
		if(i < A.size())t += A[i];// 加上A的第i位
		if(i < B.size())t += B[i];// 加上B的第i位
		
		//t % 10 得到当前位的值，t /= 10 更新进位。
		
		C.push_back(t % 10);// 当前位结果
		t /= 10;// 计算进位（0或1）
	}
	//如果循环结束后 t > 0，说明最高位有进位，需补1。
	if(t) C.push_back(1);// 处理最高位可能的进位
	return C;
}
int main(){
cin>>a>>b;
for(int i = a.size() - 1;i >= 0;i --)A.push_back(a[i] - '0');// 字符转数字并逆序存储
for(int i = b.size() - 1;i >= 0;i --)B.push_back(b[i] - '0');
auto C = add(A,B);
for(int i = C.size() - 1;i >= 0;i --)cout<<C[i];
return 0;
}