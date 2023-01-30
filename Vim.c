#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dir.h>


//Prototypes
char *path(char *);
int check_function(char *);
int check(char [], char[], int );
void create_file(char *,int );
void cat(char *);
void insertstr(char *);

int main()
{
    while(1)
    {
        char command[1000];
        gets(command);
        int result=check_function(command);
        if(result==0)
            break;
        else if(result==-1)
            printf("Invalid command\n");
    }
    return 0;
}

int check_function(char *command)
{
    if(check(command,"createfile --file ",18))
    {
        char cf_address[100000];
        int i=0;
        while(command[i+18]!='\0')
        {
            cf_address[i]=command[i+18];
            i++;
        }
        --i;
        create_file(cf_address,i);
        return 1;
    }
    if(check(command,"insertstr --file ",17))
    {
        char input[10000];
        int i=0;
        while(command[i+17]!='\0')
        {
            input[i]=command[i+17];
            i++;
        }
        insertstr(input);
        return 1;
    }
    if (check(command,"cat --file ", 11))
    {
        char filename[100000];
        int i=0;
        while(command[i+11]!='\0')
        {
            filename[i]=command[i+11];
            i++;
        }
        cat(filename);
        return 1;
    }
    else if(check(command,"exit",4))
        return 0;
    else
        return -1;
}

int check(char command[], char line[], int lenght_line)
{
    for(int i=0; i<lenght_line; i++)
    {
        if(command[i]!= line[i])
            return 0;
    }
    return 1;
}

char *path(char *address)
{
    int k=0;
    if(address[0]=='"')
    {
        int k;
        for(k=0; address[k]!='\0'; k++)
        {
            address[k]=address[k+1];
        }
        address[k]='\0';
        address[k-2]='\0';
    }
    if(address[0]=='/')
    {
        int i;
        for(i=0; address[i]!='\0'; i++)
        {
            address[i]=address[i+1];
        }
        address[i]='\0';
    }
    return address;
}
void create_file(char *address, int lenght)
{
    char path[1000];
    path[0]=0;
    if(address[0]=='"')
    {
        for(int i=0; i<lenght; i++)
        {
            address[i]=address[i+1];
        }
    }
    address[lenght]='\0';
    address[lenght-1]='\0';
    char *tok=strtok(address,"/");
    while(tok!=NULL)
    {
        char *tok2=strtok(NULL,"/");
        if(tok2!= NULL)
        {
            strcat(path,tok);
            mkdir(path);
            strcat(path,"/");
        }
        else
            break;
        tok=tok2;
    }
    strcat(path,tok);
    FILE *f=fopen(path,"r");
    if(f==NULL)
    {
        FILE *f2=fopen(path, "w");
        fclose(f2);
        printf("File created\n");
    }
    else
    {
        printf("File existed\n");
        fclose(f);
    }
}

void cat(char filename[])
{
    char *newname=path(filename);
    FILE *fp=fopen(newname, "r");
    if(fp==NULL)
    {
        printf("File doesn't exist or is empty!\n");
    }
    else
    {
        while(!feof(fp))
        {
            int c=fgetc(fp);
            printf("%c", c);
        }
        printf("\n");
        fclose(fp);
    }
}

void insertstr(char *input)
{
    char *address1,*add,*pos;
    char *tok=strtok(input," ");
    address1=tok;
    if(*(address1+0)=='"')
    {
        tok=strtok(NULL," ");
        address1=strcat(address1,tok);
    }
    tok=strtok(NULL," ");
    if(strcmp(tok,"--str")!=0)
    {
        printf("Invalid command!\n");
    }
    tok=strtok(NULL," ");
    add=tok;
    if(*(add+0)=='"')
    {
        tok=strtok(NULL," ");
        char tok2[1]=" ";
        char *tokk=strcat(tok2,tok);
        add=strcat(add,tokk);
    }
    tok=strtok(NULL," ");
    if(strcmp(tok,"--pos")!=0)
    {
        printf("Invalid command!\n");
    }
    tok=strtok(NULL," ");
    pos=tok;
    int x=0;
    int line_num=0,char_num=0;
    while(*(pos+x)!=':')
    {
        line_num=line_num*10+(*(pos+x)-'0');
        x++;
    }
    x++;
    while(*(pos+x)!='\0')
    {
        char_num=char_num*10+(*(pos+x)-'0');
        x++;
    }
    int k=0;
    char *address=path(address1);
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
    }
    FILE *temp=fopen("temp.t", "w");
    for(int i=1; i<line_num; i++)
    {
        char c=fgetc(file);
        fputc(c,temp);
    }
    for(int j=0; j<char_num; j++)
    {
        char c=fgetc(file);
        fputc(c,temp);
    }
    int r=0,cot=0;
    while(*(add+r)!='\0')
    {
        if(*(add+r)=='"' && cot==0)
        {
            cot=1;
        }
        else if(*(add+r)=='"' && cot==1)
        {
            break;
        }
        else if((int)*(add+r)==92)
        {
            if(*(add+r+1)=='n')
                {
                    fputc('\n',temp);
                    r++;
                }
            else
                {
                    fputc(*(add+r),temp);
                    fputc(*(add+r+1),temp);
                    r++;
                }
        }
        else
            fputc(*(add+r),temp);
        r++;
    }
    char after;
    after=fgetc(file);
    while(after!=EOF)
    {
        fputc(after,temp);
        after=fgetc(file);
    }
    fclose(file);
    fclose(temp);
    file=fopen(input,"w");
    temp=fopen("temp.t","r");
    char text;
    text=fgetc(temp);
    while(text!=EOF)
    {
        fputc(text,file);
        text=fgetc(temp);
    }
    fclose(temp);
    fclose(file);
    remove("temp.t");
    printf("Text inserted successfully :)\n");
}
