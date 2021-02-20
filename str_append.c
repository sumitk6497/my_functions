/******* Implementation of strncat() function *******/


/*****************************************************
*	STANDARD HEADER FILES
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

/****************************************************
*	MACRO
****************************************************/
#define SIZE 200

/****************************************************
*	FUNCTION DECLARATION
****************************************************/
char * my_strcat(char * str1, const char * src);
int my_strlen(const char *str);

/****************************************************
*	FUNCTION DEFINATION
*****************************************************
*
*	Function Name : my_strncat
*	Arguments     : char * dest (Destination String)
	                char * src  (Source String)
			int n       (No. of characters to be append)
*	Return Value  : char *      (char pointer of dest string)
****************************************************/
char * my_strcat(char * str1, const char * str2)
{
    int i = 0,
        j = 0;
    static int count;

    i = my_strlen(str1);	//calculating length of destination string

//    for(j = 0; str2[j] != '\0'; j++)
    while(str2[j] != '\0')
    {
        str1[i + j] = str2[j];	//copying n characters of source string into end of destination string
	j++;
    }
    if (count == 0)
    {
	count++;
        my_strcat(str1,"C_Programming");
        str1[i + j + 13] = '\0';		//add NULL character
    }
    return str1;		//return pointer of destination string
}


/****************************************************
*	Function Name : my_strlen
*	Arguments     : char * str (Input String)
*	Return Value  : int length (length of the Input String)
****************************************************/
int my_strlen(const char *str)
{
    int length = 0;		//variable for string length

    while(*(str + length) != '\0')	//running loop at the end of string
    {
        length++;		//incrementing length by 1
    }	

    return length;		//return total length of string
}

/***************************************************
*	MAIN FUNCTION
***************************************************/
int main()
{
    int size = 200;
    int c, d;
    char * str1 = NULL;		//char array for source string
    char * str2 = NULL;		//char array for destination string
    int n = 0;
    int len = 0;

    str1 = (char *)malloc(sizeof(char) * size);
    str2 = (char *)malloc(sizeof(char) * size);

    printf("Enter String 1 : ");
    c = getline(&str1, &size, stdin);


    printf("Enter String 2 : ");
    d = getline(&str2, &size, stdin);

    my_strcat(str1, str2);	//function call of my_strncat
    printf("String 1 after append : %s\n", str1);

    return 0;
}
