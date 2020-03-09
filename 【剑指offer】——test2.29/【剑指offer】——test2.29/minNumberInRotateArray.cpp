#include<iostream>
#include<vector>
using namespace std;

/*
   题目描述：
   把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
   输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
   例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/


/*
   题目分析：
	采用二分法解答这个问题，
	mid = low + (high - low)/2
	需要考虑三种情况：
	(1)array[mid] > array[high]:
	出现这种情况的array类似[3,4,5,6,0,1,2]，此时最小数字一定在mid的右边。
	low = mid + 1
	(2)array[mid] == array[high]:
	出现这种情况的array类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边
	还是右边,这时只好一个一个试 ，
	high = high - 1
	(3)array[mid] < array[high]:
	出现这种情况的array类似[2,2,3,4,5,6,6],此时最小数字一定就是array[mid]或者在mid的左
	边。因为右边必然都是递增的。
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
			//确认子数组是否是类似1,1,2,4,5，..,7的非递减数组
			if(rotateArray[left] < rotateArray[right])
				return rotateArray[left];
			int mid = left + (right - left) / 2;

			//如果左半数组为有序数组
			if(rotateArray[left] < rotateArray[mid])
				left = mid + 1;

			//如果右半数组为有序数组
			else if(rotateArray[mid] < rotateArray[right])
				right = mid;

			//否则，rotateArray[mid] = rotateArray[right] = rotateArray[left]
			else{
				++left;
			}
		}
		return rotateArray[left];
    }
};