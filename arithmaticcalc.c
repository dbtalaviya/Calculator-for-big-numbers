#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node1{

    int data;
    struct node1 *next;
    struct node1 *prev;

};

struct node2{

    int data;
    struct node2 *next;
    struct node2 *prev;

};

struct node3{

    int data;
    struct node3 *next;
    struct node3 *prev;
};


struct node1* insertatfirst(struct node1 *head,int dat)
{
    struct node1 *p=(struct node1*)malloc(sizeof(struct node1));

    head->data=dat;
    head->prev=p;
    p->prev=NULL;
    p->next=head;
    return p;
}

struct node2* insertatfirst2(struct node2 *head,int dat)
{
    struct node2 *p=(struct node2*)malloc(sizeof(struct node2));

    head->data=dat;
    head->prev=p;
    p->prev=NULL;
    p->next=head;
    return p;
}

struct node3* insertatfirst3(struct node3 *head,int dat)
{
    struct node3 *p=(struct node3*)malloc(sizeof(struct node3));

    head->data=dat;
    head->prev=p;
    p->prev=NULL;
    p->next=head;
    return p;
}

struct node3* insertatlast3(struct node3 *tail,int dat)
{
    struct node3 *p=(struct node3*)malloc(sizeof(struct node3));

    p->data=dat;
    tail->next=p;
    p->next=NULL;
    p->prev=tail;
    return p;
}

void clearlinkedlist(struct node1 *p1,struct node2 *p2,struct node3 *p3)
{
    while(p1->prev!=NULL)
    {
        struct node1 *p1c=p1->prev;
        free(p1);
        p1=p1c;
    }

    while(p2->prev!=NULL)
    {
        struct node2 *p1c=p2->prev;
        free(p2);
        p2=p1c;
    }

    while(p3->prev!=NULL)
    {
        struct node3 *p1c=p3->prev;
        free(p3);
        p3=p1c;
    }

}

void addition()
{
    char s1[1000];
    char s2[1000];
    printf("\nEnter the First Number:");
    scanf("%s",s1);
    printf("\nEnter the Second Number:");
    scanf("%s",s2);
    

    struct node1* head1=(struct node1*)malloc(sizeof(struct node1));
    struct node2* head2=(struct node2*)malloc(sizeof(struct node2));

    
    head1->next=NULL;
    head2->next=NULL;
    head1->prev=NULL;
    head2->prev=NULL;

    struct node1* tail1=head1;
    struct node2* tail2=head2;

    struct node1* p1=head1;
    struct node2* p2=head2;

    for(int i=strlen(s1)-1;i>=0;i--)
    {
        head1=insertatfirst(head1,s1[i]-'0');
    }

    for(int i=strlen(s2)-1;i>=0;i--)
    {
        head2=insertatfirst2(head2,s2[i]-'0');
    }

     struct node3* head3=(struct node3*)malloc(sizeof(struct node3));
     head3->next=NULL;
     head3->prev=NULL;
     struct node3* tail3=head3;
      struct node3* p3=head3;
    
     int carry=0;

     while(tail1->prev!=NULL&&tail2->prev!=NULL)
     {
        int sum=tail1->data + tail2->data + carry;
        head3=insertatfirst3(head3,sum%10);
        carry = sum/10;
        tail1=tail1->prev;
        tail2=tail2->prev;
     }

     while(tail1->prev!=NULL)
     {
        int sum=tail1->data + carry;
        head3=insertatfirst3(head3,sum%10);
        carry=sum/10;
        tail1=tail1->prev;
     }

     while(tail2->prev!=NULL)
     {
        int sum=tail2->data + carry;
        head3=insertatfirst3(head3,sum%10);
        carry=sum/10;
        tail2=tail2->prev;
     }

     if(carry==1)
     {
        head3=insertatfirst3(head3,1);
        carry=0;
     }

     printf("\nYour Answer is::");
     head3=head3->next;
     while(head3!=NULL)
     {
        printf("%d",head3->data);
        head3=head3->next;
     }
     clearlinkedlist(p1,p2,p3);
}

void substraction()
{
    char s1[1000];
    char s2[1000];
    printf("\nEnter the First Number:");
    scanf("%s",s1);
    printf("\nEnter the Second Number:");
    scanf("%s",s2);

    int neg=0;
    if(strcmp(s1,s2)<0)
    {
        neg=1;
        char s[1000];
        strcpy(s,s1);
        strcpy(s1,s2);
        strcpy(s2,s);
    }

    struct node1* head1=(struct node1*)malloc(sizeof(struct node1));
    struct node2* head2=(struct node2*)malloc(sizeof(struct node2));

    
    head1->next=NULL;
    head2->next=NULL;
    head1->prev=NULL;
    head2->prev=NULL;

    struct node1* tail1=head1;
    struct node2* tail2=head2;

    struct node1* p1=head1;
    struct node2* p2=head2;

    for(int i=strlen(s1)-1;i>=0;i--)
    {
        head1=insertatfirst(head1,s1[i]-'0');
    }

    for(int i=strlen(s2)-1;i>=0;i--)
    {
        head2=insertatfirst2(head2,s2[i]-'0');
    }

     struct node3* head3=(struct node3*)malloc(sizeof(struct node3));
     head3->next=NULL;
     head3->prev=NULL;
     struct node3* tail3=head3;
      struct node3* p3=head3;
    
     int carry=0;

     while(tail1->prev!=NULL&&tail2->prev!=NULL)
     {
        int sum=(tail1->data - tail2->data) - carry;
        if(sum<0)
        {
            carry = 1;
            sum+=10;
            head3=insertatfirst3(head3,sum);
        }
        else
        {
            carry = 0;
            head3=insertatfirst3(head3,sum);
        }
        tail1=tail1->prev;
        tail2=tail2->prev;

     }

     while(tail1->prev!=NULL)
     {
        int sum=(tail1->data ) - carry;

        if(sum<0)
        {
            carry = 1;
            sum+=10;
            head3=insertatfirst3(head3,sum);
        }

        else
        {
            carry = 0;
            head3=insertatfirst3(head3,sum);
        }

        tail1=tail1->prev;
     }

     printf("\nYour Answer is::");
     if(neg==1)
     {
        printf("-");
     }

     head3=head3->next;
     while(head3->next!=NULL)
     {
        if(head3->data!=0)
        {
            break;
        }
        head3=head3->next;
     }
     while(head3!=NULL)
     {
        printf("%d",head3->data);
        head3=head3->next;
     }
     clearlinkedlist(p1,p2,p3);
}

void multiplication()
{
    char s1[1000];
    char s2[1000];
    printf("\nEnter the First Number:");
    scanf("%s",s1);
    printf("\nEnter the Second Number:");
    scanf("%s",s2);
    

    struct node1* head1=(struct node1*)malloc(sizeof(struct node1));
    struct node2* head2=(struct node2*)malloc(sizeof(struct node2));

    
    head1->next=NULL;
    head2->next=NULL;
    head1->prev=NULL;
    head2->prev=NULL;

    struct node1* tail1=head1;
    struct node2* tail2=head2;

    struct node1* p1=head1;
    struct node2* p2=head2;

    for(int i=strlen(s1)-1;i>=0;i--)
    {
        head1=insertatfirst(head1,s1[i]-'0');
    }

    for(int i=strlen(s2)-1;i>=0;i--)
    {
        head2=insertatfirst2(head2,s2[i]-'0');
    }

     struct node3* head3=(struct node3*)malloc(sizeof(struct node3));
     head3->next=NULL;
     head3->prev=NULL;
     struct node3* tail3=head3;
     struct node3* p3=head3;
    
     int carry=0;
     char s[1000];
     strcpy(s,"0");
     int cnt=0;

     while(tail2->prev!=NULL)
     {

     tail1=p1;
     carry=0;
     char temp[1000];
     strcpy(temp,"");
     int carrysum=0;

     struct node3 *p=p3;

     for(int i=0;i<cnt;i++)
     {
        if(p->prev==NULL)
        {
            int add= 0;
            p= insertatfirst3(p,add%10);
            head3=p;
        }
       else{
        p=p->prev;
       }
     }
     cnt++;

     while(tail1->prev!=NULL)
     {
        int sum=(tail1->data*tail2->data) + carry;
        carry = sum/10;
        if(p->prev==NULL)
        {
            int add= sum%10 ;
            // p->data=add%10;
            p= insertatfirst3(p,add%10);
            carrysum=add/10;
            head3=p;
        }

        else
        {
            int add= sum%10 + p->data;
            p->data=add%10;
            carrysum=add/10;
            p=p->prev;
        }
        tail1=tail1->prev;
        carry+=carrysum;
     }
     while(carry>0)
     {
        if(p->prev==NULL)
        {
            int add= carry;
            // p->data=add%10;
            p = insertatfirst3(p,add%10);
            carry=add/10;
            head3=p;
        }
        else{
            int add= p->data +  carry;
            p->data=add%10;
            carry=add/10;
            p=p->prev;
        }
     }
        tail2=tail2->prev;
    }

     printf("\nYour Answer is::");

     head3=head3->next;
     while(head3!=NULL)
     {
        printf("%d",head3->data);
        head3=head3->next;
     }

     clearlinkedlist(p1,p2,p3);
}

void division()
{
    char s1[1000];
    int dev;
    printf("Enter Number\n");
    scanf("%s",s1);
    printf("Enter Divisor\n");
    scanf("%d",&dev);
    printf("Your Answer:: \n");

    struct node1* head1=(struct node1*)malloc(sizeof(struct node1));
    struct node2* head2=(struct node2*)malloc(sizeof(struct node2));

    
    head1->next=NULL;
    head2->next=NULL;
    head1->prev=NULL;
    head2->prev=NULL;

    struct node1* tail1=head1;
    struct node2* tail2=head2;

    struct node1* p1=head1;
    struct node2* p2=head2;

    for(int i=strlen(s1)-1;i>=0;i--)
    {
        head1=insertatfirst(head1,s1[i]-'0');
    }

    for(int i=strlen(s1)-1;i>=0;i--)
    {
        head2=insertatfirst2(head2,s1[i]-'0');
    }

     struct node3* head3=(struct node3*)malloc(sizeof(struct node3));
     head3->next=NULL;
     head3->prev=NULL;
     struct node3* tail3=head3;
     struct node3* p3=head3;

     int temp=0,i;

     for(i=0;i<strlen(s1);i++)
     {
        if(temp>=dev)
        {
            break;
        }

        else{
            temp = temp*10 + (s1[i]-'0');
        }
     }

     for(i;i<strlen(s1);i++)
     {
        printf("%d",temp/dev);
        temp=(temp % dev)*10 + (s1[i]-'0');
     }

     printf("%d.",temp/dev);
     temp=(temp%dev)*10;
     for(i=0;i<10;i++)
     {
        printf("%d",temp/dev);
        temp=(temp%dev)*10;
     }

}

int main()
{
   
    while(1)
    {
        printf("\nArithmatic calculator\n");
        printf("\n1.Addition");
        printf("\n2.Substraction");
        printf("\n3.Multiplication");
        printf("\n4.division");

        int x;
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            addition();
            break;

        case 2:
            substraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        default:
            printf("\nINVALID INPUT\n");
            break;
        }
    }
}