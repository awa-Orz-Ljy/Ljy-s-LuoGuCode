#include<bits/stdc++.h>
using namespace std;
double x[10],y[10];

double distance(double x1,double y1,double x2,double y2){
	return sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
}

int main(){
	for(int i = 1;i < 4;i ++)cin>>x[i]>>y[i];
	double a = distance(x[1],y[1],x[2],y[2]);
	double b = distance(x[1],y[1],x[3],y[3]);
	double c = distance(x[2],y[2],x[3],y[3]);
	printf("%.2lf",a + b + c);
	return 0;
}