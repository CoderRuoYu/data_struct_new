#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void test01()
{
	SListNode* phead = NULL;
	SListPrint(phead);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushBack(&phead, 5);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListNode* pos = SListFind(phead, 3);
	SListInsertAfter(pos, 1);
	SListPrint(phead);
	SListEraseAfter(pos);
	SListPrint(phead);
	SListEraseAfter(pos);
	SListPrint(phead);
	SListDestroy(&phead);
	SListPrint(phead);



}
int main()
{
	test01();
	return 0;
}
