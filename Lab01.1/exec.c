#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    char carta[2];
    char naipe;
    struct node *next;
}*head;

void add(char str[3])
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (str[1] == '0'){
        temp->naipe = str[2];
        temp->carta[0] = '1';
        temp->carta[1] = '0';
    }
    else {
        temp->carta[0] = str[0];
        temp->naipe = str[1];
    }
    if (head== NULL)
    {
    head=temp;
    head->next=NULL;
    }
    else
    {
    temp->next=head;
    head=temp;
    }
}

void recebe_baralho(struct node* to){

	int j;
	char str[3];
	to = NULL;
	head = to;
	for(j = 0; j < 3; j++){
	
		scanf("%s", str);
		add(str);
	}
}

int delete(struct node* from)
{
	struct node *temp, *prev;
	head = from;
	temp = head;
	if(temp==head)
	{
		printf("P1");
		head=temp->next;
		free(temp);
		return 1;
	}
	else
	{
		printf("P2");
		prev->next=temp->next;
		free(temp);
		return 1;
	}
	else
	{
	        prev=temp;
	        temp= temp->next;
		printf("P5");
	}
	return 0;
}

void troca (struct node* from, struct node* to){
	char aux1[3];
	if (from->carta[0] == '1'){
	        aux1[0] = '1';
	        aux1[1] = '0';
	        aux1[2] = from->naipe;
	}
	else {
	        aux1[0] = from->carta[0];
	        aux1[1] = from->naipe;
	}
	head = to;
	add(aux1);
	printf("ok");
	delete(aux1, from);
}
 
void  display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
    return;
    }
    while(r!=NULL)
    {
      if (r->carta[0] != '1'){
	printf("%c%c\n",r->carta[0],r->naipe);
      }
      else{
	printf("%c%c%c\n",r->carta[0],r->carta[1],r->naipe);
      }
    r=r->next;
    }
    printf("ok1");
}

void  display_last(struct node *r)
{
    r=head;
    if(r==NULL)
    {
    return;
    }
    if (r->carta[0] != '1'){
      printf("%c%c\n",r->carta[0],r->naipe);
    }
    else{
      printf("%c%c%c\n",r->carta[0],r->carta[1],r->naipe);
    }
}
 
 
int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}
 
int main (){
    int i;
    char str[3];
    char charin1;
    char charin2;
    struct node *n, *E, *D, *J1, *J2, *J3, *J4, *J5, *J6, *J7;
    struct node *S1, *S2, *S3, *S4;
    head=NULL;
    recebe_baralho(E);
    display(E);
    display_last(E);
    //troca(E, D);
    
    return 0;
}
