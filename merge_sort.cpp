#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void merge(vector<int> &a, vector<int> &tmp, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid || j <= r) {
        if(i > mid) tmp[k++] = a[j++];
        else if(j > r) tmp[k++] = a[i++];
        else {
            if(a[i] < a[j]) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
    }
    for(i = l; i <= r; ++i) a[i] = tmp[i];
}

void sort(vector<int> &a, vector<int> &tmp, int l, int r) {
    if(l >= r) return ;
    int mid = (l + r) / 2;
    sort(a, tmp, l, mid);
    sort(a, tmp, mid + 1, r);
    merge(a, tmp, l, mid, r);
}

int main() {
    vector<int> a{10, 9, 9, 3, 4, 5, 7, 3, 28, 9, 1, 0};
    vector<int> tmp(a.size());
    // sort(a, tmp, 0, a.size() - 1);
    int e, m;
    int len;
    for(len = 2; len <= a.size(); len *= 2) {
        for(int i = 0; i < a.size(); i += len) {
            e = min(i + len - 1, (int)a.size() - 1); // make sure in range
            m = (i + e) / 2;
            if(i < e) merge(a, tmp, i, m, e);
        }
    }

    // this is ugly
    int i, n = a.size();
    for(i = 0; i + 1 < n; ++i) {
        if(a[i] > a[i + 1]) break;
    }
    if(i + 1 != n) merge(a, tmp, 0, i, n - 1);

    for(auto i: a) cout << i << " ";
    cout << endl;
    
    return 0;
}