#include<conio.h>
#include<stdio.h>
#include<iostream.h>
struct node
{
int data;
node *left,*right;
int ht;
};
class avl
{
  node *avlroot;
  node *insert(node*,int);
  node *delete1(node *,int);
  void pre(node *);
  void in(node *);
  int height(node *);
  node *rotright(node *);
  node *rotleft(node *);
  node *rr(node *);
  node *ll(node *);
  node *lr(node *);
  node *rl(node *);
  int bf(node *);
public:
  avl()
  {
   avlroot=NULL;
   }
   void insert(int x)
   {
     avlroot=insert(avlroot,x);
     }
   void delete1(int x)
   {
     avlroot=delete1(avlroot,x);
     }
   void pre()
   {
   pre(avlroot);
   }
   void in()
   {
    in(avlroot);
    }
    void makenull()
    {
    avlroot=NULL;
    }
    };
void main()
{
clrscr();
avl a;
int x,n,i,op;
do
{
 cout<<"1.create\n2.insert\n3.print";
 cout<<"Enter ur ch:";
 cin>>op;
  switch(op)
 {
 case 1:
  cout<<"Enter no of ele:";
  cin>>n;
  cout<<"enter tree data:";
  a.makenull();
  for(i=0;i<n;i++)
  {
  cin>>x;
  a.insert(x);
  }
  break;
  case 2:
  cout<<"enter data";
  cin>>x;
  a.insert(x);
  break;
  case 3:
  cout<<"print==";
  a.pre();
  cout<<"ans==";
  a.in();
  break;
  }
  }while(op!=0);
  }
  node *avl::insert(node *t,int x)
  {
  if(t==NULL)
	{
	  t=new node;
	  t->data=x;
	  t->left=NULL;
	  t->right=NULL;
	}
  else
	{
	  if(x>t->data)
	  {
	  t->right=insert(t->right,x);
  //	  if(bf(t)==-2)
	  if(x>t->right->data)
	  t=rr(t);
	  else
	  t=rl(t);
	  }
  else
  if(x<t->data)
  {
  t->left=insert(t->left,x);
 // if(bf(t)==2)
  if(x<t->left->data)
  t=ll(t);
  else
  t=lr(t);
  }  }
  t->ht=height(t);
  return t;
  }
  int avl::height(node *t)
  {
  int lh,rh;
  if(t==NULL)
  return(0);
  if(t->left==NULL)
  lh=0;
  else
  lh=1+t->left->ht;
  if(t->right==NULL)
  rh=0;
  else
  rh=1+t->right->ht;
  if(lh>rh)
  return(lh);
  return(rh);
  }
  node *avl::rotright(node *x)
  {
  node *y;
  y=x->left;
  x->left=y->right;
  y->right=x;
  x->ht=height(x);
  y->ht=height(y);
  return(y);
  }
  node* avl::rotleft(node *x)
  {
  node *y;
  y=x->right;
  x->right=y->left;
  y->left=x;
  x->ht=height(x);
  y->ht=height(y);
  return(y);
  }
  node *avl::rr(node *t)
  {
  t=rotleft(t);
  return(t);
  }
  node *avl::ll(node *t)
  {
  t=rotright(t);
  return(t);
  }
  node *avl::lr(node *t)
  {
  t->left=rotleft(t->left);
  t=rotright(t);
  return(t);
  }
  node *avl::rl(node *t)
  {
  t->right=rotright(t->right);
  t=rotleft(t);
  return(t);
  }
  int avl::bf(node *t)
  {
  int lh,rh;
  if(t==NULL)
   return(0);
   if(t->left==NULL)
   lh=0;
   else
  lh=1+t->left->ht;
  if(t->right==NULL)
   rh=0;
  else
  rh=1+t->right->ht;
  return(lh-rh);
  }
  void avl::pre(node *t)
  {
  if(t!=NULL)
  {
  cout<<""<<t->data<<"(bf="<<bf(t)<<")";
  pre(t->left);
  pre(t->right);
  }
  }
  void avl::in(node *t)
  {
  if(t!=NULL)
  {
  in(t->left);
  cout<<""<<t->data<<"(bf="<<bf(t)<<")";
  in(t->right);
  }}
