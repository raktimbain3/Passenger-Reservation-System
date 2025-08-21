#include<stdio.h>
#include<stdlib.h>
#define N 100
int ary[N];
int cancel[N];
int pass=0;
int top=-1;

int deque[N];
int front=N/2;
int rear=N/2-1;

struct Node 
{
    int id;
    struct Node* next;
};
struct Node* head=NULL;

//Passenger menu
void passenger();
void sort();
void display();
void insertion();
void deletion();
void search();
void BinarySearch();
void LinearSearch();

//ticket Cancellation 
void ticket();
void push();
void pop();
void searchC();
void print();

//Ride request
void ride();
void insertFront(int id);
void insertRear(int id);
void removeFront();
void showDeque();

//Driver entry
void driver();
void insertFrontDriver(int id);
void insertMiddleDriver(int id, int pos);
void insertEndDriver(int id);
void deleteFrontDriver();
void deleteMiddleDriver(int pos);
void deleteEndDriver();
void searchDriver(int id);
void displayDrivers();

int main()
{
    int n;
    do
    {
        printf("********Passenger Reservation********\n");
        printf("1.Passenger Data\n2.Ticket cancellation history\n3.Ride Requests\n4.Driver Assignment\n5.Exit\n");
        printf("Enter:");
        scanf("%d",&n);

        switch(n)
        {
            case 1 : passenger();
            break;
            case 2 : ticket();
            break;
            case 3 : ride();
            break;
            case 4 : driver();
            break;
            case 5 : printf("Existing...\n");
            break;
            default : printf("Invalid input. Try again\n");
            break;
        }
        
    } while (n!=5);

    return 0;
}
void passenger()
{
    printf("===Passenger Menu===\n");
    int ch;
    do
    {
       printf("1.Display Passenger list\n2.Add Passenger\n3.Delete Passenger\n4.Sort Passenger\n5.Search Passenger\n6.Main menu\n");
       printf("Enter:");
       scanf("%d",&ch);
    
        switch (ch)
        {
            case 1 : display();
            break;
            case 2 : insertion();
            break;
            case 3 : deletion();
            break;
            case 4 : sort();
            break;
            case 5 : search();
            break;
            case 6 : printf("Going Main Menu\n");
            break;
            default : printf("Invalid Operation\n");
            break;
        }
        
    } while (ch!=6);
    

}
void display()
{
    printf("===Passenger ID List===\n");
    if(pass==0)
    {
        printf("NO passenger to show\n\n");
    }
    else
    {
        for(int i=0; i<pass; i++)
        {
          printf("%d\n",ary[i]);
        }
    }   
    
}
void insertion()
{
    if(pass<=N)
    {
        int id,pos;
        printf("Enter Passenger id:");
        scanf("%d",&id);
        printf("Enter position(1-%d):",pass+1);
        scanf("%d",&pos);
        for( int i=pass; i>=pos-1; i--)
        {
            ary[i+1]=ary[i];
        }
        pass++;
        ary[pos-1]=id;
        printf("Insertion successful\n");
    }
    else
    {
        printf("No more spece..\n");
    }

}
void deletion()
{
    if(pass==0)
    {
        printf("Passenger list empty\n");
    }
    else
    {
       int  delpos;
       printf("Enter the position of the passenger id you want to delete(1-%d):",pass);
       scanf("%d",&delpos);
       int t;
       t=ary[delpos-1];
       for (int i=delpos-1; i<pass; i++)
       {
          ary[i]=ary[i+1];
       }
       pass--;
       printf("%d is deleted\n",t);
    }
    
}
void sort()
{
    if(pass==0)
    {
        printf("No passenger id to sort\n");
    }
    else
    {
        for ( int i=0; i < pass; i++ )
       {
           for ( int j=0; j < pass-i-1; j++ )
           {
                if (ary[j] > ary[j + 1])
                {
                  int temp = ary[j];
                  ary[j] = ary[j + 1];
                  ary[j + 1] = temp;
                }
            }
       }
    }
 

    printf("Sorting completed...\n");
}
void search()
{
    if(pass==0)
    {
        printf("No passenger id to search\n");
    }
    else
    {
        int s;
        printf("1.Binary\n2.Linear\nEnter:");
        scanf("%d",&s);
        switch(s)
        {
            case 1 : 
            {
                printf("The array must be sorted. Sorting process ongoing..\n");
                sort();
                BinarySearch();
            }
            break;
            case 2 : LinearSearch();
            break;
            default : printf("Invalid operation..\n");
            break;
        }

    }
    
}
void BinarySearch()
{
    int v;
    printf("Enter Passenger id:");
    scanf("%d",&v);
    
    int l=0,h=pass-1;
    int m;
    while( l<=h )
    {
       m=(l+h)/2;
       if( v>ary[m] )
       {
           l=m+1;
       }
       else if(v==ary[m])
       {
           printf("PAssenger id found in %dth position\n",m+1);
           break;
       }
       else if(v<ary[m])
       {
          h=m-1;
       }
    }
       if(l>h)
       {
           printf("Passenger Id not found\n");
       }

}
void LinearSearch()
{
    int v;
    int search=0;
    printf("Enter Passenger id:");
    scanf("%d",&v);

    for( int i=0; i<pass; i++ )
    {
        if(v==ary[i])
        {
            printf("Passenger id found in %dth position\n",i+1);
            search=1;
        }
    }

    if(search==0)
    {
        printf("Passenger Id not found\n");
    }
}
void ticket()
{
    int c;
    do
    {
        printf("===Cancellation History Stack===\n");
        printf("1.Push canceled ticket ID\n2.Pop last cancellation ID\n3.Search a canceled ID\n4.Print current canceled IDs\n5.Main Menu\n");
        printf("Enter:");
        scanf("%d",&c);

        switch(c)
        {
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : searchC();
            break;
            case 4 : print();
            break;
            case 5 : printf("Going Menu\n");
            break;
            default : printf("Invalid Operation\n");
            break;
        }
    } while (c!=5);
    
}
void push()
{
    int v;
    printf("Enter canceled ID:");
    scanf("%d",&v);
     if (top==N-1)
    {
        printf("Stack full\n");
    }
    else
    {
        top++;
        cancel[top]=v;
        printf("ID Pushing Successful..\n");
    }
}
void pop()
{
    int v;
    if(top==-1)
    {
        printf("No ID to delete\n");
    }
    else
    {
        v=cancel[top];
        top--;
        printf("ID:%d is deleted\nPoping successful...\n",v);
    }
}
void searchC()
{
    if (top==-1)
    {
        printf("There is no ID. Stack is empty..\n");
    }
    else
    {
        int v;
        int search=0;
        printf("Enter an ID to search:");
        scanf("%d",&v);

        for( int i=0; i<=top; i++ )
        {
            if(v==cancel[i])
            {
                printf("ID found in %dth position\n",i+1);
                search=1;
            }
        }

        if(search==0)
        {
            printf("ID not found\n");
        }
    }
}
void print()
{
    printf("===== Canceled IDs =====\n");  
    if (top==-1)
    {
        printf("There is no ID\n");
    }
    else
    {  for(int i=top; i>=0; i--)
       {
           printf("\t%d\n",cancel[i]);
       }
    }
}
void ride() 
{
    int ch,id;
    do {
        printf("\n=== Ride Menu ===\n1.Insert Normal Passenger\n2.Insert VIP Passenger\n3.Remove from front\n4.Show Queue\n5.Main Menu\nEnter:");
        scanf("%d", &ch);
        switch(ch) 
        {
            case 1 : 
            {
                printf("Enter ID:"); 
                scanf("%d",&id); 
                insertRear(id);
            }
            break;
            case 2 : 
            {
                printf("Enter ID:"); 
                scanf("%d",&id); 
                insertFront(id);
            }
            break;
            case 3 : removeFront(); 
            break;
            case 4 : showDeque(); 
            break;
            default : printf("Invalid Poeration..\n") ;
            break;
        }
    } while(ch!=5);
}
void insertFront(int id) 
{
    if(front==0)
    {
        printf("No space at front.\n");
    }
    else if (rear<front)
    {
        deque[front]=id;
        printf("1st VIP passenger inserted successfully!\n");
    }
    else 
    {
        deque[--front]=id;
        printf("VIP passenger inserted successfully !\n");
    }
}
void insertRear(int id) 
{
    if(rear==N-1) 
    {
        printf("Queue full.\n");
    }
     else if (rear<front)
    {
        rear=front;
        deque[rear]=id;
        printf("1st normal passenger inserted successfully!\n");
    }
    else 
    {
        deque[++rear]=id;
        printf("Passenger inserted successfully !\n");
    }
}
void removeFront() 
{
    if (rear<front) 
    {
        printf("Queue empty.\n");
    }
    else 
    {
        printf("Boarded: %d\n",deque[front]);

        if (front==rear) 
        {
            front=N/2;
            rear=N/2-1;
        }
        else 
        {
            front++;
        }
    }
}
void showDeque() 
{
    if (rear<front) 
    {
        printf("Empty queue\n");
    }
    else 
    {
        printf("Current queue: ");
        for(int i=front; i<=rear; i++) 
        {
            printf("%d  ",deque[i]);
        }
        printf("\n");
    }
}
void driver() 
{
    int ch,id,pos;
    do 
    {
        printf("\n=== Driver Assignment Menu ===\n");
        printf("1. Insert at Front\n2. Insert at Middle\n3. Insert at End\n");
        printf("4. Delete from Front\n5. Delete from Middle\n6. Delete from End\n");
        printf("7. Search Driver\n8. Show Driver List\n9. Return to Main Menu\nEnter: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1 :
                printf("Enter Driver ID to insert at front: ");
                scanf("%d",&id);
                insertFrontDriver(id);
                break;
            case 2 :
                printf("Enter Driver ID and position to insert in middle: ");
                scanf("%d %d",&id,&pos);
                insertMiddleDriver(id,pos);
                break;
            case 3 :
                printf("Enter Driver ID to insert at end: ");
                scanf("%d",&id);
                insertEndDriver(id);
                break;
            case 4 :
                deleteFrontDriver();
                break;
            case 5 :
                printf("Enter position to delete from middle: ");
                scanf("%d",&pos);
                deleteMiddleDriver(pos);
                break;
            case 6 :
                deleteEndDriver();
                break;
            case 7 :
                printf("Enter Driver ID to search: ");
                scanf("%d",&id);
                searchDriver(id);
                break;
            case 8 :
                displayDrivers();
                break;
            case 9 :
                printf("Returning to Main Menu...\n");
                break;
            default :
                printf("Invalid choice.\n");
        }
    } while (ch!=9);
}
void insertFrontDriver(int id) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->id=id;
    newNode->next=head;
    head=newNode;
    printf("Inserted at front.\n");
}
void insertEndDriver(int id) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->id=id;
    newNode->next=NULL;

    if (head==NULL) 
    {
        head=newNode;
    } 
    else 
    {
        struct Node* temp=head;
        while (temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    printf("Inserted at end.\n");
}
void insertMiddleDriver(int id, int pos) 
{
    if (pos<=1) 
    {
        // If position is 1 or less, treat as front insertion
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->id = id;
        newNode->next = head;
        head = newNode;
        printf("Inserted at front (position 1).\n");
    }
    else 
    {
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->id=id;

        struct Node* temp = head;
        for (int i=1; i<pos-1 && temp!=NULL; i++) 
        {
            temp=temp->next;
        }

        if (temp==NULL) 
        {
            printf("Position out of range.\n");
            free(newNode);
        }
        else 
        {
            newNode->next=temp->next;
            temp->next=newNode;
            printf("Inserted at position %d.\n",pos);
        }
    }
}

// Delete from front
void deleteFrontDriver() 
{
    if (head==NULL) 
    {
        printf("List is empty.\n");
    }
    else 
    {
        struct Node* temp=head;
        head=head->next;
        printf("Deleted: %d\n",temp->id);
        free(temp);
    }
}

// Delete from end
void deleteEndDriver() 
{
    if (head==NULL) 
    {
        printf("List is empty.\n");
    }
    else 
    {
        if (head->next==NULL) 
        {
            printf("Deleted: %d\n", head->id);
            free(head);
            head=NULL;
        }
        else 
        {
            struct Node* temp = head;
            while (temp->next->next!=NULL) 
            {
                temp=temp->next;
            }

            printf("Deleted: %d\n",temp->next->id);
            free(temp->next);
            temp->next=NULL;
        }
    }
}
void deleteMiddleDriver(int pos) 
{
    if (head==NULL) 
    {
        printf("List is empty.\n");
    }
    else 
    {
        if (pos==1) 
        {
            deleteFrontDriver();
        }
        else 
        {
            struct Node* temp=head;
            for (int i=1; i<pos-1 && temp!=NULL; i++) 
            {
                temp=temp->next;
            }

            if (temp==NULL || temp->next==NULL) 
            {
                printf("Position out of range.\n");
            }
            else 
            {
                struct Node* del=temp->next;
                temp->next=del->next;
                printf("Deleted: %d\n", del->id);
                free(del);
            }
        }
    }
}
void searchDriver(int id) 
{
    struct Node* temp=head;
    int found=0;

    while (temp!=NULL) 
    {
        if (temp->id==id) 
        {
            printf("Driver %d found.\n", id);
            found=1;
            break;
        }
        temp=temp->next;
    }

    if (found==0) 
    {
        printf("Driver %d not found.\n", id);
    }
}
void displayDrivers() 
{
    struct Node* temp=head;
    if (temp==NULL) 
    {
        printf("No drivers assigned.\n");
    }
    else
    {
       printf("Driver List: ");
       while (temp!=NULL) 
       {
           printf("%d -> ",temp->id);
           temp=temp->next;
       }
       printf("NULL\n");
    }
}