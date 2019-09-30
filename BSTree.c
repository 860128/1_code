// ConsoleApplication50.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
struct BSTree//��С���Ҵ�
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
		node* parents = nullptr;//ɵ��vs
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
