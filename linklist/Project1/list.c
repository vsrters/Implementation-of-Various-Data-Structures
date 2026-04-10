#define _CRT_SECURE_NO_WARNINGS
#include"slinklist.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

sltnode* buylistnode(sltdatatype x)
{
	sltnode* newnode = (sltnode*)malloc(sizeof(sltnode));
	newnode->data = x;
	newnode->next = NULL;
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}

	return newnode;
}
void slistprintf(sltnode* phead)
{
	sltnode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void slistpushback(sltnode** pphead, sltdatatype x)
{
	sltnode* newnode = buylistnode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		sltnode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

void slistpushfront(sltnode** pphead, sltdatatype x)
{
	sltnode* newnode = buylistnode(x);
	newnode->next = *pphead;
	*pphead = newnode;

}



void slistpopback(sltnode** pphead)
{
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		sltnode* prev = NULL;
		sltnode* tail = *pphead;

		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

	}

}

void slistpopfront(sltnode** pphead)
{
	assert(*pphead != NULL);
	sltnode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

sltnode* slistfind(sltnode* phead, sltdatatype x)
{
	sltnode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void slistinsert(sltnode** pphead, sltnode* pos, sltdatatype x)
{
	assert(pos != NULL);
	sltnode* newnode = buylistnode(x);
	sltnode* posprev = *pphead;
	if (*pphead == pos)
	{
		if (posprev->next != pos)
		{
			posprev = pos->next;
		}
		posprev->next = newnode;
		newnode->next = pos;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

void slisterase(sltnode** pphead, sltnode* pos)
{
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		sltnode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
			prev->next = pos->next;
			free(pos);
	}
}

void slistdestroy(sltnode** pphead)
{
	assert(*pphead);
	sltnode* cur = *pphead;
	while (cur)
	{
		sltnode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}