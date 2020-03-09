#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*
   ��Ŀ������ʹ������ջ��ʵ�ֶ���
*/

/*
   ��Ŀ������������ȷ�����еĽṹ���Ƚ��ȳ���ջ�Ľṹ���Ƚ����������ʵ�����£�
                  1����ӣ���Ԫ�ؽ�ջA
				  2�����ӣ��ж�ջB�Ƿ�Ϊ�գ����Ϊ�գ���ջA�е�����Ԫ��pop,��push
				  ��ջB�����ջB��Ϊ�գ�ջBֱ�ӳ�ջ
*/

class Solution
{
public:
    void push(int node) {
		stack1.push(node);
    }

    int pop() {
        int a;
		if(stack2.empty()){
			while(!stack1.empty()){
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();
		stack2.pop();
		return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


/*
    ��չ������������ʵ��ջ
	������
	      1����ջ����Ԫ�ؽ���
		  2����ջ���ж϶�A��Ԫ�صĸ����Ƿ�Ϊ1���������1,����ӣ����򽫶���A��
		  Ԫ���Դ˳����в��������B��ֱ������A�е�Ԫ������һ����Ȼ�����A�����У�
		  �ٰ�B�е�Ԫ�س������Դ˷������A��

		  ������ʵ����������ԱȽ��鷳����ʵ��һ�����м���ʵ�֣�
		  ֻ�ý�n-1��βԪ���ó���ͷ�壬�ٳ���βԪ�أ�����ɾ����βԪ��
*/

class Solution
{
public:
    void push(int node) {
		queue1.push(node);
    }

    int pop() {
		int size = queue1.size() - 1;
		for(int i = 0; i < size; i++){

			//�Ѷ���ǰ���Ԫ��ȫ���ó����������
			queue1.push(queue1.front());
			queue1.pop();
		}
		int front = queue1.front();
		queue1.pop();
		return front;
    }
private:
    queue<int> queue1;
};