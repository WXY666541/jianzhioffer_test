#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
***************************************************************************
题目要求：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
分析：用位操作即可实现n&(n-1)
***************************************************************************
*/
/*方法一：
 *与操作可以判定二进制数中的1。所以用1
 *1自身左移运算和n的每一位进行与运算
*/
int Numberof(int n)
{
    int count = 0;
    int flag = 1;
    while (flag != 0)
    {
        if((n & flag) != 0)//此处不能用while，会死循环
        {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}
//方法二：
int  NumberOf1(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = (n - 1) & n;
        count++;
    }
    return count;
}
/*
***************************************************************************
题目要求：给定一个double类型的浮点数base和int类型的整数exponent。
          求base的exponent次方。保证base和exponent不同时为0
分析：考虑base等于0，exponent等于0的特殊情况
      还要考虑exponent小于0的情况
***************************************************************************
*/
double Power(double base, int exponent)
{
    double result = 1;
    if (base == 0)return 0;
    if (exponent == 0)return 1;
    int e = exponent;
    if (exponent < 0)
    {
        e = -exponent;
    }
    while (e != 0)
    {
        result = result * base;
        e--;
    }
    if (exponent < 0)
    {
        result = 1 / result;
    }
    return result;
}

/*
***************************************************************************
题目要求：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
          使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
          并保证奇数和奇数，偶数和偶数之间的相对位置不变。
***************************************************************************
*/
/*方法一：
      新开辟一个数组，先把奇数先push,再把偶数push
*/
void reOrderArray(vector<int>& array) 
{
    vector<int> res;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] % 2 == 1)
        {
            res.push_back(array[i]);
        }
    }
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] % 2 == 0)
        {
            res.push_back(array[i]);
        }
    }
    array = res;
}
void init(vector<int>& array)
{
    for (int i = 0; i < 10; i++)
    {
        array.push_back(i);
    }
}
void Print(vector<int>& array)
{
    vector<int>::iterator it = array.begin();
    while (it < array.end())
    {
        cout << *it << endl;
        it++;
    }
}
/*方法二：
      使用冒泡排序的算法，遇到前偶后奇就交换
      但是这种方法，效率不高，有很多重复的交换趟数,且不稳定
*/
void reOrderArray1(vector<int>& array)
{
    for (int i=0; i < array.size(); i++)
    {
        for (int j = array.size() - 1; j > i; j--)
        {
            if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
            {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}
/*方法三：
     因为题目要求相对位置不变，所以存在稳定性的问题，回顾我们的所有排序算法
     插入排序是比较稳定的。再者要求，奇数在前偶数在后，所以存在判断数据挪动问题

*/
void reOrderArray2(vector<int>& array)
{
    for (int i = 1; i < array.size(); i++)//注意！此处的i是从1开始的
    {
        int tmp = array[i];
        if (tmp % 2 == 1)
        {
            for (int j = i; j > 0; j--)
            {
                if (array[j - 1] % 2 == 0)
                {
                    int tmp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = tmp;
                }
            }
        }
    }
}

/*
***************************************************************************
题目要求：输入一个链表，输出该链表中倒数第k个结点。
***************************************************************************
*/
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
/*方法一：
  使用栈。将结点压入栈中，再取出第k个结点即可
  注意！下面程序实现有错误
ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k)
{
    if (pListHead == NULL || k <= 0) return NULL;
    stack< ListNode> st;
    int size = 0;
    while (pListHead != NULL)
    {
        st.push(pListHead->val);
        pListHead = pListHead->next;
        size++;
    }
    if (k > size) return NULL;
    ListNode* knode = NULL;
    for (int i = 0; i < k; i++)
    {
        knode->val=st.pop();
    }
    return knode;

}*/
/*方法二：
  使用两个指针，p2指针先走k-1步，然后再一起走，
  直到p2为最后一个时，p1为倒数第k个结点
*/
ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) 
{
    if (pListHead == NULL || k <= 0) return NULL;
    ListNode* p1 = pListHead;
    ListNode* p2 = pListHead;
    while (k > 1)
    {
        if (p2->next != NULL)
        {
            p2 = p2->next;
            k--;
        }
        else return NULL;//说明k已经大于链表长度了
    }
    while (p2->next != NULL)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}
int main()
{

    //int n = 10;
    //cout << NumberOf1(n) << endl;
    /*cout << Power(3.14, 2) << endl;
    cout << Power(0, 2) << endl;
    cout << Power(3.14, 0) << endl;*/
    vector<int> ar;
    init(ar);
    reOrderArray2(ar);
    Print(ar);
    return 0;
}