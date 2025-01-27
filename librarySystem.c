#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "library.h"
#include "account.h"

void clearKeyboardBuffer(void);
void promptOptions(int* x);
void promptCheckout(char* arr, int size);
int promptLibrary();
void promptAccount();
Status checkProperCharacters(STRING password);

int main(int argc, char* argv[]) {
    int x;
    printf("Hey! Welcome to Nick's library. Let me know what I can do for you.\n");
    initialize_library_selection();
    STRING leave = string_init_assign("exit!");
    encode_string(leave);    
    do {
        promptOptions(&x);
        printf("\n");

        if (x == 1)
            output_library_selection();
        if (x == 2) {   
            char arr[100];
            STRING toCheckOut;
            do {
                promptCheckout(arr, 100);
                toCheckOut = string_init_assign(arr);
            }
            while (!string_compare(leave, toCheckOut) &&  !checkout_book(arr));
        }
        if (x == 3)
            promptAccount();
        if (x == 4)
            printf("function not implemented yet, it will eventually tho\n");
    }
    while (promptLibrary());

    return 0;
}

void promptOptions(int* x) {
    printf("Type 1 - To look at the library's selection\n");
    printf("Type 2 - To check out a book\n");
    printf("Type 3 - To make an account with the library\n");
    printf("Type 4 - To Return a book\n");
    printf("Select an option: ");
    scanf("%d", x);
    clearKeyboardBuffer();
    while (*x != 1 && *x != 2 && *x != 3 && *x != 4) {
        printf("Please type 1, 2, 3, or 4 to select an option: ");
        scanf("%d", x);
        clearKeyboardBuffer();
    }
}

void promptCheckout(char* arr, int size) {
    printf("Which book would you like to check out? Please enter the full title exactly (or type 'exit'): ");
    fgets(arr, size, stdin);
}

int promptLibrary() {
    char c = ' ';
    printf("Would you like to keep using the library (y/n)?: ");
    scanf("%c", &c);
    c = tolower(c);
    clearKeyboardBuffer();
    while (c != 'y' && c != 'n') {
        printf("Would you like to keep using the library (y/n)?: ");
        scanf("%c", &c);
        c = tolower(c);
        clearKeyboardBuffer();
    }
    return (c == 'y');
}

void promptAccount()
{
    STRING username;
    STRING password;
    char user[100];
    char pass[100];
    
    printf("Please enter the username you would like to use: ");
    scanf("%s", user);
    username = string_init_assign(user);
    printf("Please enter a password (between 8-20 letters, numbers, or special characters): ");
    scanf("%s", pass);
    password = string_init_assign(pass);
    clearKeyboardBuffer();

    while (string_length(password) > 14 || string_length(password) < 8 || !checkProperCharacters(password)) {
        string_destroy(&password);
        printf("Please enter a password (between 8-20 letters, numbers, or special characters): ");
        scanf("%s", pass);
        clearKeyboardBuffer();
        password = string_init_assign(pass);
    }

    encode_string(password);
    create_account(username, password);
}

Status checkProperCharacters(STRING password)
{
    for (int i = 0; i < string_length(password); i++) {
        char c = *string_at(password, i);
        if(isspace(c))
            return FAILURE;
    }
    return SUCCESS;
}

void clearKeyboardBuffer(void) {
    char c = '\0';
    while (c != '\n') {
        scanf("%c", &c);
    }
}