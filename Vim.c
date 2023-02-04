#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dir.h>
#include <dirent.h>
#include <windows.h>
#include <unistd.h>
#include <ctype.h>


//Prototypes
char *path(char *);
int check_function(char *);
long line_counter(char *,int );
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
int find(char *);
void auto_indent(char *);
void compare(char *, char *);
void tree(char *, int ,int );

int main()
{
    printf("Welcome ^^\nPlease write your command:\n");
    while(1)
    {
        char command[20];
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
    if(!strcmp(command,"createfile"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"insertstr"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if (!strcmp(command,"cat"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"removestr"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"copystr"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"cutstr"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"pastestr"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"undo"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
    else if(!strcmp(command,"tree"))
    {
        int depth;
        scanf("%d", &depth);
        printf("Your tree with depth %d:\n", depth);
        tree("./root",0,depth);
        return 1;
    }
    else if(!strcmp(command,"auto-indent"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
        auto_indent(input);
        return 1;
    }
    else if(!strcmp(command,"compare"))
    {
        char input1[100],input2[100];
        char a1,a2;
        a1=getchar();
        if(a1=='"')
        {
            int l=0;
            a1=getchar();
            while(a1!='"')
            {
                input1[l]=a1;
                a1=getchar();
                l++;
            }
            input1[l]='\0';
        }
        else
        {
            input1[0]=a1;
            int u=1;
            a1=getchar();
            while (a1!=' ')
            {
                input1[u]=a1;
                a1=getchar();
                u++;
            }
            input1[u]='\0';
        }
        a2=getchar();
        if(a2=='"')
        {
            int l=0;
            a2=getchar();
            while(a2!='"')
            {
                input2[l]=a2;
                a2=getchar();
                l++;
            }
            input2[l]='\0';
        }
        else
        {
            input2[0]=a2;
            int u=1;
            a2=getchar();
            while (a2!='\n')
            {
                input2[u]=a2;
                a2=getchar();
                u++;
            }
            input2[u]='\0';
        }
        compare(input1,input2);
        return 1;
    }
    else if (!strcmp(command,"find"))
    {
        char file[7];
        scanf("%s",file);
        getchar();
        if(strcmp(file,"--file")!=0)
        {
            return -1;
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
        find(input);
        return 1;
    }
    else if(!strcmp(command,"exit"))
        return 0;
    else
        return -1;
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
    FILE *temp=fopen("temp.txt","r");
    char text;
    text=fgetc(temp);
    while(text!=EOF)
    {
        fputc(text,file);
        text=fgetc(temp);
    }
    fclose(temp);
    fclose(file);
    remove("temp.txt");
}

long line_counter(char *address,int num)
{
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File%d doesn't exist\n",num);
        return -1;
    }
    long line=0;
    char c=fgetc(file);
    while(c!=EOF)
    {
        if(c=='\n')
        {
            line++;
        }
        c=fgetc(file);
    }
    fclose(file);
    return line;
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
    FILE *temp=fopen("temp.txt", "w");
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
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    fclose(file);
    int result;
    if(strcmp(move,"-b")==0)
    {
        result=remove_b(address,line_num,char_num,size_num);
        if(result==0)
        {
            return 0;
        }
    }
    else if(strcmp(move,"-f")==0)
    {
        result=remove_f(address,line_num,char_num,size_num);
        if(result==0)
        {
            return 0;
        }
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
    FILE *temp=fopen("temp.txt", "w");
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
    return 1;
}

int remove_f(char *address ,int line_num ,int char_num ,int size_num)
{
    FILE *file=fopen(address,"r");
    FILE *temp=fopen("temp.txt", "w");
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
    return 1;
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
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    fclose(file);
    int result;
    if(strcmp(move,"-f")==0)
    {
        result=clipboard_f(address,line_num,char_num,size_num);
        if(result==0)
        {
            return 0;
        }
    }
    else if(strcmp(move,"-b")==0)
    {
        result=clipboard_b(address,line_num,char_num,size_num);
        if(result==0)
        {
            return 0;
        }
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
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return 0;
    }
    fclose(file);
    int result_c,result_r;
    if(strcmp(move,"-f")==0)
    {
        result_c=clipboard_f(address,line_num,char_num,size_num);
        result_r=remove_f(address,line_num,char_num,size_num);
        if(result_c==0 || result_r==0)
        {
            return 0;
        }
    }
    else if(strcmp(move,"-b")==0)
    {
        result_c=clipboard_b(address,line_num,char_num,size_num);
        result_r=remove_b(address,line_num,char_num,size_num);
        if(result_c==0 || result_r==0)
        {
            return 0;
        }
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
    FILE *temp=fopen("temp.txt", "w");
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
    FILE *clipb=fopen("clipboard.t", "r");
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
    FILE *clipb=fopen("clipboard.t","w");
    wchar_t* fileLPCWSTR = "clipboard.t";
    int attr = GetFileAttributes(fileLPCWSTR);
    if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0)
    {
       SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
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
    return 1;
}

int clipboard_b(char *address, int line_num, int char_num, int size_num)
{
    FILE *file=fopen(address,"r");
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
    FILE *clipb=fopen("clipboard.t", "w");
    wchar_t* fileLPCWSTR = "clipboard.t";
    int attr = GetFileAttributes(fileLPCWSTR);
    if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0)
    {
       SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
    }
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
    return 1;
}

void undo_file(char *address)
{
    FILE *file=fopen(address,"r");
    FILE *un_file=fopen("undo.t","w");
    wchar_t* fileLPCWSTR = "undo.t";
    int attr = GetFileAttributes(fileLPCWSTR);
    if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0)
    {
       SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
    }
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
    FILE *un_file=fopen("undo.t","r");
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

int find(char *input)
{
    int wildcard=0;
    char *address=path(input);
    char str[6];
    scanf("%s",str);
    if(strcmp(str,"--str")!=0)
    {
        printf("Invalid command!\n");
        return 0;
    }
    getchar();
    char f_chr=getchar();
    char find_chr[100];
    char correct_find_chr[100];
    int l=0;
    if(f_chr=='"')
    {
        f_chr=getchar();
        while(f_chr!='"')
        {
            find_chr[l]=f_chr;
            f_chr=getchar();
            l++;
        }
        find_chr[l]='\0';
    }
    else
    {
        find_chr[l]=f_chr;
        f_chr=getchar();
        l++;
        while (f_chr!='\n')
        {
            find_chr[l]=f_chr;
            f_chr=getchar();
            l++;
        }
        find_chr[l]='\0';
    }
    int len=strlen(find_chr);
    if(find_chr[len-1]=='*')
    {
        if(find_chr[len-2]=='\\')
        {
            strncpy(correct_find_chr,find_chr,len-2);
            strcat(correct_find_chr,"*");
        }
        else
        {
            strncpy(correct_find_chr,find_chr,len-1);
            wildcard=2;
        }
    }
    else if(find_chr[0]=='*')
    {
        for(int i=0;i<len-1;i++)
        {
            correct_find_chr[i]=find_chr[i+1];
        }
        wildcard=1;
    }
    else
    {
        strcpy(correct_find_chr,find_chr);
    }
    int len_correct=strlen(correct_find_chr);
    FILE *file=fopen(address,"r");
    char strtext[200];
    char fulltext[2000];
    while(!feof(file))
    {
        fgets(strtext,200,file);
        strcat(fulltext,strtext);
    }
    if(strstr(fulltext,correct_find_chr))
    {
        int pointer=0;
        for(int i=0;i<strlen(fulltext);i++)
        {
            if(fulltext[i]==correct_find_chr[0])
            {
                pointer=1;
                for(int j=1; j<len_correct;j++)
                {
                    if(fulltext[i+j]==correct_find_chr[j])
                    {
                        pointer++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(pointer==len_correct)
                {
                    pointer=i;
                    if(wildcard==1)
                    {
                        while(fulltext[pointer]!=' ')
                        {
                            pointer--;
                            if(pointer<0)
                            {
                                break;
                            }
                        }
                        pointer++;
                    }
                    else if(wildcard==2)
                    {
                        pointer--;
                        if(pointer<0)
                        {
                            pointer=0;
                            printf("The first occurrence index is: %d\n",pointer);
                            fclose(file);
                            return 0;
                        }
                        if(fulltext[pointer]!=' ')
                        {
                            continue;
                        }
                        pointer++;
                    }
                    printf("The first occurrence index is: %d\n",pointer);
                    fclose(file);
                    return 0;
                }
            }
        }
        printf("No item found.");
        fclose(file);
        return -1;
    }
    else
    {
        printf("No item found.");
        fclose(file);
        return -1;
    }
    fclose(file);
    return 0;
}

void tree(char *base_path ,int round ,int depth)
{
    DIR *dir;
    struct dirent *my_dir;
    if (depth==-1)
    {
        if (!(dir=opendir(base_path)))
        return;
    }
    else if (depth>=-1)
    {
        if (!(dir = opendir(base_path)) || round>=2*depth)
            return;
    }
    else
    {
        printf("Invalid depth :(\n");
        return;
    }
    while ((my_dir=readdir(dir))!=NULL)
    {
        char path[512];
        if (strcmp(my_dir->d_name, ".") == 0 || strcmp(my_dir->d_name, "..") == 0)
            continue;
        snprintf(path, sizeof(path), "%s/%s", base_path, my_dir->d_name);
        printf("|-%*s'%s'\n", round,"",my_dir->d_name);
        tree(path,round+2,depth);
    }
    closedir(dir);
}

void auto_indent(char *input)
{
    char *address=path(input);
    FILE *file=fopen(address,"r");
    if(file==NULL)
    {
        printf("File doesn't exist\n");
        return;
    }
    undo_file(address);
    FILE *temp=fopen("temp.txt","w");
    char chr=fgetc(file);
    long len=0;
    int counter=0,flag=0,last_enter=0;
    char last_char;
    while(chr!=EOF)
    {
        if(chr==' ')
        {
            if(flag==1)
            {
                fputc(chr,temp);
                last_char=' ';
            }
            flag=0;
            chr=fgetc(file);
            if(chr==' ')
            {
                while(chr==' ')
                {
                    chr=fgetc(file);
                }
            }
            else
            {
                if(chr!='{')
                {
                    last_char=chr;
                    flag=1;
                }
                else
                    continue;
            }
        }
        if(chr=='{')
        {
            if(last_char!=' ' && flag==1)
            {
                fputc(' ',temp);
            }
            for(int i=0; i<counter; i++)
            {
                fputc(' ',temp);
            }
            fputc('{',temp);
            fputc('\n',temp);
            counter+=4;
            last_char='{';
            flag=0;
        }
        if(chr=='}')
        {
            if(last_char!='}')
                fputc('\n',temp);
            counter-=4;
            if(counter<0)
            {
                counter=0;
            }
            for(int i=0; i<counter; i++)
            {
                fputc(' ',temp);
            }
            fputc('}',temp);
            fputc('\n',temp);
            last_char='}';
            last_enter=1;
            flag=0;
        }
        else
        {
            if(chr!='{' && chr!='\n')
                fputc(chr,temp);
            if(chr=='{')
                flag=0;
            if(chr=='\n')
            {
                if(last_enter==0)
                {
                    fputc('\n',temp);
                }
                flag=0;

            }
            else
            {
                flag=1;
            }
            last_char=chr;
            last_enter=0;
        }
        chr=fgetc(file);
    }
    fclose(file);
    fclose(temp);
    change_file(address);
    printf("Done!\n");
    return;

}

void compare(char *input1, char *input2)
{
    char *address1=path(input1);
    char *address2=path(input2);
    long line1,line2,line_number=0;
    char str1[1000],str2[1000];
    char *string1=(char*) calloc(1000,sizeof(char));
    char *string2=(char*) calloc(1000,sizeof(char));
    line1=line_counter(address1,1);
    line2=line_counter(address2,2);
    if(line1==-1 || line2==-1)
    {
        return;
    }
    FILE *file1=fopen(address1,"r");
    FILE *file2=fopen(address2,"r");
    while(line_number<=line1 && line_number<=line2)
    {
        fgets(str1,1000,file1);
        string1=str1;
        fgets(str2,1000,file2);
        string2=str2;
        line_number++;
        if(strcmp(string1,string2)!=0)
        {
            printf("============ #%d ============\n",line_number);
            printf("%s\n%s\n",string1,string2);
            break;
        }
    }
    if(line_number>line1 && line_number<=line2)
    {
        printf("\nFile2 is longer\n");
        printf(">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n",line_number,line2);
        for(int i=line_number-1; i<=line2; i++)
        {
            fgets(str2,1000,file2);
            string2=str2;
            printf("%s\n", string2);
        }
    }
    else if(line_number>line2 && line_number<=line1)
    {
        printf("\nFile1 is longer\n");
        printf(">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n",line_number,line1);
        for(int i=line_number-1; i<=line2; i++)
        {
            fgets(str1,1000,file1);
            string1=str1;
            printf("%s\n", string1);
        }
    }
    fclose(file1);
    fclose(file2);
    printf("compared-.-\n");
    return 1;
}
