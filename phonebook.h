#ifndef PHONEBOOK_H
#define PHONEBOOK_H
//function prototype
void addentry();
void display (int index);
void displayAll();
void search (char *key,search_t type);
void removeEntry(char * mobilenumber);
void savetofile();
void readfromfile();
void modify(char * mobilenumber);
#endif // PHONEBOOK_H

