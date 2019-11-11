#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];/* stk is the stack used for shift redue parsing,and a is the character array used to store the string*/
void check(){
    strcpy(ac,"REDUCE TO E");
    for(z=0;z<c;z++){
        if(stk[z]=='i' && stk[z+1]=='d'){   //iterate through the string and check if the string is identifier ie 'id' or not
            stk[z]='E';
            stk[z+1]='\0';
            printf("\n$%s\t%s$\t%s",stk,a,ac);
            j++;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            i=i-2;

        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
              stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
           i=i-2;

        }
    }

}
void check_accept(){
    if(stk[1]=='E'){
        printf("\n");
        printf("$%s\tACCEPT",stk);
    }
    else{
        printf("\nREJECT");
    }
}

int main(){
    printf("GRAMMER IS E->E+E \n E->E*E \n E->(E) \n E->id");
    printf("Enter a string");
    gets(a);
    c=strlen(a);
    strcpy(act,"SHIFT->");
    printf("stack \t input \t action");
    for(k=0,i=0; j<c; k++,i++,j++){
        if(a[j]=='i' && a[j+1]=='d'){
            stk[i]=a[j];
            stk[i+1]=a[j+1];
            stk[i+2]='\0';
            a[j]=' ';
            a[j+1]=' ';
            printf("\n$%s\t%s$\t%sid",stk,a,act);
            check();
        }
        else{
            stk[i]=a[j];
            stk[i+1]='\0';
            a[j]=' ';
            printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
            check();
        }
    }
    check_accept();//function to check whether the string in accepted or not
}
/*
 sample input
 id+id*id+id
 */