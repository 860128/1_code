// ConsoleApplication51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(K key,V value) 
		:_Left(nullptr)
		, _Right(nullptr)
		, _Parents(nullptr)
		, _key(key)
		,_value(value)
		,_bf(0)
	{}
public:

	AVLTreeNode<K,V>* _Left;
	AVLTreeNode<K,V>* _Right;
	AVLTreeNode<K,V>* _Parents;
	K _key;
	V _value;
	int _bf;

};

template<class K, class V>
struct AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree()
	{
		_Proot = nullptr;
	}

	bool Insert(const K& key, const V& value)
	{
		if (_Proot == nullptr)
		{
			_Proot = new Node(key, value);
			return true;
		}
		Node* root = _Proot;
		
		Node* pnode = nullptr;
		while (root)
		{
			pnode = root;
			if (root->_value > value)
			{
				root = root->_Left;
			}
			else if (root->_value < value)
			{
				root = root->_Right;
			}
			else if (root->_value == value)
				return true;
		}

		
		if (pnode->_Left == root)
		{
			pnode->_Left = new Node(key, value);
			
		}

		else if (pnode->_Right == root)
		{
			pnode->_Right = new Node(key, value);
			
		}
		

		while (pnode)
		{
			if (root == pnode->_Left)
				pnode->_bf--;
			if (root == pnode->_Right)
				pnode->_bf++;

			if(pnode->_bf == 0)
				return true;

			else if (pnode->_bf == 1 || pnode->_bf == -1)
			{
				root = pnode;
				pnode = root->_Parents;
			}
			else if (pnode->_bf == 2 || pnode->_bf == -2)
			{
				if (pnode->_bf == 2)
				{
					if (root->_bf == 1)//哪边单旋哪边变长
					{
						_RotateL(pnode);
					}
					else if (root->_bf == -1)
					{
						_RotateRL(pnode);
					}

				}
				else if (pnode->_bf == -2)
				{
					if (root->_bf == -1)
					{
						_RotateR(pnode);
					}
					else if (pnode->_bf == 1)
					{
						_RotateLR(pnode);
					}
				}
				break;
			}

		}
		return true;
	}

	void _RotateL(Node*  pnode)
	{
		Node* ppnode = pnode->_Parents;
		Node* Rnode = pnode->_Right;
		pnode->_Right = Rnode->_Left;
		if (Rnode->_Left)
		{
			Rnode->_Left->_Parents = pnode;
		}

		 Rnode->_Left = pnode;
		 
		 if (ppnode == nullptr)
		 {
			 _Proot = Rnode;
		}
		 else
		 {
			 if (ppnode->_Left == pnode)
			 {
				 ppnode->_Left = Rnode;
			 }
			 else if(ppnode->_Right == pnode)
			 {
				 ppnode->_Right = Rnode;
			 }
			 Rnode->_Parents = ppnode;
		 }
		 pnode->_Parents = Rnode;
		 pnode->_bf = 0;
		 Rnode->_bf = 0;
	}

	void _RotateR(Node*  pnode)
	{
		Node* ppnode = pnode->_Parents;
		Node* Lnode = pnode->_Left;
		pnode->_Left = Lnode->_Right;
		if (Lnode->_Right)
		{
			Lnode->_Right->_Parents = pnode;
		}
		Lnode->_Right = pnode;
		
		if (ppnode == nullptr)
		{
			_Proot = Lnode;
		}
		else
		{
			Lnode->_Parents = ppnode;
			if (ppnode->_Left == pnode)
			{
				ppnode->_Left = Lnode;
			}
			else if(ppnode->_Right == pnode)
			{
				ppnode->_Right= Lnode;
			}
		}
		pnode->_Parents = Lnode;
		Lnode->_bf = 0;
		pnode->_bf = 0;
	}

	void _RotateRL(Node*  pnode)
	{
		Node* SURL = pnode->_Right->_Left;
		_RotateR(pnode->_Right);
		_RotateL(pnode);
		
		if (SURL->_bf == -1)
		{
			pnode->_bf = -1;
		}
		else if (SURL->_bf == 1)
		{
			pnode->_Parents->_Right->_bf = 1;
		}
		SURL->_bf = 0;
	}

	void _RotateLR(Node* pnode)
	{
		Node* SULR = pnode->_Left->_Right;
		_RotateL(pnode->_Right);
		_RotateR(pnode);
		if (SULR->_bf == -1)
		{
			pnode->_bf = -1;
		}
		else if (SULR->_bf == 1)
		{
			pnode->_Parents->_Right->_bf = 1;
		}
		SULR->_bf = 0;
	}
	void showtree()
	{
		Node* root = _Proot;
		_show(root);
	}

	void _show(Node* root)
	{
		if (nullptr == root)
			return;
		_show(root->_Left);
		_show(root->_Right);

		cout << "root->_bf:  "<<  root->_bf <<"root->_key :  "<< root->_key <<"root->_value:  " <<root->_value<<endl;

	}
private:
	Node* _Proot;
	
};


int main()
{
	struct AVLTreeNode<int, int> m(3, 2);
	AVLTree<int,int> b;
	for (int i = 0; i < 9; i++)
		b.Insert(i, i);
	b.showtree();
    std::cout << "Hello World!\n";
}
