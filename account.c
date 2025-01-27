#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "account.h"

STRING to_binary(int x);
STRING to_base64(STRING binaryString);

Status encode_string(STRING hString) {
    int n = string_length(hString);
    STRING binary = string_init_default();
    // convert all of the characters in a string to ascii
    for (int i = 0; i < n; i++) {
        int x = *string_at(hString, i);   
        string_concat(binary, to_binary(x));
    }
    // group together and adjust for necessary padding 
    //STRING base64 = string_init_default();  
    //if (n % 3 == 0)     // no padding required
    
    //if (n % 3 == 1)     // som
    
    return SUCCESS;
}

Status decode_string(STRING hString) {
    return FAILURE;
}

STRING to_binary(int x) {
    int divisor = x;
    int remainder;
    STRING reversedString = string_init_default();
    while (divisor > 0)
    {
        remainder = divisor % 2;
        divisor /= 2;
        string_push_back(reversedString, (remainder == 1) ? '1' : '0');
    }
    
    // pad string with proper ammount of zeros
    while(string_length(reversedString) < 8)
        string_push_back(reversedString, '0');
    // after repeated division, the string is backwards so it must be reveresed. I am treating it like a stack,
    // and the element at the top of the reversedString to the properString, and then popping to access the element below.
    STRING properString = string_init_default();
    while(string_length(reversedString) != 0)
    {
        string_push_back(properString, *string_at(reversedString, string_length(reversedString)-1));
        string_pop(reversedString);
    }
    string_destroy(&reversedString);

    return properString;
}

STRING to_base64(STRING binaryString)
{
    return NULL;
}