#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define Empty -1
#define PUSH(data) stack[++top2] = data
#define POP stack[top2--] = '\0'

char *chr,*p,stack[10],*prefix1=NULL;
int top2 = -1,cnt3=0,i;

void display_prefix(char *p,char c);
void add_2_prefix(char ch);
int priority2(char top,char ch);
int isOperator2(char ch);
void revstr(char *p);

char *inf_2_prefix(char *inf)
{
          chr = inf;
          p = inf;
          for(i=strlen(chr)-1 ; i>=0 ; i--)
          {
                  display_prefix(p,chr[i]);
              if(chr[i] == ')'){
                PUSH(chr[i]);
              }
              else if(isOperator2(chr[i])){
                      if(top2 == Empty)
                            PUSH(chr[i]);
                      else if(stack[top2] == ')')
                            PUSH(chr[i]);
                      else if(priority2(stack[top2],chr[i]))
                            PUSH(chr[i]);
                     // else if(priority2(chr[i]))
                //          PUSH(chr[i]);  
                      else {
                            add_2_prefix(stack[top2]);
                            POP;
                            continue;
                      }
              }
              else if(chr[i] == '('){
                      while(stack[top2] == ')'){
                         add_2_prefix(chr[i]);
                         POP;
                      }
              }
              else
                      add_2_prefix(chr[i]);
          }
          if(top2>-1){
                 while(top2 != -1){
                      add_2_prefix(stack[top2]);
                      POP;
                 }
          }

          display_prefix(p,chr[i]);
          revstr(prefix1);
          prefix1[cnt3]='\0';
          return prefix1;
}

void display_prefix(char *p,char c){
     system("clear");
//infix exp
     printf("\n  INFIX EXP : ");
   for(;*p;p++){
       if(*p == c)
            printf("\033[46;31m  %c   \033[0m ",*p);
       else
            printf("\033[43;31m  %c   \033[0m ",*p);
   }
//stack
   printf("\n\n\t\t\t  STACK\n");

  for(int i=5;i>=0;i--)
  {
    if(top2==-1 && i==0 )
            printf("\t\t\t\033[47;36m  Empty  \033[0m\n");
    else if(top2==4 && i==5)
            printf("\t\t\t\033[47;36m  FULL   \033[0m\n");
    else if(i<=top2){
        if(i<top2)
            printf("\t\t\t\033[46;31m  %3c    \033[0m\n",stack[i]);
        else
            printf("\t\t Top -> \033[43;31m  %3c    \033[0m\n",stack[i]);
    }
    else
       printf("\t\t\t\033[47m         \033[0m\n");
  }

  if(prefix1 != NULL){
          printf("\n\n PREFIX EXP : ");
    for(int i=0;prefix1[i];i++){
      printf(" %c",prefix1[i]);
    }
    printf("\n\n");
  }

  sleep(2);
}

void add_2_prefix(char ch){
     prefix1 = realloc(prefix1,cnt3+1);
     prefix1[cnt3] = ch;
     cnt3++;
}
int isOperator2(char ch){
    switch(ch){
      case '+' : return 1;
      case '-' : return 1;
      case '*' : return 1;
      case '/' : return 1;
    }
    return 0;
}
void revstr(char *p){
        char *l,*r,temp;
        l=p;
        r=p+strlen(p)-1;
        while(l<r){
             temp=*l;
             *l=*r;
             *r=temp;
             l++;
             r--;
        }
}
int priority2(char top,char ch){
    char opr[4]="*/+-";
    int op1=0,op2=0;
    for(int i=0;i<4;i++)
    {
        if(top == opr[i])
                op1 = i;
        if(ch == opr[i])
                op2 = i;
    }
    if(op2<=op1)
            return 1;
    return 0;
/*    if(ch == '+' || ch == '-')
            return 1;
    if(ch == '*' || ch == '%' || ch =='/')
               return 2;
    return 0;*/
}
