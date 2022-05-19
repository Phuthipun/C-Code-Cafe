
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

/* ******************** clear screen ******************** */
void clrscr()
{
    system("@cls||clear"); //library stdlib
}
/* *********************** create struct Menu *********************** */
struct Menu
  {
    int icode;
    char sName[31];
    int ipriceH;
    int ipriceC;
  };
  typedef struct Menu stM;

/* *********************** used file *********************** */
void Savereport(char *name)
{
  FILE *femployees;
  char sreport[501];

  femployees = fopen(name,"a");
  printf("What will you complain : ");
  scanf(" %[^\n]%*c", sreport);
  fprintf(femployees ,"%s\n" ,sreport);
  fclose(femployees);
}
/* ***************** function print day ***************** */
void day()
{
  printf("1.Sunday\n");
  printf("2.Monday\n");
  printf("3.Tuesday\n");
  printf("4.Wednesday\n");
  printf("5.Thursday\n");
  printf("6.Friday\n");
  printf("7.Saturday\n");
}
/* ******************* random name employees ******************* */
void Barista()
{
  int irange;
  srand(time(NULL));
  irange = (rand()%5)+1;
  switch(irange)
  {
    case 1:
      printf("Barista is Tam\n");
      printf("-----Thank you for choosing us.-----\n");
      break;
    case 2:
      printf("Barista is Aun\n");
      printf("-----Thank you for choosing us.-----\n");
      break;
    case 3:
      printf("Barista is Sand\n");
      printf("-----Thank you for choosing us.-----\n");
      break;
    case 4:
      printf("Barista is Tigger\n");
      printf("-----Thank you for choosing us.-----\n");
      break;
    case 5:
      printf("Barista is Nut\n");
      printf("-----Thank you for choosing us.-----\n");
      break;
  }

}
/* ************************ function print name ************************ */
void name()
{
	printf("Tam\n");
	printf("Aun\n");
	printf("Sand\n");
	printf("Tigger\n");
	printf("Nut\n");
}
/* ***************** function print menu in each day ***************** */
void coffee_information(stM *menu ,int day)
{
  int icount;
  for(icount=0;icount<5;icount++)
  {
    printf("| |%3d.\t",menu[icount].icode);
    printf("%s\t\t",menu[icount].sName);
    printf("%d\t\t",menu[icount].ipriceH);
    printf("%-8d| |\n",menu[icount].ipriceC);
  }
  printf("| |%3d.\t%s\t\t%d\t\t%-8d| |\n",menu[4+day].icode ,menu[4+day].sName ,menu[4+day].ipriceH ,menu[4+day].ipriceC);
  printf("| |%3d.\t%s%-53s| |\n",13,"Exi","t");
}

/* ***************************** Print bear ***************************** */
void printBorder(int parts)
{
  if(parts == 1)
  {
    printf("                     ,---.           ,---. \n");
    printf("                    / /\"`.\\.--\"\"\"--./,'\"\\ \\ \n");
    printf("                    \\ \\    _       _    / / \n");
    printf("                     `./  / __   __ \\  \\,' \n");
    printf("                      /    /_O)_(_O\\    \\ \n");
    printf("                      |  .-'  ___  `-.  | \n");
    printf("                   .--|       \_/       |--. \n");
    printf("                 ,'    \\   \\   |   /   /    `. \n");
    printf("                /       `.  `--^--'  ,'       \\ \n");
    printf("             .-\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"-. \n");
    printf(".-----------/         \\------------------/         \\--------------. \n");
    printf("| .---------\\         /----------------- \\         /------------. | \n");
    printf("| |          `-`--`--'                    `--'--'-'             | | \n");
  }
  else if(parts == 2)
  {
    printf("| |_____________________________________________________________| | \n");
    printf("|_________________________________________________________________| \n");
    printf("                   )__________|__|__________( \n");
    printf("                  |            ||            | \n");
    printf("                  |____________||____________| \n");
    printf("                    ),-----.(      ),-----.( \n");
    printf("                  ,'   ==.   \\    /  .==    `. \n");
    printf("                 /            )  (            \\ \n");
    printf("                 `==========='    `===========' \n");

  }
}
/*********************************** Main ***********************************/
int main()
{
  /* ********************** list Menu ********************** */
  stM stmenu[12] = {{1 ,"Espresso            " ,30 ,45}
                   ,{2 ,"Cappucino           " ,40 ,50}
                   ,{3 ,"Latte               " ,40 ,50}
                   ,{4 ,"Thai tea            " ,40 ,50}
                   ,{5 ,"Premium Green tea   " ,45 ,55}
                   ,{6 ,"Orange Coffee       " ,50 ,60}
                   ,{7 ,"Apple Soda          " ,0 ,55}
                   ,{8 ,"Strawberry Macchiato" ,0 ,60}
                   ,{9 ,"Oreo Chocolate      " ,0 ,50}
                   ,{10,"Hojicha             " ,50 ,65}
                   ,{11,"Mixed Berry Soda    " ,0 ,55}
                   ,{12,"Caramel Macchiato   " ,55 ,65}
                   };
  /* ********************** variable declaration ********************** */
  char smenu[10];
  int icount;//count loop
  int iday;
  int ibool=1; // while loop 1==true
  int icodecoffee ,icoffeetype ,inumcoffee;
  int isumprice=0; // sum price
  int irevenue,irevenue2; // input money
  int iOrder[12][3]; //column0 = code coffee ,column1 =
  int iInput=0; //input menu
  int ilenname;
  int icheck=0;
  char sname[20];//name employees
  char scomment[30][501];

  /* ************************ select mode ************************ */
  inputmode:
  printf ("----------Welcome to C Code Cafe----------\n");
  printf ("\n");
  printf("Hello,How can I help you sir?");
  printf("\n1.Order coffee\n2.Report employees\n");
  printf("Please select 1 or 2 : "); //1=order coffee 2=report employee
  scanf("%s",smenu);
  system("@cls||clear"); //clear screen

  /* ******************************* mode order coffee ******************************* */
  if(strcmp(smenu,"1") ==0) //1=order coffee
  {
    printf("\nWhen would you come , sir?\n");
  day();//print day

  inputday:
  printf("Input 1-7 : ");
  icheck = scanf("%d",&iday);
  if(iday>7 || iday<1 || icheck!=1) //error when day!=1-7
  {
    printf("%d",icheck);
    rewind(stdin);
    printf("Error day\n");
    goto inputday; //go to line 182
  }
  /* ****************************** print menu ****************************** */
    system("@cls||clear");
    printBorder(1);
    printf("| |%11s\t\t\t\t%s\t\t%-4s\t| |\n","Menu","Hot","Cold");
    coffee_information(stmenu,iday);
    printBorder(2);

    /* ****************************** input order ****************************** */
    while(ibool == 1) //input menu
      {
        inputmenu:
        printf("\nYour menu : ");
        icheck = scanf("%d",&icodecoffee);
        if(icheck!=1)
        {
            rewind(stdin);
            goto inputmenu; //go to line 202
        }

        if(icodecoffee>5 && icodecoffee<13) //check menu if it is not in that day
        {
          if(icodecoffee!=iday+5)
          {
            printf("This menu is not in this day!!!");
            goto inputmenu; //go to line 202
          }
        }
        if(icodecoffee == 13) //End input menu
        {
          ibool = 0;
          printf("\n-----------Thank you!-----------\n");
        }
        else if(icodecoffee>13)
        {
            printf("Don't have menu");
            goto inputmenu; //go to line 202
        }
        else if(icodecoffee == 7 || icodecoffee == 8 || icodecoffee == 9 || icodecoffee == 11) //some coffee type do not have (0 baht) , so it will count the price from another type
        {
          numcoffee1:
          printf("Number of cup : ");
          icheck = scanf("%d",&inumcoffee);
          if(icheck!=1)
          {
              rewind(stdin);
              goto numcoffee1; //go to line 231
          }
          printf("Comment : ");
          scanf(" %[^\n]%*c", scomment[iInput]);
          isumprice = isumprice + (inumcoffee * stmenu[icodecoffee-1].ipriceC);
          iOrder[iInput][0] = icodecoffee; //code of coffee
          iOrder[iInput][1] = 2; //type of coffee
          iOrder[iInput][2] = inumcoffee; //Number of coffee;
          iInput++;

        }
        else//the basic menu
        {
          printf("Choose the type of coffee\n");
          printf("1.Hot\n2.Cold\n");
          inputtype:
          printf("Select coffee type: ");
          icheck = scanf("%d",&icoffeetype);
          if(icheck!=1)
          {
              rewind(stdin);
              goto inputtype; //go to line 252
          }
          if(icoffeetype == 1) //hot
          {
            numcoffee2:
            printf("Number of cup : ");
            icheck = scanf("%d",&inumcoffee);
            if(icheck!=1)
            {
              rewind(stdin);
              goto numcoffee2; //go to line 262
            }
            printf("Comment : ");
            scanf(" %[^\n]%*c", scomment[iInput]);
            isumprice = isumprice + (inumcoffee * stmenu[icodecoffee-1].ipriceH);
            iOrder[iInput][0] = icodecoffee; //code of cofffee
            iOrder[iInput][1] = icoffeetype; //type of coffee
            iOrder[iInput][2] = inumcoffee; //Number of coffee;
            iInput++;
          }
          else if(icoffeetype == 2) //cold
          {
            numcoffee3:
            printf("Number of cup : ");
            icheck = scanf("%d",&inumcoffee);
            if(icheck!=1)
            {
              rewind(stdin);
              goto numcoffee3; //go to line 280
            }
            printf("Comment : ");
            scanf(" %[^\n]%*c", scomment[iInput]);
            isumprice = isumprice + (inumcoffee * stmenu[icodecoffee-1].ipriceC);
            iOrder[iInput][0] = icodecoffee; //code of cofffee
            iOrder[iInput][1] = icoffeetype; //type of coffee
            iOrder[iInput][2] = inumcoffee; //Number of coffee;
            iInput++;
          }
          else
          {
            printf("Coffee has 2 type\n");
            goto inputtype; //go to line 252
          }
        }
      }

    /* ************************ input money ************************ */
    printf("Sum of price = %d\n",isumprice);
    inputmoney:
    printf("Input your money : ");
    icheck = scanf("%d",&irevenue);
    if(icheck != 1)
    {
        rewind(stdin);
        goto inputmoney; //go to line 306
    }
    if(irevenue<isumprice)
    {
      printf("\nNot enough money\n---Input more money---\n");
      for(icount=1 ;icount<=3 ;icount++) //max input = 3 times
        {
          printf("\nCurrent money : %d\n",irevenue);
          printf("Input your money : ");
          icheck = scanf("%d",&irevenue2);
          if(icheck != 1)
          {
              rewind(stdin);
              icount = icount-1;
              continue;
          }
          irevenue = irevenue+irevenue2;
          if(irevenue>=isumprice)
          {
            break;
          }
        }
      if(icount>3) //max input = 3 times
      {
        clrscr();
        printf("This order expired.");
        return 0;
      }
    }

    /* ***********************print slip************************ */
    clrscr();
    printf("\n----------------Slip----------------\n");
    for(icount=0 ;icount<iInput ;icount++)
      {
        printf("%d\t",iOrder[icount][2]);
        printf("%s\t",stmenu[iOrder[icount][0]-1].sName);
        if(iOrder[icount][1] == 1)
        {
          printf("%d\n",stmenu[iOrder[icount][0]-1].ipriceH * iOrder[icount][2]);
        }
        else if(iOrder[icount][1] == 2)
        {
          printf("%d\n",stmenu[iOrder[icount][0]-1].ipriceC * iOrder[icount][2]);
        }
        printf("#\t%s\n",scomment[icount]);
      }
    printf("\nSum of price = %d\n",isumprice); //total price
    printf("Your recirved a change of %d baht\n\n",irevenue-isumprice); //the change you will get
    Barista(); //print barista name
  }

   /* ************************** report ******************************** */
  else if(strcmp(smenu,"2") ==0)
  {
    printf("\nAll Employees\n");
    name(); //print employee name
    printf("Input Name : ");
    scanf(" %[^\n]%*c",sname);
    ilenname = strlen(sname);
    /* ******************* upper string ******************* */
    for(icount=0 ;icount<ilenname ;icount++)
    {
      if(sname[icount]>='a' && sname[icount]<='z')
      {
        sname[icount] = sname[icount]-32;
      }
    }

    strcat(sname,".txt");
    Savereport(sname); //save comment to file
  }
  /* ******************* input mode error ******************* */
  else
  {
    printf("Error!!! only 1 or 2\n");
    goto inputmode; //go to line 167
  }

  return 0;
}
