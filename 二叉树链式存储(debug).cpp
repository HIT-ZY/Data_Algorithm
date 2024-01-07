#include <iostream>

using namespace std;

#define EMPTY 0
#define MAX_NODE_NUMBER 100

typedef int Elemtype;

typedef struct biTreeNode
{
	Elemtype data;
	struct biTreeNode *lchild;
	struct biTreeNode *rchild;
}BiTreeNode;

class BiTreeLink
{
public:
	// 构造空树T
	bool InitBiTree();
	// 层序数组生成
	Elemtype AssignArr(int index);
	// 先序构造二叉树
	void CreateBiTree(BiTreeNode* p);
	// 若树T存在，则将树T销毁
	bool DestroyBiTree(BiTreeNode* p);
	// 若T为空树则返回true，否则返回false
	bool TreeEmpty();
	// 返回树的深度
	int TreeDepth(BiTreeNode* p);
	// 返回T的根结点
	Elemtype Root();
	// p指向树T中一个结点位置，返回此节点的值
	Elemtype Value(BiTreeNode* p);
	// 给p指向的树T结点赋值为value
	bool Assign(BiTreeNode* p, Elemtype value);
	// 先序遍历二叉树
	void PreOrderTraverse(BiTreeNode* p);
	// 中序遍历二叉树
	void InOrderTraverse(BiTreeNode* p);
	// 后序遍历二叉树
	void PostOrderTraverse(BiTreeNode* p);
	// 返回头指针
	BiTreeNode* GetBTN();
protected:
private:
	BiTreeNode* BTN;
};

int main()
{
	BiTreeLink BTL;
	BTL.InitBiTree();
	BiTreeNode* p = BTL.GetBTN();
	cout << BTL.TreeEmpty() << endl;
	BTL.CreateBiTree(p);
	cout << BTL.TreeEmpty() << endl;
	// cout << BTL.TreeDepth(p) << endl;
	cout << BTL.Root() << endl;
	p = BTL.GetBTN();
	BTL.Assign(p, 666);
	BTL.PreOrderTraverse(p);
	BTL.InOrderTraverse(p);
	BTL.PostOrderTraverse(p);
	BTL.DestroyBiTree(p);
	return 0;
	return 0;
}

// 构造空树T
bool BiTreeLink::InitBiTree()
{
	BTN = nullptr;
	return true;
}

// 层序数组生成
Elemtype BiTreeLink::AssignArr(int index)
{
	Elemtype arr[MAX_NODE_NUMBER] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;
	for (i = 10; i < MAX_NODE_NUMBER; i++)
	{
		arr[i] = EMPTY;
	}
	return arr[index];
}

// 先序构造二叉树
void BiTreeLink::CreateBiTree(BiTreeNode* p)
{
	static int i = 0;
	Elemtype num = AssignArr(i);
	// cout << num << endl;
	p = new BiTreeNode;
	p->data = num;
	// 头指针与头节点关联
	if (i == 0)
	{
		BTN = p;
	}
	i++;
	if (num == EMPTY)
	{
		p = nullptr;
	}
	else
	{
		CreateBiTree(p->lchild);
		CreateBiTree(p->rchild);
	}
}

// 若树T存在，则将树T销毁
bool BiTreeLink::DestroyBiTree(BiTreeNode* p)
{
	static int flag = 0;
	if (flag == 0)
	{
		p = BTN;
	}
	flag++;
	if (!TreeEmpty())
	{
		if (p->lchild)
		{
			DestroyBiTree(p->lchild);
		}
		if (p->rchild)
		{
			DestroyBiTree(p->rchild);
		}
		delete p;
		p = nullptr;
	}
	return true;
}

// 若T为空树则返回true，否则返回false
bool BiTreeLink::TreeEmpty()
{
	if (BTN == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 返回树的深度
int BiTreeLink::TreeDepth(BiTreeNode* p)
{
	static int flag = 0;
	if (flag == 0)
	{
		p = BTN;
	}
	flag++;
	int i = 0;
	int j = 0;
	if (p->lchild)
	{
		i = TreeDepth(p->lchild);
	}
	else
	{
		i = 0;
	}
	if (p->rchild)
	{
		j = TreeDepth(p->rchild);
	}
	else
	{
		j = 0;
	}
	return i > j ? i + 1 : j + 1;
}

// 返回T的根结点
Elemtype BiTreeLink::Root()
{
	if (!TreeEmpty())
	{
		return BTN->data;
	}
	else
	{
		return EMPTY;
	}
}

// p指向树T中一个结点位置，返回此节点的值
Elemtype BiTreeLink::Value(BiTreeNode* p)
{
	return p->data;
}

// 给p指向的树T结点赋值为value
bool BiTreeLink::Assign(BiTreeNode* p, Elemtype value)
{
	p->data = value;
	return true;
}

// 先序遍历二叉树
void BiTreeLink::PreOrderTraverse(BiTreeNode* p)
{
	/*static int flag = 0;
	if (flag == 0)
	{
		p = BTN;
	}
	flag++;*/
	if (p == nullptr)
	{
		return;
	}
	cout << p->data << " ";
	PreOrderTraverse(p->lchild);
	PreOrderTraverse(p->rchild);
}

// 中序遍历二叉树
void BiTreeLink::InOrderTraverse(BiTreeNode* p)
{
	/*static int flag = 0;
	if (flag == 0)
	{
		p = BTN;
	}
	flag++;*/
	if (p == nullptr)
	{
		return;
	}
	PreOrderTraverse(p->lchild);
	cout << p->data << " ";
	PreOrderTraverse(p->rchild);
}

// 后序遍历二叉树
void BiTreeLink::PostOrderTraverse(BiTreeNode* p)
{
	/*static int flag = 0;
	if (flag == 0)
	{
		p = BTN;
	}
	flag++;*/
	if (p == nullptr)
	{
		return;
	}
	PreOrderTraverse(p->lchild);
	PreOrderTraverse(p->rchild);
	cout << p->data << " ";
}

// 返回头指针
BiTreeNode* BiTreeLink::GetBTN()
{
	return BTN;
}