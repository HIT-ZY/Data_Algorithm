#include <iostream>
using namespace std;

typedef int Elemtype;
typedef struct queuenode
{
	Elemtype data;
	struct queuenode* next;
}QueueNode;
typedef struct queuelink
{
	QueueNode* front;
	QueueNode* rear;
}QueueLink;

class QueueLinkList
{
public:
	// 初始化一个空队列
	QueueLinkList();
	// 清空队列
	void ClearQueue();
	// 判断队列是否为空
	bool QueueEmpty();
	// 返回队头元素
	Elemtype GetHead();
	// 插入元素
	void EnQueue(Elemtype e);
	// 删除元素
	void DeQueue();
	// 返回队列长度
	int QueueLength();
	// 打印队列
	void ShowQueue();
protected:
private:
	QueueLink ql;
	int length;
};

int main()
{
	QueueLinkList qll;
	cout << qll.QueueEmpty() << endl;
	qll.EnQueue(1);
	qll.EnQueue(2);
	qll.EnQueue(3);
	qll.EnQueue(4);
	qll.EnQueue(5);
	cout << qll.QueueLength() << endl;
	qll.ShowQueue();
	qll.DeQueue();
	qll.DeQueue();
	cout << qll.QueueLength() << endl;
	qll.ShowQueue();
	qll.EnQueue(6);
	qll.EnQueue(7);
	qll.EnQueue(8);
	qll.EnQueue(9);
	qll.EnQueue(10);
	qll.EnQueue(11);
	cout << qll.QueueLength() << endl;
	qll.ShowQueue();
	qll.DeQueue();
	qll.DeQueue();
	cout << qll.QueueLength() << endl;
	qll.ShowQueue();
	qll.ClearQueue();
	cout << qll.QueueLength() << endl;
	qll.ShowQueue();
	cout << qll.QueueEmpty() << endl;
	return 0;
}

// 初始化一个空队列
QueueLinkList::QueueLinkList()
{
	QueueNode* headNode = new QueueNode;
	ql.front = headNode;
	ql.rear = headNode;
	ql.rear->next = nullptr;
	length = 0;
}

// 清空队列
void QueueLinkList::ClearQueue()
{
	ql.rear = ql.front;
	ql.rear->next = nullptr;
	length = 0;
}

// 判断队列是否为空
bool QueueLinkList::QueueEmpty()
{
	if (ql.front == ql.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 返回队头元素
Elemtype QueueLinkList::GetHead()
{
	if (!QueueEmpty())
	{
		return ql.front->next->data;
	}
}

// 插入元素
void QueueLinkList::EnQueue(Elemtype e)
{
	QueueNode* s = new QueueNode;
	s->data = e;
	ql.rear->next = s;
	ql.rear = s;
	ql.rear->next = nullptr;
	length++;
}

// 删除元素
void QueueLinkList::DeQueue()
{
	QueueNode* p = ql.front->next;
	ql.front->next = p->next;
	delete p;
	length--;
}

// 返回队列长度
int QueueLinkList::QueueLength()
{
	return length;
}

// 打印队列
void QueueLinkList::ShowQueue()
{
	QueueNode* p = ql.front;
	while (p)
	{
		p = p->next;
		if (p)
		{
			cout << p->data << " ";
		}
	}
	cout << endl;
}