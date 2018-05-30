#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int data;
	struct node *left,*right,*parent;
};
struct node *lastnode=NULL;
struct node *root;
struct node *tree;
struct node *heapify(struct node *tree);
struct node *insert(struct node *,struct node *,int,int[],int);
struct node *preorder(struct node *tree);
struct node *heaporder(struct node *tree);
struct node *extract_min(struct node *,struct node *);
int main()
{
	int n,val,i,j=0,count,binaryNum[10],pos;
	root = (struct node *)malloc(sizeof(struct node));
	printf("Enter the number of elements you want");
	scanf("%d ",&n);
	scanf("%d ",&val);
    root->data=val;
    root->left=NULL;
    root->right=NULL;
    root->parent=NULL;
    tree=root;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&val);
		pos=i;
		count=0;
		 while(pos>0)
    {
        binaryNum[count] = pos % 2;
        pos = pos / 2; 
        ++count;
    }
    count=count-2;
	insert(tree,root,val,binaryNum,count);
	}
	printf("The ordered tree is..\n");
	preorder(root);

	extract_min(tree,lastnode);
	printf("\n The tree after extracting min is..\n");
	preorder(tree);
	
}
struct node *heaporder(struct node *tree)
{ 
int temp;
	if(tree->parent!=NULL)
	{
	if(tree->data < tree->parent->data)
	{
	temp=tree->data;
	tree->data=tree->parent->data;
	tree->parent->data=temp;
	heaporder(tree->parent);
	lastnode=tree;
    }
    else
    return tree;
    }
	
}
struct node *insert(struct node *tree,struct node *parent,int val,int arr[],int count)
{
	
	if(tree==NULL)
	{
	  tree = (struct node *)malloc(sizeof(struct node));
	  tree->data=val;
	  tree->left=NULL;
	  tree->right=NULL;
	  tree->parent=parent;
	  heaporder(tree);
	}
	else 
	{
		if(count>=0)
		{
			if(arr[count]==0)
		    {
				count--;
			
			tree->left=insert(tree->left,tree,val,arr,count);
			
		    }
		else 
		{
		 count--;
  		tree->right=insert(tree->right,tree,val,arr,count);
       	}
        }
    }
	return tree;
}
struct node *preorder(struct node *tree)
{
    if (tree != NULL)
    {
    	printf(" %d", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
    
    return tree;
}
struct node *heapify(struct node *tree)
{
	int temp;
	int smallest=tree->data;
	struct node *small=NULL;
	if(tree->left==NULL || tree->right== NULL)
	return tree;
	else
	{
	if(smallest<tree->left->data&& smallest<tree->right->data)
	return tree;
    else if(tree->left->data<tree->right->data)
    {
    	temp=tree->data;
    	tree->data=tree->left->data;
    	tree->left->data=temp;
    	small=tree->left;
    }
    else
    {
    	temp=tree->data;
    	tree->data=tree->right->data;
    	tree->right->data=temp;
    	small=tree->right;
    }
    heapify(small);
    }
    
}

struct node *extract_min(struct node *tree,struct node *lastnode)
{
	if(tree->parent==NULL)
	{
		tree->data=lastnode->data;
		if(lastnode->parent->right==NULL)
		{
		lastnode->parent->left=NULL;
		lastnode=lastnode->parent;
	    }
	    else
	    {
	    lastnode->parent->right=NULL;
	    lastnode=lastnode->parent->left;
     	}
     	heapify(tree);
    }
  return tree;      
    
}
