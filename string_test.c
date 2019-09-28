942. 增减字符串匹配

给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。

返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：

如果 S[i] == "I"，那么 A[i] < A[i+1]
如果 S[i] == "D"，那么 A[i] > A[i+1]
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-string-match

```
class Solution {
public:
    vector<int> diStringMatch(string S) {
	int i = S.size();
	int contb = 0, conte = i;
	vector<int> num;
	for (int j = 0; j <=i; ++j)
	{
		if (S[j] == 'I')
			num.push_back(contb++);
		if (S[j] == 'D')
			num.push_back(conte--);
	}

	num.push_back(conte);

	return num;
}
};
```
557. 反转字符串中的单词 III




给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

```
class Solution {
public:
    string reverseWords(string s) {
        int begin =0;
        int end;
        for(int i=0;i<= s.size();i++)
        {
            if(s[i] ==' ' || s[i] =='\0')
            {
                for(end = i-1;begin < end;begin++,end--)
                {
                    swap(s[begin],s[end]);
                }
                begin = i+1;
            }
            
        }
            return s;
    }
};
```
1047.给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

示例：

输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

```
class Solution {
public:
    string removeDuplicates(string S) 
    {
        int flag = 1;
        while(flag == 1)
        {
            flag = 0;
           for(int i=0;i< S.size();i++)
        {
            if(i!= S.size()-1)
            {
                if(S[i] == S[i+1])
                {
                    S.erase(i,2);
                    flag = 1;
                    
                }
            }
        } 
        }
        
        return S;
    }
};
```
844. 比较含退格的字符串
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符

```
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> T1,S1;
        for(auto& e: S)
        {
            if(e != '#')
                S1.push_back(e);
            if(e == '#'&& S1.empty() != 1)
                S1.pop_back();
        }
        for(auto& e: T)
        {
            if(e != '#')
                T1.push_back(e);
            if(e == '#' && T1.empty() != 1)
                T1.pop_back();
        }
        if(T1 == S1)
            return true;
        else
            return false;
    }
};
```
415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

```
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int count = 0;
        string num3;
        int i = num1.size()-1;
        int j = num2.size()-1;
       while(i>=0||j>=0||count!=0)
       {
           if(i >=0)
               count += num1[i--]-'0';
           if(j>=0)
               count += num2[j--]-'0';
           num3 += to_string(count%10);
           count /=10;
       }
        reverse(num3.begin(),num3.end());
        return num3;
    }
};
```



