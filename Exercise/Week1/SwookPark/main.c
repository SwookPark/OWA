#include <stdio.h>
#include <stdlib.h>

///////���� 1  ���Ḯ��Ʈ�� �̿��Ͽ� ���� �ڷᱸ���� �����غ���. ///////

typedef struct _linkedListNode
{
	int key;
	struct _linkedListNode *next;
} LLNode;

typedef struct _linkedListStack
{
	LLNode *top;
    int size;
} LLStack;


LLStack *createStack()
{
	LLStack *lls = malloc(sizeof(LLStack));
    lls->top = NULL;
    lls->size = 0;
    return lls;
}

void deleteStack(LLStack *targetStack)
{
	LLNode *nodePtr = targetStack->top;
    while (nodePtr != NULL)
    {
    	LLNode *next = nodePtr->next;
        free(nodePtr);
        nodePtr = next;
    }
    free(targetStack);
}


int push(LLStack *targetStack, int value)
{
    if (targetStack == NULL) return 0;

    LLNode *newNode = malloc(sizeof(LLNode));

    if (newNode == NULL) return 0;

    newNode->key = value;
    newNode->next = targetStack->top;
    targetStack->top = newNode;
    targetStack->size += 1;

    return 1;
}

int pop(LLStack *targetStack, int *value)
{
    if (targetStack == NULL || targetStack->top == NULL) return 0;

    *value = targetStack->top->key;
    LLNode *nodeDelete = targetStack->top;
    targetStack->top = targetStack->top->next;
    targetStack->size -= 1;
    free(nodeDelete);

    return 1;
}
///////���� 1  ���Ḯ��Ʈ�� �̿��Ͽ� ���� �ڷᱸ���� �����غ���. ///////

int main(void)
{
///// ���� 1 �׽�Ʈ /////

	LLStack *testStack1;
	testStack1 = createStack();

	int intTemp, i;

	push(testStack1, 10);
	push(testStack1, 10);

	for(i = 0; i < 10; i++)
	{
		if(pop(testStack1, &intTemp))
		{
			printf("poped %d\n", intTemp);
		}
	}
	deleteStack(testStack1);

///// ���� 1 �׽�Ʈ /////


///// ���� 2 ���� �� ���� �̿��Ͽ� ť�� ����� ����� �����ϱ�? ť�� ���Ҹ� �ְ� /////
/////(enqueue), ����(dequeue) ������ ������ ȿ�����̾�� �Ѵ�. /////



	return 0;
}


