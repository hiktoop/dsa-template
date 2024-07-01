/*
数组形式的链表应用，选自算法竞赛入门经典例题6-4：
输入一系列字符串，包括字母、下划线和字符'['与']'，'['表示光标移动到文本的开头，']'表示光标移动到文本的结尾。输出最后的结果
例如：
输入：This_is_a_[Beiju]_text
输出：BeijuThis_is_a__text
输入：[][][[]]Whatcanisayman
输出：Whatcanisayman
*/

#include <cstdio>
#include <cstring>

const int maxn = 100000 + 5;
int last, cur, next[maxn];
char s[maxn];

int main() {
    while (scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1);
        last = cur = 0;
        next[0] = 0;
        for (int i = 1; i <= n; i++) {
            char ch = s[i];
            if (ch == '[') cur = 0;
            else if (ch == ']') cur = last;
            else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) last = i;
                cur = i;
            }
        }
        for (int i = next[0]; i != 0; i = next[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
