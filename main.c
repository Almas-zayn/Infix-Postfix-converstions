#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void display_screen();
char *prefix="Not converted",*postfix="Not converted",infix[100]="A+B*C-D";
int res_prefix,res_postfix;
char ch;
int main()
{
   while(1){
    display_screen();
    printf("\n\t1.Infix expression\n\t2.Infix to prefix\n");
    printf("\t3.Infix to postfix\n\t4.Evaluate Prefix\n\t5.Evaluate Postfix\n");
    scanf(" %c",&ch);
    switch(ch){
            case '1':scanf("%s",infix);break;
            case '2':prefix = inf_2_prefix(infix);break;
            case '3':postfix = inf_2_postfix(infix);break;
            case '4':res_prefix = eval_prefix(prefix);break;
            case '5':res_postfix = eval_postfix(postfix);break;
    }
   }
}

void display_screen(){
     system("clear");
     printf("\n\n\n\t\tINFIX   EXP - \033[0;33m %s \033[0m\n",infix);
     printf("\t\tPREFIX  EXP - \033[0;33m %s \033[0m\n",prefix);
     printf("\t\tPOSTFIX EXP - \033[0;33m %s \033[0m\n",postfix);
     printf("\t\tPOSTFIX Eva - \033[0;33m %d \033[0m\n",res_postfix);

}
