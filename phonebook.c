#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tpes.h"
#include "phonebook.h"
#include "utlities.h"
#define MAX_SIZE 100

//array to hold our contact
Contact phonebook[MAX_SIZE];
//current size of the phonebook array
int currentsize = 0;

void addentry()
{
    int boo=1, i;
    if (currentsize == MAX_SIZE){
        printf ("error! phonebook is full!");
    }
    Contact c;
    boo=0;
    do{
        printf ("enter first name :");
        gets(c.firstname);
        for(i=0 ;i < currentsize ; i++)
        {
            if (strcmp(phonebook[i].firstname,c.firstname)==0){
                    printf("\n..Similar name found!!! Try again....\n");
                    boo=1;
                    break;
            }
            else boo=0;
        }
    }while(boo);
    boo=0;
    do{
            printf ("enter last name :");
    gets(c.lastname);
        for(i=0 ;i < currentsize ; i++)
        {
            if (strcmp(phonebook[i].lastname,c.lastname)==0){
                    printf("\n..Similar name found!!! Try again....\n");
                    boo=1;
                    break;
            }
            else boo=0;
        }
    }while(boo);
    boo=0;
    do{
            printf ("enter mobile number :");
    gets(c.mobilenumber);
        for(i=0 ;i < currentsize ; i++)
        {
            if (strcmp(phonebook[i].mobilenumber,c.mobilenumber)==0){
                    printf("\n..Similar number found!!! Try again....\n");
                    boo=1;
                    break;
            }
            else boo=0;
        }
    }while(boo);

    phonebook[currentsize]=c;
    currentsize++;
     printf("\ncontact added\n");
}
void display (int index)
{
    if (index < 0 || index >= currentsize)
    {
        printf("error! invalid index!");
    }
    else{
    Contact c = phonebook[index];
    printf ("first name : %s\n",c.firstname);
    printf ("last name : %s\n",c.lastname);
    printf ("mobile no : %s\n",c.mobilenumber);
    }
}
void displayAll ()
{
    if (currentsize == 0){
        printf("PhoneBook is empty\n");
    }
    int i;
    for(i=0;i<currentsize;i++){
            display(i);
            printf("\n");//new line
        }
}

void search (char *key , search_t  type)
{
    int found=0;
    int i;
    strtolower(key);
    char content[41];
    if (type == FIRST_NAME){
        //search by first name
        for (i = 0 ; i < currentsize ; i++)
        {
            strcpy(content,phonebook[i].firstname);
            strtolower(content);

            if (strcmp(content,key)==0)
            {
                display(i);
                found =1;
            }
        }
    }
    else if (type == LAST_NAME){
        //search by last name
        for (i = 0 ; i < currentsize ; i++)
        {
            strcpy(content,phonebook[i].lastname);
            strtolower(content);

            if (strcmp(content,key)==0)
            {
                display(i);
                found =1;
            }
        }

    }
    else if (type == MOBILE_NUMBER){
        //search by mobile no
        for (i = 0 ; i < currentsize ; i++)
        {
            strcpy(content,phonebook[i].mobilenumber);
            strtolower(content);

            if (strcmp(content,key)==0)
            {
                display(i);
                found =1;
            }
        }

    }
    else{
        printf ("!error . invalid search type!");
    }
    if (!found){
        printf ("\nnot found in the phonebook\n");
    }
}
void removeEntry(char * mobilenumber)
{
    if (currentsize == 0){
        printf("PhoneBook is empty nothing to delete\n");
    }
    int i,j;
    //int count =0;
    for(i=0 ;i < currentsize ; i++)
    {
        if (strcmp(phonebook[i].mobilenumber,mobilenumber)==0){
                printf(".\n.\n.\n%s %s's Phone Number is deleted.\n",phonebook[i].firstname,phonebook[i].lastname);
            for(j=i;j<currentsize-1;j++)
            {
                phonebook[j]=phonebook[j+1];
            }
            strcpy(phonebook[j].firstname, " ");
            strcpy(phonebook[j].lastname, " ");
            strcpy(phonebook[j].mobilenumber, " ");
            currentsize -= 1;
        }
    }
}
void modify(char * mobilenumber){
    if (currentsize == 0){
        printf("PhoneBook is empty nothing to Modify\n");
    }
    int i;
    //int count =0;
    for(i=0 ;i < currentsize ; i++)
    {
        if (strcmp(phonebook[i].mobilenumber,mobilenumber)==0){
                printf("Enter first name to modify contact \n[%s] to :",phonebook[i].firstname);
                strcpy(phonebook[i].firstname, "");
                gets(phonebook[i].firstname);
                printf("Enter last name to modify contact \n[%s] to :",phonebook[i].lastname);
                strcpy(phonebook[i].lastname, "");
                gets(phonebook[i].lastname);
        }
    }
    printf("Modify Completed........\n\n");
}
void readfromfile()
{
    FILE  * fp;
    if ((fp=fopen("phonebook.bd","rb"))==NULL){
        printf ("error can't load the database");
    }
    //read the size of the phonebook
    if (fread(&currentsize,sizeof(currentsize),1,fp) != 1){
        printf ("error! can't read data");
    }
    //read the actual phonebook content
     if (fread(phonebook,sizeof(phonebook),1,fp) != 1){

    }
}
void savetofile()
{
    FILE *fp=fopen("phonebook.bd","wb");
    if (fp==NULL){
        printf ("error! can't create a database file");
    }
    //save the current size of the phonebook
    if (fwrite(&currentsize,sizeof(currentsize),1,fp) != 1){
        printf ("error! can't save data");
    }
    //save the phonebook contents
    if (fwrite(phonebook,sizeof(phonebook),1,fp) !=1){
        printf ("error! can't save the file");
    }
    else{
        printf("PhoneBook saved to file succesfully\n");
    }

}
