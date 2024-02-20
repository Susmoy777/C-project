#include<string.h>
#include<ctype.h>
#include "utlities.h"

//this functions modify the given string
void strtolower(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0 ; i < len ; i++)
    {
        str[i]= tolower(str[i]);
    }
}
