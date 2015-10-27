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
	if (targetStack == NULL) return -1;

	LLNode *newNode = malloc(sizeof(LLNode));

	if (newNode == NULL) return -1;

	newNode->key = value;
	newNode->next = targetStack->top;
	targetStack->top = newNode;
	targetStack->size += 1;

	return 0;
}

int pop(LLStack *targetStack, int *value)
{
	if (targetStack == NULL || targetStack->top == NULL) return -1;

	*value = targetStack->top->key;
	LLNode *nodeDelete = targetStack->top;
	targetStack->top = targetStack->top->next;
	targetStack->size -= 1;
	free(nodeDelete);

	return 0;
}
///////���� 1  ���Ḯ��Ʈ�� �̿��Ͽ� ���� �ڷᱸ���� �����غ���. ///////


///// ���� 2 ���� �� ���� �̿��Ͽ� ť�� ����� ����� �����ϱ�? ť�� ���Ҹ� �ְ� /////
/////(enqueue), ����(dequeue) ������ ������ ȿ�����̾�� �Ѵ�. /////


typedef struct _linkedListQueue
{
	LLStack *pushStack;
	LLStack *popStack;
} LLQueue;


LLQueue *createQueue()
{
	LLQueue *llq = malloc(sizeof(LLQueue));
	llq->pushStack = createStack();
	llq->popStack = createStack();
	return llq;
}

int enqueue(LLQueue *targetQueue, int value)
{
	if(push(targetQueue->pushStack, value) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int dequeue(LLQueue *targetQueue, int *value)
{
	if (targetQueue->pushStack == NULL && targetQueue->popStack == NULL)
	{
		return -1;
	}

	if (targetQueue->pushStack->size < 1 && targetQueue->popStack->size < 1)
	{
		return 1;
	}

	int tempValue = 0;
	if(targetQueue->popStack->size < 1)
	{
		while (targetQueue->pushStack->size > 0)
		{
			pop(targetQueue->pushStack, &tempValue);
			push(targetQueue->popStack, tempValue);
		}
	}

	pop(targetQueue->popStack, value);
	return 0;
}

LLQueue *deleteQueue(LLQueue *targetQueue)
{
	deleteStack(targetQueue->pushStack);
	deleteStack(targetQueue->popStack);
	free(targetQueue);
	return 0;
}

///// ���� 2 ���� �� ���� �̿��Ͽ� ť�� ����� ����� �����ϱ�? ť�� ���Ҹ� �ְ� /////
/////(enqueue), ����(dequeue) ������ ������ ȿ�����̾�� �Ѵ�. /////


int main(void)
{
///// ���� 1 �׽�Ʈ /////

	LLStack *testStack1 = NULL;
	testStack1 = createStack();

	int intTemp, i;

	push(testStack1, 1);
	push(testStack1, 2);
	push(testStack1, 3);
	push(testStack1, 4);
	push(testStack1, 5);

	for(i = 0; i < 10; i++)
	{
		if(pop(testStack1, &intTemp) == 0)
		{
			printf("poped %d\n", intTemp);
		}
	}
	deleteStack(testStack1);

///// ���� 1 �׽�Ʈ /////

///// ����2 �׽�Ʈ /////
	LLQueue *testQueue = NULL;
	testQueue = createQueue();

	enqueue(testQueue, 1);
	enqueue(testQueue, 2);
	enqueue(testQueue, 3);
	enqueue(testQueue, 4);
	enqueue(testQueue, 5);

	for(i = 0; i < 10; i++)
	{
		if(dequeue(testQueue, &intTemp) == 0)
		{
			printf("dequeue %d\n", intTemp);
		}
	}
	deleteQueue(testQueue);

///// ���� 2 �׽�Ʈ /////

	return 0;
}


