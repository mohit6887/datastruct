#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lchild;
        int info;
	struct node *rchild;
};
struct node *getnode(int x);
void display(struct node *p, int level);
struct node *insertnode(struct node *root, int x);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
int height(struct node *p);
struct node *findmin(struct node *p);
struct node *findmax(struct node *p);
struct node *deletenode(struct node *p,int x);
int main()
{
	printf(" inside the %s \n",__func__);
	struct node *root =NULL;

		
	int choice,x;


	while(1)
	{
		

		printf("1 -->create tree \n");
		printf("2 --> insertnode \n");
		printf("3 --> display node \n");
		printf("4 --> inorder \n");
		printf("5 --> postorder \n");
		printf("6 --> preorder \n");
		printf("7 --> find max \n");
		printf("8 -->find max \n");
		printf("9 --> delete the element in tree \n");
		printf("11 --> Exit the code\n");

		printf("Enter the choice :\n");
		scanf("%d",&choice);
		if(choice ==11)
		{
			break;
		}

		switch(choice)
		{
			case 1:
				printf("Enter the value for the root node");
				scanf("%d",&x);
				root=getnode(x);
				break;
			case 2:
                                printf("Enter the value to be inserted \n");
				scanf("%d",&x);
				root=insertnode(root,x);
                                break;

			case 3:
				printf("==============\n");
				display(root,0);
				printf("\n");
				printf("===============\n");
				break;
			case 4:
				printf(" inorder :");
				inorder(root);
				printf("\n");
				break;
			case 5:
				printf("Postorder :");
				postorder(root);
				printf("\n");
				break;
			case 6:
				printf(" Preorder :");
				preorder(root);
				printf("\n");
				break;
			case 7:
				printf(" FIND MIN VALUE in tree \n");
				root=findmin(root);
				printf("minimum value in BST is = %d",root->info);
				printf("\n");
				break;
			case 8:
				printf("FInd max value in a tree \n");
				root=findmax(root);
				printf("Max value in the a tree =%d",root->info);
				printf("\n");
				break;
			case 9: 
				printf("Delete \n");
				printf("Enter the number to delete \n");
				scanf("%d",&x);
				root=deletenode(root,x);
				printf("\n");
				break;



			default:
				printf("Wrong choice \n");
				break;
		}
	}

	/*i
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
*/

}

struct node *getnode(int x)
{
	struct node *p =(struct node *)malloc(sizeof(struct node));
	p->info =x;
	p->lchild=p->rchild=NULL;

	return p;
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
	printf("%d",p->info);
//	printf("\n");
	display(p->lchild,level+1);
	
}

struct node *insertnode(struct node *p, int x)
{
	if(p==NULL)
		p=getnode(x);
	else if (x < p->info)
		p->lchild =insertnode(p->lchild,x);
	else if ( x > p->info)
		p->rchild =insertnode(p->rchild,x);
	else 
		printf("%d already present in tree \n",x);
	return p;
}

void preorder(struct node *p)
{
	if(p == NULL)
		return;
	printf("%d \t",p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}

void inorder(struct node *p)
{
        if(p == NULL)
                return;
	inorder(p->lchild);
        printf("%d \t",p->info);
        inorder(p->rchild);
}



void postorder(struct node *p)
{
        if(p == NULL)
                return;
        postorder(p->lchild);
        postorder(p->rchild);
	printf("%d \t",p->info);
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
struct node *findmin(struct node *p)
{
	while(p->lchild!=NULL)
	{
		p=p->lchild;
	}
	return p;
}
struct node *findmax(struct node *p)
{
        while(p->rchild!=NULL)
        {
                p=p->rchild;
        }
        return p;
}
struct node *deletenode(struct node *p,int x)
{
	if(p==NULL) 
	{
		return p;
	}
	else if ( x < p->info)
	{	
		p->lchild=deletenode(p->lchild,x);
	}
	else if (x > p->info)
	{
		p->rchild =deletenode(p->rchild,x);
	}
	else
	{
		// no child
		if ((p->lchild ==NULL) && (p->rchild))
		{
			free(p);
			p =NULL;
		}
		// 1 child
		else if(p->lchild ==NULL)
	       	{
			struct node* temp =p;
			p=p->rchild;
			free(p);
		}
		else if (p->rchild ==NULL)
		{
			struct node *temp =p;
			p=p->lchild;
			free(p);
		}
		//2 child
		else
		{
			struct node *temp =findmin(p->rchild);
			p->info=temp->info;
			p->rchild=deletenode(p->rchild,temp->info);

		}
	}
	return p;

}
