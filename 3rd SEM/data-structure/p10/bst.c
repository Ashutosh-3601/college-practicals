#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
//Function to create a BST of N integers:6 9 5 2 8 15 24 14 7 8 5 2
NODE insert_node(int item,NODE root)
{
NODE cur,temp,prev;
temp=(NODE)malloc(sizeof(struct node));
temp->info=item;
temp->llink=temp->rlink=NULL;
if(root==NULL)
return temp;
prev=NULL;
cur=root;
while(cur!=NULL)
{
prev=cur;
if(item<cur->info)
cur=cur->llink;
else if(item>cur->info)
cur=cur->rlink;
else
{
printf("Item already exists cant insert\n");//if duplicates items
free(temp);
return root;
}
}
if(item<prev->info)
prev->llink=temp;
else
prev->rlink=temp;
return root;
}
void inorder(NODE root)
{
if(root==NULL)
return;
inorder(root->llink);
printf("%d\t",root->info);
inorder(root->rlink);
}
void preorder(NODE root)
{
if(root==NULL)
return;
printf("%d\t",root->info);
preorder(root->llink);
preorder(root->rlink);
}
void postorder(NODE root)
{
if(root==NULL)
return;
postorder(root->llink);
postorder(root->rlink);
printf("%d\t",root->info);
}
NODE search(int item,NODE root)
{
if(root==NULL||item==root->info)
return root;
if(item<root->info)
return search(item,root->llink);
return search(item,root->rlink);
}
NODE delete_node(int item,NODE root)
{
NODE child,suc,par,cur;
//if tree is empty
if(root==NULL)
{
printf("Tree is empty\n");
return root;
}
//tree is existing
par=NULL;
cur=root;
while(cur!=NULL&&item!=cur->info)
{
par=cur;
if(item<cur->info)
cur=cur->llink;
else
cur=cur->rlink;
}
if(cur==NULL)
{
printf("Item not found\n");
return root;
}
//node to be delted has only one subtree
if(cur->llink==NULL)
child=cur->rlink;
else if(cur->rlink==NULL)
child=cur->llink;
//node to be deleted has both subtrees
else
{
child=cur->rlink;
suc=cur->rlink;
while(suc->llink!=NULL)
{
suc=suc->llink;
}
suc->llink=cur->llink;
}
if(par==NULL)
{
free(cur);
return child;
}
//Node to be deleted has no children
if(cur==par->llink)
par->llink=child;
else
par->rlink=child;
free(cur);
return root;
}
int main()
{
int ch,item;
NODE root=NULL,temp,parent;
for(;;)
{
printf("\n1.Create\n");
printf("2.Traverse the tree in Preorder, Inorder and Postorder \n");
printf("3.Search\n");
printf("4.Delete an element from the tree\n");
printf("5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the item to be inserted\n");
scanf("%d",&item);
root=insert_node(item,root);
break;
case 2:if(root==NULL)
printf("\nTree is not created\n");
else
{
printf("\nThe Inorder display:\n");
inorder(root);
printf("\nThe Preorder display:\n");
preorder(root);
printf("\nThe Postorder display:\n");
postorder(root);
}
break;
case 3:printf("\nEnter Elements to be searched\n");
scanf("%d",&item);
temp=search(item,root);
if(temp==NULL)
printf("\nElement does not exists\n");
else
printf("\nThe Element %d is found\n",temp->info);
break;
case 4:printf("\nEnter the Element to be deleted\n");
scanf("%d",&item);
root=delete_node(item,root);
break;
default:exit(0);
}
}
}
