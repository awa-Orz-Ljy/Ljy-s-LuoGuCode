#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 9;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int k; cin >> k;
    int ans = 0;
    for(int i = 10000; i <= 30000; i++)
    {
    	//取数方式
        int sub1 = i / 100;
        int sub2 = i / 10 % 1000;
        int sub3 = i % 1000;
        if((sub1 % k == 0) && (sub2 % k == 0) && (sub3 % k == 0))
            {
                cout << i << '\n';
                ans = 1;
            }
    }

    if(!ans) cout << "No";

    return 0;
}