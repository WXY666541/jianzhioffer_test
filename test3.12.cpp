#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
***************************************************************************
��ĿҪ������һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
��������λ��������ʵ��n&(n-1)
***************************************************************************
*/
/*����һ��
 *����������ж����������е�1��������1
 *1�������������n��ÿһλ����������
*/
int Numberof(int n)
{
    int count = 0;
    int flag = 1;
    while (flag != 0)
    {
        if((n & flag) != 0)//�˴�������while������ѭ��
        {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}
//��������
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
��ĿҪ�󣺸���һ��double���͵ĸ�����base��int���͵�����exponent��
          ��base��exponent�η�����֤base��exponent��ͬʱΪ0
����������base����0��exponent����0���������
      ��Ҫ����exponentС��0�����
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
��ĿҪ������һ���������飬ʵ��һ�����������������������ֵ�˳��
          ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
          ����֤������������ż����ż��֮������λ�ò��䡣
***************************************************************************
*/
/*����һ��
      �¿���һ�����飬�Ȱ�������push,�ٰ�ż��push
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
/*��������
      ʹ��ð��������㷨������ǰż����ͽ���
      �������ַ�����Ч�ʲ��ߣ��кܶ��ظ��Ľ�������,�Ҳ��ȶ�
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
/*��������
     ��Ϊ��ĿҪ�����λ�ò��䣬���Դ����ȶ��Ե����⣬�ع����ǵ����������㷨
     ���������ǱȽ��ȶ��ġ�����Ҫ��������ǰż���ں����Դ����ж�����Ų������

*/
void reOrderArray2(vector<int>& array)
{
    for (int i = 1; i < array.size(); i++)//ע�⣡�˴���i�Ǵ�1��ʼ��
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
��ĿҪ������һ����������������е�����k����㡣
***************************************************************************
*/
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
/*����һ��
  ʹ��ջ�������ѹ��ջ�У���ȡ����k����㼴��
  ע�⣡�������ʵ���д���
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
/*��������
  ʹ������ָ�룬p2ָ������k-1����Ȼ����һ���ߣ�
  ֱ��p2Ϊ���һ��ʱ��p1Ϊ������k�����
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
        else return NULL;//˵��k�Ѿ�������������
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