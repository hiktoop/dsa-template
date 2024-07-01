/*
双向链表的数组形式，取自算法竞赛入门经典6-5：
从 1 ~ n 编号的盒子顺序放置，有四种操作：
1 x y：将 x 放到 y 的相邻左边
2 x y：将 x 放到 y 的相邻右边
3 x y：互换 x 和 y 的位置
4：翻转链表
最后输出所有奇数位置的盒子编号和
输入样例：
6 4
1 1 4
2 3 5
3 1 6
4
输出样例：
Case 1: 12
*/

#include <cstdio>

const int maxn = 1000;
int left[maxn], right[maxn];

void link(int L, int R) {
  right[L] = R; left[R] = L;
}
void swap(int x, int y) {
    int t = x; x = y; y = t;
}

int main() {
    int n, m, kase = 0;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) { // 初始化顺序连接
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }

        right[0] = 1; left[0] = n;
        int op, x, y, inv = 0;
        while (m--) {
            scanf("%d", &op);
            if (op == 4) inv = !inv; // 翻转链表
            else {
                scanf("%d%d", &x, &y);
                if (op == 3 && right[y] == x) swap(x, y); // 相邻时保证 x 在左边，便于后续直接操作
                if (op != 3 && inv) op = 3 - op; // 翻转后的链表的操作对应更改
                if (op == 1 && x == left[y]) continue; // 不需要进一步处理
                if (op == 2 && x == right[y]) continue;

                // 连接操作
                int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
                if (op == 1) { link(lx, rx); link(ly, x); link(x, y); }
                else if(op == 2) { link(lx, rx); link(y, x); link(x, ry); }
                else if(op == 3) {
                    if (right[x] == y) { link(lx, y); link(y, x); link(x, ry); }
                    else { link(lx, y); link(y, rx); link(ly, x); link(x, ry); }
                }
            }
        }

        int b = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            b = right[b];
            if (i % 2 == 1) ans += b; // 保存奇数序号下的盒子编号
        }
        if (inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans; // 排除不需要计算的情况（n 为奇数时）
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}
