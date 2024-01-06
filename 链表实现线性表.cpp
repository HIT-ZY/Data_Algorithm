#include <iostream>
using namespace std;

typedef int Elemtype;
typedef struct node
{
	Elemtype data;
	struct node* next;
}Node;

class LinkList
{
public:
	LinkList();
	// 尾插法创建链表
	void CreateList();
	// 删除链表
	void DeleteList();
	// 显示链表
	void ShowList();
	// 获取链表长度
	int GetLength();
	// 获取链表第m个位置元素
	Elemtype GetElem(int m);
	// 在线性表第m个位置插入新元素
	void ListInsert(int m, Elemtype e);
	// 删除线性表第m个位置元素
	void ListDelete(int m);
	// 判断线性表是否为空
	bool ListEmpty();
protected:
private:
	Node *phead;     // 头指针
	int length;      // 长度
};

int main()
{
	LinkList L;
	L.CreateList();
	L.ShowList();
	cout << L.GetLength() << endl;
	cout << L.ListEmpty() << endl;
	cout << L.GetElem(2) << endl;
	L.ListInsert(10, 100);
	L.ShowList();
	L.ListDelete(5);
	L.ShowList();
	L.DeleteList();
	//L.ShowList();
	cout << L.GetLength() << endl;
	return 0;
}	 


LinkList::LinkList()
{
	phead = new Node;
	length = 0;
}

// 尾插法创建链表
void LinkList::CreateList()
{
	int n;
	Node *p = new Node;
	p = phead;
	cout << "请输入创建链表的长度：" << endl;
	cin >> n;
	Node* s;
	Elemtype num;
	for (int i = 0; i < n; i++)
	{
		s = new Node;
		cin >> num;
		s->data = num;
		p->next = s;
		p = s;
		length++;
	}
	p->next = nullptr;
}

// 删除链表
void LinkList::DeleteList()
{
	Node* p = phead->next;
	Node* q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
		length--;
	}
}

// 显示链表
void LinkList::ShowList()
{
	Node* p = phead->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

// 获取链表长度
int LinkList::GetLength()
{
	return length;
}

// 判断线性表是否为空
bool LinkList::ListEmpty()
{
	if (length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 获取链表第m个位置元素
Elemtype LinkList::GetElem(int m)
{
	Node* p = phead;
	if ((m <= length) && (m > 0))
	{
		for (int i = 0; i < m; i++)
		{
			p = p->next;
		}
		return p->data;
	}
	else
	{
		cout << "获取元素下标不合法！";
		return -1;
	}
}

// 在线性表第m个位置插入新元素
void LinkList::ListInsert(int m, Elemtype e)
{
	Node* p = phead;
	if ((m <= length) && (m > 0))
	{
		for (int i = 0; i < m - 1; i++)
		{
			p = p->next;
		}
		Node* q = p->next;
		Node* temp = new Node;
		p->next = temp;
		temp->next = q;
		temp->data = e;
		length++;
	}
	else
	{
		cout << "元素下标越界，无法插入！";
	}
}

// 删除线性表第m个位置元素
void LinkList::ListDelete(int m)
{
	Node* p = phead;
	if ((m <= length) && (m > 0))
	{
		for (int i = 0; i < m - 1; i++)
		{
			p = p->next;
		}
		Node* q = p->next;
		Node* r = q->next;
		p->next = r;
		delete q;
		length--;
	}
	else
	{
		cout << "元素下标越界，无法删除！";
	}
}