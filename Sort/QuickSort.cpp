#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(std::vector<int>& nums, int left, int right) {
    int mid = left + (right - left) / 2;
    if(nums[left] > nums[mid]) std::swap(nums[left], nums[mid]);
    if(nums[left] > nums[right]) std::swap(nums[left], nums[right]);
    if(nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
    
    std::swap(nums[mid], nums[right]);   // ����ֵ�ŵ����һ��λ��
    
    // int i = left-1;                      // ���ڴ��С�ڵ�����ֵ�����һ��λ�ã���ʼֵΪleft��ǰһ��λ�ã���������Чֵ
    int i = left;
    for(int j = left; j < right; j++) {     // ���һλ����ֵ
        if(nums[j] < nums[right]) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }

    // std::swap(nums[i+1], nums[right]);   // nums[i]��С�ڵ�����ֵ�����һ��λ�ã���nums[i+1]�Ǵ����ֵ��λ�ã�nums[right]������ֵ
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
���Ӷȷ�����
    ʱ�临�Ӷȣ�O(n*log(n))-O(n^2)
      ��ƽ������£����������ʱ�临�Ӷ�Ϊ O(n*log(n))������ n �Ǵ����������Ԫ�ظ�����
        ������Ϊÿ��ѡ��һ��Ԫ����Ϊ��׼��Ȼ�������Ϊ�����֣�ÿ���ֵĴ�С����Ϊԭʼ�����һ�롣
        ��ˣ��ݹ����ȴ�ԼΪ log(n)����ÿһ��Ĳ�������Ҫ O(n) ��ʱ�䡣
      ������O(n^2)���������Ѿ�������߽ӽ�����ʱ�����ÿ�η���������ѡ�������е���С�����Ԫ����Ϊ��ŦԪ��
        ����ѡ�����Ļ�׼Ԫ�أ����ܵ��·ָ���������鼫�Ȳ�ƽ�⡣����������ȽϺ�����
    �ռ临�Ӷȣ�O(log(n))
      ��Ҫȡ���ڵݹ����ʱ�Ķ���ռ�ռ�á�
      ��Ϊÿ���ݹ���ö��ᴴ��һ���µĺ�������ջ֡��ÿ�εݹ���ö�������ֳ����룬�ݹ����ĸ߶��Ƕ��������

�ȶ��ԣ�
  ���ȶ�����Ϊ�ڷ�������ʱ�����Ԫ�ص����˳����ܻ�ı䡣���磬����ķ��������У��������ȵ�Ԫ�أ����ǿ��ܻ�������󽻻�λ�á�
*/
/******************************���Գ�������*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    quickSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}