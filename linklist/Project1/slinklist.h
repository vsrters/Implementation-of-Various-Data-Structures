#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int sltdatatype;
typedef struct slistnode
{
	sltdatatype data;
	struct slistnode* next;
}sltnode;

void slistprintf(sltnode* phead);
void slistpushback(sltnode** pphead, sltdatatype x);
void slistpushfront(sltnode** pphead, sltdatatype x);
void slistpopfront(sltnode** pphead);
void slistpopback(sltnode** pphead);
sltnode* slistfind(sltnode* phead, sltdatatype x);
void slistinsert(sltnode** pphead, sltnode* pos, sltdatatype x);
void slisterase(sltnode** pphead, sltnode* pos);
void slistdestroy(sltnode** pphead);

