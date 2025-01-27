#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "string.h"
#include "status.h"

Status encode_string(STRING hString);
Status decode_string(STRING hString);

#endif