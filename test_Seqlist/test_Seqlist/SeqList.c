#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
	SLDateType* tem = (SLDateType*)malloc(sizeof(SLDateType) * baseNum);
	if (!tem)
	{
		perror("SeqListInit::malloc");
		return;
	}
	ps->data = tem;
	ps->size = 0;
	ps->capacity = baseNum;
}
void CheckCapacity(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->capacity == ps->size)
	{
		SLDateType* tem = (SLDateType*)realloc(ps->data, sizeof(SLDateType) * (ps->capacity) * 2);
		if (!tem)
		{
			perror("CheckCapacity::realloc");
			return;
		}
		ps->data = tem;
		ps->capacity = ps->capacity * 2;
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	CheckCapacity(ps);
	ps->data[ps->size++] = x;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	CheckCapacity(ps);
	int i = ps->size;
	while (i > 0)
	{
		ps->data[i] = ps->data[i - 1];
		i--;
	}
	ps->data[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->size == 0)
		return;
	int i = 0;
	while (i < ps->size - 1)
	{
		ps->data[i] = ps->data[i + 1];
		i++;
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->size == 0)
		return;
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps != NULL && pos >= 0 && pos <= ps->size);
	CheckCapacity(ps);
	ps->size++;
	for (int i = ps->size; i > pos; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[pos] = x;
}
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps != NULL && pos >= 0 && pos < ps->size);
	if (ps->size == 0)
		return;
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps != NULL);
	free(ps->data);
	ps->data = 0;
	ps->capacity = 0;
	ps = NULL;
}


