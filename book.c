#include "book.h"
#include "vector.h"
#include <string.h>

VECTOR library;

void initialize_library_selection(void)
{
    library = vector_init_default();
    FILE* fp = fopen("library.txt", "r");
    while(1)
    {
        //create a book object
        int i = 0;
        Book b;
        STRING str = string_init_default();
        string_extraction(str, fp);
        if(string_empty(str))
            break;
        char* token = strtok(string_at(str, 0), ",");
        while(token != NULL)
        {
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
        string_destroy(&str);
        vector_push_back(library, b);
    }
    fclose(fp);
}
void output_library_selection(void)
{
    for(int i = 0; i < vector_size(library); i++)
    {
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
        printf("\n");
    }
}