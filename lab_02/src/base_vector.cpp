#include "../inc/base_vector.h"


BaseVector::~BaseVector()
{
    size = 0;
}


size_t BaseVector::get_size() const
{
    return size;
}


BaseVector::operator bool() const noexcept
{
    return size == 0;
}

