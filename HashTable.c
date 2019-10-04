#pragma

#include<iostream>
#include<vector>
using namespace std;

enum States
{
	EXIST,
	DELETE,
	EMPTY,
};

template <class K, class V>
struct HashNode
{
public:
	States states = EMPTY;
	pair<K, V> _kv;

};

template <class K, class V>
struct HashTable
{
	typedef typename HashNode<K, V> Node;

	bool Insert(pair<K, V> kv)
	{
		Checkapcity();
		size_t index = (kv.first % _table.size());
		size_t start = index;
		int i = 1;
		while (_table[index].states == EXIST)//¶þ´ÎÌ½²â£¬±ÕÉ¢ÁÐ
		{
			if (_table[index]._kv.first == kv.first)
				return false;

			index = (start + i * i) % _table.size();
			i++;
		}

		_table[index]._kv = kv;
		_table[index].states = EXIST;
		_size++;
		return true;

	}

	void Checkapcity()
	{
		if (_table.size() == 0 || 10 * _size / _table.size() >= 7)
		{
			int newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable newtable;
			newtable._table.resize(newsize);
			for (int i = 0; i < _table.size(); ++i)
			{
				if (_table[i].states == EXIST)
					newtable.Insert(_table[i]._kv);
			}
			newtable._table.swap(_table);

		}
	}
	HashNode<K, V>* Find(const K& kv)
	{
		size_t index = (kv % _table.size());
		size_t start = index;
		int i = 1;
		while (_table[index].states != EMPTY)
		{
			if (_table[index].states == EXIST && _table[index]._kv.first == kv)
			{
				return &_table[index];
			}
			else
			{
				index = (start + i * i) % _table.size();
				i++;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashNode<K, V>* ret = Find(key);
		if (ret)
		{
			ret->states = DELETE;
			return true;
		}
		return false;
	}


public:

	vector<Node> _table;
	size_t _size = 0;
};


int main()
{
	HashTable<int, char> a;
	for (int i = 'a'; i - 'a' < 20; i++)
		a.Insert(make_pair(i - 'a', i));
	HashNode<int, char>* c = a.Find(1);
	cout << "hello world";
}