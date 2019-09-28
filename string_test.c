942. �����ַ���ƥ��

����ֻ�� "I"�����󣩻� "D"����С�����ַ��� S ���� N = S.length��

���� [0, 1, ..., N] ���������� A ʹ�ö������� i = 0, ..., N-1�����У�

��� S[i] == "I"����ô A[i] < A[i+1]
��� S[i] == "D"����ô A[i] > A[i+1]
 

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/di-string-match

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
557. ��ת�ַ����еĵ��� III




����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��

ʾ�� 1:

����: "Let's take LeetCode contest"
���: "s'teL ekat edoCteeL tsetnoc" 

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
1047.������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�

�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����

����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��

 

ʾ����

���룺"abbaca"
�����"ca"
���ͣ�
���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��

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
844. �ȽϺ��˸���ַ���
���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ�

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
415. �ַ������
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�

ע�⣺

num1 ��num2 �ĳ��ȶ�С�� 5100.
num1 ��num2 ��ֻ�������� 0-9.
num1 ��num2 ���������κ�ǰ���㡣
�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

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



