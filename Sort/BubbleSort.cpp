#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bubbleSort n-1�������Ƚ����ڵ�Ԫ�ز��������ǡ�������ÿ�ν�ǰ��δ���򲿷ֵ����ֵ��ð�ݡ�������λ�ã�
void bubbleSort(vector<int>& nums) {
    int N = nums.size();
    for(int i = 0; i < N - 1; i++) {        // ��Ϊ N ��ԭ���ǣ����һ��Ԫ�ز���Ҫ���бȽ�
        for(int j = 0; j < N-1-i; j++) {    // �Ѿ�����õ�Ԫ�ػ��𽥾ۼ��������ĩβ�������ڲ�ѭ������Ҫ�ٱȽ���Щ�Ѿ�����õ�Ԫ��
            if(nums[j] > nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
}
/*
���Ӷȷ�����
    ʱ�临�Ӷȣ�O(n^2)
    �ռ临�Ӷȣ�O(1)
    
�ȶ��ԣ�
  �ȶ�����Ϊ�������Ԫ�ص�ֵ��ȣ����ǲ��ᱻ������������ǵ����λ�����������Ȼ���ֲ��䡣�����ȶ��ġ�
*/
/******************************���Գ�������*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    bubbleSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}