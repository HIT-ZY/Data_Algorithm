#include <iostream>
using namespace std;

#define MAXSIZE 10

typedef int Elemtype;
typedef struct sqqueue
{
	Elemtype data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

class QueueList
{
public:
	// 初始化一个空队列
	QueueList();
	// 清空队列
	void ClearQueue();
	// 判断队列是否为空
	bool QueueEmpty();
	// 判断队列是否已满
	bool QueueFull();
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
	SqQueue sq;
	int length;
};

int main()
{
	QueueList ql;
	cout << ql.QueueEmpty() << endl;
	ql.EnQueue(1);
	ql.EnQueue(2);
	ql.EnQueue(3);
	ql.EnQueue(4);
	ql.EnQueue(5);
	cout << ql.QueueLength() << endl;
	ql.ShowQueue();
	ql.DeQueue();
	ql.DeQueue();
	cout << ql.QueueLength() << endl;
	ql.ShowQueue();
	ql.EnQueue(6);
	ql.EnQueue(7);
	ql.EnQueue(8);
	ql.EnQueue(9);
	ql.EnQueue(10);
	ql.EnQueue(11);
	cout << ql.QueueLength() << endl;
	ql.ShowQueue();
	cout << ql.QueueFull() << endl;
	ql.DeQueue();
	ql.DeQueue();
	cout << ql.QueueLength() << endl;
	ql.ShowQueue();
	ql.ClearQueue();
	cout << ql.QueueLength() << endl;
	ql.ShowQueue();
	cout << ql.QueueEmpty() << endl;
	return 0;
}

// 初始化一个空队列
QueueList::QueueList()
{
	sq.front = 0;
	sq.rear = 0;
	length = 0;
}

// 清空队列
void QueueList::ClearQueue()
{
	sq.front = 0;
	sq.rear = 0;
	length = 0;
}

// 判断队列是否为空
bool QueueList::QueueEmpty()
{
	if (sq.front == sq.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 判断队列是否已满
bool QueueList::QueueFull()
{
	if ((sq.rear + 1) % MAXSIZE == sq.front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 返回队头元素
Elemtype QueueList::GetHead()
{
	return sq.data[sq.front];
}

// 插入元素
void QueueList::EnQueue(Elemtype e)
{
	if (!QueueFull())
	{
		sq.data[sq.rear] = e;
		sq.rear = (sq.rear + 1) % MAXSIZE; 
		length++;
	}
	else
	{
		cout << "队列已满，不可插入！" << endl;
	}
}

// 删除元素
void QueueList::DeQueue()
{
	if (!QueueEmpty())
	{
		sq.front = (sq.front + 1) % MAXSIZE;
		length--;
	}
	else
	{
		cout << "队列为空，不可删除！" << endl;
	}
}

// 返回队列长度
int QueueList::QueueLength()
{
	return length;
}

// 打印队列
void QueueList::ShowQueue()
{
	for (int i = 0; i < length; i++)
	{
		cout << sq.data[(sq.front + i) % MAXSIZE] << " ";
	}
	cout << endl;
}