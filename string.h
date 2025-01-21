#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdlib.h>
#include "status.h"

typedef void* STRING;

STRING string_init_default(void);
STRING string_init_assign(const char* str);
void string_destroy(STRING* phString);

int string_length(STRING hString);
Status string_empty(STRING hString);
char* string_at(STRING hString, int index);
Status string_concat(STRING target, STRING append);
Status string_push_back(STRING hString, char c);
Status string_pop(STRING hString);

Status string_extraction(STRING hString, FILE* readFrom);
void string_output(STRING hString);


#endif