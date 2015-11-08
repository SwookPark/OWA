#include <stdio.h>
#include <stdlib.h>

///////Week1���� ����� ���� ///////
typedef struct _linkedListNode
{
	int key;
	struct _linkedListNode *next;
	//struct _linkedListNode *prev;
} LLNode;

typedef struct _linkedListStack
{
	LLNode *top;
	int size;
} LLStack;

static LLStack *createStack(void);
static void deleteStack(LLStack *targetStack);
static int push(LLStack *targetStack, int value);
static int pop(LLStack *targetStack, int *value);
///////Week1���� ����� ���� ///////

static int printHanoi(LLStack *postA, LLStack *postB, LLStack *postC); // hanoi ž ���
static int moveHanoi(LLStack **post, int from, int to, int other, int height); // hanoi ž �̵�.


#define postLoads 100

int main(void)
{
	LLStack *post[3] = {NULL,};

	post[0] = createStack();//
	post[1] = createStack();// ��� 3�� ����. ������ ������ ���1 ���2 ���3 ���� ����.
	post[2] = createStack();//

	char inputTemp[10] = {0,};

	printf("Number of Disk? \n");// �ϳ��� ž ����.
	fflush(stdout);
	fgets(inputTemp,10,stdin);

	int numOfDisk = 0;

	numOfDisk = atoi(inputTemp);
	printf("Number of Disk : %d.\n",numOfDisk);
	fflush(stdout);

	int i;
	for (i = 0; i < numOfDisk; i++)
	{
		push(post[0], numOfDisk - i);
	}

	printHanoi(post[0], post[1], post[2]);

	moveHanoi(post, 0, 1, 2, numOfDisk);

	deleteStack(post[0]);
	deleteStack(post[1]);
	deleteStack(post[2]);
	return 0;
}


static int moveHanoi(LLStack **post, int from, int to, int other, int height)
{
	if(height < 1)
		return 0;

	moveHanoi(post, from, other, to ,height - 1);

	int intTemp;

	pop(post[from], &intTemp);
	push(post[to], intTemp);
	printHanoi(post[0], post[1], post[2]);

	moveHanoi(post, other, to, from ,height - 1);

	return 0;
}

#ifndef MAX
	#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

static int printHanoi(LLStack *postA, LLStack *postB, LLStack *postC)
{
	if(postA == NULL || postB == NULL || postC == NULL)
	{
		return -1;
	}
	int maxNum = 0;

	maxNum = MAX(MAX(postA->size, postB->size), postC->size);

	int i;
	LLNode *tempA = NULL;
	LLNode *tempB = NULL;
	LLNode *tempC = NULL;

	for(i = maxNum;i > 0;i--)
	{
		if(tempA == NULL && postA->size == i)
		{
			tempA = postA->top;
		}
		if(tempB == NULL && postB->size == i)
		{
			tempB = postB->top;
		}
		if(tempC == NULL && postC->size == i)
		{
			tempC = postC->top;
		}

		if(tempA != NULL)
		{
			printf("%d\t", tempA->key);
			tempA = tempA->next;
		}
		else
		{
			printf(" \t");
		}

		if(tempB != NULL)
		{
			printf("%d\t", tempB->key);
			tempB = tempB->next;
		}
		else
		{
			printf(" \t");
		}

		if(tempC != NULL)
		{
			printf("%d", tempC->key);
			tempC = tempC->next;
		}
		else
		{
			printf(" ");
		}

		printf("\n");
	}
	printf("A\tB\tC\n\n");
	return 0;
}


///////Week1���� ����� ����  �Լ�///////

static LLStack *createStack()
{
	LLStack *lls = malloc(sizeof(LLStack));
	lls->top = NULL;
	lls->size = 0;
	return lls;
}

static void deleteStack(LLStack *targetStack)
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


static int push(LLStack *targetStack, int value)
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

static int pop(LLStack *targetStack, int *value)
{
	if (targetStack == NULL || targetStack->top == NULL) return -1;

	*value = targetStack->top->key;
	LLNode *nodeDelete = targetStack->top;
	targetStack->top = targetStack->top->next;
	targetStack->size -= 1;

	free(nodeDelete);

	return 0;
}
///////Week1���� ����� ���� �Լ� ///////
