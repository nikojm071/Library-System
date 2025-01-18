#ifndef STRING_H
#define STRING_H
#include "status.h"

typedef void* STRING;

STRING string_init_default(void);
STRING string_init_assign(const char* str);
void string_destroy(STRING* phString);

int string_length(STRING hString);
Status string_empty(STRING hString);
STRING* string_at(STRING hString, int index);
Status string_concat(STRING targt, STRING append);
Status string_push_back(STRING hString, char c);
Status string_pop(STRING hString);

#endif