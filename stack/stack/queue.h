#pragma once
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
#include <yvals_core.h>

typedef int QDatatype;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq,QDatatype x);
void QueuePop(Queue* pq);
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);
int QueueSize(Queue* pq);
int Queuempty(Queue* pq);


