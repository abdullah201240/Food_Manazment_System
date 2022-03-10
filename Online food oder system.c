#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void returnfunc(void);
void mainmenu(void);
void office(void);
void food(void);
void addrecord(void);
void deleterecord(void);
void searchrecord(void);
void viewrecord(void);
void Localfood(void);
void Fastfood(void);
void cancelorder(void);
void details(void);
void aboutus(void);


int getdata();

struct employee
{

    char name[30];
    int id;
    int dd;
    int mm;
    int yyyy;
    int YOJ;
    char place[20];
    float salary;
    char department[20];

    int quantity;
};
struct employee e;

FILE *fp,*ft,*dp,*dt;

int s;
char findrecord;
int again;
int quantity;
double total=0;
int t;
struct cancelorder
{
long long int phone;
char name1[20];
char name2[20];


char address[40];
};
struct cancelorder var;
FILE*cust,*fz;


int main()
{
    mainmenu();
    return 0;
}



void mainmenu(void)
{

    system("cls");



    printf("\n \n");
    printf("  \033[33m                                               WELCOME TO S&M ONLINE FOOD ORDER SYSTEM\n\033[0m");
    printf("                                 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");
    printf("  \033[31m        1. OFFICE SECTION  - \n\n          2. FOOD ORDER - \n\n          3. ABOUT US  - \n\n          4. Exit  - \n\n\n             Choice your option - \033[0m");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        office();
    }
    else if(choice==2)
    {
        food();
    }
    else if(choice==3)
    {
        aboutus();
    }
    else if(choice==4)
    {
        system("cls");
        printf("\n\n\n\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$ THANK YOU $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

        printf("ARE U  HUNGRY -_- ? Call or Walk-In S&M\n\n");
        exit(0);
    }
}

void office(void)
{

    system("cls");
    printf("\n \n");
    printf("    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ WELCOME TO EMPLOYEE SECTION $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("    ............................................................................................................\n\n");
    printf("          1. New Record\n\n          2. Search Record\n\n          3. Delete Record\n\n          4. View Records\n\n          5. Back To Main Menu \n\n             Enter Your Choice  -");
    int n;
    scanf("%d",&n);
    printf("\n\n");
    int wait;

    for(wait=0; wait<=100; wait++)
    {
        printf("\rLOADING : %d",wait/10);
    }
    printf("\n\n");
    if(n==1)
    {
        addrecord();
    }
    else if(n==2)
    {
        searchrecord();
    }
    else if(n==3)
    {
        deleterecord();
    }
    else if(n==4)
    {
        viewrecord();
    }

    else if(n==5)
    {
        system("cls");
        mainmenu();
    }
    else
    {
        printf(" PLease Enter The Correct Option");
        if(getch())
            office();
    }

}

void addrecord(void)
{
    system("cls");
    fp=fopen("record1.txt","a");
    if(getdata()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&e,sizeof(e),1,fp);
        fclose(fp);
        printf("\n\n");
        printf("The Record Is Successfully Saved ! !\n\n");
        printf("Save any more?(Y / N): ");
        if(getch()=='n')
            office();
        else
            system("cls");
        addrecord();
    }
}

void deleterecord(void)
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
        system("cls");
        printf("                Enter The Employee ID To Delete :");
        scanf(" %d",&d);
        fp=fopen("record1.txt","r+");
        rewind(fp);
        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(e.id==d)
            {
                printf("\n\n");
                printf("                              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ The Employee Record Is Available @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
                printf("               Employee Name Is %s\n\n",e.name);
                printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
                findrecord='t';
            }
        }
        if(findrecord!='t')
        {
            printf("                                    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ No record  found  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
            if(getch())
                office();
        }
        if(findrecord=='t' )
        {
            printf("Are You Want To Delete  Record ? (Y/N) ");
            if(getch()=='y')
            {
                ft=fopen("test1.txt","w");
                rewind(fp);
                while(fread(&e,sizeof(e),1,fp)==1)
                {
                    if(e.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&e,sizeof(e),1,ft);
                    }
                }
                fclose(ft);
                fclose(fp);
                remove("record1.txt");
                rename("test1.txt","record1.txt");
                fp=fopen("record1.txt","r");
                if(findrecord=='t')
                {
                    printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
                    printf("        Delete Another Record ? (Y/N) : ");
                }
            }
            else
                office();
            fflush(stdin);
            another=getch();
        }
    }
    office();
}

void searchrecord(void)
{
    system("cls");
    int d;
    printf("                    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Search Employees Record $$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("    ----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("                  1. Search By ID\n");
    printf("                  2. Search By Name\n\n");
    printf("                  Enter Your Choice - ");
    fp=fopen("record1.txt","r");
    rewind(fp);
    switch(getch())
    {
    case '1':
    {
        system("cls");
        printf("                                   $$$$$$$$$$$$$$$$$$$$$$$ Search Record By Id $$$$$$$$$$$$$$$$$$$$\n");
        printf("    ----------------------------------------------------------------------------------------------------------------------\n\n");
        printf("                Enter The Employee ID : ");
        scanf(" %d",&d);
        printf("\n\n");
         while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(e.id==d)
            {
                printf("\n\n");
                printf("                    #########################The Record is available############################\n");
                printf("    ............................................................................................................\n\n");
                printf("       ID : %d\n\n",e.id);
                printf("       Name : %s\n\n",e.name);
                printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
                printf("       Year Of Joining :%d\n\n",e.YOJ);
                printf("       Department :%s\n\n",e.department);
                printf("       Place :%s\n\n",e.place);
                findrecord='t';
            }

        }
        if(findrecord!='t')
        {
            printf("\aNo Record Found\a");
        }
        printf("Try Another Search ? (y/n)");
        if(getch()=='y')
            searchrecord();
        else
            office();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        printf("                     ######################### Search Employees By Name ####################\n");
        printf("    ............................................................................................................\n\n");
        printf("               Enter Employee Name : ");
        scanf(" %s",s);
        int d=0;
        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.name,(s))==0)
            {
                printf("                         ####################### The Record is available ###################\n\n\n");
                printf("    ............................................................................................................\n\n");
                printf("       ID : %d\n\n",e.id);
                printf("       Name : %s\n\n",e.name);
                printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
                printf("       Year Of Joining :%d\n\n",e.YOJ);
                printf("       Department :%s\n\n",e.department);
                printf("       Place :%s\n\n",e.place);
                d++;
            }

        }
        if(d==0)
        {
            printf("\aNo Record Found\a");
        }
        printf("Try Another Search ? (Y/N)");
        if(getch()=='y')
            searchrecord();
        else
            office();
        break;
    }
    default :
        getch();
        searchrecord();
    }
    fclose(fp);
}

void viewrecord(void)
{
    system("cls");
    printf("                          ####################### Employee Details ################################\n\n");
    printf("    ............................................................................................................\n\n");
    printf("                 DEPARTMENT        ID        EMPLOYEE NAME        D.O.B        Y.O.J        PLACE\n\n");

    fp=fopen("record1.txt","r");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
        printf("                 %s",e.department);
        printf("        %d",e.id);
        printf("        %s",e.name);
        printf("        %d/%d/%d",e.dd,e.mm,e.yyyy);
        printf("        %d",e.YOJ);
        printf("        %s",e.place);
        printf("\n\n");
    }

    fclose(fp);
    returnfunc();
}

void returnfunc(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
e:
    if(getch()==13)
        office();
    else
        goto e;
}

int checkid(int c)
{
    rewind(fp);
    while(fread(&e,sizeof(e),1,fp)==1)
        if(e.id==c)

            return 0;

    return 1;
}
int getdata()
{

    printf("        Employee ID :\t");
    scanf("%d",&t);
    if(checkid(t)==0)
    {
        printf("\n\n");
        printf("\a                        The Employee Record Already Exists !!!\a");
        getch();
        mainmenu();
        return 0;
    }
    e.id=t;
    printf("        Employee Name : ");

    scanf("%s",e.name);
    printf("        Date Of Birth (dd/mm/yyyy) :");
    scanf("%d/%d/%d",&e.dd,&e.mm,&e.yyyy);
    printf("        Year OF Joining :");
    scanf("%d",&e.YOJ);
    printf("        Place :");
    scanf("%s",e.place);
    printf("        Department :");
    scanf("%s",e.department);
    return 1;
}
void food(void)
{

    system("cls");
    printf("\n");
    printf("                                               WELCOME\n                           #################################################\n\n");
    printf("               YOU ARE - \n\n               1. Fast Food\n\n               2. Local Food\n\n               3. Cancel Order\n\n                OR\n\n               4. Back To Main Menu\n\n   Enter Your Choice  - ");
    int k;
    scanf("%d",&k);

    if(k==1)
    {
        system("cls");
        Fastfood();
    }
    else if(k==2)
    {
        system("cls");
        Localfood();
    }

    else if(k==3)
    {
        system("cls");
        cancelorder();
    }

    else if(k==4)
    {
        system("cls");
        mainmenu();
    }
    else
    {
        printf("Please Enter The Correct Option......\n\n");
        food();
    }
}
void  Fastfood(void)
{
    int choice;
    int again;
    int quantity;
    double price=0;
    printf("\n");
    printf("                                Fast Food    MENU\n                    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");

    char v;
    FILE *vmenu;

    vmenu=fopen("Fastfood.txt","rt");
    while((v=getc(vmenu))!=EOF)
    {
        printf("%c",v);
    }
    fclose(vmenu);
    printf("\n\n What Do You Want :");
    printf("\n\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Quantity :  ");
        scanf("%d",&quantity);
        total=total + 40*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        printf("\n");
        if(again==1)
        {
            printf("\n\n");
            Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==2)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 60*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
             Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==3)
    {
        printf("Quantity :  ");
        scanf("%d",&quantity);
        total=total + 45*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
             Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : TK. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==4)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 35*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
             Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : TK. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==5)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 150*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
             Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : TK. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }

    }
    else if(choice==6)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 80*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
             Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==7)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 45*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==8)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 100*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
             Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==9)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 35*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==10)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 25*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            Fastfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Tk. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==11)
    {
        system("cls");
        food();
    }
    else
    {
        printf("Please enter The Correct Option\n\n");
        if(getch())
        Fastfood();
    }
}
void Localfood(void)
{
    int choice;
    int again;
    int quantity;
    double price=0;
    printf("                                                   Local Food. Menu\n");
    printf("                                    ################################################\n");

    char n;
    FILE *nmenu;
    nmenu = fopen("localfood.txt","rt");
    while((n=getc(nmenu))!=EOF)
    {
        printf("%c",n);
    }
    printf("\n\n What Do You Want :");
    printf("\n\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Quantity : ");
        scanf(" %d",&quantity);
        total=total + 150*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk :%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==2)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 200*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==3)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 110*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==4)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 50*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk :%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==5)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 260*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==6)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 120*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==7)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 250*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==8)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 80*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==9)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 250*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            Localfood();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is Tk:%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("All_oder_list.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==10)
    {
        system("cls");
        food();
    }
    else
    {
        printf("Please Enter The Correct Option\n\n");
        Localfood();
    }
}


void details(void)
{


    printf("Please Give Your Details in below \n");
    printf(" First Name : ");
    scanf("%s",var.name1);
    printf("Last Name : ");
    scanf("%s",var.name2);
    printf("Phone : ");
    scanf("%lld",&var.phone);
    printf("Address : ");
    scanf("%s",var.address);
    printf("\n\n");
    printf("Your Entered Details Are --->\n");
    cust = fopen("All_oder_list.txt","a");
    fprintf(cust,"Order Placed By : %s %s\nAddress :%s\nPhone number : %lld\n",var.name1,var.name2,var.address,var.phone);
    fclose(cust);
    printf("    - First Name :  %s\n    - Last Name   :  %s\n    - Phone     :%lld \n    - >Address  :%s \n",var.name1,var.name2,var.phone,var.address);
    printf("\n\n\n");
    printf("                                             Your Order Will Be At Your home In max 1 hour.\n");
    printf("                                                       -_- HAPPY ORDERING -_- \n");
    printf("                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Press Any KEY to go Main menu.");
    if(getch())
        food();

}
 void cancelorder(void)
{
    system("cls");
    printf("If you want to cancel your order Please call:017******** within 20 minutes. \n \n \n");
        printf("Press Any KEY to go Main menu.");
    if(getch())
        food();

}

void aboutus(void)
{
    system("cls");
    printf(" PROJECT ARE CREATED BY  :\n\n Abdullah Al Sakib\n\n");
    printf("   Any Key To Go Back.");
    if(getch())
        mainmenu();
}
