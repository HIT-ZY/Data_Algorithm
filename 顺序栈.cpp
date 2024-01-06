#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int Elemtype;
typedef struct sqstack
{
	Elemtype data[MAXSIZE];
	int top;
}SqStack;

class StackList
{
public:
	// 新建一个空栈
	void InitStack();
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
	int StackLength();
	// 打印栈元素
	void StackShow();

protected:
private:
	SqStack s;
	int length;
};

int main()
{
	StackList SL;
	SL.InitStack();
	SL.Push(1);
	SL.Push(2);
	SL.Push(3);
	SL.Push(4);
	SL.Push(5);
	SL.StackShow();
	cout << SL.GetTop() << endl;
	cout << SL.StackEmpty() << endl;
	cout << SL.StackLength() << endl;
	SL.Pop();
	SL.Pop();
	SL.StackShow();
	cout << SL.GetTop() << endl;
	cout << SL.StackEmpty() << endl;
	cout << SL.StackLength() << endl;
	SL.CleanStack();
	SL.StackShow();
	cout << SL.GetTop() << endl;
	cout << SL.StackEmpty() << endl;
	cout << SL.StackLength() << endl;
	return 0;
}

// 新建一个空栈
void StackList::InitStack()
{
	s.top = -1;   // -1代表空栈
	length = 0;
}

// 清空栈
void StackList::CleanStack()
{
	s.top = -1;
	length = 0;
}

// 判断栈是否为空
bool StackList::StackEmpty()
{
	if (s.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 获取栈顶元素
Elemtype StackList::GetTop()
{
	if (!StackEmpty())
	{
		return s.data[s.top];
	}
	else
	{
		cout << "空栈，无法获取栈顶元素！" << endl;
		return -1;
	}
}

// 插入元素
void StackList::Push(Elemtype e)
{
	s.top++;
	s.data[s.top] = e;
	length++;
}

// 删除元素
void StackList::Pop()
{
	s.top--;
	length--;
}

// 获取栈元素个数
int StackList::StackLength()
{
	return length;
}

// 打印栈元素
void StackList::StackShow()
{
	for (int i = 0; i < length; i++)
	{
		cout << s.data[i] << " ";
	}
	cout << endl;
}