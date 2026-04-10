#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include"slinklist.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include"dlist.h"



//void testsltlist()
//{
//	sltnode* plist = NULL;
//	slistpushback(&plist, 1);
//	slistpushback(&plist, 2);
//	slistpushback(&plist, 3);
//	slistpushback(&plist, 4);
//	slistpushback(&plist, 2);
//	slistpushback(&plist, 2);
//
//
//	slistprintf(plist);
//
//	sltnode* pos = slistfind(plist, 2);
//	int i = 1;
//	while (pos)
//	{
//		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
//		pos = slistfind(pos->next, 2);
//	}
//	pos = slistfind(plist, 2);
//}
//
//int main()
//{
//	testsltlist();
//	return 0;
//}
void test()
{
	LTNode* plist = NULL;
	plist = linkInit();
	linkPushBack(plist, 1);
	linkPushBack(plist, 2);
	linkPushBack(plist, 3);
	linkPushBack(plist, 4);

	printlink(plist);

	linkPopBack(plist);
	linkPopBack(plist);
	linkPopBack(plist);


	printlink(plist);


	linkPushFront(plist, 1);
	linkPushFront(plist, 2);
	linkPushFront(plist, 3);
	linkPushFront(plist, 4);

	printlink(plist);

	linkPopFront(plist);
	linkPopFront(plist);

	printlink(plist);

}

int main()
{
	test();
	return 0;
}