#include<stdio.h>
#include<string.h>

FILE *fp;

struct cust
{
  char a_name[25];
  int a_bal,a_no;
};
typedef struct cust cus;

//searching
char search(int an)
{
  cus a;
  fp=fopen("banking.txt","rb");
  while(fread(&a,sizeof(a),1,fp))
  {
    if(a.a_no==an)
    {
      return 'y';
    }
  }
  return 'n';
  fclose(fp);
  }

//deposit
void deposit(int amount,int an)
{
  cus a;
  fp=fopen("banking.txt","rb+");
  while(fread(&a,sizeof(a),1,fp))
  {
    if (a.a_no==an)
    {
      a.a_bal+=amount;
      fseek(fp,-sizeof(a),SEEK_CUR);
      fwrite(&a,sizeof(a),1,fp);
      fflush(stdin);
      printf("_____________________________________________________________________________");
      printf("\n\t\t\tyour current balance is : %d",a.a_bal);
      break;
    }
  }
  fclose(fp);
}

//withdraw
void withdraw(int amount,int an)
{
  cus a;
  fp=fopen("banking.txt","rb+");
  while(fread(&a,sizeof(a),1,fp))
  {
    if (a.a_no==an)
    {
      a.a_bal-=amount;
      fseek(fp,-sizeof(a),SEEK_CUR);
      fwrite(&a,sizeof(a),1,fp);
      fflush(stdin);
      printf("__________________________________________________________________________");
      printf("\n\t\t\tyour current balance is : %d",a.a_bal);
      break;
    }
  }
fclose(fp);
}

//old custumer
void old(int an)
{
 cus a;
 int ch=0,amount=0;

 fp=fopen("banking.txt","rb");
 while(fread(&a,sizeof(a),1,fp))
 {
   if(a.a_no==an)
   {
    printf("\n\t\twelcom %s",a.a_name);
    printf("\n\t1.Deposit\n\t2.Withdraw\n\t3.view balance");
    printf("\nenter you choice: ");
    scanf("%d",&ch);
    fclose(fp);
    switch(ch)
    {
      case 1:
      {
        printf("===============================================================================");
        printf("\nenter amount to deposit: ");
        scanf("%d",&amount);
        deposit(amount,an);
        break;
      }
      case 2:
      {
        printf("===============================================================================");
        printf("\nenter amount to withdraw: ");
        scanf("%d",&amount);
        if(amount<=a.a_bal)
        {
          withdraw(amount,an);
        }
        else
        {
          printf("_______________________________________________________________________________");
          printf("\n\t\t\tINSUFFICIENT BALANCE");
        }
        break;
      }
      case 3:
      {
       printf("===============================================================================");
       printf("\n\t\t\tyour current balance is:  %d",a.a_bal);
       break;
      }
      default:
      {
        printf("\ninvalid choice");
      }
    }
    break;
   }
 }
 }

//new customer
void newacc(int an)
{
  int ch=0;
  printf("\nyour account number NOT FOUND");
  printf("\n\t\t1.Register\n\t\t2.exit\nenter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   {
     cus a;
     int ch,amtt;
     fp=fopen("banking.txt","ab");

     printf("enter your name: ");
     scanf("%s",a.a_name);
     a.a_bal=0;
     a.a_no=an;
     fwrite(&a,sizeof(a),1,fp);
     fflush(stdin);
     printf("________________________________________________________________________________");
     printf("\n\t\t\t SUCCESSFULLY CREATED");
     printf("\n\t\t 1. deposit now\n\t\t 2. exit\nenter your choice: ");
     scanf("%d",&ch);
     fclose(fp);
     switch(ch)
     {
      case 1:
      {
        printf("\nenter amount you need to deposit: ");
        scanf("%d",&amtt);
        deposit(amtt,an);
        break;
      }
     }
   }
 }
}

main()
{
while (1)
{

{
  int an;
  char check;

  printf("________________________________________________________________________________");
  printf("\n\t\t\t\tWELCOME\n");
  printf("________________________________________________________________________________");
  printf("\n\tEnter account number: ");
  scanf("%d",&an);
  check=search(an);
  switch(check)
  {
    case 'y':
    {
      old(an);
      break;
    }
    case 'n':
    {
      newacc(an);
      break;
    }
    default:
    {
      printf(" Invalid Choice");
    }
  }

printf("\n________________________________________________________________________________");
printf("\n\t\t\t\tTHANK YOU \n\n");

}
}
}
