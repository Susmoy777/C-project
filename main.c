#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "tpes.h"
#include "phonebook.h"
void clear ();
int z=1;
int main()
{
    while(z){
        char pass[]="762794", p[50];
    printf("Enter Password to enter:");
    gets(p);
    if(strcmp(pass,p)==0){
            z=0;
            printf("Succesfully Logged in\n");
    }
    else {
        printf("Wrong Pass!!!!!!\nLOCKED!!!!!!!!!!!!\n");
    }
    }
    clear();
    //z=0;
    readfromfile();
    char selection[41];
    int choice;
    int i;
    while(1){

            printf(" \t\t\t\t #####@ Welcome To PhoneBook Application @######\n");

    printf("\n\n\n\t\t\t\t      PhoneBook application main menu.\n");
    printf(" \t\t\t\t       1.Insert a new entry           \n");
    printf(" \t\t\t\t       2.Display all entry           \n");
    printf(" \t\t\t\t       3.Search by first name           \n");
    printf(" \t\t\t\t       4.Search by last name           \n");
    printf(" \t\t\t\t       5.Search by mobile number            \n");
    printf(" \t\t\t\t       6.Delete a contact (by mobile number)           \n");
    printf(" \t\t\t\t       7.Save Database           \n");
    printf(" \t\t\t\t       8.Modify number               \n");
    printf(" \t\t\t\t       9.Exit           \n");
    do{
         printf("Enter your choice:\n");
         gets(selection);
         choice = atoi(selection); //converts a string into an integer numerical representation(atoi)
    }while (choice < 1 || choice >9);
    switch (choice)
    {
    case 1:
        addentry();
        clear();
        break;
    case 2:
        displayAll();
         clear();
        break;
    case 3:
        printf("Enter first name to search:\n");
        gets(selection);
        search(selection,FIRST_NAME);
         clear();
        break;
    case 4:
        printf("Enter last name to search:\n");
        gets(selection);
        search(selection,LAST_NAME);
         clear();
        break;
    case 5:
        printf("Enter mobile number to search:\n");
        gets(selection);
        search(selection,MOBILE_NUMBER);
         clear();
        break;
    case 6:
        printf("Enter mobile number to deleted\n");
        gets(selection);
        removeEntry(selection);
        clear();
        break;
    case 7:
        savetofile();
         clear();
        break;
    case 8:
        printf("Enter mobile number to Modify\n");
        gets(selection);
        modify(selection);
        clear();
        break;
    case 9:
        exit(0);
        break;
    default:
        break;
    }
}
    return 0;
}
void clear ()
{
    system("PAUSE");
    system ("CLS");
}

