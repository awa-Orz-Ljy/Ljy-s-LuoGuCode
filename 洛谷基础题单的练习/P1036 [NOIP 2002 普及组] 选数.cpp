
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, k, cnt;
int a[N];

bool is_prime(int x){
	if(x == 0||x == 1)return false;
	for(int i = 2;i*i <= x;i ++){
		//检查到x的平方根就发现是合数的话就真的寄了，说明*********因子很早就出现，并非素数，提高效率罢了
		//接下来是is_prime函数，判断一个数是否是素数。如果x小于2，直接返回false。
		//然后从2遍历到***************x的平方根，如果有因数，就不是素数，返回false。否则返回true。
		//这个判断素数的方法是正确的，但需要注意循环条件i <= x / i，
		//这样写是为了避免使用sqrt函数，同时防止溢出，这是常见的写法。
		if(x % i == 0)return false;
	}
	return true;
}


void dfs(int m, int sum, int startx) 
//m表示当前已经选择了几个数 sum表示当前选择数的和 startx表示当前选择数的序号 保证是升序序列 避免重复 
{
	//搜出边界了直接返回
    if (startx > n) return;
    //选完了全部组合，判断是否计数 
    if (m == k)
    {
        if (is_prime(sum)) cnt ++ ;
        return;
    }
    //两种选择
    //那这个代码的逻辑应该就是，通过DFS的方式生成所有可能的k个数的组合，然后计算它们的和，
    //判断是否是素数，符合条件的就计数。这里的关键在于如何避免重复的组合。
    //例如，当选择数的顺序不同，但元素相同的情况会被视为同一组合，
    //所以为了避免这种情况，
    //DFS每次递归都只能选择当前startx之后的元素，这样就不会出现重复的组合。
    //最新的递归都在栈顶，类似压栈的顺序，，
    dfs(m, sum, startx + 1);
    dfs(m + 1, sum + a[startx], startx + 1); 
    return;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    dfs(0, 0, 0);
    printf("%d\n", cnt);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, k, cnt;
int a[N];
vector<int> selected;  // 用于记录当前选择的数

bool is_prime(int x) {
    if (x == 0 || x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void dfs(int m, int sum, int startx) {
    if (startx > n) return;
    if (m == k) {
        // 输出当前组合
        cout << "组合: ";
        for (int num : selected) {
            cout << num << " ";
        }
        cout << " 和: " << sum;
        //判断
        if (is_prime(sum)) {
            cout << " (是素数)" << endl;
            cnt++;
        } else {
            cout << " (不是素数)" << endl;
        }
        return;
    }
    // 不选当前数
    dfs(m, sum, startx + 1);
    // 选当前数
    selected.push_back(a[startx]);
    dfs(m + 1, sum + a[startx], startx + 1);
    selected.pop_back();  // 回溯，撤销选择
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    dfs(0, 0, 0);
    printf("素数组合的数量: %d\n", cnt);
    return 0;
}
*/