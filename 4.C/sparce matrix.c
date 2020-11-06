#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct SM
{
	int r,c,d;
	struct SM *next;
}node;
node *create(node *,int [][5]);
void disp(node *);
node *add(node *,node *,node *);
void main()
{
	node *root=NULL,*root2=NULL,*ans=NULL;
	int a[5][5]={{0,0,0,0,1},{0,0,0,5,0},{1,9,0,0,0},{0,0,11,0,0},{0,0,0,0,11}};
	int b[5][5]={{0,0,0,0,1},{0,0,0,5,0},{1,9,0,0,0},{0,0,11,0,0},{0,0,0,0,11}};
	clrscr();
	root=create(root,a);
	printf("\nThe Sparce Matrix1 representation in linked list\n");
	disp(root);
	root2=create(root2,b);
	printf("\nThe Sparce Matrix2 representation in linked list\n");
	disp(root2);
	ans=add(root,root2,ans);
	disp(ans);
	getch();
}
node *create(node *a,int sm[][5])
{
	int i,j,e_c=0;
	node *root=a;

	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			printf("%d ",sm[i][j]);
			if(sm[i][j]!=0)
			{
				e_c++;
				if(root==NULL) // if will execute only once
				{

					a=(node *)malloc(sizeof(node));
					a->r=i; // row
					a->c=j; // column
					a->d=sm[i][j]; // data
					root=a;   // creation of root.

				}
				else
				{
					a->next=(node *)malloc(sizeof(node));
					a=a->next;
					a->r=i;
					a->c=j;
					a->d=sm[i][j];
				}


			}


		}

		printf("\n");

	}

	a->next=(node *)malloc(sizeof(node));  // last node to store
	a=a->next;
	a->r=i;  // total no. of rows
	a->c=j;  // total no. of cols.
	a->d=e_c;  // total no. of elements.

	a->next=NULL;

	return root;

}
void disp(node *root)
{
	node *a=root;

	printf("\n\n");

	while(a!=NULL)
	{
		printf("%d %d %d\t",a->r,a->c,a->d);
		a=a->next;
	}
	printf("\n\n");
}
node *add(node *a,node *b,node *ans)
{
	node *root=NULL;
	int data,row,column;
	int ec=0;
	while(a->next!=NULL || b->next!=NULL)
	{
		if(a->r==b->r && a->c==b->c)
		{
			data=a->d+b->d;
			row=a->r;
			column=a->c;
			a=a->next;
			b=b->next;
		}
		else if(a->r<b->r)
		{
			data=a->d;
			row=a->r;
			column=a->c;
			a=a->next;
		}
		else if(b->r<a->r)
		{
			data=b->d;
			row=b->r;
			column=b->c;
			b=b->next;

		}
		else if(a->r==b->r && a->c<b->c)
		{
			data=a->d;
			row=a->r;
			column=a->c;
			a=a->next;
		}
		else if(a->r==b->r && a->c>b->c)
		{
			data=b->d;
			row=b->r;
			column=b->c;
			b=b->next;
		}

		if(root==NULL)
		{
			ans=(node *)malloc(sizeof(node));
			ans->r=row;
			ans->c=column;
			ans->d=data;
			root=ans;  // root of the resultant sparce matrix
			ec++;
		}
		else
		{
			ans->next=(node *)malloc(sizeof(node));
			ans=ans->next;
			ans->r=row;
			ans->c=column;
			ans->d=data;
			ec++;
		}

	}


	while(a->next!=NULL)
	{
		ans->next=(node *)malloc(sizeof(node));
		ans=ans->next;
		ans->r=a->r;
		ans->c=a->c;
		ans->d=a->d;
		a=a->next;
		ec++;
	}
	while(b->next!=NULL)
	{
		ans->next=(node *)malloc(sizeof(node));
		ans=ans->next;
		ans->r=b->r;
		ans->c=b->c;
		ans->d=b->d;
		b=b->next;
		ec++;
	}

	ans->next=(node *)malloc(sizeof(node));
	ans=ans->next;
	ans->r=5;
	ans->c=5;
	ans->d=ec;

       ans->next=NULL;
       return root;
}
