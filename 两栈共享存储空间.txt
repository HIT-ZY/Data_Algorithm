#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int Elemtype;
typedef struct sqdoublestack
{
	Elemtype data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

class DoubleStack
{
public:
	// 新建两个空栈
	DoubleStack();
	// 判断两栈是否已满
	bool StackFull();
	// 清空栈
	void CleanStack(int stackNumber);
	// 判断栈是否为空
	bool StackEmpty(int stackNumber);
	// 获取栈顶元素
	Elemtype GetTop(int stackNumber);
	// 插入元素
	void Push(int stackNumber, Elemtype e);
	// 删除元素
	void Pop(int stackNumber);
	// 获取栈元素个数
	int StackLength(int stackNumber);
	// 打印栈元素
	void StackShow(int stackNumber);
protected:
private:
	SqDoubleStack sds;
	int length1;
	int length2;
};

int main()
{
	DoubleStack s;
	cout << s.StackFull() << endl;
	cout << s.StackEmpty(1) << endl;
	cout << s.StackEmpty(2) << endl;
	s.Push(1, 1);
	s.Push(1, 2);
	s.Push(1, 3);
	s.Push(1, 4);
	s.Push(1, 5);
	s.Push(2, 10);
	s.Push(2, 9);
	s.Push(2, 8);
	s.Push(2, 7);
	s.Push(2, 6);
	s.StackShow(1);
	s.StackShow(2);
	s.Pop(1);
	s.Pop(1);
	s.Pop(2);
	s.Pop(2);
	s.StackShow(1);
	s.StackShow(2);
	cout << s.StackLength(1) << endl;
	cout << s.StackLength(2) << endl;
	s.CleanStack(1);
	s.CleanStack(2);
	cout << s.StackLength(1) << endl;
	cout << s.StackLength(2) << endl;
	return 0;
}

// 新建两个空栈
DoubleStack::DoubleStack()
{
	sds.top1 = -1;
	sds.top2 = MAXSIZE;
	length1 = 0;
	length2 = 0;
}

// 判断两栈是否已满
bool DoubleStack::StackFull()
{
	if (sds.top1 + 1 == sds.top2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 清空栈
void DoubleStack::CleanStack(int stackNumber)
{
	if (stackNumber == 1)
	{
		sds.top1 = -1;
		length1 = 0;
	}
	else if (stackNumber == 2)
	{
		sds.top2 = MAXSIZE;
		length2 = 0;
	}
	else
	{
		cout << "请输入正确的栈选项！" << endl;
	}
}

// 判断栈是否为空
bool DoubleStack::StackEmpty(int stackNumber)
{
	if (stackNumber == 1)
	{
		if (sds.top1 == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (stackNumber == 2)
	{
		if (sds.top2 == MAXSIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "请输入正确的栈选项！" << endl;
	}
}

// 获取栈顶元素
Elemtype DoubleStack::GetTop(int stackNumber)
{
	if (stackNumber == 1)
	{
		return sds.data[sds.top1];
	}
	else if (stackNumber == 2)
	{
		return sds.data[sds.top2];
	}
	else
	{
		cout << "请输入正确的栈选项！" << endl;
	}
}

// 插入元素
void DoubleStack::Push(int stackNumber, Elemtype e)
{
	if (StackFull())
	{
		cout << "两栈已满，无法插入！" << endl;
	}
	else
	{
		if (stackNumber == 1)
		{
			sds.top1++;
			sds.data[sds.top1] = e;
			length1++;
		}
		else if (stackNumber == 2)
		{
			sds.top2--;
			sds.data[sds.top2] = e;
			length2++;
		}
		else
		{
			cout << "请输入正确的栈选项！" << endl;
		}
	}
}

// 删除元素
void DoubleStack::Pop(int stackNumber)
{
	if (stackNumber == 1)
	{
		if (!StackEmpty(1))
		{
			sds.top1--;
			length1--;
		}
		else
		{
			cout << "1栈已为空，无法删除抛出元素！" << endl;
		}
	}
	else if (stackNumber == 2)
	{
		if (!StackEmpty(2))
		{
			sds.top2++;
			length2--;
		}
		else
		{
			cout << "2栈已为空，无法删除抛出元素！" << endl;
		}
	}
	else
	{
		cout << "请输入正确的栈选项！" << endl;
	}
}

// 获取栈元素个数
int DoubleStack::StackLength(int stackNumber)
{
	if (stackNumber == 1)
	{
		return length1;
	}
	else if (stackNumber == 2)
	{
		return length2;
	}
	else
	{
		cout << "请输入正确的栈选项！" << endl;
	}
}

// 打印栈元素
void DoubleStack::StackShow(int stackNumber)
{
	if (stackNumber == 1)
	{
		if (!StackEmpty(1))
		{
			for (int i = 0; i <= sds.top1; i++)
			{
				cout << sds.data[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "1栈为空！" << endl;
		}
	}
	else if (stackNumber == 2)
	{
		if (!StackEmpty(2))
		{
			for (int i = MAXSIZE - 1; i >= sds.top2; i--)
			{
				cout << sds.data[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "2栈为空！" << endl;
		}
	}
	else
	{
		cout << "请输入正确的栈选项！" << endl;
	}
}