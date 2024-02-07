#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
二叉堆：一种特殊的二叉树数据结构，通常用于实现优先队列等抽象数据类型。
它具有以下两个主要特点：
    二叉堆是一颗完全二叉树：这意味着除了最后一层外，所有层的节点都是满的，而且最后一层的节点都尽可能地从左向右填充。
    二叉堆具有堆序性质：这意味着对于大根堆（或大顶堆），父节点的值大于或等于其子节点的值；对于小根堆（或小顶堆），父节点的值小于或等于其子节点的值。
        二叉堆可以分为两种类型：
            大根堆（或大顶堆）：在大根堆中，根节点的值最大，每个父节点的值都大于或等于其子节点的值。
            小根堆（或小顶堆）：在小根堆中，根节点的值最小，每个父节点的值都小于或等于其子节点的值。

二叉堆建堆步骤如下：（这里是建立大根堆）
    1. 假设原数组就是一个二叉堆，但是现在这个二叉堆是无序的。（所以要进行堆化heapify，就是保证每个节点的值>其左子节点和右子节点的值）
    2. 因为是从下而上进行堆化，所以从最后一个叶子节点的父节点开始进行堆化（就是nums.size()/2 - 1，因从0开始，所以要减一）
    3. 堆化函数把当前节点的值存储在一个临时int变量large中，并且假设当前节点的值最大。 初始化left和right
    4. 比较 左子节点的值nums[left] 和 最大值nums[large]， 若nums[left] > nums[large]，则更新large为left
    5. 比较 右子节点的值nums[right] 和 最大值nums[large]， 若nums[right] > nums[large]，则更新large为right 
    6. 如果large还是原来的cur，说明假设的cur节点的值就是最大，不用交换；否则交换nums[large]  和 nums[cur]。
        交换当前根节点nums[cur] 和 最大值nums[large]后，可能large下标所代表的节点的子树不符合二叉堆规则
        （可能存在交换后的nums[large]比其子树小）， 所以要对large所在子树进行堆化操作。
    7. 一直递归，直到退出到buildHeap的for循环，然后继续for循环，直到for循环结束，最后得到一个有序的二叉堆
*/
void heapify(vector<int>& nums, int cur) {
    int large = cur;            // 初始化当前根节点的值最大（保存的是节点的下标）
    int left = 2*cur + 1;       // 当前根节点cur的左子节点（因为是从下标0开始保存的，所以要加一）
    int right = 2*cur + 2;      // 当前根节点cur的右子节点

    // 以下if语句的目的：从当前节点cur、左子节点left、右子节点right。这三个节点中找出值最大的，然后放到cur的这个位置。
    // 即：保证当前根节点的值是最大的。
    if(left < nums.size() && nums[left] > nums[large])    // 表示：left在有效范围内 && 左子节点值 > 右子节点值
        large = left;                                   // 更新最大值的下标
    if(right < nums.size() && nums[right] > nums[large])
        large = right;
    if(large != cur){                   // 若large不是原来的cur这个位置了，说明原来的cur这个位置的值不是最大的，需要交换
        swap(nums[large], nums[cur]);   // large下标和cur交换了值，以large为根节点的子树可能顺序被打破。所以下面要对large所在的子树继续堆化
        heapify(nums, large);           // 只是对large所在的子树进行堆化
    }
}

void buildHeap(vector<int>& nums) {
    int length = nums.size();
    for(int i = length / 2 - 1; i >= 0; i--) {  // 这里采用的是自下而上的堆化。即：从最后一个叶子节点的父节点开始堆化。
        heapify(nums, i);
    }
}
/******************************测试程序如下*******************************/
int main() {
    vector<int> nums = {5,9,8,0,7,1,6};
    buildHeap(nums);

    for_each(begin(nums), end(nums), [](int a){cout << a << " ";});
    cout << endl;

    return 0;
}
/*
原来数组为：（假设原来的数组就是一个二叉堆，但是是无序的）
      5
    9   8
  0  7 1  6
  
输出结果为：
  9 7 8 0 5 1 6 
即为：
      9
    7   8
  0  5 1  6
  每个节点的值都 > 其左子节点和右子节点。大根堆建立成功！
*/
/*
二叉堆应用场景：
二叉堆通常用于实现优先队列，因为它支持高效的插入、删除和查找最大（或最小）元素操作，时间复杂度都为O(log n)，其中n是堆中元素的数量。
*/