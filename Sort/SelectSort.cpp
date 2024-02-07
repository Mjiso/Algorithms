#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// selectSort 每次将当前元素替换为后面最小的元素 (即：按从小到大的顺序排序，每次将后面未排序部分中的最小值放到当前位置)
void selectSort(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        int min = i;  // 存放的是下标，而非元素值
        for (int j = i + 1; j < N; j++) {
            if (nums[j] < nums[min]) min = j;
        }
        int tmp = nums[i];
        nums[i] = nums[min];
        nums[min] = tmp;
    }
}
/*
复杂度分析：
    时间复杂度：O(n^2)
    空间复杂度：O(1)
    
稳定性：
  不稳定。因为在选择最小元素的过程中可能会改变相等元素的相对顺序。
*/
/******************************测试程序如下*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    selectSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}