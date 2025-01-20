#ifndef BOOK_H
#define BOOK_H
#include "string.h"
#include "vector.h"

struct book{
    STRING title;
    STRING author;
    int publishDate;
    int pageLength;
};
typedef struct book Book;

#endif