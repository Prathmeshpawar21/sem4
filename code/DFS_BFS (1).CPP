#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define max 20

class graph
{
   private:
   int data;
   graph *next,*down,*start;

   public:
	void create();
	void dfs();
	void bfs();
	void push(int,int []);
	int pop();
	void insert(int,int []);
	int del();
	void display();
};
int stack[max],queue[max],top=-1,front,rear;


void graph::create()
{
   int ch,ch1;
   graph *temp,*node,*temp1,*node1;
   temp=new graph;
   temp1=new graph;
   start=new graph;
   node=new graph;
   cout<<"\nENTER THE PARENT NODE:\t";
   cin>>node->data;
   node->down=NULL;
   node->next=NULL;

   start=node;
   temp=node1=start;

   temp1=node;
   do
   {
      node1=new graph;
      cout<<"ENTER THE ADJACENT NODE FOR "<<node->data<<":";
      cin>>node1->data;
      node1->down=NULL;
      node1->next=NULL;

      temp1->next=node1;
      temp1=node1;
      cout<<"\nDO YOU WANT TO ENTER MORE ADJACENT NODE[1:YES/0:NO]:\t";
      cin>>ch;
   }
   while(ch==1);
   cout<<endl<<"DO YOU WANT TO ENTER MORE PARENT NODE[1:YES/0:NO]:\t";
   cin>>ch1;
   if(ch1==1)
   {
      do
      {
	 node=new graph;
	 cout<<"\nENTER THE PARENT NODE:\t";
	 cin>>node->data;
	 node->down=NULL;
	 node->next=NULL;
	 temp->down=node;
	 temp=node;
	 temp1=node;
	 do
	 {
	   node1=new graph;
	   cout<<"ENTER THE ADJACENT NODE FOR  "<<node->data<<":";
	   cin>>node1->data;
	   node1->down=NULL;
	   node1->next=NULL;

	   temp1->next=node1;
	   temp1=node1;
	   cout<<"\nDO YOU WANT TO ENTER MORE ADJACENT NODE[1:YES/0:NO]:\t";
	   cin>>ch;
	 }
	 while(ch==1);
	 cout<<endl<<"DO YOU WANT TO ENTER MORE PARENT NODE[1:YES/0:NO]:\t";
	 cin>>ch1;
      }
      while(ch1==1);
   }
}

void graph::dfs()
{
   int visit[max];
   graph *temp,*temp1;
   int node,flag,node1;
   temp=new graph;
   temp1=new graph;

   temp1=start;

   for(int i=0;i<max;i++)
   visit[i]=0;

   cout<<"\nENTER THE INITIAL NODE FROM WHERE YOU HAVE TO START:\t";
   cin>>node;

   cout<<"\nTHE DEPTH FIRST SEARCH TRAVERSAL OF THE GRAPH IS:\t";
   cout<<node;

   push(node,visit);

   while(top!=-1)
   {
     flag=0;
     node1=pop();
     temp=start;
     while(temp!=NULL)
     {
       if(temp->data==node1)
       {
	 temp1=temp->next;
	 while(temp1!=NULL)
	 {
	   if(visit[temp1->data]==0)
	   {
	     cout<<"\t"<<temp1->data;
	     push(temp->data,visit);
	     push(temp1->data,visit);
	     flag=1;
	     break;
	   }
	   else
	     temp1=temp1->next;
	 }
       }
       if(flag==1)
	 break;
       else
	 temp=temp->down;
     }
   }
}

void graph::bfs()
{
   int visit1[max];
   graph *temp,*temp1;
   int node,flag,node1;
   temp=new graph;
   temp1=new graph;
   temp1=start;

   for(int i=0;i<max;i++)
   visit1[i]=0;

   cout<<"\nENTER THE INITIAL NODE FROM WHERE YOU HAVE TO START:\t";
   cin>>node;

   cout<<"\nTHE Breadth FIRST SEARCH TRAVERSAL OF THE GRAPH IS:\n";
   cout<<node;

   insert(node,visit1);

   while((rear!=-1) || (front!=rear+1))
   {
     flag=0;
     node1=del();
     temp=start;
     while(temp!=NULL)
     {
       if(temp->data==node1)
       {
	 temp1=temp->next;
	 while(temp1!=NULL)
	 {
	   if(visit1[temp1->data]==0)
	   {
	     cout<<"\t"<<temp1->data;
	     insert(temp->data,visit1);
	     insert(temp1->data,visit1);
	     flag=1;
	   }
	   else
	     temp1=temp1->next;
	 }
       }
       if(flag==1)
	 break;
       else
	 temp=temp->down;
     }
   }
}

void graph::display()
{
  graph *temp,*temp1;
  temp=new graph;
  temp1=new graph;
  temp=start;
  while(temp!=NULL)
  {
    cout<<"\n\t"<<temp->data;
    temp1=temp->next;
    while(temp1!=NULL)
    {
      cout<<"->"<<temp1->data;
      temp1=temp1->next;
    }
    temp=temp->down;
  }
}

void graph::push(int node,int visit[])
{
   top++;
   stack[top]=node;
   if(visit[node]==0)
      visit[node]=1;
}

int graph::pop()
{
   int node;
   node=stack[top];
   top--;
   return(node);
}

void graph::insert(int node,int visit1[])
{
  rear++;
  queue[rear]=node;
  if(visit1[node]==0)
  visit1[node]=1;
}

int graph::del()
{
  int node;
  if(((rear==max-1) && (front==rear)) || (front==rear+1))
  {
    node=queue[front];
    front=0;
    rear=-1;
  }
  else
  {
    node=queue[front];
    front++;
  }
  return(node);
}

void main()
{
  int ch;
  front=0;rear=-1;
  graph g;
  clrscr();
  do
  {
    cout<<"\n ***MENU***";
    cout<<"\n1.CREATE THE GRAPH.";
    cout<<"\n2.TRAVERSAL USING DFS";
    cout<<"\n3.TRAVERSAL USING BFS";
    cout<<"\n4.DISPLAY THE GRAPH";
    cout<<"\n5.EXIT";
    cout<<"\nENTER YOUR CHOICE:\t";
    cin>>ch;
    switch(ch)
    {
      case 1:cout<<"\n * CREATE GRAPH *";
	     g.create();
	     break;

      case 2:cout<<"\n * DFS of GRAPH *";
	     g.dfs();
	     break;

      case 3:cout<<"\n * BFS OF GRAPH *";
	     g.bfs();
	     break;

      case 4:cout<<"\n * DISPLAY GRAPH *";
	     g.display();
	     break;

      case 5:exit(0);
	     break;
    }
    cout<<"\nDO YOU WANT TO CONTINUE ABOVE OPERATION[1:YES/0:NO]:\t";
    cin>>ch;
  }
  while(ch==1);
  getch();
}