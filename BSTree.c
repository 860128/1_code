// ConsoleApplication50.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#pragma warning(disable:4996)
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T()) :_data(data), _Left(nullptr), _Right(nullptr)
	{
	}
public:
	struct BSTNode<T>* _Left;
	struct BSTNode<T>* _Right;
	T _data;
};

template<class T>
struct BSTree//左小，右大
{
	typedef BSTNode<T> node;
public:
	BSTree(node* root = nullptr) : _root(root)
	{
	}

	~BSTree()
	{
		Destroy(_root);
	}

	node* Find(const T& data)
	{
		node* root = _root;
		while (root)
		{
			if (root->_data > data)
			{
				root = root->_Left;
			}
			else if (root->_data < data)
			{
				root = root->_Right;
			}
			else if (root->_data == data)
			{
				return root;
			}
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new node(data);
			return true;
		}
		node* root = _root;
		node* parents = nullptr;//傻吊vs
		while (root)
		{
			parents = root;
			if (root->_data > data)
			{
				root = root->_Left;
			}
			else if (root->_data < data)
			{
				root = root->_Right;
			}
			else if (root->_data == data)
			{
				return false;
			}
		}
		root = new node(data);
		if (parents->_data > data)
		{
			parents->_Left = root;
			return true;
		}
		if (parents->_data < data)
		{
			parents->_Right = root;
			return true;
		}
		return false;
	}

	bool Delete(T data)
	{
		if (nullptr == _root)
			return false;
		node* root = _root;
		node* parents = nullptr;
		while (root)
		{
			parents = root;
			if (root->_data == data)
				break;
			if (root->_data < data)
			{
				root = root->_Right;
			}
			if (root->_data > data)
			{
				root = root->_Left;
			}
		}
		if (nullptr == root)
		{
			return false;
		}

		if (root->_Left == nullptr)
		{
			if (root == _root)
			{
				_root = root->_Right;
				delete root;
				return true;
			}
			if (parents->_Left == root)
			{
				root->_Right = parents->_Left;
			}
			else if (parents->_Right == root)
			{
				root->_Right = parents->_Right;
			}
		}

		if (root->_Right == nullptr && root->_Left != nullptr)
		{
			if (root == _root)
			{
				_root = root->_Left;
				delete root;
				return true;
			}
			if (parents->_Left == root)
			{
				root->_Left = parents->_Left;
			}
			else if (parents->_Right == root)
			{
				root->_Left = parents->_Right;
			}
		}
		delete root;
		return true;

		if (root->_Left != nullptr && root->_Right != nullptr)
		{
			node* pparent = nullptr;
			node* Rigroot = root->_Right;
			while (Rigroot->_Left)
			{
				pparent = Rigroot;
				Rigroot = Rigroot->_Left;
			}
			root->_data = Rigroot->_data;

			if (Rigroot == pparent->_Left)
			{
				pparent->_Left = Rigroot->_Right;
			}
			else
			{
				pparent->_Right = Rigroot->_Right;
			}
			delete Rigroot;
		}


		return true;

	}

	void Destroy(node*& root)
	{
		if (root)
		{
			Destroy(root->_Left);
			Destroy(root->_Right);
			delete root;
			root = nullptr;
		}
	}
private:
	node* _root;
};




int main()
{
	BSTNode<int> a;
	BSTree<int> b;
	b.Insert(1);
	b.Insert(2);
	b.Insert(3);
	b.Insert(4);
	b.Delete(1);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
