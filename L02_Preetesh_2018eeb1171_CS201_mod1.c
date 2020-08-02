/*ENTRY NUMBER -2018EEB1171
NAME-PREETESH VERMA
COURSE-CS201*/
// I ASSURE YOU I HAVE NOT COPIED THE CODE FROM ANY OF MY FRIENDS OR from internet
// Sir my code does not run properly if u add a white space at the end of the queries i.e. like T 1 2 2 3 4 ' ' /n so it might run since i have integers as input 

#include<stdio.h>
#include<stdlib.h>
struct node {
struct node *left;
struct node *right;
int val;
int key;
};
int a=0;int stack[500];int t=0;
struct node* insert(struct node* ,int );    
struct node* new_node(struct node* ,int );
struct node* delete(struct node* ,int );
struct node* removes_avl(struct node* );
void inorder(struct node* );
void postorder(struct node* ); 
int search(struct node* ,int );
int leaf_nodes(struct node* );
int common_ancestor(struct node* ,int ,int );
int getH(struct node*  );
int max(int ,int );
void level_order(struct node* ,int );
struct node* delete_tree(struct node* );
int diameter(struct node* );
int width(struct node* ,int );
int leftsum(struct node* ,int );
int rightsum(struct  node* ,int  );
void route(struct node* ,int ,int ,int ,int ,int[]);
void preorder(struct node* );
int nodes(struct node* ,int );
int leafnodes(struct node* ,int );
struct node* insert_avl(struct node* ,int );
struct node* new_nodes(struct node* ,int );
struct node* delete_avl(struct node* ,int );
struct node* removes(struct node* );
struct node* clockwise(struct node* );
struct node* anticlockwise(struct node* );
int getHs(struct node* );
struct node* balancetree(struct node* ,int );
int getHs(struct node* root)
{
	if(!root) return 0;
	int l1=getHs(root->left);
	int l2=getHs(root->right);
	if(l1>l2)
	return (1+l1);
	else
	return(1+l2);
}
struct node* anticlockwise(struct node* y)
{
	struct node* x;struct node* t2;
	x=y->right;
	t2=x->left;
	y->right=t2;
	x->left=y;
	return x;
}
struct node* clockwise(struct node* y)
{
	struct node* x;struct node* t2;
	x=y->left;
	t2=x->right;
	y->left=t2;
	x->right=y;
	return x;
}
void main()
{
	struct node *root=NULL;
	int qq;int bst=0;
	int avl=0;
	scanf("%d",&qq);
	while(qq>0)
	{
		//printf("%d",qq);
		char cc;
		scanf("\n%c",&cc);
		if(cc=='F')
		{
			int f;scanf("%d",&f);
			if(search(root,f)==0)
				printf("YES");
			else
		       		printf("NOT FOUND");
		       	qq--;
		}
		else if(cc=='N')
		{
			int n=0;
			printf("NUMBER OF NODES %d",nodes(root,n)+1);
			qq--;
		}	
		else if(cc=='Q')
			{printf("NUMBER OF  LEAF NODES %d",leaf_nodes(root));qq--;}
		else if(cc=='P')
			{preorder(root);qq--;}	
		else if(cc=='I')
			{inorder(root);qq--;}
		else if(cc=='S')
			{postorder(root); qq--;}
		else if(cc=='L')
		{
			printf("LEVEL ORDER");
			for(int i=1;i<=getH(root);i++)
				level_order(root,i);
			qq--;
		}
		else if(cc=='D')
		{
			qq--;
			printf("HEIGHT %d",getH(root));
		}	
		else if(cc=='W')
		{
			int max_width=0;
			for(int i=1;i<=getH(root);i++)
				if(max_width<width(root,i))
					max_width=width(root,i);
			printf("WIDTH %d",max_width);	
			qq--;
		}
		else if(cc=='C')
		{
			int pp,ppp;
			scanf("%d %d",&pp,&ppp);
			printf("COMMON ANCESTOR %d",common_ancestor(root,pp,ppp));
			qq--;
		}
		else if(cc=='R')
		{
			int aa,aaa;
			scanf("%d %d",&aa,&aaa); 
			if(search(root,aa)==1&&search(root,aaa)==1)
				printf("Both the source and destination not present\n");
			else if(search(root,aa)==1)
				printf("Source not present\n");
			else if(search(root,aaa)==1)
				printf("Destination Not Present\n");
			else
				route(root,aa,aaa,0,0,stack);
			t=0;	
			qq--;
		}
		else if(cc=='Y')
		{
			a+=leafnodes(root,0);
			a+=leftsum(root->left,0);
			a+=rightsum(root->right,0);
			printf("Boundary sum %d",root->val+a);
			a=0;qq--;
		}
		else if(cc=='X')
		{
			printf("DIAMETER %d",diameter(root)-1);
			qq--;
		}
		else if(cc=='T')
		{
			qq--;
			if(root!=NULL)
				root=delete_tree(root);	
			bst=1;avl=0;
			char c;
			scanf("%c",&c);
			while(c!='\n')
			{
				int e;
				scanf("%d",&e);
				if(e>0)
					root=insert(root,e);
				else if(e<0)
					delete(root,e*-1);
				scanf("%c",&c);
			}
		}
		else if(cc=='H')
		{
			qq--;
			avl=1;bst=0;
			if(root!=NULL)
				root=delete_tree(root);	
			char c;
			scanf("%c",&c);
			while(c!='\n')
			{
				int e;
				scanf("%d",&e);
				if(e>0)
					root=insert_avl(root,e);
				else if(e<0)
					delete_avl(root,e*-1);
				scanf("%c",&c);
			}
		}
		else if(cc=='A')
		{
			qq--;
			int e;
			if(avl==0)
			{	bst=1;
				char c;
				scanf("%c",&c);
				while(c!='\n')
				{
					scanf("%d",&e);
					if(e>0)
						root=insert(root,e);
					scanf("%c",&c);
				}
			}
			else
			{
				int e;
				char c;
				scanf("%c",&c);
				while(c!='\n')
				{
					scanf("%d",&e);
					
					if(e>0)
						root=insert_avl(root,e);
					scanf("%c",&c);
				}
			}	
				
		}
		else if(cc=='U'&&root!=NULL)
		{
			qq--;
			int e;
			if(avl==0)
			{	
				char c;int e;
				scanf("%c",&c);
				while(c!='\n')
				{
					scanf("%d",&e);
					root=delete(root,e);
					scanf("%c",&c);
				}
			}
			else
			{
				char c;
				scanf("%c",&c);
				while(c!='\n')
				{
					scanf("%d",&e);
					delete_avl(root,e);
					scanf("%c",&c);
				}
			}
		}
		else printf("WRONG QUERY");		
	}
}
struct node* insert(struct node *r,int a)									//for insertion in bst
{
	
	if(r==NULL)
	{	
		r=new_node(r,a);
		return r;
	}
	else if(a< r->val)
	{
		
		r->left=insert(r->left,a);
	}
	else
	{
		
		r->right=insert(r->right,a);
	}return r;
}
struct node* new_node(struct node *rr,int a) 									//for adding new node
{
	rr=(struct node*)malloc(sizeof(struct node));
	rr->val=a;
	rr->left=NULL;
	rr->right=NULL;
	return rr;
}
struct node* delete(struct node *roots,int b)									//for deletion in BST
{
	if(roots==NULL)
		return NULL;
	else if(roots->val<b)
		roots->right=delete(roots->right,b);
	else if(roots->val>b)
		roots->left=delete(roots->left,b);
	else if(roots->val==b)
	roots=removes(roots);
	return roots;
}
struct node* removes(struct node *roott)									//deletion in BST
{

	if(roott->left==NULL&&roott->right==NULL)
	{
		roott=NULL;
		
		return roott;
	}
	else if(roott->left==NULL)
	{
		struct node *tt;
		tt=roott->right;
		roott->val=tt->val;
		roott->right=tt->right;
		roott->left=tt->left;
		free(tt);
		tt=NULL;
	}
	else if(roott->right==NULL)
	{
		struct node *tt;
		tt=roott->left;
		roott->val=tt->val;
		roott->left=tt->left;
		roott->right=tt->right;
		free(tt);
		tt=NULL;
	}
	else
	{
		struct node *temp;
		struct node *temps;
		temp=roott->left;
		temps=roott;
		if(temp->right!=NULL){
		while(temp->right->right!=NULL)
			temp=temp->right;
		temps=temp;
		temp=temp->right;		
		temps->right=temp->left;
		roott->val=temp->val;
		free(temp);
		temp=NULL;}
		else
		{
		roott->val=temp->val;
		roott->left=temp->left;
		free(temp);
		temp=NULL;
		}
		
	}
	return roott;
}
void inorder(struct node *head)											//Inorder traversal
{
	if(head)
	{
		inorder(head->left);
		printf("%d ",head->val);
		inorder(head->right);
	}
}
int search(struct node *root,int n)										//Searching 
{
	if(root==NULL)
		{
		return 1;}
	else
	{
		if(root->val==n)
			return 0;
		else if(root->val<n)
			search(root->right,n);
		else
			search(root->left,n);
	}
}
int leaf_nodes(struct node* root)										//Number of leafnodes
{
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	else
		return(leaf_nodes(root->left)+leaf_nodes(root->right));
}
int common_ancestor(struct node* root,int i,int j)								//Commom ancestor
{
	if(root==NULL||search(root,i)||search(root,j))
		return -1;
	if(i==j)
		return i;
	if((root->val>i&&root->val<j)||(root->val<i&&root->val>j))
		return (root->val);
	else if(root->val>i&&root->val>j)
		return common_ancestor(root->left,i,j);
	else 
		return common_ancestor(root->right,i,j);
}
int getH(struct node *root)											//computing height
{
	if(root==NULL)
		return 0;
	else
		return(1+max(getH(root->left),getH(root->right)));
}
int max(int a, int b)												
{
	return (a>b?a:b);
}
void level_order(struct node* root,int level)									//Level order traversal
{
	if(root==NULL)
		return;
	if(level==1)
		printf(" %d",root->val);
	level_order(root->left,level-1);
	level_order(root->right,level-1);
}
struct node* delete_tree(struct node *root)									//Deleting the full tree
{
	if(root==NULL)
		return root;
	if(root->left==NULL&&root->right==NULL)
	{
		free(root);
		root=NULL;
		return root;
	}
	
		root->left=delete_tree(root->left);
		root->right=delete_tree(root->right);
		root=delete_tree(root);
	return root;
}
int diameter(struct node* root)											//computing diameter
{
	if(root==NULL)
		return 0;
	return(max(diameter(root->left),max(diameter(root->right),1+getH(root->left)+getH(root->right))));
}		
int width(struct node* root,int level)										//perimeter
{
	if(root==NULL)
		return 0;
	else if(level==1)
		return 1;
	else
	return(width(root->left,level-1)+width(root->right,level-1));
}
int leftsum(struct node* root,int b)
{
	if(root==NULL)
	return b;
	if(root->left!=NULL)
	{
		b=leftsum(root->left,0);
		if(root->right!=NULL)
		{
			b=leftsum(root->left,0);
		}
		b=root->val+b;
	}
	if(root->right!=NULL)
	{
		b=leftsum(root->right,0);
		if(root->left!=NULL)
		{
			b=leftsum(root->left,0);
		}
		b=b+root->val;
	}	
return b;
}
int rightsum(struct node* root,int b)
{	
	if(root==NULL)
	return b;
	if(root->right!=NULL)
	{
		b=rightsum(root->right,0);
		if(root->left!=NULL)
		{
			b=rightsum(root->left,0);
		}
		b=root->val+b;
	}
	if(root->left!=NULL)
	{
		b=rightsum(root->left,0);
		if(root->right!=NULL)
		{
			b=rightsum(root->right,0);
		}
		b=b+root->val;
	}
return b;
}
void route(struct node* root,int i,int j,int flag1,int flag2,int stack[])					//Path and existence of route
{	
	/*if(root==NULL&&(flag1==0&&flag2==1))
	{
		printf("Unreachable");
		return;
	}*/
	if(root==NULL&&(flag1==1&&flag2==0))
	{
		printf("Unreachable");
		return;
	}
	else if(root==NULL&&flag1==0)
	{
		printf("Unreachable");
		return;
	}
	else if(root->val==i&&i==j)
	{
		printf("%d reached %d",i,i);
		return;
	}
	/*else if((root->val<i&&root->val>j)||(root->val>i&&root->val<j))
	{
		printf("Unreachable");
		return;
	}*/
	else if(root->val==i&&flag1==0&&flag2==0)
	{
		flag1=1;
		if(j>i)
			{stack[t++]=1;
			return route((root->right),i,j,1,0,stack);}
		if(j<i)
			{stack[t++]=2;
			return route((root->left),i,j,1,0,stack);}
	}
	else if(root->val!=j&&flag1==1&&flag2==0)
	{
		
		if(root->val>j){
		stack[t++]=2;
		return route((root->left),i,j,1,0,stack);}
		else if(root->val<j){stack[t++]=1;
		return route((root->right),i,j,1,0,stack);}
	}
	else if(root->val==j&&flag1==1)
	{
		printf("%d Reached %d\n",i,j);
		for(int i=0;i<t;i++)
		{
			if(stack[i]==1)
			printf("right");
			if(stack[i]==2)
			printf("left");
			
		}
	}
	else if(flag1==0&&flag2==0)
	{
		if(i<root->val)
			route((root->left),i,j,0,0,stack);
		else
			route((root->right),i,j,0,0,stack);
	}
}
void postorder(struct node* root)									//postorder 
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}
}
void preorder(struct node* root)									//preorder iterative code
{
	int i=0;
	if(root==NULL)
		return;
	struct node* st[500];
	st[0]=root;
	struct node* temp=st[i];
	while(i>=0)
	{
		if(st[i]!=NULL)
		{printf("%d ",st[i]->val);
		temp=st[i];}
		if(temp->right)
		{
			st[i]=temp->right;
			i++;
		}
		if(temp->left)
		{
			st[i]=temp->left;
			i++;
		}
		i--;
	}
}			
int leafnodes(struct node* root,int b)
{
	
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL&&root->right==NULL)
	{
			return b+root->val ;
	}
	if(root->left)
		b=leafnodes(root->left,b);
	if(root->right)
		b=leafnodes(root->right,b);
	return b;
}
struct node* insert_avl(struct node *r,int a)										//AVL 
{
	
	if(r==NULL)
	{	
		r=new_nodes(r,a);
		return r;
	}
	else if(a< r->val)
	{	
		r->left=insert_avl(r->left,a);
		//r=r->left;
	}
	else
	{
		r->right=insert_avl(r->right,a);
		//r=r->right;
	}
	int balance=getHs(r->left)-getHs(r->right);
	r->key=balance;
	if(balance>1&&getHs((r->left)->left)>getHs((r->left)->right))
	{
		r=clockwise(r);r->key=0;
	}
	else if(balance>1&&getHs((r->left)->right)>getHs((r->left)->left))
	{
		r->left=anticlockwise(r->left);
		r=clockwise(r);
		r->key=0;
	}
	else if(balance<-1&&getHs((r->right)->left)<getHs((r->right)->right))
	{
		r=anticlockwise(r);r->key=0;
	}
	else if(balance<-1&&getHs((r->right)->right)<getHs((r->right)->left))
	{
		r->right=clockwise(r->right);
		r=anticlockwise(r);
		r->key=0;
	}
	return r;
}
struct node* new_nodes(struct node *rr,int a)
{
	rr=(struct node*)malloc(sizeof(struct node));
	rr->val=a;
	rr->left=NULL;
	rr->right=NULL;
	return rr;
}
struct node* delete_avl(struct node *roots,int b)
{
	if(roots==NULL)
		return NULL;
	else if(roots->val<b)
	{
		roots->right=delete_avl(roots->right,b);
		int balance=getHs(roots->left)-getHs(roots->right);
		roots->key=balance;
		if(balance>1||balance<-1)
			roots=balancetree(roots,balance);
	}
	else if(roots->val>b)
	{
		roots->left=delete_avl(roots->left,b);
		int balance=getHs(roots->left)-getHs(roots->right);
		roots->key=balance;
		if(balance>1||balance<-1)
			roots=balancetree(roots,balance);
	}		
	else
	roots=removes_avl(roots);
	return roots;
}
struct node* removes_avl(struct node *roott)
{

	if(roott->left==NULL&&roott->right==NULL)
	{
		free(roott);
		roott=NULL;
		return roott;
	}
	else if(roott->left==NULL)
	{
		struct node *tt;
		tt=roott->right;
		roott->val=tt->val;
		roott->right=tt->right;
		roott->left=tt->left;
		free(tt);
		tt=NULL;
	}
	else if(roott->right==NULL)
	{
		struct node *tt;
		tt=roott->left;
		roott->val=tt->val;
		roott->left=tt->left;
		roott->right=tt->right;
		free(tt);
		tt=NULL;
	}
	else
	{
		struct node *temp;
		temp=roott->left;
		if((temp->right)!=NULL){
			while((temp->right)->right!=NULL)
				temp=temp->right;
			struct node* temp2;struct node* temp3;
			temp2=(temp->right)->left;
			temp3=temp->right;
			if(temp3!=NULL)
			roott->val=(temp3)->val;
			else
			roott->val=temp->val;
			temp->right=temp2;}
		else
			{roott->val=temp->val;temp=removes_avl(temp);roott->left=temp;}
		
		/*else
		roott->val=temp->val;
		roott->left=temp->left;
		free(temp);
		temp=NULL;*/
	}
	int balance=getHs(roott->left)-getHs(roott->right);
	roott->key=balance;
	if(balance>1||balance<-1)
		roott=balancetree(roott,balance);
	return roott;
}
struct node* balancetree(struct node* r,int balance)
{
	if(balance>1&&getHs((r->left)->left)>getHs((r->left)->right))
	{
		r=clockwise(r);r->key=0;
	}
	else if(balance>1&&getHs((r->left)->right)>getHs((r->left)->left))
	{
		r->left=anticlockwise(r->left);
		r=clockwise(r);
		r->key=0;
	}
	else if(balance<-1&&getHs((r->right)->left)<getHs((r->right)->right))
	{
		r=anticlockwise(r);r->key=0;
	}
	else if(balance<-1&&getHs((r->right)->right)<getHs((r->right)->left))
	{
		r->right=clockwise(r->right);
		r=anticlockwise(r);
		r->key=0;
	}
	else if(balance>1&&getHs((r->left))>getHs((r->right)))
	{
		r=clockwise(r);r->key=0;
	}
	else if(balance<-1&&getHs((r)->left)<getHs((r->right)))
	{
		r=anticlockwise(r);r->key=0;
	}
	return r;
}
int nodes(struct node* root,int n)											//NUMBER of NODES
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
		n= (1+nodes(root->left,n));
	if(root->right!=NULL)
		n= (1+nodes(root->right,n));
	return n;
}

