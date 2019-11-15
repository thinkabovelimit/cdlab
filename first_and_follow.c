#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,m,p,i=0,j=0;
char arr[100][100],f[10];
void first(char c){
    int k;
    if(!isupper(c))  //if charcter to be checked is in smallcase the first of that is that character itself 
        f[m++]=c; 
    for(k=0;k<n;k++){
        if(arr[k][0]==c){
            if(islower(arr[k][2])) //If the character after "=" is lowercase then first is that lowercase character itself is in first 
                f[m++]=arr[k][2];
            else
                first(arr[k][2]); //else if it is not in lowercase that is not terminal then find first again
        }
    }
}

void follow(char c){
    if(arr[0][0]==c)
        f[m++]='$'; // Add $ if the character is start symbol
    for(i=0;i<n;i++){
        for(j=2;j<strlen(arr[i]);j++){
            if(arr[i][j]==c){
                if(arr[i][j+1]!='\0') // if the result is in a->abK and to find the follow of b find first of K
                    first(arr[i][j+1]);
                if(arr[i][j+1]=='\0' && c!=arr[i][0])  //if it is in a->ab then find follow of a and that is in follow of b
                    follow(arr[i][0]);
                
            }
        }

    }
}
int main(){
    int i,z;
    char c,ch;
    printf("Enter the number of production:\n");
    scanf("%d",&n);
    printf("Enter the productions:\n");
    for(i=0;i<n;i++)
        scanf("%s%c",arr[i],&ch);
    do{
        m=0;
        printf("Enter the elements whose first and follow to be found");
        scanf("%c",&c);
        first(c);
        printf("First(%c)={",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        strcpy(f," ");
        m=0;
        follow(c);
        printf("Follow(%c)={",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        printf("Continue(0/1)?");
        scanf("%d%c",&z,&ch);
    }while(z==1);
}
/* INPUT:
PRODUCTIONS 5
E  -> TR
R  -> +T R
T  -> F Y
Y  -> *F Y  
F  -> (E) 

*/