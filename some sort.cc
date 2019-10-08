// ConsoleApplication59.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
using namespace std;

void _heap_sort(int* num, int size, int len);
void _merge_sort(int* num, int left, int right);
void _merge(int* num, int left, int mid, int right);
void _insert_asord(int* num, int size)
{
	if (num == nullptr)
		return;
	int i, j, key;
	for (int j = 1; j < size; j++)
	{
		key = num[j];
		i = j - 1;
		while (i >= 0 && num[i] > key)
		{
			num[i+1] = num[i];
			i--;
		}
		num[i+1] = key;
	}


}

void _shell_sort(int* num, int size)
{
	int gap = size;
	while (gap!=1)
	{
		gap = gap / 3 + 1;
		int i,  key;
		for (int j = 1; j < size; j+=gap)
		{
			key = num[j];
			i = j - gap;
			while (i >= 0 && num[i] > key)
			{
				num[i + gap] = num[i];
				i-=gap;
			}
			num[i + gap] = key;
		}

	}
}

void _select_sort(int* num, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		int index = i;
		int min = num[i];
		for (int j = i ; j < size; j++)
		{
			if (min > num[j])
			{
				index = j;
				min = num[j];
			}
			
		}
		swap(num[i], num[index]);
		index = i;
	}
}

void _Heap_Sort(int* num, int size)
{
	_heap_sort(num,size, size / 2 - 1);
	
}

void _heap_sort(int* num, int size,int len)
{
	for (int i = len; i >= 0; i--)
	{
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int max = i;
		if (left<size && num[left] >num[max])
		{
			max = left;
		}
		if (right <size && num[right] >num[max])
		{
			max = right;
		}
		if (max != i)
		{
			swap(num[i], num[max]);
			if (left == max)
				_heap_sort(num, size, left);
			else
				_heap_sort(num, size, right);
		}
	}
}

void _bubble_sort(int* num, int size)
{
	for(int i=0;i<size-1;i++)
		for (int j = 0; j < size - i-1; j++)
		{
			if (num[j] > num[j+1])
			{
				swap(num[j], num[j+1]);
			}
		}
}

void _re_quick_sort(int* num, int left, int right)
{
	if (left < right)
	{
		int key = num[left];
		int i = left;
		int j = right;
		while (i < j)
	{
		while (num[j] >= key && i <j)
			j--;
		while (num[i] <= key && i < j)
			i++;
		swap(num[i], num[j]);
	}
		swap(num[j], num[left]);

		_re_quick_sort(num, left, i-1);
		_re_quick_sort(num, i+1, right);
	}
}

void _quick_sort(int* num, int left, int right)
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		left= s.top();
		s.pop();
		right = s.top();
		s.pop();
		int mid;
		if (left < right)
		{
			
				int key = num[left];
				int i = left;
				int j = right;
				while (i < j)
				{
					while (num[j] >= key && i < j)
						j--;
					while (num[i] <= key && i < j)
						i++;
					swap(num[i], num[j]);
				}
				swap(num[j], num[left]);
				mid = j;
		}
		if (mid - 1 > left)
		{
			s.push(mid-1);
			s.push(left);
		}
		if (mid + 1 < right)
		{
			s.push(right);
			s.push(mid + 1);
		}
	}


}

void  _Quick_Sort(int* num, int size)
{
	//_re_quick_sort(num, 0, size - 1);
	_quick_sort(num, 0, size - 1);
}


void _Merge_Sort(int* num, int size)
{
	_merge_sort(num, 0, size - 1);
}


void _merge_sort(int* num, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right);
		_merge_sort(num, left,mid);
		_merge_sort(num, mid+1,right);
		_merge(num, left, mid, right);
	}
}


void _merge(int* num, int left, int mid,int right)
{
	int* temp = new int[right - left + 1];

	for (int i = left; i <= right; i++)
	{
		temp[i - left] = num[i];
	}
	int i = left, j = mid + 1;
	for (int k = left; k <= right; k++)
	{
		if (i > mid)
			num[k] = temp[j++ - left];
		else if (j > right)
			num[k] = temp[i++-left];
		else if (temp[i - left] < temp[j - left])
			num[k] = temp[i++ - left];
		else
			num[k] = temp[j++ - left];
	}
	delete[] temp;
		return;

}


void Test()
{
	int num[10] = { 58, 82 ,83 ,17 ,14 ,64 ,30 ,26 ,60 ,38 };
	_Quick_Sort(num, 10);
	for (int i = 0; i < 10; i++)
		cout << num[i]<<" " ;
	
}

int main()
{
	
	Test();


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
