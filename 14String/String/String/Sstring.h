#pragma once
#ifndef __SSTRING_H_
#define __SSTRING_H_
#include <stdbool.h>
#include<stdio.h>
#include<string.h>
#define MaxSize 20
#define u_char unsigned char
typedef u_char SString[MaxSize + 1];
void InitString(SString s);
void PrintString(SString s);

void StrAssign(SString s, char* str);
void StrCopy(SString s, SString t);
bool StrEmpty(SString s);
int StrCompare(SString s, SString T);
int StrLength(SString s);
void StrConcat(SString T, SString s1, SString s2);
void SubString(SString s, SString sub, int pos, int len);
void StrInsert(SString s, int pos, SString t);
void StrDelete(SString s, int pos, int len);
void StrClear(SString s);
//////////////////////////////////////////
int StrIndex(SString s, SString T, int pos);
void StrReplace(SString s, SString T, SString v);


#endif // !__SSTRING_H_

