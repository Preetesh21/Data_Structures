/*STACK PERMUATATION
ENTRY NUMBER-2018EEB1171
NAME-PREETESH VERMA
COURSE-CS201
Sir I assure you that i have not copied this code from any of my friends or taken any help from the internet.*/ 

#include<stdio.h>
char b[200];
int oop(char );
char bb='#';
int calculate(int ,int ,int );
int number[200];
int symbol[20];
int top1,top2;
int flag,a,minus,num1;
void removespaces(char *a)							//removes white spaces from the given expression
{
int count=0;
for(int i=0;a[i];i++)
{
if(a[i]!=' ')
a[count++]=a[i];
else if(a[i]==' '&&((a[i-1]<=57&&a[i-1]>=48)&&(a[i+1]<=57&&a[i+1]>=48)))	//checks if two consecutive numbers are entered without any operator between them and gives a error
{flag=1;}
else continue;
}
a[count]='\0';
}


void main()
{
char t[10];
int num=0;
int k=0;
scanf("%[^\n]%*c",t);								//takes input as string with white spaces
while(t[k]!='\0'){
num=num*10+t[k]-48;k++;}
while(num-->0)
{
char c[200];
scanf("%[^\n]%*c",c);
removespaces(c);
if(flag==1){ printf("Error\n");
flag=0;}else{
		int i=0;
		while(c[i]!=bb)							//for converting the given expression into two arrays of operators and operands 
		{
			a=0;
			minus=1;
			if(i==0)
			{
				if(c[0]=='+')
					i=i+1;
				else if(c[0]=='-')
					{minus=-1;i=i+1;}
				else if(c[0]<48||c[0]>57)
				{
					printf("Error");
					flag=1;
					break;					
				}
			}
			if(c[i]<=57&&c[i]>=48)
			{
				while(c[i]<=57&&c[i]>=48)
				{
					a=a*10+(c[i]-48);
					i++;
				}
			}
			char ch=c[i];
			if(c[i]<48||c[i]>57)
			{
				if(c[i]==bb &&(c[i-1]>=48||c[i-1]<=57))
				{num1=-1;number[top2++]=a;}
				else if(c[i]==bb &&(c[i-1]<=47||c[i-1]>=58))
				{
					printf("Error");
					flag=1;
					break;
				}
				else
				{
					if(c[i]=='-'&&(c[i-1]>=58||c[i-1]<=47))
					{
						i++;
						while(c[i]<=57&&c[i]>=48)
						{
							a=a*10+(c[i]-48);
							i++;
						}
						a=a*-1;number[top2++]=a;
					}
					if(c[i]<=57&&c[i]>=48) { printf("Error");flag=1;break;}
					num1=oop(c[i]);if(num1>-1){
					if(c[i]=='='&&c[i+1]=='=')
					{num1=74;i=i+1;}
					else if(c[i+1]=='='&&num1==44)
					{ num1=44;i=i+1;}
					else if(c[i]=='>'&&c[i+1]=='=')
					{ num1=117;i=i+1;}
					else if(c[i]=='<'&&c[i+1]=='=')
					{ num1=107;i=i+1; }
					else if(c[i]=='>'&&c[i+1]=='>')
					{ num1=135;i=i+1;}
					else if(c[i]=='<'&&c[i+1]=='<')
					{ num1=125; i=i+1;}
					else if((c[i]>57||c[i]<48)&&(c[i+1]>57||c[i+1]<48)&&(c[i+1]!='-'||c[i+1]=='#'))
					{
						printf("Error");
						flag=1;
						break;
					}i++;}
				}
			}
			if(num1>0)
			{
				if(top1==0)
				{
					symbol[top1++]=num1;
					number[top2++]=a*minus;
				}												// both the arrays are empty initially
			        else if(num1>symbol[top1-1])
			        {
			        	symbol[top1++]=num1;
			        	number[top2++]=a;
			        }												//checking for mprecedence and accordingly adding the value to the arrays
			        else if(symbol[top1-1]>num1&&(symbol[top1-1]%10!=num1%10))
			        {
					number[top2++]=a;			        	
					while(symbol[top1-1]>num1&&(symbol[top1-1]%10!=num1%10)&&top1>0)
			        	{
			        		number[top2-2]=calculate(number[top2-2],number[top2-1],symbol[top1-1]);
			        		top2--;top1--;
			        	}
			        	symbol[top1++]=num1;
			        }
			         else if(symbol[top1-1]>=num1&&(symbol[top1-1]%10==num1%10))
			        {
			        	number[top2++]=a;
			        		number[top2-2]=calculate(number[top2-2],number[top2-1],symbol[top1-1]);
			        		top2--;top1--;
			        	symbol[top1++]=num1;
			        }
			}													//solving on the basis of the order of precedence of the given operators
			if(num1==-1)
			{
				top1--;top2--;
				while(top2-1>=0)
				{
					
					number[top2-1]=calculate(number[top2-1],number[top2],symbol[top1]);
					top1--;
					top2--;
				}
			}
			
		}if(flag!=1)printf("%d\n",number[top2]);									//printing the resultant value
		else if(flag!=1)
		printf("%d\n",number[top2+1]);
	}}
}
int oop(char c)
{
	if(c=='|') return 1;
	if(c=='^') return 2;
	if(c=='&') return 3;
	if(c=='!') return 44;
	if(c=='=') return 54;	
	if(c=='<') return 87;
	if(c=='>') return 97;	
	if(c=='+') return 220;
	if(c=='-') return 210;
	if(c=='*') return 306;
	if(c=='/') return 316;
	if(c=='%') return 326;
	if(c=='#') return -1;
}												//making a function which assigns value to every operator according to their order of precedence
int calculate(int a,int b,int c)
{
	
	if(c==1)
	return(a|b);
	if(c==2)
	return(a^b);
	if(c==3)
	return(a&b);
	if(c==44)
	return(a!=b);
	if(c==74)
	return(a==b);
	if(c==87)
	return(a<b);
	if(c==97)
	return(a>b);
	if(c==107)
	return(a<=b);
	if(c==117)
	return(a>=b);
	if(c==220)
	return(a+b);
	if(c==210)
	return(a-b);
	if(c==306)
	return(a*b);
	if(c==316)
	return(a/b);
	if(c==326)
	return(a%b);
	if(c==135)
	return(a>>b);
	if(c==125)
	return(a<<b);
	
}												//solving the expression here as passed

		
			        	
			        	
			        	
		


