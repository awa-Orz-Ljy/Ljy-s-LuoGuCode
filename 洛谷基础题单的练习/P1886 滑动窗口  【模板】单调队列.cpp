#include<bits/stdc++.h>

using namespace std;

const int N = 1000010;
int a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    deque<int> dq;
    // 求最小值
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();//不符合就丢
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << ' ';
    }
    cout << '\n';
    dq = deque<int>();
    // 求最大值
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();//不符合就丢
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << ' ';
    }
}

int main() {
    solve();
    return 0;
}