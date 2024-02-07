#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// selectSort ÿ�ν���ǰԪ���滻Ϊ������С��Ԫ�� (��������С�����˳������ÿ�ν�����δ���򲿷��е���Сֵ�ŵ���ǰλ��)
void selectSort(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        int min = i;  // ��ŵ����±꣬����Ԫ��ֵ
        for (int j = i + 1; j < N; j++) {
            if (nums[j] < nums[min]) min = j;
        }
        int tmp = nums[i];
        nums[i] = nums[min];
        nums[min] = tmp;
    }
}
/*
���Ӷȷ�����
    ʱ�临�Ӷȣ�O(n^2)
    �ռ临�Ӷȣ�O(1)
    
�ȶ��ԣ�
  ���ȶ�����Ϊ��ѡ����СԪ�صĹ����п��ܻ�ı����Ԫ�ص����˳��
*/
/******************************���Գ�������*******************************/
int main() {
    vector<int> tmp = {9, 3, 6, 1, 8, 5, 2, 7, 4};
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;

    selectSort(tmp);
    for_each(begin(tmp), end(tmp), [](int a) { cout << a << " "; });
    cout << endl;
    return 0;
}