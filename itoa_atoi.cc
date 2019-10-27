void myitoa(int value, char* str, int base)
{
	char text[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//对应的值
		unsigned int unnum;
		int i = 0, j, k;
		if (value < 0)
		{
			str[0] = '-';
			i = 1;
		}
	if (value < 0)
	{
		unnum = -value;
		k = 1;
	}
	else
	{
		unnum = value;
		k = 0;
	}
	do
	{
		str[i++] = text[unnum % base];
		unnum /= base;
	} while (unnum);
	str[i] = '\0';
	value < 0 ? k = 1 : k = 0;
	
	for (int j = k;j<=(i-1)/2;j++)
	{
		if (k == 1)
			swap(str[j], str[i - j]);
		else
			swap(str[j], str[i - j - 1]);
	}

}