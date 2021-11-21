#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*top,*temp;
void push();
void pop();
void display();
int main()
{
    int choice;
    printf("--PUSH AND POP--");
    while(1)
    {
        printf("\nEnter\n1.push\n2.pop\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                exit (0);
            }
        }
    }    
    
}
void push()
{
    int n,i;
    printf("Enter the total number of datas to push : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(top==NULL)
        {
            top=temp;
        }
        else
        {
            temp->next=top;
            top=temp;
        }
        //display();
    }display();
}
void pop()
{
    int n,i;
    printf("Enter the total number of datas to pop:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(top==NULL)
        {
            printf("Stack is empty");
            return;
        }
        else
        {
            temp=top;
            printf("%d\n",top->data);
            top=top->next;
            temp->next=NULL;
            free(temp);
        }
       // display();
    }display();
}
void display()
{
    temp=top;
    printf("the element in stack:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

/*OUTPUT

--PUSH AND POP--
Enter
1.push
2.pop
3.Exit
1
Enter the total number of datas to push : 3
Enter the data : 1
Enter the data : 2
Enter the data : 3
the element in stack:
3
2
1

Enter
1.push
2.pop
3.Exit
2
Enter the total number of datas to pop:1
3
the element in stack:
2
1

Enter
1.push
2.pop
3.Exit
3
*/