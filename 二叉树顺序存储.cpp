#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

// 最大结点数
#define MAX_NODE_NUMBER 100
// 空结点数据表示
#define EMPTY 0

// 结点的数据类型
typedef int SqBiTree;

// 结点的层
typedef struct position
{
	int level;     // 层数序号
	int order;     // 本层序号
}Position;

class BiTreeArra
{
public:
	// 构造空树T
	bool InitBiTree();
	// 按层序给结点赋值
	void CreateTree();
	// 若树T存在，则将树T清为空树
	bool ClearTree();
	// 若T为空树则返回true，否则返回false
	bool TreeEmpty();
	// 返回树的深度
	int TreeDepth();
	// 返回T的根结点
	SqBiTree Root();
	// cur_e是树T中一个结点位置，返回此节点的值
	SqBiTree Value(Position cur_e);
	// 给树T的结点cur_e赋值为value
	bool Assign(Position cur_e, SqBiTree value);
	// 若cur_e是树T的非根结点，则返回它的双亲，否则返回空
	SqBiTree Parent(SqBiTree e);
	// 若cur_e是树T的非叶结点，则返回它的左孩子，否则返回空
	SqBiTree LeftChild(SqBiTree e);
	// 若cur_e是树T的非叶结点，则返回它的右孩子，否则返回空
	SqBiTree RightChild(SqBiTree e);
	// 若cur_e有左兄弟，则返回它的左兄弟，否则返回空
	SqBiTree LeftSibling(SqBiTree e);
	// 若cur_e有右兄弟，则返回它的右兄弟，否则返回空
	SqBiTree RightSibling(SqBiTree e);
	// 先序遍历二叉树
	void PreOrderTraverse();
	// PreOrderTraverse()调用 
	void PreTraverse(int e);
	// 中序遍历二叉树
	void InOrderTraverse();
	// InOrderTraverse()调用
	void InTraverse(int e);
	// 后序遍历二叉树
	void PostOrderTraverse();
	// PostOrderTraverse()调用 
	void PostTraverse(int e);
	// 层序遍历二叉树
	void LevelOrderTraverse();
	// 逐层、按本层序号输出二叉树
	void Print();
protected:
private:
	SqBiTree T[MAX_NODE_NUMBER];
};

int main()
{
	BiTreeArra BTA;
	BTA.InitBiTree();
	cout << BTA.TreeEmpty() << endl;
	BTA.CreateTree();
	cout << BTA.TreeEmpty() << endl;
	cout << BTA.TreeDepth() << endl;
	cout << BTA.Root() << endl;
	Position p;
	p.level = 3;
	p.order = 2;
	cout << BTA.Value(p) << endl;
	p.order = 3;
	BTA.Assign(p, 666);
	cout << BTA.Parent(5) << endl;
	cout << BTA.LeftChild(5) << endl;
	cout << BTA.RightChild(5) << endl;
	cout << BTA.LeftSibling(5) << endl;
	cout << BTA.RightSibling(5) << endl;
	BTA.PreOrderTraverse();
	BTA.InOrderTraverse();
	BTA.PostOrderTraverse();
	BTA.LevelOrderTraverse();
	BTA.Print();
	return 0;
}

// 构造空树T
bool BiTreeArra::InitBiTree()
{
	int i;
	for (i = 0; i < MAX_NODE_NUMBER; i++)
	{
		// 假设空树节点值全为0
		T[i] = EMPTY;
	}
	return true;
}

// 按层序给结点赋值
void BiTreeArra::CreateTree()
{
	int i = 0;
	cout << "请按层序输入结点元素的值，0表示空结点，节点数≤" << MAX_NODE_NUMBER << endl;
	while (i < 10)
	{
		T[i] = i + 1;
		i++;
	}
	while (i < MAX_NODE_NUMBER)
	{
		T[i] = EMPTY;
		i++;
	}
}

// 若树T存在，则将树T清为空树
bool BiTreeArra::ClearTree()
{
	int i;
	for (i = 0; i < MAX_NODE_NUMBER; i++)
	{
		T[i] = EMPTY;
	}
	return true;
}

// 若T为空树则返回true，否则返回false
bool BiTreeArra::TreeEmpty()
{
	// 判断根结点是否为空
	if (T[0] == EMPTY)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 返回树的深度
int BiTreeArra::TreeDepth()
{
	int num;      // 结点数
	int depth;    // 深度
	// 找出最后一个结点
	for (num = MAX_NODE_NUMBER - 1; num >= 0; num--)
	{
		if (T[num] != EMPTY)
		{
			break;
		}
	}
	// 计算深度
	for (depth = 0; depth < num; depth++)
	{
		if (num < pow(2, depth))
		{
			break;
		}
	}
	return depth;
}

// 返回T的根结点
SqBiTree BiTreeArra::Root()
{
	return T[0];
}

// cur_e是树T中一个结点位置，返回此节点的值
SqBiTree BiTreeArra::Value(Position cur_e)
{
	return T[(int)pow(2, cur_e.level - 1) + cur_e.order - 2];
}

// 给树T的结点cur_e赋值为value
bool BiTreeArra::Assign(Position cur_e, SqBiTree value)
{
	int i = (int)pow(2, cur_e.level - 1) + cur_e.order - 2;
	if (value != EMPTY && T[(i + 1) / 2 - 1] != EMPTY)
	{
		T[i] = value;
		return true;
	}
	else
	{
		return false;
	}
}

// 若cur_e是树T的非根结点，则返回它的双亲，否则返回空
SqBiTree BiTreeArra::Parent(SqBiTree e)
{
	int i;
	if (!TreeEmpty())
	{
		for (i = 1; i < MAX_NODE_NUMBER; i++)
		{
			if (T[i] == e)
			{
				return T[(i + 1) / 2 - 1];
			}
		}
	}
	else
	{
		printf("空树，不可搜索");
		return EMPTY;
	}
}

// 若cur_e是树T的非叶结点，则返回它的左孩子，否则返回空
SqBiTree BiTreeArra::LeftChild(SqBiTree e)
{
	int i;
	for (i = 0; i < MAX_NODE_NUMBER; i++)
	{
		if (T[i] == e)
		{
			if (T[2 * i + 1] != EMPTY)
			{
				return T[2 * i + 1];
			}
		}
	}
	if (i == MAX_NODE_NUMBER)
	{
		return EMPTY;
	}
}

// 若cur_e是树T的非叶结点，则返回它的右孩子，否则返回空
SqBiTree BiTreeArra::RightChild(SqBiTree e)
{
	int i;
	for (i = 0; i < MAX_NODE_NUMBER; i++)
	{
		if (T[i] == e)
		{
			if (T[2 * i + 2] != EMPTY)
			{
				return T[2 * i + 2];
			}
		}
	}
	if (i == MAX_NODE_NUMBER)
	{
		return EMPTY;
	}
}

// 若cur_e有左兄弟，则返回它的左兄弟，否则返回空
SqBiTree BiTreeArra::LeftSibling(SqBiTree e)
{
	int i;
	for (i = 1; i < MAX_NODE_NUMBER; i++)
	{
		if (T[i] == e && i % 2 == 0)
		{
			return T[i - 1];
		}
	}
	if (i == MAX_NODE_NUMBER)
	{
		return EMPTY;
	}
}

// 若cur_e有右兄弟，则返回它的右兄弟，否则返回空
SqBiTree BiTreeArra::RightSibling(SqBiTree e)
{
	int i;
	for (i = 1; i < MAX_NODE_NUMBER; i++)
	{
		if (T[i] == e && i % 2 == 1)
		{
			return T[i + 1];
		}
	}
	if (i == MAX_NODE_NUMBER)
	{
		return EMPTY;
	}
}

// 先序遍历二叉树
void BiTreeArra::PreOrderTraverse()
{
	if (!TreeEmpty())
	{
		PreTraverse(0);
	}
	cout << endl;
}

/* PreOrderTraverse()调用 */
void BiTreeArra::PreTraverse(int e)
{
	cout << T[e] << " ";
	if (T[2 * e + 1] != EMPTY)
	{
		PreTraverse(2 * e + 1);
	}
	if (T[2 * e + 2] != EMPTY)
	{
		PreTraverse(2 * e + 2);
	}
}

// 中序遍历二叉树
void BiTreeArra::InOrderTraverse()
{
	if (!TreeEmpty())
	{
		InTraverse(0);
	}
	cout << endl;
}

/* InOrderTraverse()调用 */
void BiTreeArra::InTraverse(int e)
{
	if (T[2 * e + 1] != EMPTY)
	{
		InTraverse(2 * e + 1);
	}
	cout << T[e] << " ";
	if (T[2 * e + 2] != EMPTY)
	{
		InTraverse(2 * e + 2);
	}
}

// 后序遍历二叉树
void BiTreeArra::PostOrderTraverse()
{
	if (!TreeEmpty())
	{
		PostTraverse(0);
	}
	cout << endl;
}

/* PostOrderTraverse()调用 */
void BiTreeArra::PostTraverse(int e)
{
	if (T[2 * e + 1] != EMPTY)
	{
		PostTraverse(2 * e + 1);
	}
	if (T[2 * e + 2] != EMPTY)
	{
		PostTraverse(2 * e + 2);
	}
	cout << T[e] << " ";
}

// 层序遍历二叉树
void BiTreeArra::LevelOrderTraverse()
{
	int i, j;
	for (i = MAX_NODE_NUMBER - 1; i > 0; i--)
	{
		if (T[i] != EMPTY)
		{
			break;
		}
	}
	for (j = 0; j <= i; j++)
	{
		// 只输出存在的结点
		if (T[j] != EMPTY)
		{
			cout << T[j] << " ";
		}
	}
	cout << endl;
}

// 逐层、按本层序号输出二叉树
void BiTreeArra::Print()
{
	int i, j;
	SqBiTree e;
	Position p;
	for (i = 1; i <= TreeDepth(); i++)
	{
		cout << "第" << i << "层：";
		p.level = i;
		for (j = 1; j <= pow(2, i - 1); j++)
		{
			p.order = j;
			e = Value(p);
			if (e != EMPTY)
			{
				cout << j << ":" << e << "  ";
			}
		}
		cout << endl;
	} 
}