#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
  int data;
  struct node *link;
};
struct node *head, *ptr, *temp;

/* inserting element in begining*/
void insert_front()
{

	int data_value;

	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data_value;
	temp->link = NULL;

	if(head == NULL)	head = temp;
	else
	{
		temp->link=head;
		head = temp;
	}
}

void insert_any()
{
	int data_value, key;

	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);
	printf("\nEnter data of the node after which new node is to be inserted: ");
	scanf("%d", &key);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data_value;
	temp->link = NULL;

	ptr = head;
	while(ptr->link != NULL && ptr->data != key)	ptr = ptr->link;
	if(ptr->data == key)
	{

		temp->link = ptr->link;
		ptr->link = temp;
	}
	else
	{
		printf("\nValue %d not found\n",key);
	}
}

void insert_end()
{
	int data_value;

	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data_value;
	temp->link = NULL;
    if(head==NULL) {

    	head=temp;
    	temp=head;
	}
    else{
	ptr = head;
	while(ptr->link != NULL)	ptr = ptr->link;
	ptr->link = temp;
}}
void delete_front()
{
	//If the list is already empty
	if(head == NULL)	printf("\nEmpty Linked List. Deletion not possible.\n");
	else
	{
		ptr = head;
		head = head->link;
		free(ptr);
	}
}
void display()
{   printf("\n element are:\n");
	if(head==NULL)	printf("Empty!\n");
	else
	{
		temp = head;
		while(temp!=NULL)
	   {
	     printf("%d\n",temp->data);
	     temp = temp->link;
	   }
	}
}

void stack()
{
    printf("----------------stack------------------\n");
	int choice;
 while(1)
  {
   printf("1. push an element \n");
   printf("2. pop an element \n");
   printf("3. display elements \n");
   printf("4. exit \n");
   scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  insert_front();
   display();
  break;
  case 2:
   delete_front();
   printf("element is deleted from top\n");
  break;
  case 3:
   display();
  break;
  case 4:
  	exit(0);
  }
 }
}
void queue()
{
    printf("----------------queue------------------\n");
	int choice;
 while(1)
  {
   printf("1. add an element \n");
   printf("2. delete an element \n");
   printf("3. display  element \n");
   printf("4. exit \n");
   scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  insert_end();
  display();
  break;
  case 2:
  delete_front();
  display();
  break;
  case 3:
  display();
  break;
  case 4:
  	exit(0);
  }
 }
}
void linklist()
{
    printf("----------------linklist------------------\n");
	int choice;
 while(1)
  {
   printf("1. add an element in front\n");
   printf("2. add an element in end \n");
   printf("3. add an element at given node \n");
   printf("4. display elements \n");
   printf("5. exit \n");
   scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  insert_front();
  display();
  break;
  case 2:
  insert_end();
  display();
  break;
  case 3:
   insert_any();
   display();
   break;
  case 4:
  display();
  break;
  case 5:
  	exit(0);
  }
 }
}
int main(int argc, char *argv[]) {
	head = NULL;
	if(strcmp(argv[1],"stack")==0)	stack();
	else if(strcmp(argv[1],"queue")==0)	queue();
	else if(strcmp(argv[1],"linklist")==0)	linklist();
	else printf("Invalid arguement!\n");
	return 0;
}

