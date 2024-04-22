#include <stdio.h>
#include<stdlib.h>
typedef struct tree_node
{
	int data;
	struct tree_node *right;
	struct tree_node *left;
	struct tree_node *parent;
}tree_node;

typedef struct red_black_tree{
	tree_node *root;
	
}red_black_tree;

tree_node* new_tree_node(int data)
{
	tree_node* n=malloc(sizeof(tree_node));
	n->left=NULL;
	n->right=NULL;
	n->parent=NULL;
	n->data=data;

	return n;
}

red_black_tree* new_red_black_tree()
{
	red_black_tree *t=malloc(sizeof(red_black_tree));
	t->root=NULL;
}
void left_rotate(red_black_tree *t,tree_node *x)
{
	printf("%s: Begin \n",__func__);
	tree_node *y=x->right;
	x->right=y->left;
	if(y->left !=NULL)
	{
		(y->left)->parent=x;
	}
	y->parent=x->parent;
	if(x->parent == NULL)
	{
		t->root=y;

	}
	else if (x==x->parent->left)
	{
		x->parent->left=y;
	}
	else
	{
		x->parent->right=y;
	}
	y->left=x;
	x->parent=y;

	 printf("%s: End \n",__func__);



}
void right_rotate(red_black_tree *t,tree_node*x)
{
	printf("%s: Begin \n",__func__);
	tree_node *y=x->left;
	x->left=y->right;
	if(y->right !=NULL)
	{
		y->right->parent=x;
	}
	y->parent=x->parent;
	if(x->parent == NULL)
	{
		t->root=y;
	}
	else if(x == x->parent->right)
	{
		x->parent->right=y;
	}
	else
	{
		x->parent->left=y;
	}
	y->right=x;
	x->parent=y;
	printf("%s: End \n",__func__);


}

void insert(red_black_tree *t, tree_node *z)
{
	tree_node *y=NULL;
	tree_node* temp=t->root;
	while(temp !=NULL)
	{
		y=temp;
		if(z->data < temp->data)
		{
			temp=temp->left;
		}
		else 
		{
			temp=temp->right;
		}
	}
	z->parent=y;
	if(y==NULL)
	{
		t->root=z;
	}
	else if (z->data < y->data)
	{
		y->left=z;
	}
	else{
		y->right=z;
	}
	z->right =NULL;
	z->left=NULL;
}
void inorder(red_black_tree *t,tree_node *n)
{
	if(n !=NULL)
	{
		inorder(t,n->left);
		printf("%d\n",n->data);
		inorder(t,n->right);

	}
}
int main()
{
	red_black_tree *t=new_red_black_tree();
	tree_node *x,*y,*z;
	x=new_tree_node(65);
	y=new_tree_node(55);
	z=new_tree_node(45);

	insert(t,x);
	insert(t,y);
	insert(t,z);

	inorder(t,t->root);
	right_rotate(t,t->root);
//	left_rotate(t,t->root);
	inorder(t,t->root);

	return 0;



}
