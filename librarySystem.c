#include <stdio.h>
#include <stdlib.h>
//#include "vector.h"
//#include "string.h"
#include "book.h"

//look at available books
//checkout a book
//make a library card
//access you account to view your checked out books

int main(int argc, char* argv[])
{
    printf("Hey! Welcome to Nick's Library. Please let me know how I can help you.\n");
    Book b1;
    Book b2;
    Book b3;
    Book b4;
    Book b5;
    Book b6;
    Book b7;
    Book b8;
    Book b9;
    Book b10;
    VECTOR hVector = vector_init_default();
    if(vector_empty(hVector))
        printf("this vector is empty\n");
    b2.author = string_init_assign("David Foster Wallace"); 
    vector_push_back(hVector, b1);
    vector_push_back(hVector, b2);
    vector_push_back(hVector, b3);
    vector_push_back(hVector, b4);
    vector_push_back(hVector, b5);
    vector_push_back(hVector, b6);
    vector_push_back(hVector, b7);
    vector_push_back(hVector, b8);
    vector_push_back(hVector, b9);
    vector_push_back(hVector, b10);
    printf("This vector has a size of %d\n", vector_size(hVector));
    printf("What is the name of the first book in the vector: ");
    string_output((vector_at(hVector,1)->author));
    printf("\n");
    for(int i = 0; i < 12; i++)
    {
        vector_pop(hVector);
    }

    STRING hString = string_init_assign("hi my name is nick,");
    printf("String has a size of: %d\n", string_length(hString));
    string_output(hString);
    printf("\n");
    
    STRING hString2 = string_init_default();
    STRING hString3 = string_init_default();
    FILE* fp = fopen("test.txt", "r");
    if(fp == NULL)
    {
        printf("Failed to open file");
        exit(1);
    }
    string_extraction(hString2, fp);
    string_output(hString2);
    printf("\n");

    string_extraction(hString3, fp);
    string_output(hString3);
    printf("\n");
    fclose(fp);


    string_destroy(&hString);
    string_destroy(&hString2);
    string_destroy(&hString3);
    vector_destroy(&hVector);
    return 0;
}