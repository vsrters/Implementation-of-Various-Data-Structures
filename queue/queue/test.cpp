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

//void test()
//{
//	ST st;
//	StackInit(&st);
//
//	Stackpush(&st, 1);
//	Stackpush(&st, 2);
//	Stackpush(&st, 3);
//	Stackpush(&st, 4);
//	Stackpush(&st, 5);
//
//}

void queuetest()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	int top = QueueBack(&q);
	printf("%d\n", top);

	while (!Queueempty(&q))
	{
		QDatatype front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");


}

int main()
{
	//test();
	queuetest();
	return 0;
}