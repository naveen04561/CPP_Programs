#include<stdio.h>
#include<stdlib.h>

int c,i,id;
char name[20];
FILE *fp;
int n;

long curr_pos;

struct details
{
    int id;
    char name[20];
};

details d;

int search(FILE *fp,int id)
{
    rewind(fp);
    curr_pos = ftell(fp);
    while(fread(&d,sizeof(d),1,fp))
    {
        if(id==d.id) {return 1;}

        curr_pos = ftell(fp);
    }
    return 0;
}

void display(FILE *fp)
{
    rewind(fp);
    while(fread(&d,sizeof(d),1,fp))
    {
        printf("\n%d\t%s",d.id,d.name);
    }
}


int main()
{
    printf("\nHow many records you would like to insert ? : "); fflush(stdout);

    scanf("%d",&n);
    fp=fopen("one.txt","a");
    for(i=0;i<n;i++)
    {
        printf("\nEnter id and name"); fflush(stdout);
        scanf("%d%s",&d.id,d.name);
        fwrite(&d,sizeof(d),1,fp);
    }
    fclose(fp);

    while(1)
    {
        printf("\nWhat would you like to do now ? : \n");
        printf("\n1.Display \t2.Search \t3.Modify \t4.Delete \t5.Exit\n");
        fflush(stdout);

        scanf("%d",&c);
        switch(c)
        {
            case 1:
                fp=fopen("one.txt","r+");
                display(fp);
                fclose(fp);
                break;
            case 2:
                fp=fopen("one.txt","r+");
                printf("\nEnter ID to search : "); fflush(stdout);
                scanf("%d",&id);
                if(search(fp,id))
                {
                    printf("\nThe record is as follows : ");
                    printf("\n%d\t%s",d.id,d.name); fflush(stdout);
                }
                else
                    printf("\nRecord not found");
                fclose(fp);
                break;
            case 3:
                fp=fopen("one.txt","r+");
                printf("\nEnter ID to modify d record : "); fflush(stdout);
                scanf("%d",&id);

                if(search(fp,id))
                {
                    printf("\nEnter new name : "); fflush(stdout);
                    scanf("%s",d.name);

                    // back-up one record, to get to start of current record
                    fseek(fp, curr_pos, 0);
                    fwrite(&d,sizeof(d),1,fp);
                }
                else
                    printf("\nSpecified record not found ");
                fclose(fp);
                break;
        }
    }
}
