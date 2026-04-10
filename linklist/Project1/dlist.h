
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

typedef struct listNode
{
	sltdatatype data;
	struct listNode* next;
	struct listNode* prev;
}LTNode;

LTNode* linkInit();
void linkPushBack(LTNode* phead, sltdatatype x);
void printlink(LTNode* phead);
void linkPushBack(LTNode* phead, sltdatatype x);
void linkPopBack(LTNode* phead);
void linkPushFront(LTNode* phead, sltdatatype x);
void linkPopFront(LTNode* phead);
LTNode* buynode(sltdatatype x);





