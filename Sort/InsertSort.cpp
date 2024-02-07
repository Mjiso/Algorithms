#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// insertSort 每次将当前元素插入到前面已经排好序的元素中
/*
算法思想：
    每次将待插入的元素值和前面有序部分的元素值进行比较。
      如果待插入的元素值 小于 当前有序部分的元素值，说明待插入元素值的插入位置在前面（左边），还需要向前面（左边）移动。
      如果待插入的元素值 大于等于 有序部分的某个值，说明这个地方就是待插入的位置。结束寻找循环，插入元素值。
    
    所以，数据有序程度越高，插入排序算法越高效（移动少）
*/
void insertSort(vector<int>& nums) {
    int N = nums.size();
    int i , j, tmp;
    for (int i = 1; i < N; i++) {                       // 规定原序列第一个元素为有序区的第一个元素。所以无序区的第一个元素是nums[1]
        tmp = nums[i];      // 暂存待插入值
        for (j = i - 1; j >= 0 && tmp < nums[j]; j--) { // j的初始值为 i-1, 表示有序区的最后一个元素的下标。即查找插入位置的开始下标
            nums[j+1] = nums[j];                        // 移动元素值
        }
        nums[j+1] = tmp;    // 插入元素值。因为最后 j 的位置是 tmp>=nums[j] 的位置，所以应该是插入到nums[j]的后面，即nums[j+1]这个位置
    }
}

/*
复杂度分析：
    时间复杂度：O(n^2)
    空间复杂度：O(1)
    
稳定性：
  稳定。因为在插入排序中，当找到相等元素时，不会交换它们的位置，所以是稳定的。
*/
/******************************测试程序如下*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    insertSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}