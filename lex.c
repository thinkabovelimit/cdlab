#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char identifiers[10][10];
int isize;

int iskeyword(char s[10])
{
		char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int i, flag = 0;
	for(i=0;i<32;i++)
	{
		if(strcmp(s,keywords[i])==0)
		{
			return 1;
		}
	}
	return 0;
}
int isdig(char s[10])
{
	int n=strlen(s),i,flag=1;
	for(i=0;i<n;i++)
	{
		if(!isdigit(s[i]))
		{
			flag=0;
			break;
		}
	}
	return flag;

}

int isdup(char buffer[15])
{
	int i;
	for(i=0;i<isize;i++)
	{
		if(strcmp(buffer,identifiers[i])==0)
		{
			return 1;
		}
	}
	return 0;
}

void main()
{
	char c,buffer[15],operators[]="+-%=*/",dupop[10],opsize=0,k,dupflag;
	int i,flag,j=0;
	FILE *fp;
	isize=0;

	fp=fopen("pgm.txt","r");

	if(fp==NULL)
	{
		printf("\n cannot open file");
		exit(0);
	}
	while((c=fgetc(fp))!=EOF)
	{
		dupflag=0;
		
		flag=0;
		for(i=0;i<6;i++)
		{
			if(c==operators[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			for(k=0;k<opsize;k++)
			{
				if(c==dupop[k])
				{
					dupflag=1;
					break;
				}
			}
			if(dupflag==0)
			{
				printf("\n%c is an operator",c);
				dupop[opsize++]=c;
			}
		}
		if(isalnum(c))
		{
			buffer[j++]=c;
		}
		else if((c==' ' || c=='\n' || c==',' || c==';' || flag==1 ) && j!=0)
		{
			buffer[j]='\0';
			j=0;
			if(iskeyword(buffer))
			{
				printf("\n %s is a keyword",buffer);
			}
			else if(isdig(buffer)==0)
			{
				if(isdup(buffer)==0)
				{
					printf("\n %s is an identifier",buffer);
					strcpy(identifiers[isize++],buffer);
				}
			}
		}
	}
	fclose(fp);
}