#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dir.h>


//Prototypes
char *path(char *);
int check_function(char *);
int check(char [], char[], int );
void change_file(char *);
void create_file(char *);
int cat(char *);
int insertstr(char *);
int removestr(char *, int);
int remove_b(char * ,int ,int ,int );
int remove_f(char * ,int ,int ,int );
int copy(char *,int );
int cut(char *);
int paste(char *);
int clipboard_f(char *,int ,int ,int );
int clipboard_b(char *, int ,int ,int );
void undo_file(char *);
int undo(char *);

int main()
{
    while(1)
    {
        char command[1000];
        scanf("%s",command);
        getchar();
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
    if(check(command,"createfile",10))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!='\n')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        create_file(input);
        return 1;
    }
    else if(check(command,"insertstr",9))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!=' ')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        insertstr(input);
        return 1;
    }
    else if (check(command,"cat",3))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!='\n')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        cat(input);
        return 1;
    }
    else if(check(command,"removestr",9))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!=' ')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        removestr(input,1);
        return 1;
    }
    else if(check(command,"copystr",7))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!=' ')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        copy(input,1);
        return 1;
    }
    else if(check(command,"cutstr",6))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!=' ')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        cut(input);
        return 1;
    }
    else if(check(command,"pastestr",8))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!=' ')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        paste(input);
        return 1;
    }
    else if(check(command,"undo",4))
    {
        char file[10];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            printf("Invalid command\n");
            return 1;
        }
        char a1;
        char input[100];
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input[l]=a1;
                a1=getchar();
                l++;
            }
            input[l]='\0';
        }
        else
        {
            input[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!='\n')
            {
                input[u]=a1;
                a1=getchar();
                u++;
            }
            input[u]='\0';
        }
        undo(input);
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

void change_file(char *address)
{
    FILE *file=fopen(address,"w");
    FILE *temp=fopen("temp.t","r");
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
}

void create_file(char *address)
{
    char path[1000];
    path[0]=0;
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

int cat(char filename[])
{
    char *newname=path(filename);
    FILE *fp=fopen(newname, "r");
    if(fp==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
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
        return 1;
    }
}

int insertstr(char *input)
{
    char *address=path(input);
    undo_file(address);
    char str[10];
    scanf("%s",str);
    if(strcmp(str,"--str")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    getchar();
    char add1=getchar();
    char add[100];
    if(add1=='"')
    {
        int l=0;
        add1=getchar();
        while(add1!='"')
        {
            add[l]=add1;
            add1=getchar();
            l++;
        }
        add[l]='\0';
    }
    else
    {
        add[0]=add1;
        int u=1;
        add1=getchar();
        while (add1!=' ')
        {
            add[u]=add1;
            add1=getchar();
            u++;
        }
        add[u]='\0';
    }
    char pos[10];
    scanf("%s",pos);
    getchar();
    if(strcmp(pos,"--pos")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int line_num,char_num;
    scanf("%d:%d", &line_num, &char_num);
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    FILE *temp=fopen("temp.t", "w");
    for(int i=1; i<line_num; i++)
    {
        char str[1000];
        fgets(str,1000,file);
        fputs(str,temp);
    }
    for(int j=0; j<char_num; j++)
    {
        char c=fgetc(file);
        fputc(c,temp);
    }
    int r=0,cot=0;
    while(add[r]!='\0')
    {
        if(add[r]=='"' && cot==0)
        {
            cot=1;
        }
        else if(*(add+r)=='"' && cot==1)
        {
            break;
        }
        else if((int)add[r]==92)
        {
            if(add[r+1]=='n')
                {
                    fputc('\n',temp);
                    r++;
                }
            else
                {
                    fputc(add[r],temp);
                    fputc(add[r+1],temp);
                    r++;
                }
        }
        else
            fputc(add[r],temp);
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
    change_file(address);
    printf("Text inserted successfully :)\n");
    return 1;
}

int removestr(char *input,int flag)
{
    char *address=path(input);
    undo_file(address);
    char pos[10];
    scanf("%s",pos);
    getchar();
    if(strcmp(pos,"--pos")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int line_num,char_num;
    scanf("%d:%d", &line_num, &char_num);
    getchar();
    char size1[10];
    scanf("%s",size1);
    getchar();
    if(strcmp(size1,"-size")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int size_num;
    scanf("%d", &size_num);
    getchar();
    char move[3];
    scanf("%s",move);
    if(strcmp(move,"-b")==0)
    {
        remove_b(address,line_num,char_num,size_num);
    }
    else if(strcmp(move,"-f")==0)
    {
        remove_f(address,line_num,char_num,size_num);
    }
    else
    {
        printf("Invalid command!\n");
        return 0;
    }
    if(flag==1)
        printf("Text was deleted^^\n");
    return 1;
}

int remove_b(char *address,int line_num, int char_num, int size_num)
{
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    char str[1000];
    char *string1=(char*) calloc(1000,sizeof(char));
    for(int i=1; i<line_num; i++)
    {
        fgets(str,1000,file);
        string1=str;
    }
    int lenght1=strlen(string1);
    char string2[1000];
    int j;
    for(j=0; j<char_num; j++)
    {
        string2[j]=fgetc(file);
    }
    int lenght=lenght1+j;
    int num=lenght-size_num;
    fclose(file);
    file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    FILE *temp=fopen("temp.t", "w");
    for(int i=0; i<num; i++)
    {
        char c=fgetc(file);
        fputc(c,temp);
    }
    for(int j=0; j<size_num || feof(stdin); j++)
    {
        fgetc(file);
    }
    char after=fgetc(file);
    while(after!=EOF)
    {
        fputc(after,temp);
        after=fgetc(file);
    }
    fclose(file);
    fclose(temp);
    change_file(address);
    return 0;
}

int remove_f(char *address ,int line_num ,int char_num ,int size_num)
{
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    FILE *temp=fopen("temp.t", "w");
    for(int i=1; i<line_num; i++)
    {
        char str[1000];
        fgets(str,1000,file);
        fputs(str,temp);
    }
    for(int j=0; j<char_num; j++)
    {
        char c=fgetc(file);
        fputc(c,temp);
    }
    for(int r=0; r<size_num || feof(stdin); r++)
    {
        fgetc(file);
    }
    char after=fgetc(file);
    while(after!=EOF)
    {
        fputc(after,temp);
        after=fgetc(file);
    }
    fclose(file);
    fclose(temp);
    change_file(address);
    return 0;
}

int copy(char *input, int flag)
{
    char *address=path(input);
    char pos[10];
    scanf("%s",pos);
    getchar();
    if(strcmp(pos,"--pos")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int line_num,char_num;
    scanf("%d:%d", &line_num, &char_num);
    getchar();
    char size1[10];
    scanf("%s",size1);
    getchar();
    if(strcmp(size1,"-size")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int size_num;
    scanf("%d", &size_num);
    getchar();
    char move[3];
    scanf("%s",move);
    if(strcmp(move,"-f")==0)
    {
        clipboard_f(address,line_num,char_num,size_num);
    }
    else if(strcmp(move,"-b")==0)
    {
        clipboard_b(address,line_num,char_num,size_num);
    }
    else
    {
        printf("Invalid command!\n");
        return 0;
    }
    if(flag==1)
        printf("Text was copied *-*\n");
    return 1;
}

int cut(char *input)
{
    char *address=path(input);
    undo_file(address);
    char pos[10];
    scanf("%s",pos);
    getchar();
    if(strcmp(pos,"--pos")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int line_num,char_num;
    scanf("%d:%d", &line_num, &char_num);
    getchar();
    char size1[10];
    scanf("%s",size1);
    getchar();
    if(strcmp(size1,"-size")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int size_num;
    scanf("%d", &size_num);
    getchar();
    char move[3];
    scanf("%s",move);
    if(strcmp(move,"-f")==0)
    {
        clipboard_f(address,line_num,char_num,size_num);
        remove_f(address,line_num,char_num,size_num);
    }
    else if(strcmp(move,"-b")==0)
    {
        clipboard_b(address,line_num,char_num,size_num);
        remove_b(address,line_num,char_num,size_num);
    }
    else
    {
        printf("Invalid command!\n");
        return 0;
    }
    printf("Text was cuted!\n");
    return 0;
}

int paste(char *input)
{
    char *address=path(input);
    undo_file(address);
    char pos[10];
    scanf("%s",pos);
    getchar();
    if(strcmp(pos,"--pos")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    int line_num,char_num;
    scanf("%d:%d", &line_num, &char_num);
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    FILE *temp=fopen("temp.t", "w");
    for(int i=1; i<line_num; i++)
    {
        char str[1000];
        fgets(str,1000,file);
        fputs(str,temp);
    }
    for(int j=0; j<char_num; j++)
    {
        char c=fgetc(file);
        fputc(c,temp);
    }
    FILE *clipb=fopen("clipboard.txt", "r");
    char clip;
    clip=fgetc(clipb);
    while(clip!=EOF)
    {
        fputc(clip,temp);
        clip=fgetc(clipb);
    }
    char after;
    after=fgetc(file);
    while(after!=EOF)
    {
        fputc(after,temp);
        after=fgetc(file);
    }
    fclose(file);
    fclose(clipb);
    fclose(temp);
    change_file(address);
    printf("Text was pasted =)\n");
    return 0;
}

int clipboard_f(char *address, int line_num, int char_num, int size_num)
{
        FILE *file=fopen(address,"r");
        FILE *clipb=fopen("clipboard.txt","w");
        if(file==NULL)
        {
            printf("File doesn't exist\n");
            return 0;
        }
        for(int i=1; i<line_num; i++)
        {
            char str[1000];
            fgets(str,1000,file);
        }
        for(int j=0; j<char_num; j++)
        {
            fgetc(file);
        }
        for(int r=0; r<size_num || feof(stdin); r++)
        {
            char clip=fgetc(file);
            fputc(clip,clipb);
        }
        fclose(file);
        fclose(clipb);
        return 0;
}

int clipboard_b(char *address, int line_num, int char_num, int size_num)
{
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    char str[1000];
    char *string1=(char*) calloc(1000,sizeof(char));
    for(int i=1; i<line_num; i++)
    {
        fgets(str,1000,file);
        string1=str;
    }
    int lenght1=strlen(string1);
    char string2[1000];
    int j;
    for(j=0; j<char_num; j++)
    {
        string2[j]=fgetc(file);
    }
    int lenght=lenght1+j;
    int num=lenght-size_num;
    fclose(file);
    file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    FILE *clipb=fopen("clipboard.t", "w");
    for(int i=0; i<num; i++)
    {
        fgetc(file);
    }
    for(int j=0; j<size_num || feof(stdin); j++)
    {
        char clip=fgetc(file);
        fputc(clip,clipb);
    }
    fclose(file);
    fclose(clipb);
    return 0;
}

void undo_file(char *address)
{
    FILE *file=fopen(address,"r");
    FILE *un_file=fopen("undo.txt","w");
    char chr=fgetc(file);
    while(chr!=EOF)
    {
        fputc(chr,un_file);
        chr=fgetc(file);
    }
    fclose(file);
    fclose(un_file);
}

int undo(char *input)
{
    char *address=path(input);
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    fclose(file);
    file=fopen(address,"w");
    FILE *un_file=fopen("undo.txt","r");
    char chr=fgetc(un_file);
    while(chr!=EOF)
    {
        fputc(chr,file);
        chr=fgetc(un_file);
    }
    fclose(file);
    fclose(un_file);
    printf("Undo successfully!\n");
    return 0;
}
