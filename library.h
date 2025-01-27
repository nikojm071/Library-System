#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "status.h"
#include "available.h"

struct book {
    STRING title;
    STRING author;
    STRING genre;
    STRING publicationYear;
    Available checkOut; 
}; typedef struct book Book;

void initialize_library_selection(void);
void output_library_selection(void);
void exit_library(void);

Status checkout_book(const char* bookTitle);
Status create_account(STRING userName, STRING password);

#endif