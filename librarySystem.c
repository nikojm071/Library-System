#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "string.h"

//look at available books
//checkout a book
//make a library card
//access you account to view your checked out books

int main(int argc, char* argv[])
{
    printf("Hey! Welcome to Nick's Library. Please let me know how I can help you.\n");
    VECTOR hVector = init_default();
    pop(hVector);
    
    return 0;
}