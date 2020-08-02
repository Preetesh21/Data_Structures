//STACK PERMUTATION
//Name-Preetesh Verma
//Entry Number-2018eeb1171
//Sir thecomplexity of my code is of the order of factorial
//I had checked till 11 the answers came quickly for n=12 it took 40 sec and for 13 over 5 minutes.I had tried to reduce the complexity but could not and have also taken the limit of input to be 16 as it was told in the class by sir.
#include<stdio.h>
int p=0;
int c[16];//limit taken
void work(int a[],int n,int t)
{												//function to check the vlidity of a permutation
int Push[n+1];
int Pop[n+1];
for(int i=0;i<n+1;i++)
{
Push[i]=0;
Pop[i]=0;
}
int flag=0;
Pop[a[0]]=1;
for(int i=1;i<n;i++)
{
	if(Pop[a[i]]==0)
	{
		if(Push[a[i]]==0)
		{
			for(int j=0;j<=a[i];j++)
			Push[j]=1;
		}
		if(i>0)
		{
			if(a[i]<a[i-1])
			{
				for(int k=a[i-1];k>=a[i];k--)
				Pop[k]=1;
			}
			else
			Pop[a[i]]=1;
		}
	}
	else if(Pop[a[i]]==1)
	{
		flag=1;
		break;
	}
}
if(flag==0)
{
	p++;
	if(p==t){
	for(int f=0;f<n;f++)
	{c[f]=a[f];
	}
}
}
}
void permutation(int a[],int size,int n,int k)									//generating the permutation
{
int t;
if(size==n)
{	work(a,n+1,k);
	return;
}
for(int i=size;i<=n;i++)
{
		t=a[i];
		a[i]=a[size];
		a[size]=t;
	permutation(a,size+1,n,k);
		t=a[i];
		a[i]=a[size];
		a[size]=t;
}
}
void main()
{
int t;int fact=1;
scanf("%d",&t);
while(t-->0)
{
	int n,k;
	fact=1;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		fact=fact*i;
	if(fact>=k)
	{
		int a[n];
		for(int i=0;i<n;i++)
			a[i]=i+1;
		p=0;
		permutation(a,0,n-1,k);
		if(p>=k){
		printf("%d ",p);
		for(int f=0;f<n;f++)
 		printf("%d ",c[f]);
		printf("\n");		}
		else 
		printf("Error\n");
	}
	else 
		printf("Error\n");
}
}	
