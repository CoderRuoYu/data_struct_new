#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define baseNum 3
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* data;
	int size;
	int capacity;
}SeqList;
// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);
