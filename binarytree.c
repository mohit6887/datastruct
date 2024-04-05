#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lchild;
	char info;
	struct node *rchild;
};
struct node *getnode(char x);
void display(struct node *p, int level);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
int height(struct node *p);

int main()
{
	printf(" inside the %s \n",__func__);
	struct node *root =NULL;
	root=getnode('P');
	root->lchild =getnode('Q');
	root->rchild=getnode('R');
	root->lchild->lchild=getnode('A');
	root->lchild->rchild=getnode('B');
	root->rchild->lchild=getnode('X');
	root->rchild->rchild=getnode('Y');

	
	display(root,0);
	printf("\n\n:");
	
	printf(" Preorder :");
	preorder(root);
	printf("\n\n");

	printf("Inorder :");
	inorder(root);
	printf("\n\n");

	printf("Postorder :");
	postorder(root);
	printf("\n\n");

	printf("Height of tree is %d \n", height(root));


}

struct node *getnode(char x)
{
	struct node *p =(struct node *)malloc(sizeof(struct node));
	p->info =x;
	p->lchild=p->rchild=NULL;

	//return p;
}
/*
struct node *createnode(struct node* p,x)
{
	if(p==NULL)
		return;
	p=p->lchild;
	p->info =x;
}
*/
void display(struct node *p,int level)
{
	int i;
	if(p==NULL)
		return;
	display(p->rchild,level+1);
	printf("\n");
	for(i=0;i<level;i++)
	{
		printf("    ");
	}
	printf("%c",p->info);
	display(p->lchild,level+1);
}

void preorder(struct node *p)
{
	if(p == NULL)
		return;
	printf("%c",p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}

void inorder(struct node *p)
{
        if(p == NULL)
                return;
	inorder(p->lchild);
        printf("%c",p->info);
        inorder(p->rchild);
}



void postorder(struct node *p)
{
        if(p == NULL)
                return;
        postorder(p->lchild);
        postorder(p->rchild);
	printf("%c",p->info);
}
int height(struct node *p)
{
	int hL,hR;
	if(p ==NULL)
		return 0;
	if(hL>hR)
		return 1+hL;
	else 
		return 1+hR;
}
