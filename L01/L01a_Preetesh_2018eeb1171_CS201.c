/*ENTRY NUMBER -2018EEB1171
NAME-PREETESH VERMA
COURSE-CS201*/
// I ASSURE YOU I HAVE NOT COPIED THE CODE FROM ANY OF MY FRIENDS OR TAKEN HELP FROM INTERNET
 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
	struct node *prev;
};

struct node *head;
struct node *t3;
struct node *t4;
struct node *t5;


void calculate(int n)						//FUNCTION TO CALCULATE THE GIVEN FUNCTION FOR THE GIVEN NUMBER
{
head=(struct node*)malloc(sizeof(struct node));
head->val=4;
head->next=NULL;
head->prev=NULL;
int pr2,carry=0;
int c=0;
int t;
for(int i=3;i<=n;i++)
{
	for(int j=1;j<=i;j++)
	{
	t3=head;
		while(t3->prev!=NULL)
		{
			pr2=0;
			pr2=t3->val*i +carry;
			t3->val=pr2%10;
			carry=pr2/10;
			t3=t3->prev;
		}	
	pr2=t3->val*i +carry;
	t3->val=pr2%10;
	carry=pr2/10;
	t=carry;
	if(t3->prev==NULL)
	{
		while(t>0)
		{
			c++;
			t=t/10;
		}
		for(int i=1;i<=c;i++)
		{
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->val=carry%10;
			carry=carry/10;
			temp->next=t3;
			t3->prev=temp;
			t3=temp;
		}
	}
	}
}
}


void main()
{
	int t;
	int counter=0;int y=0;
	scanf("%d",&t);
	while(t-->0)
	{
		counter=0;
		int a,x,zero=0,k;
		char r[4];
		scanf("%d",&a);
		scanf("%s",r);							//K NEEDS TO BE POSITIVE AND LESS THAN 1000 AS MENTIONED IN QUESTION
		int h=k;int l=0;int u=0;int temp;
		while(r[l]!='\0')
		{
			l++;
			
		}
		int digit[l];
		while(l>0)
		{
			digit[u]=r[l-1]-48;
			u++;l--;
		}

		if(a==0&&r[0]=='1')
			printf("0 1 1");
		else if(a==0&&r[0]!='1')
			printf("0 0 1");
 		else if(a==1&&r[0]=='1')
			printf("0 1 1");
		else if(a==1&&r[0]!='1')
			printf("0 0 1");
		else if(a==2&& r[0]=='4')
			printf("0 1 4");
		else if(a==2&& r[0]!='4')
			printf("0 0 4");					//MADE HARDCORE CODE FOR FIRST THREE NUMBERS THAT IS 1,2,3
		else
		{
			calculate(a);
			x=t3->val;
			if(x==0)
			{	
				while(x==0)
				{
					y++;
					t3=t3->next;
					x=t3->val;
				}
				while(t3->next!=NULL)
				{
					t3=t3->next;
				}
			}
			while(t3->val==0)
			{
				zero++;
				t3=t3->prev;
			}							//COUNTING NUMBER OF ZEROES
			while(t3->next!=NULL)
			{
				t3=t3->next;
			}
			while(t3->prev!=NULL)
			{
				int r=0;int flags=0;
				while(r<u)
				{
					if(t3->val==digit[r])
					{
						t3=t3->prev;
						r++;
					}
					else 
					{
						flags=1;
						if(t3->val!=digit[0])
						t3=t3->prev;
					break;
					}
				}
				if(flags==0){
					 int l = u;
					while(l>1){
						l--;
						t3 = t3->next;
					}
					 counter++;
				}
			}							//COUNTING NUMBER OF PATTERNS
			if(u==1&&digit[0]==0)
				counter-=y-1;
			printf("%d %d ",zero,counter);
			while(t3->val==0)
			{
				t3=t3->next;	
			}
			while(t3->next!=NULL)
			{
				printf("%d",t3->val);
				t3=t3->next;
			}							//PRINTING THE VALUE
			printf("%d\n",head->val);
	}
}
}
