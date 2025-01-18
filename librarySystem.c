#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "string.h"
#include "book.h"

//look at available books
//checkout a book
//make a library card
//access you account to view your checked out books

int main(int argc, char* argv[])
{
    printf("Hey! Welcome to Nick's Library. Please let me know how I can help you.\n");
    VECTOR hVector = vector_init_default();
    if(vector_empty(hVector))
        printf("this vector is empty\n");
    
    STRING hString = string_init_assign("hello");
    printf("String has a size of: %d\n", string_length(hString));

    return 0;
}