
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int prec(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}
int isOp(char c){ return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }
char *infix_to_postfix(const char *in){
    int n = strlen(in);
    char stack[1024]; int top=-1;
    char *out = malloc(n*3+10); out[0]=0;
    for(int i=0;i<n;){
        if(isspace(in[i])) { i++; continue; }
        if(isdigit(in[i])){
            
            char num[64]; int j=0;
            while(i<n && isdigit(in[i])) num[j++]=in[i++];
            num[j]=0;
            strcat(out, num); strcat(out, " ");
        } else if(in[i]=='('){
            stack[++top]='('; i++;
        } else if(in[i]==')'){
            while(top>=0 && stack[top]!='('){
                strncat(out, &stack[top--], 1); strcat(out," ");
            }
            if(top>=0 && stack[top]=='(') top--;
            i++;
        } else if(isOp(in[i])){
            char op = in[i];
            while(top>=0 && isOp(stack[top]) &&
                 ((prec(stack[top]) > prec(op)) || (prec(stack[top])==prec(op) && op != '^'))){
                strncat(out, &stack[top--], 1); strcat(out," ");
            }
            stack[++top]=op; i++;
        } else {
            
        i++;
        }
    }
    while(top>=0){ char c = stack[top--]; if(c!='(') { strncat(out, &c, 1); strcat(out," "); } }
    return out;
}

long long apply(long long a, long long b, char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/') return a/b;
    if(op=='^') return (long long)pow((double)a,(double)b);
    return 0;
}

long long eval_postfix(const char *p){
    long long stack[1024]; int top=-1;
    const char *s = p;
    while(*s){
        if(isspace(*s)){ s++; continue; }
        if(isdigit(*s)){
            long long val=0;
            while(*s && isdigit(*s)){ val = val*10 + (*s - '0'); s++; }
            stack[++top]=val;
        } else if(isOp(*s)){
            char op = *s++;
            long long b = stack[top--];
            long long a = stack[top--];
            stack[++top]=apply(a,b,op);
        } else s++;
    }
    return top>=0 ? stack[top] : 0;
}

int main(){
    const char *expr = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    printf("Infix: %s\n", expr);
    char *post = infix_to_postfix(expr);
    printf("Postfix: %s\n", post);
    long long val = eval_postfix(post);
    printf("Evaluated value: %lld\n", val);
    free(post);
    return 0;
}