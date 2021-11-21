#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front,*temp,*rear;
void enqueue(int x);
void dequeue();
void display();
int main()
{
    int option;
    while(1)
    {
        printf("\nEnter the option :\n 1.enqueue\n2.dequeue\n3.display\n4.exit");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
            {
                int x;
                printf("enter the data:");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                exit(0);
            }
        }
               
    }
   
    return 0;
}
void enqueue(int x)
{
    //int n,i;
    temp=(struct node *)malloc (sizeof(struct node));
    //printf("Enter the number of elements to be enqueued:");
    //scanf("%d",&n);
   // for(i=0;i<n;i++)
    //{
     temp->data=x;
     temp->next=NULL;
     //printf("enter data for enqueue :");
     //scanf("%d",&temp->data);
     //temp->next==NULL;
     if(front==NULL)
     {
        rear=temp;
        front=temp;
     }
     else
     {
        front->next=temp;
        front=front->next;
     }
    
}
void dequeue()
{
    if(rear==NULL)
    {
        printf("underflow");
    }
    else
    {
        printf("\ndeququed element=%d",rear->data);
        rear=rear->next;
    }
    //printf("dequeued element =%d\n",front->data);
    //front=front->next;
}
void display()
{
    temp=rear;
    printf("stack list :\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}


/*OUTPUT

Enter the option :
 1.enqueue
2.dequeue
3.display
4.exit
1
enter the data:1

Enter the option :
 1.enqueue
2.dequeue
3.display
4.exit
1
enter the data:2

Enter the option :
 1.enqueue
2.dequeue
3.display
4.exit
1
enter the data:3

Enter the option :
 1.enqueue
2.dequeue
3.display
4.exit
2

deququed element=1
Enter the option :
 1.enqueue
2.dequeue
3.display
4.exit3
stack list :
2
3

Enter the option :
 1.enqueue
2.dequeue
3.display
4.exit
4
*/