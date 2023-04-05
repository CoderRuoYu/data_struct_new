#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void test01()
{
	SeqList a;
	SeqListInit(&a);
	SeqListPushBack(&a, 1);
	SeqListPushBack(&a, 1);
	SeqListPushBack(&a, 1);
	SeqListPushBack(&a, 1);
	SeqListInsert(&a, 1, 5);
	SeqListInsert(&a, 1, 5);
	SeqListInsert(&a, 1, 5);
	SeqListErase(&a, 2);
	SeqListErase(&a, 2);
	SeqListErase(&a, 2);
	SeqListErase(&a, 2);
	SeqListErase(&a, 2);
	SeqListErase(&a, 0);
	SeqListErase(&a, 0);
	SeqListPrint(&a);
	SeqListDestroy(&a);

}
int main()
{
	test01();
	return 0;
}