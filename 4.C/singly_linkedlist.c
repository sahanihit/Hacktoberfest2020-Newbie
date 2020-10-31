#include<stdio.h>
#include<conio.h>
#include<malloc.h>  // memory allocate . header file
typedef struct SLinkedList
{
	int data;
	struct SLinkedList *next;
}node;
node *create(node *);
void disp(node *);
void main()
{
	node *a=NULL;
	clrscr();
	a=create(a);
	printf("\nThe singly linked list\n");
	disp(a);
	getch();
}
node *create(node *a)
{
	int d;
	node *root=NULL;
	printf("Enter the data (-999 to exit):");
	scanf("%d",&d);  //10

	while(d!=-999)
	{
		if(a==NULL)
		{
			a=(node*)malloc(sizeof(node));    // x=(float)5/2;
			a->data=d;
			root=a;  // imp part
		}
		else
		{
			a->next=(node *)malloc(sizeof(node));
			a=a->next;
			a->data=d;
		}
		printf("Enter the data (-999 to exit):");
		scanf("%d",&d);
	}
	a->next=NULL;
	return root;

}
void disp(node *a)
{
	if(a==NULL)
	{
		printf("\nSingle linked list is empty!");
		return;
	}
	while(a!=NULL)
	{
		printf("%d ",a->data);
		a=a->next;  //(i++)
	}
}
