#include <iostream>
using namespace std;

typedef int Elemtype;
typedef struct stacknode
{
	Elemtype data;
	struct stacknode* next;
}StackNode;
typedef struct linkstack
{
	StackNode* top;
	int count;
}LinkStack;

class LinkListStack
{
public:
	// 新建一个空栈
	LinkListStack();
	// 清空栈
	void CleanStack();
	// 判断栈是否为空
	bool StackEmpty();
	// 获取栈顶元素
	Elemtype GetTop();
	// 插入元素
	void Push(Elemtype e);
	// 删除元素
	void Pop();
	// 获取栈元素个数
	int StackCount();
	// 打印栈元素
	void StackShow();
protected:
private:
	LinkStack ls;
};

int main()
{
	LinkListStack SL;
	SL.Push(1);
	SL.Push(2);
	SL.Push(3);
	SL.Push(4);
	SL.Push(5);
	SL.StackShow();
	cout << SL.GetTop() << endl;
	cout << SL.StackEmpty() << endl;
	cout << SL.StackCount() << endl;
	SL.Pop();
	SL.Pop();
	SL.StackShow();
	cout << SL.GetTop() << endl;
	cout << SL.StackEmpty() << endl;
	cout << SL.StackCount() << endl;
	SL.CleanStack();
	SL.StackShow();
	cout << SL.GetTop() << endl;
	cout << SL.StackEmpty() << endl;
	cout << SL.StackCount() << endl;
	return 0;
}

// 新建一个空栈
LinkListStack::LinkListStack()
{
	ls.count = 0;
	ls.top = nullptr;
}

// 清空栈
void LinkListStack::CleanStack()
{
	ls.count = 0;
	ls.top = nullptr;
}

// 判断栈是否为空
bool LinkListStack::StackEmpty()
{
	if (ls.top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 获取栈顶元素
Elemtype LinkListStack::GetTop()
{
	if (!StackEmpty())
	{
		return ls.top->data;
	}
	else
	{
		cout << "空栈，不可获取栈顶元素！" << endl;
		return -1;
	}
}

// 插入元素
void LinkListStack::Push(Elemtype e)
{
	StackNode* s = new StackNode;
	s->data = e;
	s->next = ls.top;
	ls.top = s;
	ls.count++;
}

// 删除元素
void LinkListStack::Pop()
{
	if (!StackEmpty())
	{
		StackNode* p = ls.top;
		ls.top = ls.top->next;
		delete p;
		ls.count--;
	}
	else
	{
		cout << "空栈，不可抛出元素！" << endl;
	}
}

// 获取栈元素个数
int LinkListStack::StackCount()
{
	return ls.count;
}

// 打印栈元素
void LinkListStack::StackShow()
{
	StackNode* p = ls.top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}