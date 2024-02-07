#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bubbleSort n-1遍历。比较相邻的元素并交换它们。（即：每次将前面未排序部分的最大值“冒泡”到最后的位置）
void bubbleSort(vector<int>& nums) {
    int N = nums.size();
    for(int i = 0; i < N - 1; i++) {        // 不为 N 的原因是：最后一个元素不需要进行比较
        for(int j = 0; j < N-1-i; j++) {    // 已经排序好的元素会逐渐聚集到数组的末尾，所以内部循环不需要再比较这些已经排序好的元素
            if(nums[j] > nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
}
/*
复杂度分析：
    时间复杂度：O(n^2)
    空间复杂度：O(1)
    
稳定性：
  稳定。因为如果两个元素的值相等，它们不会被交换，因此它们的相对位置在排序后仍然保持不变。即是稳定的。
*/
/******************************测试程序如下*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    bubbleSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}