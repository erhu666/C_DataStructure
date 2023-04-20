#include "Sstring.h"
void InitString(SString s)
{
	s[0] = '\0';
}

void PrintString(SString s)
{
	printf("%s\n", s);
}
void StrAssign(SString s, char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		s[i] = str[i];
	}
	s[len] = '\0';
}


void StrCopy(SString s, SString t)
{
	int len = StrLength(t);
	for (int i = 0; i < len; ++i)
	{
		s[i] = t[i];
	}
	s[len] = '\0';

}
bool StrEmpty(SString s)
{
	return s[0] == '\0';
}
int StrCompare(SString s, SString T)
{
	int result = 0;
	while (*s!='\0'||*T!='\0')
	{
		result = *s - *T;
		if (result!=0)
		{
			break;
		}
		s++;
		T++;
	}
	if (result>0)
	{
		result = 1;
	}
	else if(result<0)
	{
		result = -1;
	}
	return result;

}

int StrLength(SString s)
{
	int len = 0;
	while (*s!='\0')
	{
		len++;
		s++;
	}

}
void StrConcat(SString T, SString s1, SString s2)
{
	int len1 = StrLength(s1);
	int len2 = StrLength(s2);
	if (len1+len2<=MaxSize)
	{
		for (int i = 0; i < len1; ++i)
		{
			T[i] = s1[i];
		}
		for (int i, j = 0; j < len2; ++j)
		{
			T[i + j] = s2[j];
		}
		T[len1 + len2] = '\0';

	}
	else if (len1<MaxSize)
	{
		int i = 0;
		for (i ; i < len1; ++i)
		{
			T[i] = s1[i];

		}
		for (int j = 0; j < MaxSize - len1; ++j)
		{
			T[i + j] = s2[j];
		}
		T[MaxSize] = '\0';
	}
	else
	{
		for (int i = 0; i < len1; ++i)
		{
			T[i] = s1[i];
		}
		T[MaxSize] = '\0';

	}
}
void SubString(SString s, SString sub, int pos, int len)
{
	int s_len = StrLength(s);
	if (pos < 0 || pos >= s_len||len<0||len>s_len)
	{
		return;
	}
	int j = pos;
	for (int i = 0; i < len; ++i)
	{
		sub[i] = s[j + i];
	}
	sub[len] = '\0';

}

void StrInsert(SString s, int pos, SString t)
{
	int s_len = StrLength(s);
	int t_len = StrLength(t);
	if (s_len+t_len<=MaxSize)
	{
		for (int i = s_len - 1; i >= pos; --i)
		{
			s[i + t_len] = s[i];
		}
		int j = pos;
		int i;
		for (i = 0; i < t_len; ++i)
		{
			s[i + j] = t[i];
		}
		s[s_len + t_len] = '\0';
	}
	else if (s_len<MaxSize)
	{
		t_len = MaxSize - s_len;
		for (int i = s_len - 1; i >= pos; --1)
		{
			s[i + t_len] = s[i];
		}
		int j = pos;
		for (int i = 0; i < t_len; ++i)
		{
			s[j + i] = t[i];
		}
		s[s_len + t_len] = '\0';
	}


}


void StrDelete(SString s, int pos, int len)
{
	int s_len = StrLength(s);
	for (int i = pos; i < s_len; ++i)
	{
		s[i] = s[i + len];
	}
	s[s_len - len] = '\0';
}
void StrClear(SString s)
{

	s[0] = '\0';
}

int StrIndex(SString s, SString T, int pos)
{
	int i = pos;
	int j = 0;
	while (s[i]!='\0'&&t[j]!='\0')
	{
		if (s[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}

	}
	if (T[j]=='\0')
	{
		return i - j;
	}
	return -1;
}
void StrReplace(SString s, SString T, SString v)
{

}