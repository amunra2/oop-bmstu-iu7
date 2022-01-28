#ifndef BASE_EXCEPTIONS_H
#define BASE_EXCEPTIONS_H


#include <iostream>
#include <exception>

class ExceptVectorBase: public std::exception
{
public:
    ExceptVectorBase(std::string file_name,
                     std::string class_name,
                     int line,
                     const char *time,
                     std::string info);

    virtual ~ExceptVectorBase() {}

    virtual const char *what() const noexcept override;

protected:
    std::string err_info;
};







#endif
