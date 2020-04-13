#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;

/*
******************************
两个栈实现一个队列
******************************
*/
#if 0
template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
	{
		throw new exception("queue is empty");
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}

void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main()
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}


/*
******************************
两个队列实现一个栈
******************************
*/
template<typename T> class CStack
{
public:
	CStack(void);
	~CStack(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	queue<T> q1;
	queue<T> q2;
};

template<typename T> 
void CStack<T>::appendTail(const T& node)
{
	if (!q1.empty())
		q1.push(node);
	else
		q2.push(node);
}

template<typename T>
T CStack<T>::deleteHead()
{
	int ret = 0;
	if (!q1.empty())
	{
		int num = q1.size();
		while (num > 1)
		{
			q2.push(q1.front());
			q1.pop();
			num--;
		}
		ret = q1.front;
		q1.pop();
	}
	else
	{
		int num = q2.size();
		while (num > 1)
		{
			q1.push(q2.front());
			q2.pop();
			num--;
		}
		ret = q2.front;
		q2.pop();
	}
	return ret;
}


/*
******************************
包含min函数的栈
******************************
*/
template <typename T> 
class StackWithMin
{
public:
	StackWithMin(void) {}
	virtual ~StackWithMin(void) {}

	T& top(void);
	const T& top(void) const;

	void push(const T& value);
	void pop(void);

	const T& min(void) const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
	std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}
template <typename T> T& StackWithMin<T>::top()
{
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
	return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
	return m_data.size();
}

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

int main()
{
	StackWithMin<int> stack;

	stack.push(3);
	Test("Test1", stack, 3);

	stack.push(4);
	Test("Test2", stack, 3);

	stack.push(2);
	Test("Test3", stack, 2);

	stack.push(3);
	Test("Test4", stack, 2);

	stack.pop();
	Test("Test5", stack, 2);

	stack.pop();
	Test("Test6", stack, 3);

	stack.pop();
	Test("Test7", stack, 3);

	stack.push(0);
	Test("Test8", stack, 0);

	return 0;
}
#endif

/*
******************************
栈的压入、弹出序列
******************************
*/
bool IsPopOrder(const int* Ppush, const int* Ppop, int nlength)
{
	bool bpossible = false;
	if (Ppush != nullptr && Ppop != nullptr && nlength > 0)
	{
		const int* pNextPush = Ppush;
		const int* pNextPop = Ppop;

		stack<int> stackData;//定义一个辅助栈

		while (pNextPop - Ppop < nlength)
		{
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - Ppush == nlength)//如果已经把压栈元素全部压入
					break;

				stackData.push(*pNextPush);//如果辅助栈中的栈顶元素不等于弹出序列Ppop的栈顶元素
				pNextPush++;
			}
			if (stackData.top() != *pNextPop)//如果所有数字都压入过后，仍然没有找到下一个弹出的数字
				break;

			stackData.pop();//匹配成功，辅助栈弹出寻找下一个弹出的数字
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - Ppop == nlength)
			bpossible = true;//辅助栈为空并且弹出序列遍历完毕
	}
	return bpossible;
}

// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (IsPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	Test("Test1", push, pop, nLength, true);
}

void Test2()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	Test("Test2", push, pop, nLength, true);
}

void Test3()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	Test("Test3", push, pop, nLength, false);
}

void Test4()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	Test("Test5", push, pop, nLength, false);
}

void Test6()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	Test("Test6", push, pop, nLength, true);
}

void Test7()
{
	Test("Test7", NULL, NULL, 0, false);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}
