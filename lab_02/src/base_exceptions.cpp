#include "../inc/base_exceptions.h"

ExceptVectorBase::ExceptVectorBase(std::string file_name,
                                   std::string class_name,
                                   int line,
                                   const char *time,
                                   std::string info)
{
    err_info = "\n\nError in file: " + file_name +
               "\nIn class: " + class_name +
               "\nIn line: " + std::to_string(line) +
               "\nAt time: " + time +
               "\nError information: " + info;
}


const char* ExceptVectorBase::what() const noexcept
{
    return err_info.c_str();
}
