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
#include "tree.h"

typedef int BTdatatype;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTdatatype data;
}BTNode;


void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ",root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

void TreeSize(BTNode* root,int* psize)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		(*psize)++;
	}
	TreeSize(root->left, psize);
	TreeSize(root->right, psize);
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	int Asize = 0;
	TreeSize(A, &Asize);
	printf("TreeSize:%d\n", Asize);

	int Bsize = 0;
	TreeSize(B, &Bsize);
	printf("TreeSize:%d\n", Bsize);

	int Aleaf = TreeLeafSize(A);
	printf("TreeLeafSize:%d", Aleaf);
	return 0;
}