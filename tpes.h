#ifndef TYPES_H // safe gurad or include gurarding
#define TYPES_H
//structure to hold the information of a single contact
typedef struct{
       char firstname[50];
       char lastname[50];
       char mobilenumber[20];
} Contact;
//enumarator for different searchtypes
typedef enum {FIRST_NAME,LAST_NAME,MOBILE_NUMBER} search_t;
#endif // TYPES_H
