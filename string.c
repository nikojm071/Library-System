#include "string.h"

struct string {
    char* data;
    int size;
    int capacity;
}; typedef struct string String;

Status resize_string(String* pString, int newCapacity);

STRING string_init_default(void) {
    String* pString = (String*)malloc(sizeof(String));
    if (!pString) {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    pString->size = 0;
    pString->capacity = 10;
    pString->data = (char*)malloc(pString->capacity * sizeof(char));
    if (!pString->data) {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    
    return pString;
}

STRING string_init_assign(const char* str) {
    String* pString = (String*)malloc(sizeof(String));
    if (!pString) {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    pString->size = 0;
    int i = 0;
    while (str[i] != '\0') {
        pString->size++;
        i++;
    }
    pString->capacity = pString->size + 1;
    pString->data = (char*)malloc(pString->capacity * sizeof(char));
    if (!pString->data) {
        fprintf(stderr, "Failed to allocate memory for string");
        return NULL;
    }
    for (int i = 0; i < pString->capacity; i++) {
        pString->data[i] = str[i];
        /* - testing
        printf("added char: %c\n", pString->data[i]);
        printf("string: %s\n", pString->data);
        */
    }

    return pString;
}

void string_destroy(STRING* phString) {
    String* pString = (String*)*phString;
    free(pString->data);
    free(pString);
    pString = NULL;
}

int string_length(STRING hString) {
    String* pString = (String*)hString;
    return pString->size;
}

Status string_empty(STRING hString) {
    String* pString = (String*)hString;
    return (!pString->size);
}

char* string_at(STRING hString, int index) {
    String* pString = (String*)hString;
    if (index > pString->size || index < 0) {
        fprintf(stderr, "This index is out of bounds");
        exit(1);
    }
    return &pString->data[index];
}

Status string_concat(STRING target, STRING append) {
    String* pTarget = (String*)target;
    String* pAppend = (String*)append;

    while ((pTarget->size + pAppend->size) >= pTarget->capacity-1) {
        if (!resize_string(pTarget, (pTarget->capacity*2)))
            return FAILURE;
    }
    
    for (int i = 0; i < pAppend->size; i++) {
        pTarget->data[pTarget->size] = pAppend->data[i];
        //testing -
        //printf("pTarget->data[i] = %c\n", pTarget->data[i]);
        //printf("pTarget->data = %s\n", pTarget->data);
        pTarget->size++;
    }
    pTarget->data[pTarget->size] = '\0';
    
    return SUCCESS;
}

Status string_push_back(STRING hString, char c) {
    String* pString = (String*)hString;
    //pString size must ALWAYS be 1 less than the capacity to leave room for the null terminator
    if (pString->size >= (pString->capacity-1)) {
        if (!resize_string(pString, (pString->capacity * 2)))
            return FAILURE;
    }
    pString->data[pString->size] = c;
    pString->size++;
    pString->data[pString->size] = '\0';
    return SUCCESS;
}

Status string_pop(STRING hString) {
    String* pString = (String*)hString;
    if (pString->size == 0) {
        fprintf(stderr, "Unable to pop when this string is empty...");
        return FAILURE;
    }
    pString->size--;
    pString->data[pString->size] = '\0';

    if (pString->capacity <= pString->size/2) {
        if(resize_string(pString, (pString->capacity/2)))
            return FAILURE;
    }

    return SUCCESS;
}

Status string_extraction(STRING hString, FILE* readFrom) {
    String* pString = (String*)hString;
    if (readFrom == NULL) {
        fprintf(stderr, "File was not opened properly or failed to open...");
        return FAILURE;
    }
    pString->size = 0;
    char c = '\0';
    //skip leading whitespaces
    while ((c = fgetc(readFrom)) != EOF && c == ' ');
    //replace first non-leading whitespace character
    ungetc(c, readFrom);
    while ((c = fgetc(readFrom)) != EOF && c != '\n') {
        if (pString->size == pString->capacity-1) {
            if (!resize_string(pString, (pString->capacity * 2)))
                return FAILURE;
        }
        pString->data[pString->size] = c;
        pString->size++;
    }
    pString->data[pString->size] = '\0';
    return SUCCESS;
}

void string_output(STRING hString) {
    String* pString = (String*)hString;
    for (int i = 0; i < (pString->size + 1); i++) {
        printf("%c", pString->data[i]);
    }
    return;
}

int string_compare(STRING string1, STRING string2) {
    String* pString1 = (String*)string1;
    String* pString2 = (String*)string2;
    //if(pString1->size != pString2->size)
        //return 0;
    for (int i = 0; i < pString1->size; i++) {
        if (pString1->data[i] != pString2->data[i])
            return 0;
    }
    return 1;
}

Status resize_string(String* pString, int newCapacity) {
    char* temp = (char*)malloc(sizeof(char) * newCapacity);
    if (!temp) {
        fprintf(stderr, "Failed to allocate memory upon resize request...\n");
        return FAILURE;
    }
    for (int i = 0; i < pString->size; i++) {
        temp[i] = pString->data[i];
    }
    temp[pString->size+1] = '\0';
    free(pString->data);
    pString->capacity = newCapacity;
    pString->data = temp;
    return SUCCESS;
}