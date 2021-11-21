#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*tail,*temp,*t,*head1,*tail1;
void create();
void clone();
void print();
int main()
{
    create();
    clone();
    print();
}
void create()
{
    int n,i;
    printf("Enter the total number of nodes to be created :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=tail->next;
        }
    }
}
void clone()
{
    temp=head;
    while(temp!=NULL)
    {
        t=(struct node*)malloc(sizeof(struct node)); 
        t->data=temp->data;
        t->next=NULL;
        if(head1==NULL)
        {
            head1=tail1=t;
        }
        else
        {
            tail1->next=t;
            tail1=tail1->next;
        }
        temp=temp->next;
        
    }
}
void print()
{
    temp=head;
    t=head1;
    printf("The original list is :\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("The cloned list is :\n");
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}


/* OUTPUT

Enter the total number of nodes to be created :3
Enter the data :1
Enter the data :2
Enter the data :3
The original list is :
1
2
3
The cloned list is :
1
2
3

*/