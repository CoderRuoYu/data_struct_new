#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* tem = plist;
	while (tem!=NULL)
	{
		printf("%d->", tem->data);
		tem = tem->next;
	}
	printf("NULL\n");
}
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* tem = (SListNode*)malloc(sizeof(SListNode));
	if (!tem)
	{
		perror("malloc");
		return NULL;
	}
	tem->data = x;
	tem->next = NULL;
	return tem;
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* tem = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = tem;
	}
	else
	{
		SListNode* cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = tem;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{

	SListNode* tem = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = tem;
	}
	else
	{
		tem->next = *pplist;
		*pplist = tem;
	}
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tem = *pplist;
		while (tem->next->next != NULL)
		{
			tem = tem->next;
		}
		free(tem->next);
		tem->next = NULL;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tem = *pplist;
	*pplist = (*pplist)->next;
	free(tem);
	tem = NULL;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* tem = plist;
	while (tem)
	{
		if (tem->data == x)
		{
			return tem;
		}
		tem = tem->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos != NULL);
	SListNode* tem = BuySListNode(x);
	if (tem == NULL)
	{
		printf("插入失败\n");
		return;
	}
	tem->next = pos->next;
	pos->next = tem;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL);
	if (pos->next == NULL)
		return;
	SListNode* tem = pos->next;
	pos->next = tem->next;
	free(tem);
	tem = NULL;
}
// 单链表的销毁
void SListDestroy(SListNode** pplist)
{
	assert(*pplist != NULL);
	SListNode* tem = *pplist;
	while (*pplist != NULL)
	{
		tem = *pplist;
		*pplist = (*pplist)->next;
		free(tem);
	}
	*pplist = NULL;
}