#ifndef BOOK_H
#define BOOK_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "status.h"

struct book{
    STRING title;
    STRING author;
    STRING genre;
    STRING publicationYear;
};
typedef struct book Book;

void initialize_library_selection(void);
void output_library_selection(void);

#endif