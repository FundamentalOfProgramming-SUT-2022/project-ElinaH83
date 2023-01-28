#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dir.h>


//Prototypes
int check_function(char *);
int check(char [], char[], int );
void create_file(char *,int );
void cat(char *);

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
    /*if(check(command,"insertstr --file ",17))
    {
    }*/
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
    if(filename[0]=='"')
    {
        int i;
        for(i=0; filename[i]!='\0'; i++)
        {
            filename[i]=filename[i+1];
        }
        filename[i]='\0';
        filename[i-2]='\0';
    }
    if(filename[0]=='/')
    {
        int i;
        for(i=0; filename[i]!='\0'; i++)
        {
            filename[i]=filename[i+1];
        }
        filename[i]='\0';
    }
    FILE *fp=fopen(filename, "r");
    if(fp==NULL)
    {
        printf("File doesn't exist or is empty!");
    }
    else
    {
        while(!feof(fp))
        {
            int c=fgetc(fp);
            printf("%c", c);
        }
        fclose(fp);
    }
}
