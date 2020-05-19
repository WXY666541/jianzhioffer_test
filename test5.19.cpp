/*
实现一个单链表的建立、测长和打印
*/

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct student
{
	int m_data;
	struct student* next;
}node;

node* create()
{
	node* head, * p, * s;
	int flag = 1;
	int x;
	head = (node*)malloc(sizeof(node));
	p = head;
	while (flag)
	{
		printf("pleadse input the data\n");
		scanf_s("%d", &x);
		if (x != 0)
		{
			s = (node*)malloc(sizeof(int));
			s->m_data = x;
			printf("%d\n", s->m_data);
			p->next = s;
			p = s;
		}
		else flag = 0;
	}

	head = head->next;
	p->next = NULL;
	return head;
}

int length(node* head)
{
	int count = 0;
	node* p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

void Print(node* head)
{
	node* p = head;
	while (p != NULL)
	{
		printf("%d", p->m_data);
		p = p->next;
	}
}

//删除单链表的结点
node* del(node* head, int num)
{
	node* p1, * p2;
	p1 = head;
	while (p1->m_data != num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->m_data == num)
	{
		if (p1 == head)
		{
			head = p1->next;
			free(p1);
		}
		else
		{
			p2->next = p1->next;
		}
	}
	else
	{
		printf("could not been foud %d\n", num);
	}
	return head;
}

//单链表的插入
node* insert(node* head, int num)
{
	node* p0, * p1, * p2;
	p0 = (node*)malloc(sizeof(int));
	p0->m_data = num;
	p1 = head;

	while (p0->m_data > p1->m_data&& p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->m_data <= p1->m_data)
	{
		if (p1 == head)
		{
			p0->next = p1;
			p0 = head;
		}
		else
		{
			p2->next = p0;
			p2->next = p1;
		}

	}
	else
	{
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}

//单链表的排序
void* Sort(node* head)
{
	node* p;
	int temp;
	int n = length(head);

	if (head == NULL || head->next == NULL)
		return head;
	p = head;
	for (int j = 1; j < n; j++)
	{
		p = head;
		for (int i = 0; i < n - j; i++)
		{
			if (p->m_data > p->next->m_data)
			{
				temp = p->m_data;
				p->m_data = p->next->m_data;
				p->next->m_data = p->m_data;
			}
			p = p->next;
		}
	}
	return head;
}

//单链表的逆置
void* Reverse(node* head)
{
	node* p1, * p2, * p3;
	if (head == NULL || head->next == NULL)
		return head;

	p1 = head;
	p2 = p1->next;

	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p2 = p1;
		p3 = p2;
	}
	head->next = NULL;
	head = p1;
	return head;
}
int main()
{
	node* head, stud;
	int n, del_num, insert_num;
	head = create();
	Print(head);
	cout << "\nInt : ";
	cin >> del_num;
	head = del(head, del_num);
	Print(head);

	cout << "please input the insert number:";
	cin >> insert_num;
	head = insert(head, insert_num);
	Print(head);
	return 0;
}