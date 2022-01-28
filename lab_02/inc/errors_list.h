#ifndef ERRORS_LIST_H
#define ERRORS_LIST_H

#include "../inc/base_exceptions.h"


class ExceptOutOfRange: public ExceptVectorBase
{
public:
    ExceptOutOfRange(std::string file_name,
                     std::string class_name,
                     int line,
                     const char *time,
                     std::string info = "Index is out of range"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptEmptyVector: public ExceptVectorBase
{
public:
    ExceptEmptyVector(std::string file_name,
                      std::string class_name,
                      int line,
                      const char *time,
                      std::string info = "Vector is empty"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptMemory: public ExceptVectorBase
{
public:
    ExceptMemory(std::string file_name,
                 std::string class_name,
                 int line,
                 const char *time,
                 std::string info = "Error in memory allocate"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptSize: public ExceptVectorBase
{
public:
    ExceptSize(std::string file_name,
               std::string class_name,
               int line,
               const char *time,
               std::string info = "Vector has no size"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptIteration: public ExceptVectorBase
{
public:
    ExceptIteration(std::string file_name,
                    std::string class_name,
                    int line,
                    const char *time,
                    std::string info = "Error while iteration"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptCopyArr: public ExceptVectorBase
{
public:
    ExceptCopyArr(std::string file_name,
                  std::string class_name,
                  int line,
                  const char *time,
                  std::string info = "Error while copping"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptDivisionByZero: public ExceptVectorBase
{
public:
    ExceptDivisionByZero(std::string file_name,
                         std::string class_name,
                         int line,
                         const char *time,
                         std::string info = "Division by zero"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};


class ExceptDeletedObject: public ExceptVectorBase
{
public:
    ExceptDeletedObject(std::string file_name,
                    std::string class_name,
                    int line,
                    const char *time,
                    std::string info = "Error - work with deleted object"):
            ExceptVectorBase(file_name, class_name, line, time, info) {}

    virtual const char *what() const noexcept
    {
        return err_info.c_str();
    }
};



#endif
