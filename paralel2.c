#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    char carta[2];
    char naipe;
    struct node *next;
}*head;

struct node *D2, *J1, *J12, *J2, *J22, *J3, *J32, *J4, *J42, *J5, *J52, *J6, *J62, *J7, *J72;
struct node *E, *D, *S1, *S2, *S3, *S4; //S1 = Paus, S2 = Copas, S3 = Espadas, S4 = Ouros

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

void cria_pilha(struct node** to){
  *to = (struct node *)malloc(sizeof(struct node));
  (*to)->next = NULL;
}

//Mudado pra lidar com to como **
void recebe_baralho(struct node** to){
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
	if (from->carta[0] == '1'){
	        aux1[0] = '1';
	        aux1[1] = '0';
	        aux1[2] = from->naipe;
	}
	else {
	        aux1[0] = from->carta[0];
	        aux1[1] = from->naipe;
	}
	add(aux1, to);
	delete2(from);
}
 
//void distribui_baralho(){
//  int i;
//  for (i = 0, i<28, i++){
    
//  }
//}
 
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

int full(){
  if (count(S1) == 13 && count(S2) == 13 && count(S3) == 13 && count(S4) == 13){
    return 1;
  }
  else return 0;
}

void check_A(struct node *check){
  if (check->carta[0] == 'A'){
    if (check->naipe == 'P'){
      troca(check, S1);
    }
    else if (check->naipe == 'C'){
      troca(check, S2);
    }
    else if (check->naipe == 'E'){
      troca(check, S3);
    }
    else if (check->naipe == 'O'){
      troca(check, S4);
    }
  }
}
 
int main (){
    cria_pilha(&D); cria_pilha(&D2); cria_pilha(&J1); cria_pilha(&J12); cria_pilha(&J2);
    cria_pilha(&J22); cria_pilha(&J3); cria_pilha(&J32); cria_pilha(&J4); cria_pilha(&J42);
    cria_pilha(&J5); cria_pilha(&J52); cria_pilha(&J6); cria_pilha(&J62); cria_pilha(&J7);
    cria_pilha(&J72); cria_pilha(&S1); cria_pilha(&S2); cria_pilha(&S3); cria_pilha(&S4); 
    
    struct node **vetor;
    vetor = malloc(sizeof(struct node*));
    int i;
    //for(i = 0; i < 3; i++){
  
    recebe_baralho(&E);
    display(E);
    troca(E, D);
    display(E);
    display(D);
    
    //while (!(full())){
      //if (count(D) == 0){
        //troca(D, D2);
        //troca(E, D);
        //check_A(D);
      //}
      
    //}
    
    return 0;
}
