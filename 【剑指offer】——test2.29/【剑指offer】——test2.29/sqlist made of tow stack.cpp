#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*
   题目描述：使用两个栈来实现队列
*/

/*
   题目分析：首先明确，队列的结构是先进先出，栈的结构是先进后出，所以实现如下：
                  1、入队：将元素进栈A
				  2、出队：判断栈B是否为空，如果为空，则将栈A中的所有元素pop,并push
				  进栈B，如果栈B不为空，栈B直接出栈
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
    扩展：用两个队列实现栈
	分析：
	      1、入栈：将元素进队
		  2、出栈：判断队A中元素的个数是否为1，如果等于1,则出队，否则将队列A中
		  元素以此出队列并放入队列B，直到队列A中的元素留下一个，然后队列A出队列，
		  再把B中的元素出队列以此放入队列A中

		  但是其实这样做会相对比较麻烦，其实用一个队列即可实现：
		  只用将n-1队尾元素拿出来头插，再出队尾元素，或是删除队尾元素
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

			//把队列前面的元素全部拿出来重新入队
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