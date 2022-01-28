#ifndef BASE_VECTOR_H

#define BASE_VECTOR_H

#include <iostream>


class BaseVector
{
public:
    BaseVector(size_t size = 0): size(0) { }

    virtual ~BaseVector() = 0;

    virtual size_t get_size() const;
    virtual operator bool() const noexcept;

protected:
    size_t size = 0;
};


#endif
