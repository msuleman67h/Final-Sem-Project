#include<stdio.h>
void addgoods(int a,int b[100],int c[100],char d[100],char f[100][100])
{
    int i,e;
    int confirm = 1;
    printf("					Add Articles\n\n\n");
    do
    {
        system("cls");
        printf("Enter new code for the article:\n");
        scanf("%d",&a);

        printf("Enter the rate of the item:\n");
        scanf("%d",&b[a]);

        printf("Enter the quantity of the item:\n");
        scanf("%d",&c[a]);

        printf("Enter the name of the item:\n");
        scanf("%s,%s",&d[a],f[a]);

        printf("Enter new record(0=NO/1=YES)");
        scanf("%d",&e);

        printf("Do you want to add another item? (0=NO/1=YES)");
        scanf("%d",&confirm);
    }
    while(confirm == 1);
}

void editgoods(int b[100],int c[100],char d[100],char e[100][100])
{
    printf("					Edit Articles\n\n\n");

    int l;
    system("cls");

    printf("Enter the ID of the good you wish to edit:\n");
    scanf("%d",&l);

    if(b[l]>0)
    {
        printf("Enter the changed rate of the item:\n");
        scanf("%d",&b[l]);

        printf("Enter the quantity of the item:\n");
        scanf("%d",&c[l]);

        printf("Enter the name of the item:\n");
        scanf("%s,%s",&d[l],&e[l]);
    }
    else
    {
        printf("This ID does not exist\n");
    }
}

void search(int b[100],int c[100],char d[100][100])
{
    printf("					Search Articles\n\n\n");
    int n;
    system("cls");
    printf("Enter the id of the good you wish to search:\n");
    scanf("%d",&n);

    if(b[n]>0)
    {
        printf("The rate of the item is:%d\n",b[n]);

        printf("The quantity of the item is:%d\n",c[n]);

        printf("The name of the item is:%s\n",d[n]);
    }
    else
    {
        printf("No good exists at this entered ID\n");
    }
}

void displayall(int b[100],int c[100],char d[100][100])
{
    int i;
    system("cls");
    printf("					Displayed Goods\n");

    printf("ID\tItem name\t\tQuantity\t\tRate\n");

    for(i=0; i<25; i++)
    {
        if(b[i]!=0)
        {
            printf("%d\t%s\t\t\t%d\t\t\t%d\n",i,d[i],c[i],b[i]);
        }
        else
        {
            printf("										\n");
        }
    }
}

void deletedgoods(int a,int b[100])
{
    system("cls");
    printf("Enter the ID of the good you wish to delete:\n");
    scanf("%d",&a);

    b[a]=0;
}

void billc(int b[100],char d[100][100])
{
    system("cls");
    printf("					Bill Calculation\n\n\n");
    int n,tb=0,i,l,q,total;

    printf("How many types of goods you wish to buy?:\n");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        printf("Enter the ID of the good you wish to buy:\n");
        scanf("%d",&l);

        if(b[l]>0)
        {
            printf("Enter its quantity too:\n");
            scanf("%d",&q);

            tb+=q*b[l];

            total=q*b[l];
            printf("\t\t\t\t\tCUSTOMER'S BILL\n");

            printf("ID\tItem name\tQuantity\t\t\t\tRate\t\tTotal\n");
            printf("%d\t%s\t\t%d\t\t\t\t\t%d\t\t%d\n",l,d[l],q,b[l],total);
            printf("Your total bill is RS%d\n",tb);
        }
        else
        {
            printf("Nothing exists at this ID\n");
        }
    }
}
int main()
{
    int id,quantity[100]= {12,10,40,4,32,10,20,20,10,5},rate[100]= {80,20,30,300,80,20,100,20,120,150};
    char name[100][100]= {"BIRYANI","COKE","JUICE","PIZZA","APPLE","TISSUE BOX","MINERAL WATER","SOAP","REGISTER","BURGER"},fake[100];
    int i,n,m,label1,label2,label3,label4,label5,label6;
label1:
label2:
label3:
label4:
label5:
label6:

    printf("Do you wish to exit?(0=N0/1=YES):\n");
    scanf("%d",&m);

    while(m==0)
    {
        system("cls");
        printf("\t\t\t************* *UET LAHORE* ****************\n				  Departmental Store\n\n\n					Main Menu\n\n\n");

        printf("Enter 1 to calculate the bill\nEnter 2 to add goods\nEnter 3 to edit goods\nEnter 4 to display all the goods\nEnter 5 to search for any good\nEnter 6 to delete any good\nEnter 7 to exit\n");
        scanf("%d",&n);

        switch(n)
        {

        case 1:
            billc(rate,name);
            goto label1;
            break;

        case 2:
            addgoods(id,rate,quantity,fake,name);
            goto label2;
            break;

        case 3:
            editgoods(rate,quantity,fake,name);
            goto label3;
            break;

        case 4:
            displayall(rate,quantity,name);
            goto label4;
            break;

        case 5:
            search(rate,quantity,name);
            goto label5;
            break;

        case 6:
            deletedgoods(id,rate);
            goto label6;
            break;

        case 7:
            return 0;

        default:
            printf("Invalid input\n");
        }
    }
}
