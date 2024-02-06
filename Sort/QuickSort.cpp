#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(std::vector<int>& nums, int left, int right) {
    int mid = left + (right - left) / 2;
    if(nums[left] > nums[mid]) std::swap(nums[left], nums[mid]);
    if(nums[left] > nums[right]) std::swap(nums[left], nums[right]);
    if(nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
    
    std::swap(nums[mid], nums[right]);   // 将轴值放到最后一个位置
    
    // int i = left-1;                      // 用于存放小于等于轴值的最后一个位置，初始值为left的前一个位置，可能是无效值
    int i = left;
    for(int j = left; j < right; j++) {     // 最后一位是轴值
        if(nums[j] < nums[right]) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }

    // std::swap(nums[i+1], nums[right]);   // nums[i]是小于等于轴值的最后一个位置，则nums[i+1]是存放轴值的位置，nums[right]就是轴值
    std::swap(nums[i], nums[right]);
    return i;
}
void quickSort1(std::vector<int>& nums, int left, int right) {
    if(left >= right) return ;
    else{
        int mid = left + (right - left) / 2;
        int pivot = partition(nums, left, right);
        quickSort1(nums, left, pivot-1);
        quickSort1(nums, pivot+1, right);
    }
}
void  quickSort(std::vector<int>& nums) {
    quickSort1(nums, 0, nums.size()-1);
}
/*
复杂度分析：
    时间复杂度：O(n*log(n))-O(n^2)
      在平均情况下，快速排序的时间复杂度为 O(n*log(n))，其中 n 是待排序数组的元素个数。
        这是因为每次选择一个元素作为基准，然后将数组分为两部分，每部分的大小大致为原始数组的一半。
        因此，递归的深度大约为 log(n)，而每一层的操作都需要 O(n) 的时间。
      最坏情况是O(n^2)，当数组已经有序或者接近有序时。如果每次分区操作都选择数组中的最小或最大元素作为枢纽元素
        即：选择最差的基准元素，可能导致分割出的子数组极度不平衡。但这种情况比较罕见。
    空间复杂度：O(log(n))
      主要取决于递归调用时的额外空间占用。
      因为每个递归调用都会创建一个新的函数调用栈帧，每次递归调用都将数组分成两半，递归树的高度是对数级别的

稳定性：
  不稳定。因为在分区操作时，相等元素的相对顺序可能会改变。例如，在你的分区操作中，如果有相等的元素，它们可能会在排序后交换位置。
*/
/******************************测试程序如下*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    quickSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}