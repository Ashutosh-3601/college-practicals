#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
 int cf;
 int px;
 int py;
 int pz;
 struct node *link; //self referencial structure
};
typedef struct node* NODE;
void display(NODE head)
{
 NODE cur;
 if(head->link==head)
 {
 printf("Polynomial does not exists\n");
 return;
 }
 cur=head->link;
 while(cur!=head)
 {
 if(cur->cf>0)
 printf("+");
 printf("%d",cur->cf);
 printf("x^%d",cur->px);
 printf("y^%d",cur->py);
 printf("z^%d",cur->pz);
 cur=cur->link;
 }
}
NODE insert_rear(int cf,int px,int py,int pz,NODE head)
{
 NODE temp,cur;
 temp=(NODE)malloc(sizeof(struct node));
 temp->cf=cf;
 temp->px=px;
 temp->py=py;
 temp->pz=pz;
 temp->link=temp;
 cur=head->link;
 while(cur->link!=head)
 {
 cur=cur->link;
 }
 cur->link=temp;
 temp->link=head;
 return head;
}
NODE readpoly(NODE head)
{
 int n,i,cf,px,py,pz;
 printf("enter the number of terms\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 printf("\nenter the coefficients of %dterm\n",i);
 scanf("%d",&cf);

 printf("\nenter the power of x of %d term\n",i);
 scanf("%d",&px);
 printf("\nenter the power of y of %d term\n",i);
 scanf("%d",&py);
 printf("enter the power of z of %d term\n",i);
 scanf("%d",&pz);
 head=insert_rear(cf,px,py,pz,head);
 }
 return head;
}
void evaluate(NODE head)
{
 NODE cur;
 int x,y,z,result=0;
 if(head->link==head)
 {
 printf("Polynomial does not exists\n");
 return;
 }
 printf("\nEnter the value of x\n");
 scanf("%d",&x);
 printf("Enter the value of y\n");
 scanf("%d",&y);
 printf("Enter the value of z\n");
 scanf("%d",&z);
 cur=head->link;
 while(cur!=head)
 {
 result=result+cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
 cur=cur->link;
 }
 printf("The result of evaluation is %d\n",result);
}
NODE addpoly(NODE h1,NODE h2,NODE h3)
{
 NODE p1,p2;
 p1=h1->link;
 p2=h2->link;
 int sumcf;
 while(p1!=h1&&p2!=h2)
 {
 if(p1->px > p2->px)
 {
 h3=insert_rear(p1->cf,p1->px,p1->py,p1->pz,h3);
 p1=p1->link;
 }
 else if(p1->px < p2->px)
 {
 h3=insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3);
 p2=p2->link;
 }
 else
 {
 if(p1->py > p2->py)
 {
 h3=insert_rear(p1->cf,p1->px,p1->py,p1->pz,h3);
 p1=p1->link;
 }
 else if (p1->py < p2->py)
 {

 h3=insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3);
 p2=p2->link;
 }
 else
 {
 if(p1->pz > p2->pz)
 {
 h3=insert_rear(p1->cf,p1->px,p1->py,p1->pz,h3);
 p1=p1->link;
 }
 else if (p1->pz < p2->pz)
 {

 h3=insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3);
 p2=p2->link;
 }
 else
 {
 sumcf=p1->cf+p2->cf;
 if(sumcf!=0)
 h3=insert_rear(sumcf,p1->px,p1->py,p1->pz,h3);
 p1=p1->link;
 p2=p2->link;
 }
 }
 }
 }
while(p1!=h1)
{
 h3=insert_rear(p1->cf,p1->px,p1->py,p1->pz,h3);
 p1=p1->link;
}
while(p2!=h2)
{
 h3=insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3);
 p2=p2->link;
}
return h3;
}
int main()
{
 NODE h1,h2,h3;
 h1=(NODE)malloc(sizeof(struct node));
 h2=(NODE)malloc(sizeof(struct node));
 h3=(NODE)malloc(sizeof(struct node));
 h1->link=h1;
 h2->link=h2;
 h3->link=h3;
 printf("enter the first polynomial\n");
 h1=readpoly(h1);
 printf("enter the Second polynomial\n");
 h2=readpoly(h2);
 h3=addpoly(h1,h2,h3);
 printf("The first polynomial is \n");
 display(h1);
 evaluate(h1);

 printf("The Second polynomial is \n");
 display(h2);
 evaluate(h2);
 printf("The Sum is \n");
 display(h3);
 evaluate(h3);
}
