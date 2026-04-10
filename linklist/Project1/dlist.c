#define _CRT_SECURE_NO_WARNINGS
#include"dlist.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

LTNode* buynode(sltdatatype x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
LTNode* linkInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(struct listNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void linkPushBack(LTNode* phead, sltdatatype x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	tail->next = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	phead->prev = newnode;

}

void printlink(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void linkPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* cur = phead->prev;
	phead->prev = cur->prev;
	cur->prev->next = phead;
	free(cur);
	cur = NULL;
}
void linkPushFront(LTNode* phead, sltdatatype x)
{
	assert(phead);
	LTNode* newnode = buynode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
}

void linkPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->next;
	phead->next = tail->next;
	tail->next->prev = phead;
	free(tail);
	tail = NULL;
}