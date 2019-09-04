// ConsoleApplication32.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
char* my_strcpy(char* copy, const char* proto)
{
	char* ret = copy;//复制
	assert(copy != NULL);
	assert(proto != NULL);
	while (*copy++ = *proto++);
	*copy = *proto;
	return ret;
}

char* my_strcat(char* destination,const char* source)
{
	assert(source != NULL);//粘贴
	assert(destination != NULL);
	 char* ret = destination;
	while (*destination)
		destination++;
	while (*destination++ = *source++);
	*destination = *source;
	return ret;
}

char* my_strstr(char* str1,const char*  str2)
{
	assert(str1 != NULL);//确定位置
	assert(str2 != NULL);
	const char* p = str1;
	const char* q = str2;
	while (*str1)
	{
		while (*p && *q && *p++ == *q++);
		if (*q == '\0')
			return str1;
		str1++;

	}
	return NULL;
}

char* my_strchr(const char* str, char c)
{
	assert(str != NULL);

	while (*str)
	{
		
		if (*str == c)
			return (char *)str;
		str++;
	}
}

int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 != NULL);
	assert(s2 != NULL);

	while (*s1 || *s2)//比较大小
	{
		if (*s1 && !*s2 || *s1 > *s2)
			return 1;
		if (*s2 && !*s1 || *s2 > *s1)
			return -1;
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	return 0;
}

void* my_memcpy(void* destin, void* source, unsigned n)
{
	assert(destin != NULL);
	assert(source != NULL);
	char* str1 = (char*)destin;
	char* str2 = (char*)source;
	for (unsigned int i = 0; i < n; i++)
	{
		*str1++ = *str2++;
	}
	return destin;
}

void* my_memmove(void* destin, void* source, unsigned n)
{
	assert(destin != NULL);
	assert(source != NULL);
	char* str1 = (char*)destin;
	char* str2 = (char*)source;
	if (str2 > str1)
	{
		for (unsigned int i = 0; i < n; i++)
		{
			*str1++ = *str2++;
		}
		return destin;
	}
	if(str2 < str1)
	{
		str1 += n;
		str2 += n;
		for (unsigned int i = 0; i < n; i++)
		{
			str1--;
			str2--;
			*str1 = *str2;
			
		}
		return destin;
	}
}

int main()
{
	char my[10];
	my_strcpy(my, "klkk");
	my_strcat(my, "coc");
	for (int i = 0; my[i]!='\0'; i++)
	{
		printf("%c", my[i]);
	}
	char my2[20] = { "13132" };
	printf("\n%s",strstr("accabcba", "bc"));
	printf("\n%s", strchr("accabcba", 'b'));
	printf("\n%d", my_strcmp("accD", "accD"));
	memcpy(my2, my, 5);
	printf("\n%s", my2);
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
