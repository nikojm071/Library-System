#ifndef STRING_C
#define STRING_C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "status.h"
#include "string.h"

struct string{
    char* data;
    int size;
    int capacity;
};
typedef struct string String;

STRING string_init_default(void)
{
    String* pString = (String*)malloc(sizeof(String));
    if(!pString)
    {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    pString->size = 0;
    pString->capacity = 10;
    pString->data = (char*)malloc(sizeof(pString->capacity)* sizeof(char));
    if(!pString->data)
    {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }

    return pString;
}

STRING string_init_assign(const char* str)
{
    String* pString = (String*)malloc(sizeof(String));
    if(!pString)
    {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    pString->size = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        pString->size++;
        i++;
    }
    pString->capacity = pString->size + 1;
    pString->data = (char*)malloc(pString->capacity * sizeof(char));
    if(!pString->data)
    {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    for(int i = 0; i < pString->size; i++)
    {
        pString->data[i] = str[i];
        printf("added char: %c\n", pString->data[i]);
        printf("string: %s\n", pString->data);
    }

    return pString;
}

void string_destroy(STRING* phString)
{
    String* pString = (String*)*phString;
    free(pString->data);
    free(pString);
    pString = NULL;
}

int string_length(STRING hString)
{
    String* pString = (String*)hString;
    return pString->size;
}

Status string_empty(STRING hString)
{
    return SUCCESS;
}

STRING* string_at(STRING hString, int index)
{
    return NULL;
}

Status string_concat(STRING targt, STRING append)
{
    return SUCCESS;
}

Status string_push_back(STRING hString, char c)
{
    return SUCCESS;
}

Status string_pop(STRING hString)
{
    return SUCCESS;
}

#endif