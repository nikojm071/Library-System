#include "library.h"
#include "vector.h"
#include "account.h"
#include <string.h>
#include <cjson/cJSON.h>

VECTOR library;
VECTOR checkedOut;

void initialize_library_selection(void) {
    library = vector_init_default();
    checkedOut = vector_init_default();
    FILE* fp = fopen("library.txt", "r");
    while (1) {
        //create a book object
        int i = 0;
        Book b;
        STRING str = string_init_default();
        string_extraction(str, fp);
        if (string_empty(str))
            break;
        char* token = strtok(string_at(str, 0), ",");
        while (token != NULL) {
            if(i == 0)
                b.title = string_init_assign(token);
            if(i == 1)
                b.author = string_init_assign(token);
            if(i == 2)
                b.genre = string_init_assign(token);
            if(i == 3)
                b.publicationYear = string_init_assign(token);
            token = strtok(NULL, ",");
            i++;
        }
        b.checkOut = AVAILABLE;
        string_destroy(&str);
        vector_push_back(library, b);
    }
    fclose(fp);
}

void output_library_selection(void) {
    for (int i = 0; i < vector_size(library); i++) {
        printf("Title: ");
        string_output(vector_at(library,i)->title);
        printf("\n");
        printf("Author: ");
        string_output(vector_at(library,i)->author);
        printf("\n");
        printf("Genre: "); 
        string_output(vector_at(library,i)->genre);
        printf("\n");
        printf("Publication Year: ");
        string_output(vector_at(library,i)->publicationYear);
        printf("\n");
        printf("Availability: %s", (vector_at(library, i)->checkOut == AVAILABLE) ? "Available" : "Checked out");
        printf("\n");
        printf("\n");
    }
}

void exit_library(void) {
    vector_destroy(&library);
    vector_destroy(&checkedOut);
}

Status checkout_book(const char* bookTitle) {
    STRING book = string_init_assign(bookTitle);
    for (int i = 0; i < vector_size(library); i++) {
        if (string_compare(vector_at(library,i)->title, book) && (vector_at(library,i)->checkOut == AVAILABLE)) {
            vector_at(library, i)->checkOut = UNAVAILABLE;
            vector_push_back(checkedOut, *vector_at(library, i));
            printf("You checked out: "); 
            string_output(vector_at(library,i)->title);
            printf("\n");
            return SUCCESS;
        }
    }
    printf("You cannot check out that book it is unavailable.\n"); 
    return FAILURE;   
}

Status create_account(STRING userName, STRING password)
{
    // verify if userName is already taken (ie check database)
    // verify if password is of proper length and is 
    return SUCCESS;
}