#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// mergeSort 建立在归并操作的一种高效的排序方法，该方法采用了分治的思想，比较适用于处理较大规模的数据，但比较耗内存
/*
递归二路归并排序算法思想;
  将待排序的序列分割成两个子序列，然后对这两个子序列进行排序，最后再将排好序的两个子序列合并为一个有序序列即可。
  
从这里可以看出递归二路归并排序是：
  将大的序列分为小的，直至序列长度为1。然后开始合并序列，直至合并到为一个完整的一个序列
*/
void mergeSeq(vector<int>& nums, int left, int mid, int right) {    // 合并两个有序子序列
    int *tmp = new int[right-left+1];           // 暂存两个子序列合并后的序列，因为要保证排序稳定，所以需要额外的一个空间。
    int i = left, j = mid+1, k = 0;             // i：第一个子序列开始下标，j：第二个子序列开始下标，k：存放合并结果的下标
    for(; i <= mid && j <= right; ) {           // 只要其中一个子序列取完，结束循环
        if(nums[i] <= nums[j]) tmp[k++] = nums[i++];    // 注：整个归并算法是否稳定，取决于这里是否有等于（当两个元素相等时，会先将前一个子序列的元素放入结果数组，以此保持稳定）
        else tmp[k++] = nums[j++];
    }
    
    while(i <= mid) tmp[k++] = nums[i++];       // 表示：将第 1 个序列的剩余部分合并到结果数组中
    while(j <= right) tmp[k++] = nums[j++];     // 表示：将第 2 个序列的剩余部分合并到结果数组中
    
    for(k = 0, i = left; i <= right; ) nums[i++] = tmp[k++];    // 将原数组中未排序的数据 替换为 暂存在tmp中的合并结果
    delete[] tmp;                               // 销毁手动分配的内存
}

void mergeSort1(vector<int>&nums, int left, int right) {
    if(left == right) return;                   // 若只有一个元素，递归结束（因为只有一个元素时，是有序的）
    else {
        int mid = left + (right - left) / 2;
        mergeSort1(nums, left, mid);            // 归并排序前半个子序列
        mergeSort1(nums, mid+1, right);         // 归并排序后半个子序列
        mergeSeq(nums, left, mid, right);       // 将已经排序好的两个子序列合并
    }
}

void mergeSort(vector<int>& nums) {
    mergeSort1(nums, 0, nums.size()-1);         // 第一次调用递归函数
}
/*
复杂度分析：
    时间复杂度：O(nlog(n))  
      其中 n 是待排序数组的长度。因为每一次递归都将数组拆分为两半，且每次合并操作需要线性时间，所以时间复杂度可以表示为 O(nlog(n))。
    空间复杂度：O(n)
    
稳定性：
  稳定。因为在在合并两个子序列的过程中，当两个元素相等时，会先将前一个子序列的元素放入结果数组，
  保持了相等元素的相对顺序不变。这确保了排序的稳定性。
*/

/*
二路归并排序递归算法使用场景：
  因为递归算法需要额外的函数调用开销和内存空间，因为它会在递归调用栈中保存中间结果。
  所以：二路归并排序递归算法对于小型数据集或者不需要特别高性能的场景非常适用，因为它的实现相对简单。
*/


/******************************测试程序如下*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    mergeSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}
/*
输出结果: 
9 3 6 1 8 5 2 7 4 
1 2 3 4 5 6 7 8 9
*/