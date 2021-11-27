#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
#define INCREASELEN 10 
typedef  char Elemtype;
typedef  float Flemtype;
typedef  int  Status;
typedef struct {
	Elemtype *base;
	Elemtype *top;
	int maxsize;
}sqStack;
typedef struct {
	Flemtype *base;
	Flemtype *top;
	int maxsize;
}fqStack;
Status isEmpty(sqStack s){
	if(s.top==s.base)
		return 1;
	else 
		return 0;
}
Status FisEmpty(fqStack s){
	if(s.top==s.base)
		return 1;
	else 
		return 0;
}
void initStack(sqStack *s){
	s->maxsize = MAXLEN;
	s->base = (Elemtype *)malloc(MAXLEN*sizeof(Elemtype));
	if(!s->base)
		exit(0);
	s->top=s->base;	
} 
void FinitStack(fqStack *s){
	s->maxsize = MAXLEN;
	s->base = (Flemtype *)malloc(MAXLEN*sizeof(Flemtype));
	if(!s->base)
		exit(0);
	s->top=s->base;	
} 
void increaseStack(sqStack *s){
		s->base=(Elemtype *)realloc(s->base,(s->maxsize+INCREASELEN)*sizeof(Elemtype));
		if(!s->base)
			exit(0);
		s->maxsize=s->maxsize + INCREASELEN;		
}
void FincreaseStack(fqStack *s){
		s->base=(Flemtype *)realloc(s->base,(s->maxsize+INCREASELEN)*sizeof(Flemtype));
		if(!s->base)
			exit(0);
		s->maxsize=s->maxsize + INCREASELEN;		
}
void push(sqStack *s,Elemtype e){
	if(s->top-s->base>=s->maxsize)
		increaseStack(s);
	*(s->top)=e;
	(s->top)++;
}
void Fpush(fqStack *s,Flemtype e){
	if(s->top-s->base>=s->maxsize)
		FincreaseStack(s);
	*(s->top)=e;
	(s->top)++;
}
void pop(sqStack *s,Elemtype *e){
	if(s->top==s->base)
		return ;
	*e=*--(s->top);
}
void Fpop(fqStack *s,Flemtype *e){
	if(s->top==s->base)
		return ;
	*e=*--(s->top);
}
void arithmetic(fqStack *num,Elemtype c){
	float *f1,*f2;
	float f3;
	switch(c){
					case '*':
						Fpop(num,f1);
						Fpop(num,f2);
						f3=(*f1)*(*f2);
						Fpush(num,f3);
						break;
					case '/':
						Fpop(num,f1);
						Fpop(num,f2);
						f3=(*f1)/(*f2);
						Fpush(num,f3);
						break;
					case '+':
						Fpop(num,f1);
						Fpop(num,f2);
						f3=(*f1)+(*f2);
						Fpush(num,f3);
						break;
					case '-':
						Fpop(num,f1);
						Fpop(num,f2);
						f3=(*f1)-(*f2);
						Fpush(num,f3);
						break;						
				}	
}
int main(){
	int flag;
	float sum=0;
//	float *f1,*f2;
	fqStack *num;
	sqStack *sign;
	Elemtype e;
	Elemtype *a;
	//Elemtype str[10];
	num=(fqStack*)malloc(sizeof(fqStack));
    sign=(fqStack*)malloc(sizeof(fqStack));

	FinitStack(num);
	initStack(sign);
	scanf("%c",&e);
	while(e != '#'){
		flag =0;
		while(e>='0' && e<=9)
		{
			sum=sum*10+(e-'0');
			flag =1;
			scanf("%c",&e);
		}
		if(flag)
			Fpush(num,sum);
		if(e=='#')
			break;
		else if(e==')')
		{
			pop(sign,a);
			while(*a!='(')
			{
				arithmetic(num,*a);
			}
		}
		else if(e=='+' || e=='-'){
			if(isEmpty(*sign)){
				push(sign,e);
			}
			else{
				do{
					pop(sign,a);
					if(*a == '('){
						push(sign,*a);
					}
					else{
						arithmetic(num,*a);
					}					
				}
				while(!(isEmpty(*sign)) && *a!='(');
				push(sign,e);
			}
		}
		else if(e=='*' || e=='/' || e=='('){
			push(sign,e);
		}
		else{
			printf("ÊäÈë´íÎó\n");
			return -1;
			}
		scanf("%c",e);
	}
	printf("%.2f",*(num->top));	
	/*while(e !='#')
	{
		push(s,e);
		scanf("%c",&e);
	}
	//getchar();
	while(s->top != s->base)
	{
		pop(s,a);
		printf("%c\t",*a);
	}*/
	return 0;
}