#include<stdio.h>
int adj[20][20],buffer[20],state=0,k=0;
 
void addbuffer(int j){      /* Function to avoid duplication of states and for adding the closure into the buffer*/
    int m,i,flag=0;

    for(i=0;i<20;i++){
        if(buffer[i]==j)
            flag=1;
    }
    if(flag==0)
        buffer[state++]=j;
    
}
void print(int i){  //Function for printing the printing the values
    int l=0;
    printf("q%d->\t{",i);

    for(l=0;l<20;l++){
        if(buffer[l]!=-2)
            printf("q%d,",buffer[l]);
    }
    printf("}");
    printf("\n");
     for(l=0;l<20;l++){
        buffer[l]=-2;
    }
}
int main(){
    for(k=0;k<20;k++){
        buffer[k]=-2;
    }
    printf("NOTE-Enter -1 for epsilon  transitions\n");
    printf("NOTE-The transition states are starting from q0,q1......\n\n\n");
    
    int i,j,trans[3],num_trans,alphabets,p,k,num_states; /*trans is an array to store the transition ,num_trans stores the number of transtions*/
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            adj[i][j]=-2;
        }
    }
    printf("Enter the number of states:");
    scanf("%d",&num_states);
    
    printf("Enter the number of transtions:");
    scanf("%d",&num_trans);
    for(i=0;i<num_trans;i++){
        printf("Enter the transition %d\n",i);
        printf("##########\n");
        printf("##########\n");
        scanf("%d%d%d",&trans[0],&trans[1],&trans[2]);
        //printf("%d\t%d \t%d\t",trans[0],trans[1],trans[2]);
        adj[trans[0]][trans[2]]=trans[1];

    }
    j=0;
    for(i=0;i<num_states;i++){
        addbuffer(i);
        for(j=0;j<num_states;j++){
            if(adj[i][j]==-1 || adj[i][j]==0){
                addbuffer(j);
                p=j;
                for(k=0;k<num_states;k++){
                    if(adj[p][k]==-1  ){
                        addbuffer(k);
                    }
                }
            }
        }   
            print(i);
        
    }
     /*for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }*/
    

}
/*
    Sample input 
    -----------
    0   0   0
    1   -1  1
    1   0   1
    1   -1  2
    2   0   2


    sample output
    ------------
    q0->    {q0,q1,q2}
    q1->   {q1,q2}
    q2->    {q2}
*/