#include <iostream>
using namespace std;

#define MAX_LENGTH 100

typedef int Elemtype;
typedef struct arraylist
{
	Elemtype array[MAX_LENGTH];
	int length;
}ArrayList;

class SequentialStorageList
{
public:
	SequentialStorageList(ArrayList AL)
	{
		this->L = AL;
	}
	// 初始化一个线性表
	void InitList();
	// 判断线性表是否为空
	bool ListEmpty();
	// 清空线性表
	void ClearList();
	// 获得线性表中第m个位置元素
	Elemtype GetElem(int m);
	// 查找元素
	int LocateElem(Elemtype e);
	// 在线性表第m个位置插入新元素
	void ListInsert(int m, Elemtype e);
	// 删除线性表第m个位置元素
	Elemtype ListDelete(int m);
	// 获得线性表元素个数
	int ListLength();
	// 获得线性表元素
	ArrayList ListArray();
protected:

private:
	ArrayList L;
};

int main()
{
	ArrayList AList;
	AList.length = 0;
	int i;
	for (i = 0; i < 10; i++)
	{
		AList.array[i] = i;
		AList.length++;
	}
	SequentialStorageList SSL(AList);
	//SSL.InitList();
	cout << SSL.ListEmpty() << endl;
	cout << SSL.GetElem(5) << endl;
	cout << SSL.LocateElem(8) << endl;
	SSL.ListInsert(1, 10);
	for (i = 0; i < SSL.ListLength(); i++)
	{
		cout << SSL.ListArray().array[i] << " ";
	}
	cout << endl;
	SSL.ListDelete(3);
	for (i = 0; i < SSL.ListLength(); i++)
	{
		cout << SSL.ListArray().array[i] << " ";
	}
	cout << endl;
	return 0;
}

// 初始化一个线性表
void SequentialStorageList::InitList()
{
	//int i;
	L.length = 0;
	cout << "Initial success!" << endl;
	/*for (i = 0; i < 10; i++)
	{
		L.array[i] = i;
		L.length++;
	}*/
}

// 判断线性表是否为空
bool SequentialStorageList::ListEmpty()
{
	if (L.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 清空线性表
void SequentialStorageList::ClearList()
{
	if (!ListEmpty())
	{
		L.length = 0;
		cout << "Empty success!" << endl;
	}
}

// 获得线性表中第i个位置元素
Elemtype SequentialStorageList::GetElem(int m)
{
	if (L.length == 0)
	{
		cout << "列表为空，无法获取元素！";
		return 0;
	}
	else if(m < 1 || m > L.length)
	{
		cout << "位置越界，不合法！";
		return 0;
	}
	else
	{
		return L.array[m - 1];
	}
}

// 查找元素
int SequentialStorageList::LocateElem(Elemtype e)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.array[i] == e)
		{
			cout << "找到了！";
			return i + 1;   // 返回列表位置
		}
	}
	cout << "没找到！";
	return -1;
}

// 在线性表第i个位置插入新元素
void SequentialStorageList::ListInsert(int m, Elemtype e)
{
	int i;
	for (i = L.length; i > m - 1; i--)
	{
		L.array[i] = L.array[i - 1];
	}
	L.array[m - 1] = e;
	L.length++;
}

// 删除线性表第i个位置元素
Elemtype SequentialStorageList::ListDelete(int m)
{
	int i;
	Elemtype temp = L.array[m - 1];
	for (i = m - 1; i < L.length - 1; i++)
	{
		L.array[i] = L.array[i + 1];
	}
	L.length--;
	return temp;
}

// 获得线性表元素个数
int SequentialStorageList::ListLength()
{
	return L.length;
}

// 获得线性表元素
ArrayList SequentialStorageList::ListArray()
{
	return L;
}