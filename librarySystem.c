#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "book.h"

void clearKeyboardBuffer(void);
void promptOptions(int* x);
void promptCheckout(char* arr);
int keepUsingLibrary();

int main(int argc, char* argv[])
{
    int x;
    printf("Hey! Welcome to Nick's library. Let me know what I can do for you.\n");
    do
    {
        promptOptions(&x);
        initialize_library_selection();
        printf("\n");

        if(x == 1)
            output_library_selection();
        if(x == 2)
        {
            char arr[100];
            do
            {
                promptCheckout(arr);
            }
            while(!checkout_book(arr));
        }
        if(x == 3)
            printf("function not implemented yet, it will eventually tho\n");
        if(x == 4)
            printf("function not implemented yet, it will eventually tho\n");
    }
    while(keepUsingLibrary());
    return 0;
}

void promptOptions(int* x)
{
    printf("Type 1 - To look at the library's selection\n");
    printf("Type 2 - To check out a book\n");
    printf("Type 3 - To make an account with the library\n");
    printf("Type 4 - Return a book\n");
    printf("Select an option: ");
    scanf("%d", x);
    clearKeyboardBuffer();
    while(*x != 1 && *x != 2 && *x != 3 && *x != 4)
    {
        printf("Please type 1, 2, 3, or 4 to select an option: ");
        scanf("%d", x);
        clearKeyboardBuffer();
    }
}

void promptCheckout(char* arr)
{
    printf("Which book would you like to check out? Please enter the full title exactly: ");
    scanf("%s", arr);
    clearKeyboardBuffer();
}

int keepUsingLibrary()
{
    char c = ' ';
    printf("Would you like to keep using the library (y/n)?: ");
    scanf("%c", &c);
    c = tolower(c);
    clearKeyboardBuffer();
    while(c != 'y' && c != 'n')
    {
        printf("Would you like to keep using the library (y/n)?: ");
        scanf("%c", &c);
        c = tolower(c);
        clearKeyboardBuffer();
    }
    return (c == 'y');
}

void clearKeyboardBuffer(void)
{
    char c = '\0';
    while(c != '\n')
    {
        scanf("%c", &c);
    }
}