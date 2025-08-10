
#include <stdio.h>
#include <string.h>
int isOpening(char c) { return c=='(' || c=='[' || c=='{'; }
int isClosing(char c) { return c==')' || c==']' || c=='}'; }
int matches(char o, char c){
    return (o=='('&&c==')') || (o=='['&&c==']') || (o=='{'&&c=='}');}
int balanced(const char *s){
    int n = strlen(s);
    char stack[1024];
    int top = -1;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(isOpening(c)) stack[++top]=c;
        else if(isClosing(c)){
            if(top<0) return 0;
            char o = stack[top--];
            if(!matches(o,c)) return 0;
        }
    }
    return top==-1;
}
int main(){
    const char *tests[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    for(int i=0;i<3;i++){
        printf("Expression: %s\n", tests[i]);
        printf("Balanced? %s\n\n", balanced(tests[i]) ? "Yes" : "No");
    }
    return 0;
}