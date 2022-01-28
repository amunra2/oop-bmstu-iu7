#ifndef ERROR_LIST_H
#define ERROR_LIST_H

#include <QMessageBox>

enum Errors
{
    OK,
    ERR_FILE_OPEN,
    ERR_DATA,
    ERR_MEMORY_ALLOCATE,
    ERR_NO_FIELD,
    ERR_NO_FIGURE,
    ERR_EXTRA_ERROR
};

using err_t = enum Errors;


void catch_error(err_t error);


#endif // ERROR_LIST_H
