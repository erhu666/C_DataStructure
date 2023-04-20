#include"HSString.h"
void InitString(Hstring* s)
{
	s->ch = NULL;
	s->length = 0;
}
void PrintString(Hstring* s)
{
	for (int i = 0; i < s->length; ++i)
	{
		printf("%c", s->ch[i]);
	}
	printf("\n");
}
void StrAssign(Hstring* s, char* str)
{
	int len = strlen(str);
	if (s->ch!=NULL)
	{
		free(s->ch);
	}
	s->ch = (char*)malloc(sizeof(char*) * len);
	assert(s->ch != NULL);
	for (int i = 0; i < len; ++i)
	{
		s->ch[i] = str[i];

	}
	s->length = len;
}
void StrCopy(Hstring* s, Hstring* t)
{
	int len = StrLength(t);
	if (s->ch!=NULL)
	{
		free(s->ch);
	}
	s->ch = (char*)malloc(sizeof(char) * len);
	assert(s->ch != NULL);
	for (int i = 0; i < len; ++i)
	{
		s->ch[i] = t->ch[i];
	}
	s->length = len;
}
bool StrEmpty(Hstring* s)
{
	return s->length == 0;
}
int StrCompare(Hstring* s, Hstring* t)
{
	if (s->length==0&&t->length==0)
	{
		return 0;
	}
	int result = 0;
	int i = 0;
	int j = 0;
	while (i<s->length&&j<t->length)
	{
		if (s->ch[i]>t->ch[i])
		{
			return 1;
		}
		else if (s->ch[i]<t->ch[j])
		{
			return -1;
		}
		else
		{
			i++;
			j++;
		}
	}
	if (i<s->length)
	{
		result = 1;
	}
	if (j<t->length)
	{
		return -1;
	}
	return result;
}

int StrLength(Hstring* s)
{
	return s->length;
}
void StrConcat(Hstring* t, Hstring* s1, Hstring* s2)
{
	if (t->ch!=NULL)
	{
		free(t->ch);
	}
	int len1 = StrLength(s1);
	int len2 = StrLength(s2);

	t->ch = (char*)malloc(sizeof(char*) * (len1 + len2));
	assert(t->ch != NULL);
	for (int i = 0; i < len1; i++)
	{
		t->ch[i] = s1->ch[i];
	}
	for (int  j = 0; j < len2; j++)
	{
		t->ch[i + j] = s2->ch[j];
	}
	t->length = len1 + len2;
}

void SubString(Hstring* s, Hstring* sub, int pos, int len)
{
	if (pos<0||pos>s->length||len<0||len>s->length-pos)
	{
		return;
	}
	if (sub->ch!=NULL)
	{
		free(sub->ch);

	}
	sub->ch = (char*)malloc(sizeof(char) * len);
	assert(sub->ch != NULL);
	int j = pos;
	for (int  i = 0; i < len; i++)
	{
		sub->ch[i] = s->ch[i + j];
	}
	sub->length = len;
}
void StrInsert(Hstring* s, int pos, Hstring* t)
{
	if (t->length==0)
	{
		return;
	}
	if (pos<0||pos>s->length)
	{
		return;
	}
	char* ch = (char*)realloc(s->ch, sizeof(char) * (s->length + t->length));
	assert(ch != NULL);
	s->ch = ch;
	for (int i = s->length - 1; i >= pos; --i)
	{
		s->ch[i + t->length] = s->ch[i];
	}
	int j = pos;
	for (int  i = 0; i < t->length; i++)
	{
		s->ch[j + i] = t->ch[i];
	}
	s->length += t->length;


}

void StrDelete(Hstring* s, int pos, int len)
{
	if (pos<0||pos>s->length)
	{
		return;
	}
	int j = pos;
	for (int  i = 0; i < len; i++)
	{
		s->ch[i + j] = s->ch[j + i + len];
	}
	s->length -= len;
}
void StrClear(Hstring* s)
{
	s->length = 0;
	if (s->ch!=NULL)
	{
		free(s->ch);
	}
	s->ch = NULL;
}

///////////////////////////////////
void StrIndex(Hstring* s, Hstring* t, int pos)
{

}
void StrReplace(Hstring* s, Hstring* t, Hstring* v)
{

}
