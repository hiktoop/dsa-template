#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getNext(const string &needle, vector<int> &next) {
    int m = needle.size(), j = 0;
    int t = next[0] = -1;
    while(j < m - 1) {
        if(t < 0 || needle[j] == needle[t])
            next[++j] = ++t;
        else t = next[t];
    }
}

int kmp(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    vector<int> next(n);
    getNext(needle, next);

    int i = 0, j = 0;
    while(i < m && j < n) {
        if(j < 0 || haystack[i] == needle[j]) 
            i++, j++;
        else j = next[j];
    }
    return j == n ? i - j : -1;
}

int main() {
    string haystack = "this is a centence.";
    string needle = "centence";
    cout << kmp(haystack, needle);
}