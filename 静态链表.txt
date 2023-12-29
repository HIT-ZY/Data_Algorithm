#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int Elemtype;
typedef struct
{
	Elemtype data;
	int cur;
}StaticData;

class StaticLinkList
{
public:
	// 初始化静态链表
	StaticLinkList();
	// 申请空间
	int MallocSSL();
	// 在第m个位置插入元素e
	void ListInsert(int m, Elemtype e);
	// 删除位置为m的元素
	void ListDelete(int m);
	// 释放空间
	void FreeSSL(int k);
	// 获取静态链表长度
	int GetLength();
	// 打印静态链表中所有元素
	void ListShow();
protected:
private:
	StaticData staticList[MAXSIZE];
	int length;
};

int main()
{
	StaticLinkList L;
	L.ListInsert(1, 10);
	L.ListInsert(2, 9);
	L.ListInsert(3, 8);
	L.ListInsert(4, 7);
	L.ListInsert(5, 6);
	cout << L.GetLength() << endl;
	L.ListShow();
	L.ListDelete(2);
	L.ListShow();
	return 0;
}

// 初始化静态链表
StaticLinkList::StaticLinkList()
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		staticList[i].cur = i + 1;
	}
	staticList[MAXSIZE - 1].cur = 0;
	length = 0;
}

// 申请空间
int StaticLinkList::MallocSSL()
{
	int i = staticList[0].cur;
	if (staticList[0].cur)
	{
		staticList[0].cur = staticList[i].cur;
	}
	return i;
}

// 在第m个位置插入元素e
void StaticLinkList::ListInsert(int m, Elemtype e)
{
	int j;
	int k = MAXSIZE - 1;
	if (m > 0 && m <= MAXSIZE)
	{
		j = MallocSSL();
		if (j)
		{
			staticList[j].data = e;
			for (int i = 1; i < j; i++)
			{
				k = staticList[k].cur;
			}
			staticList[j].cur = staticList[k].cur;
			staticList[k].cur = j;
		}
		length++;
	}
	else
	{
		cout << "插入元素下标不合法！" << endl;
	}
}

// 删除位置为m的元素
void StaticLinkList::ListDelete(int m)
{
	int temp;
	int k = MAXSIZE - 1;
	if (m > 0 && m <= MAXSIZE)
	{
		for (int i = 1; i < m; i++)
		{
			k = staticList[k].cur;
		}
		temp = staticList[k].cur;
		staticList[k].cur = staticList[temp].cur;
		FreeSSL(temp);
		length--;
	}
	else
	{
		cout << "删除元素下标不合法！" << endl;
	}
}

// 释放空间
void StaticLinkList::FreeSSL(int k)
{
	// 新的元素最优先考虑这个位置
	staticList[k].cur = staticList[0].cur;
	staticList[0].cur = k;
}

// 获取静态链表长度
int StaticLinkList::GetLength()
{
	return length;
}

void StaticLinkList::ListShow()
{
	int k = MAXSIZE - 1;
	for (int i = 0; i < length; i++)
	{
		k = staticList[k].cur;
		cout << staticList[k].data << " ";
	}
	cout << endl;
}