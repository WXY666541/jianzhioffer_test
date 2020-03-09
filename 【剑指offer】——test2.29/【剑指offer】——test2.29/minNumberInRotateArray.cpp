#include<iostream>
#include<vector>
using namespace std;

/*
   ��Ŀ������
   ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
   ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
   ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
    NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/


/*
   ��Ŀ������
	���ö��ַ����������⣬
	mid = low + (high - low)/2
	��Ҫ�������������
	(1)array[mid] > array[high]:
	�������������array����[3,4,5,6,0,1,2]����ʱ��С����һ����mid���ұߡ�
	low = mid + 1
	(2)array[mid] == array[high]:
	�������������array���� [1,0,1,1,1] ����[1,1,1,0,1]����ʱ��С���ֲ����ж���mid���
	�����ұ�,��ʱֻ��һ��һ���� ��
	high = high - 1
	(3)array[mid] < array[high]:
	�������������array����[2,2,3,4,5,6,6],��ʱ��С����һ������array[mid]������mid����
	�ߡ���Ϊ�ұ߱�Ȼ���ǵ����ġ�
	high = mid
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
		if(rotateArray.empty())
			return 0;
		int left = 0 ;
		int right = rotateArray.size() - 1;
		while(left < right){
			//ȷ���������Ƿ�������1,1,2,4,5��..,7�ķǵݼ�����
			if(rotateArray[left] < rotateArray[right])
				return rotateArray[left];
			int mid = left + (right - left) / 2;

			//����������Ϊ��������
			if(rotateArray[left] < rotateArray[mid])
				left = mid + 1;

			//����Ұ�����Ϊ��������
			else if(rotateArray[mid] < rotateArray[right])
				right = mid;

			//����rotateArray[mid] = rotateArray[right] = rotateArray[left]
			else{
				++left;
			}
		}
		return rotateArray[left];
    }
};