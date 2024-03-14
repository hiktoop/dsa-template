#include <iostream>
#include <vector>
using namespace std;

void qsort(vector<int> &nums, int l, int r) {
    if(l >= r) return ;
    int piv = nums[l], i = l, j = r;
    while(i < j) {
        while(i < j && piv <= nums[j]) --j;
        while(i < j && piv >= nums[i]) ++i;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    qsort(nums, l, i);
    qsort(nums, i + 1, r);
}

int main() {
    vector<int> nums{10, 23, 4, 324, 4, 54, 52, 5, 6, -1, 543, -543, 0};
    qsort(nums, 0, nums.size() - 1);
    for(int i: nums) cout << i << " ";
    cout << endl;
    return 0;
}