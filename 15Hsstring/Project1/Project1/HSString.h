#pragma once
#ifndef __HSTRING_H_
#define __HSTRING_H_

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
typedef struct Hstring{
	char* ch;
	int length;
}Hstring;

void InitString(Hstring* s);
void PrintString(Hstring* s);

void StrAssign(Hstring*s, char* str);
void StrCopy(Hstring* s, Hstring* t);
bool StrEmpty(Hstring* s);
int StrCompare(Hstring* s, Hstring* t);
int StrLength(Hstring* s);
void StrConcat(Hstring* t, Hstring* s1, Hstring* s2);
void SubString(Hstring* s, Hstring* sub, int pos, int len);
void StrInsert(Hstring* s, int pos, Hstring* t);
void StrDelete(Hstring* s, int pos, int len);
void StrClear(Hstring* s);

///////////////////////////////////
void StrIndex(Hstring* s, Hstring* t, int pos);
void StrReplace(Hstring* s, Hstring* t, Hstring* v);

#endif // !__HSTRING_H_

