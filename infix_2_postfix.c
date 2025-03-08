#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define Empty -1
#define PUSH(data) stack[++top] = data
#define POP stack[top--] = '\0'

char *chr,*p,stack[10],*postfix1=NULL;
int top = -1,cnt=0;

void display_postfix(char *p);
void add_2_postfix(char ch);
int priority(char top,char ch);
int isOperator(char ch);

char *inf_2_postfix(char *inf)
{
          chr = inf;
          p = inf;
          free(postfix1);
          while(*chr){
                  display_postfix(p);
              if(*chr == '('){
                PUSH(*chr);
              }
              else if(isOperator(*chr)){
                      if(top == Empty)
                            PUSH(*chr);
                      else if(stack[top] == '(')
                            PUSH(*chr);
                      else if(priority(stack[top],*chr))
                            PUSH(*chr);
                      else {
                            add_2_postfix(stack[top]);
                            POP;
                            continue;
                      }
              }
              else if(*chr == ')'){
                      while(stack[top] == '('){
                         add_2_postfix(*chr);
                         POP;
                      }
              }
              else
                      add_2_postfix(*chr);
              chr++;
          }
          if(top>-1){
                 while(top != -1){
                      add_2_postfix(stack[top]);
                      POP;
                 }
          }

          display_postfix(p);
          postfix1[cnt]='\0';
          cnt=0;
          return postfix1;
}

void display_postfix(char *p){
     system("clear");
//infix exp
printf("\n  INFIX EXP : ");
   for(;*p;p++){
       if(*p == *chr)
            printf("\033[43;31m  %c   \033[0m ",*p);
       else       
            printf("\033[46;31m  %c   \033[0m ",*p);
   }

//stack
   printf("\n\n\t\t\t  STACK\n");

  for(int i=5;i>=0;i--)
  {
    if(top==-1 && i==0 )
            printf("\t\t\t\033[47;36m  Empty  \033[0m\n");
    else if(top==4 && i==5)
            printf("\t\t\t\033[47;36m  FULL   \033[0m\n");
    else if(i<=top){
        if(i<top)
            printf("\t\t\t\033[46;31m  %3c    \033[0m\n",stack[i]);
        else
            printf("\t\t Top -> \033[43;31m  %3c    \033[0m\n",stack[i]);
    }
    else
       printf("\t\t\t\033[47m         \033[0m\n");
  }

  if(postfix1 != NULL){
          printf("\n\n POSTFIX EXP : ");
    for(int i=0;postfix1[i];i++){
      printf(" %c",postfix1[i]);
    }
    printf("\n\n");
  }

  sleep(2);
}
void add_2_postfix(char ch){
     postfix1 = realloc(postfix1,cnt+1);
     postfix1[cnt] = ch;
     cnt++;
}

int isOperator(char ch){
    switch(ch){
      case '+' : return 1;
      case '-' : return 1;
      case '*' : return 1;
      case '/' : return 1;
    }
    return 0;
}

int priority(char top,char ch){
    char opr[4]="*/+-";
    int op1=0,op2=0;
    for(int i=0;i<4;i++)
    {
        if(top == opr[i])
                op1 = i;
        if(ch == opr[i])
                op2 = i;
    }
    if(op2<op1)
            return 1;
    return 0;
}
