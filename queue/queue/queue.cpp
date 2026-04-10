#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <xkeycheck.h>
#include "queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->next = NULL;
	newnode->data = x;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!Queueempty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(!Queueempty(pq));
	return pq->head->data;
}
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(!Queueempty(pq));
	return pq->tail->data;
}
int QueueSize(Queue* pq)
{
	QueueNode* cur = pq->head;
	int n = 0;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}
int Queueempty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
