#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    char carta[2];
    char naipe;
    struct node *next;
}*head;

void add(char str[3], struct node* to)
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

//Atualizado para lidar com o nó cabeça

    if (to->next== NULL)
    {
    to->next=temp;
    to->next->next=NULL;
    }
    else
    {
    temp->next=to->next;
    to->next=temp;
    }
}

//Mudado pra lidar com to como **
void recebe_baralho(struct node** to){
	struct node vazio;
	*to = (struct node *)malloc(sizeof(struct node));

//Setado como NULL por motivos de segurança

    (*to)->next = NULL;
	int j;
	char str[3];

	for(j = 0; j < 3; j++){
	
		scanf("%s", str);
		add(str, *to);
	}
}

//int delete(struct node* from)
//{
//	struct node *temp, *prev;
//	printf("1\n");
//	head = from;
//	printf("2\n");
//	temp = head;
//	printf("3\n");
//	if(temp==head)
//	{
//		printf("P1");
//		head=temp->next;
//		free(temp);
//		return 1;
//	}
//	else
//	{
//		printf("P2");
//		prev->next=temp->next;
//		free(temp);
//		return 1;
//	}
//
//	return 0;
//}


//Mudada por causa do nó cabeça
void delete2 (struct node *from) {
	struct node *removida;
	removida = from->next;
	from->next = removida->next;
	free (removida);
}

void troca (struct node* from, struct node* to){
	char aux1[3];
	if (from->next->carta[0] == '1'){
	        aux1[0] = '1';
	        aux1[1] = '0';
	        aux1[2] = from->next->naipe;
	}
	else {
	        aux1[0] = from->next->carta[0];
	        aux1[1] = from->next->naipe;
	}

	add(aux1, to);
	delete2(from);
}
 

//Mudada por causa do nó cabeça
void  display(struct node *r)
{

    if(r->next==NULL)
    {
    return;
    }
    while(r->next!=NULL)
    {
      if (r->carta[0] != '1'){
	printf("%c%c\n",r->next->carta[0],r->next->naipe);
      }
      else{
	printf("%c%c%c\n",r->next->carta[0],r->next->carta[1],r->next->naipe);
      }
    r=r->next;
    }
}


//Mudada por causa do nó cabeça
void  display_last(struct node *r)
{

    if(r->next==NULL)
    {
    return;
    }
    if (r->next->carta[0] != '1'){
      printf("%c%c\n",r->next->carta[0],r->next->naipe);
    }
    else{
      printf("%c%c%c\n",r->next->carta[0],r->next->carta[1],r->next->naipe);
    }
}
 
 
//Mudada por causa do nó cabeça
int count(struct node *n)
{

    int c=0;

    while(n->next!=NULL)
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
    struct node *E, *D, *J1, *J2, *J3, *J4, *J5, *J6, *J7;
    struct node *S1, *S2, *S3, *S4;
    E=NULL;
    recebe_baralho(&E);
    display(E);
    //display_last(E);
    delete2(E);
    //troca(head, D);
    display(E);
    return 0;
}
