#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*head=NULL,*temp,*prev,*tail;
void insert_beg();
void insert_end();
void insert_middle();
void print();
void create();
void main()
{
    create();
    insert_middle();
    print();
}
void create()
{
    int n,x,i;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the number:");
        scanf("%d",&temp->data);
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
          tail->next=temp;
          tail=temp;
        }
    }
        
}
void insert_beg()
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    //temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    printf("enter the data to be inserted:");
    scanf("%d",&temp->data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    print();
    
}
void insert_end()
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    //temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    printf("enter the data to be added:");
    scanf("%d",&temp->data);
    struct node*t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=temp;
    temp->prev=t;
    print();
}
void insert_middle()
{
    struct node*temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    int y;
    temp->prev=NULL;
    temp->next=NULL;
    printf("enter the data to be added:");
    scanf("%d",&temp->data);
    printf("enter the element after which you want to insert:");
    scanf("%d",&y);
    t=head;
    while(t->data!=y)
    {
        t=t->next;
    } 
    temp->next=t->next;
    t->next=temp->prev;
    t->next=temp;
   // temp->next=t->next;
//    temp->prev=t;
  //  t->next->prev=temp;
    //t->next=temp;
   // print();
}
void delete_beg(int x)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
       temp=head;
       head=head->next;
       head->prev=NULL;
       free(temp);
       temp=NULL;
    }
    print();
}
void delete_middle()
{
    int y;
    if(head==NULL)
    {
        printf("the list is empty:");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
      struct node*t=head;
      struct node*temp=head;
      printf("\nenter the data to be deleted:");
      scanf("%d",&y);  
      while(temp->data!=y)
      {
          t=temp;
          temp=temp->next;
      }
      t->next=temp->next;
      temp->next->prev=t;
      temp->next=NULL;
      temp->prev=NULL;
      
      
      free(temp);
    }
    print();
}
void delete_end()
{
    //struct node*t=head;
    //struct node*prev=head;
    if(head==NULL)
    {
        printf("list is empty:");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head==NULL;
    }
    else
    {
      struct node*temp=head;
      struct node*t=head;
      while(temp->next!=NULL)
      {
        t=temp;
        temp=temp->next;
      }
      t->next=NULL;
      temp->prev=NULL;
      free(temp);
      temp=NULL;
    }
    print();
}
void print() 
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}


/*OUTPUT
enter the number of nodes:3
enter the number:1
enter the number:2
enter the number:3
enter the data to be inserted:4
4123

enter the number of nodes:3
enter the number:4
enter the number:1
enter the number:5
enter the data to be added:2
enter the element after which you want to insert:1
4125

enter the number of nodes:3
enter the number:4
enter the number:5
enter the number:6
enter the data to be added:1
4561

Enter the option:1
enter the number of nodes:3
enter the data:1
enter the data:2
enter the data:3

the list is:23

Enter the option:2
enter the number of nodes:3
enter the data:1
enter the data:2
enter the data:3

enter the data to be deleted:2

the list is:13

Enter the option:3
enter the number of nodes:3
enter the data:1
enter the data:2
enter the data:3

the list is:12
*/