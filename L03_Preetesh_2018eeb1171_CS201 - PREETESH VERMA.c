/*
Name: Preetesh Verma
Entry Number:2018eeb1171
I have not copied this code from internet or any of my friends.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    char color;
    int eweight;
    int distance;
    struct node *parent;
    struct node *next;
};													//Struct node for storing the vertices of graphs
int tree=0;
int back=0;
int cross=0;
int forward=0;
int time=0;												
int top=0;
void bfs_undirected(struct node* array[] ,int n,int s);    
void bfs_directed(struct node *array[],int n,int s);
int dfs_undirected(struct node* array[],int s);
int dfs_directed(struct node* array[],int s);
int topological_sort(struct node* array[],int s,int stack[]);
void djikstra(struct node* array[],int s,int n);
void bellman_ford(struct node* array[],int s,int n);

int main()												//main function 
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
        int q,edge=0;int negative=0;
        tree=0;
        back=0;
        cross=0;
        forward=0;
        time=0;
        top=0;
        scanf("%d",&q);
        int n,d,s;
        if(q!=3){
        scanf("%d %d %d",&n,&d,&s);}
        else
        scanf("%d",&n);
        struct node *array[n];
        int arr[n][n];
        struct node *temp;
        for(int i=0;i<n;i++)
        {
                array[i]=(struct node*)malloc(sizeof(struct node));
            array[i]->next=NULL;
            array[i]->parent=NULL;
            array[i]->data=i+1;
            array[i]->color='W';
            array[i]->eweight=0;
            array[i]->distance=0;
            if(q==4||q==5)
                array[i]->distance=9999999;
        }												//Creating Adjajency Lists
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a;
                scanf("%d",&a);
                if(a<0)
                negative=1;
                arr[i][j]=a;
                if(q==1||q==2||q==3){
                if(a!=0)
                {
                    edge++;
                    temp=array[i];
                    while(temp->next!=NULL)
                        temp=temp->next;
                    struct node* new_node=(struct node*)malloc(sizeof(struct node));
                    temp->next=new_node;
                    new_node->data=j+1;
                    new_node->color='W';
                    new_node->next=NULL;
                    new_node->eweight=a;
                    new_node->distance=0;
                    if(q==4||q==5)
                        new_node->distance=9999999;
                }}else{
                if(a!=999999&&a!=0)
                {
                    edge++;
                    temp=array[i];
                    while(temp->next!=NULL)
                        temp=temp->next;
                    struct node* new_node=(struct node*)malloc(sizeof(struct node));
                    temp->next=new_node;
                    new_node->data=j+1;
                    new_node->color='W';
                    new_node->next=NULL;
                    new_node->eweight=a;
                    new_node->distance=0;
                    if(q==4||q==5)
                        new_node->distance=9999999;
                }}
            }
        }													//Assigning the adjagency lists the values according to the queries because 999999 is edgeweight for query 1 2 3 and no edge for 4 and 5.
        if(q==1&&d==0)
        bfs_undirected(array,n,s);
        if(q==1&&d==1)
        bfs_directed(array,n,s);
        if(q==2&&d==0)
        {
            dfs_undirected(array,s);
            for(int i=0;i<n;i++)
                if(array[i]->color=='W')
                    dfs_undirected(array,i+1);
        printf("%d %d %d\n",array[s-1]->distance,tree,back);
        }
        if(q==2&&d==1)
        {
	
            dfs_directed(array,s);
            for(int i=0;i<n;i++)
                if(array[i]->color=='W')
                    dfs_directed(array,i+1);
        printf("%d %d %d %d %d\n",array[s-1]->distance,tree,back,forward,edge-tree-back-forward);
        }
        if(q==3)
        {
            int flag=0,flag1=0;int i;
            for( i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(arr[j][i]!=0)
                    flag1=1;
                }
                if(flag1==0)
                { 
                    flag=1;
                    break;
                }
                else flag1=0;
            }
            if(flag==0)
            printf("-1\n");
            else
            {
                int stack[n];
                topological_sort(array,i+1,stack);
                if(back==0)
                {
                    while(top>0)
                    printf("%d ",stack[--top]);
                    printf("\n");
                }
                else printf("-1\n");
            }
        }
        if(q==4&&negative==0)
            djikstra(array,s,n);
        if(q==4&&negative==1)
            printf("-1\n");
        if(q==5)
            bellman_ford(array,s,n);
        
                    
        
    }
    return 0;
}

void bfs_undirected(struct node *array[],int n,int s)								//bfs_undirected 
{
    int dist[n+1];
    for(int i=0;i<n+1;i++)
        dist[i]=0;
    array[s-1]->color='G';
    int queue[n];
    int front=-1;
    int rear=-1;
    int size=0;
    queue[++front]=s;
    rear=1;
    size++;
    struct node* u;
    struct node* temp;
    while(front!=rear)
    {
        u=array[queue[front]-1];
        temp=u->next;
        while(temp!=NULL)
        {
            if(temp->color=='W'&&array[temp->data-1]->color=='W')
            {
                temp->color='G';

                array[temp->data-1]->color='G';
                tree++;
                temp->distance=u->distance+1;
                array[temp->data-1]->distance=temp->distance;
                queue[rear]=temp->data;
                rear=(rear+1)%n;
                size++;
                temp=temp->next;
                

            }
            else if(temp->color=='W'&&array[temp->data-1]->color=='G')
            {    cross++;
                temp=temp->next;
            }
            else temp=temp->next;
            
        }
        u->color='B';
        dist[u->distance]++;
        front=(front+1)%n;
        size--;
    }
    for(int i=1;i<n+1;i++)
    {
        if(dist[i]<=0)
            break;
        else
            printf("%d ",dist[i]);
    }
    printf("0 %d %d\n",tree,cross);
    tree=0;
    cross=0;
}        

void bfs_directed(struct node *array[],int n,int s)								//bfs_directed
{
    int dist[n+1];
    for(int i=0;i<n+1;i++)
        dist[i]=0;
    array[s-1]->color='G';
    int queue[n];
    int front=-1;
    int rear=-1;
    int size=0;
    queue[++front]=s;
    rear=1;
    size++;
    struct node* u;
    struct node* temp;
    while(front!=rear)
    {
        u=array[queue[front]-1];
        temp=u->next;
        while(temp!=NULL)
        {
            if(temp->color=='W'&&array[temp->data-1]->color=='W')
            {
                temp->color='G';

                array[temp->data-1]->color='G';
                array[temp->data-1]->parent=u;
                tree++;
                temp->distance=u->distance+1;
                array[temp->data-1]->distance=temp->distance;
                queue[rear]=temp->data;
                rear=(rear+1)%n;
                size++;
                temp=temp->next;
                

            }
            else if(temp->color=='W'&&array[temp->data-1]->color=='G')
            {    cross++; 
                temp=temp->next;
            }
            else if(temp->color=='W'&&array[temp->data-1]->color=='B')
            {    
                struct node* t=u->parent;
                int flag=0;
                while(t!=array[s-1]){
                if(t==array[temp->data-1])
                {   back++; flag=1;break;}
                t=t->parent;}
                if(t==array[temp->data-1])
                {   back++; flag=1;}
         
                if(flag==0) cross++; 
                temp=temp->next;
            }
            else temp=temp->next;
            
        }
        u->color='B';
        dist[u->distance]++;
        front=(front+1)%n;
        size--;
    }
    for(int i=1;i<n+1;i++)
    {
        if(dist[i]<=0)
            break;
        else
            printf("%d ",dist[i]);
    }
    printf("0 %d %d 0 %d\n",tree,back,cross);
    tree=0;
    cross=0;
    back=0;
}    

int dfs_undirected(struct node* array[],int s)										//dfs_undirected
{
    time=time+1;
    array[s-1]->color='G';
    struct node* u=array[s-1];
    struct node* temp=u->next;
    while(temp!=NULL)
    {
        if(temp->color=='W'&&array[temp->data-1]->color=='W')
        {
            tree++;
            array[temp->data-1]->parent=u;
            array[temp->data-1]->color='G';
            int a=dfs_undirected(array,temp->data);
        }
        else if(temp->color=='W'&&array[temp->data-1]->color=='G'&&array[u->data-1]->parent!=array[temp->data-1])
            back++;
        temp=temp->next;
    }
    array[u->data-1]->color='B';
    array[u->data-1]->distance=time+1;
    time=time+1;
    return 0;
}
    
int dfs_directed(struct node* array[],int s)									//dfs_directed
{
    time=time+1;
    array[s-1]->color='G';
    struct node* u=array[s-1];
    struct node* temp=u->next;
    while(temp!=NULL)
    {
        if(temp->color=='W'&&array[temp->data-1]->color=='W')
        {
            tree++;
            array[temp->data-1]->parent=u;
            array[temp->data-1]->color='G';
            int a=dfs_directed(array,temp->data);
        }
        else if(temp->color=='W'&&array[temp->data-1]->color=='G')
           { back++;}
        else if(temp->color=='W'&&array[temp->data-1]->color=='B')
        {  
            struct node* t=array[temp->data-1]->parent;
            int flag=0;
            while(t!=array[s-1]&&t!=NULL)
            {
                
                if(t==array[u->data-1])
                {   forward++; flag=1;
                    break;
                }
                 t=t->parent;
            }                
            if(t==array[u->data-1])
                    {   forward++; flag=1;}

        }
        temp=temp->next;
    }
    array[u->data-1]->color='B';
    array[u->data-1]->distance=time+1;
    time=time+1;
    return 0;
}    
    
    
int topological_sort(struct node* array[],int s,int stack[])								//topological_sort
{
    time=time+1;
    array[s-1]->color='G';
    struct node* u=array[s-1];
    struct node* temp=u->next;
    while(temp!=NULL)
    {
        if(temp->color=='W'&&array[temp->data-1]->color=='W')
        {
            tree++;
            array[temp->data-1]->parent=u;
            array[temp->data-1]->color='G';
            int a=topological_sort(array,temp->data,stack);
        }
        else if(temp->color=='W'&&array[temp->data-1]->color=='G')
            back++;
        else if(temp->color=='W'&&array[temp->data-1]->color=='B')
            forward++;
        temp=temp->next;
    }
    array[u->data-1]->color='B';
    array[u->data-1]->distance=time+1;
    time=time+1;
    stack[top++]=u->data;
    return 0;
}

void djikstra(struct node* array[],int s,int n)										//djikstra's algorithm
{
    int selected_vertices[n+1];
    int min_path[n];
    for(int i=0;i<n+1;i++)
    {    selected_vertices[i]=0;    
        min_path[i]=999999;
    }
    min_path[s-1]=0;
    array[s-1]->color='B';
    selected_vertices[s]=1;
    struct node* u=array[s-1];
    array[u->data-1]->distance=0;
    struct node* temp=u->next;
    if(temp==NULL)
    {
	for(int i=0;i<n+1;i++)   
        	min_path[i]=999999;
        min_path[s-1]=0;
        for(int i=0;i<n;i++)
       		printf("%d ",min_path[i]);
    	printf("\n");
    	return;
    }	
	
    int queue[n];
    int front=0;
    int flag=0;int index=0;
    int rear=0;
    queue[rear++]=s;
    while(front!=rear)
    {
        front=(front+1)%n;
        while(temp!=NULL)
        {
            if(temp->color=='W'&&array[temp->data-1]->color=='W')
            {
                temp->color='G';

                array[temp->data-1]->color='G';
                if(array[temp->data-1]->distance>temp->eweight+array[u->data-1]->distance)
                {
                    array[temp->data-1]->distance=temp->eweight+array[u->data-1]->distance;
                    array[temp->data-1]->color='G';

                }
                queue[rear]=temp->data;
                rear=(rear+1)%n;
                temp=temp->next;
                
            }
            else if(temp->color=='W'&&array[temp->data-1]->color=='G')
            {
                if(array[temp->data-1]->distance>temp->eweight+array[u->data-1]->distance)
                {
                    array[temp->data-1]->distance=temp->eweight+array[u->data-1]->distance;
                    array[temp->data-1]->color='G';
                }
                temp=temp->next;
            }
            else temp=temp->next;
        }
        int i;int min=999999;int visited=0;
        for(i=front;i!=rear;i=(i+1)%n)
        {    visited=1;
            if(min>array[queue[i]-1]->distance)
            {    min=array[queue[i]-1]->distance;
                flag=queue[i];
                index=i;
            }
        }
        u=array[flag-1];
        temp=u->next;
        int lalu;
        lalu=queue[index];
        queue[index]=queue[front];
        queue[front]=lalu;
        min_path[u->data-1]=u->distance;
        array[u->data-1]->color='B';
    }
    for(int i=0;i<n;i++)
        printf("%d ",min_path[i]);
    printf("\n");
}        

void bellman_ford(struct node* array[],int s,int n)									//bellman_ford's algorithm
{
    int min_path[n+1];
    for(int i=0;i<n+1;i++)
        min_path[i]=999999;
    min_path[s]=0;
    int modified=0, internal_modified=0;
    int relax=0,internal_relax=0;
    struct node* temp;
    int negative_wt_cycle=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp=array[j]->next;
            while(temp!=NULL)
            {
                internal_relax++;
                if(min_path[temp->data]>min_path[array[j]->data]+temp->eweight)
                {
                    internal_modified++;
                    modified++;
                    min_path[temp->data]=min_path[array[j]->data]+temp->eweight;
                }
                temp=temp->next;
            }
        }
        if(internal_modified>0)
            relax+=internal_relax;
        else if(internal_modified==0)
            i=i+n;
        internal_modified=0;
        internal_relax=0;
    }
    for(int j=0;j<n;j++)
    {
        temp=array[j]->next;
        while(temp!=NULL)
        {
            if(min_path[temp->data]>min_path[array[j]->data]+temp->eweight)
            {
                negative_wt_cycle=1;
                break;
            }
            temp=temp->next;
        }
    }            
    if(negative_wt_cycle==1)
        printf("-1");
    else
    {
        for(int i=1;i<n+1;i++)
            printf("%d ",min_path[i]);
            
        printf("%d %d\n",relax,modified);
    }    
}
