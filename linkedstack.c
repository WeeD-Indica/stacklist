#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
  int data;
  struct node *link;
}node;
node *top=NULL;
void push(int x);
void pop();
void display();

void main()
{
  int ch,x;
  int choice;
  do
    {
      printf("\n1)push\n2)pop\n3)Traverse\n\nChoose your option:");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:printf("enter element:");
	  scanf("%d",&x);
	  push(x);
	  break;
	case 2:pop();
	  break;
	case 3:display();
	  break;
	default:printf("Error");
	}
      printf("\nDo you want to continue(1/0):");
      scanf("%d",&choice);
    }
  while(choice);
}

void push(int x)
{
  node *newnode=(node*)malloc(sizeof(node));
  newnode->data=x;
  node* temp=top;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  if(top==NULL){
    top=newnode;
    newnode->link=NULL;
    return;
  }
  else{
    newnode->link=top;
    top=newnode;
    return;
  }
}

void pop()
{
  node *temp;
  if(top==NULL)
    printf("\nSTACK UNDERFLOW!!!\n");
  else
    {
      temp=top;
      top=top->link;
      free(temp);
    }
}

void display()
{
  node*p;
  p=top;
  while(p!=NULL)
    {
      printf("%d\t",p->data);
      p=p->link;
    }
}
	     
