#ifndef CONST_ITERATOR_HPP

#define CONST_ITERATOR_HPP

#include "../inc/errors_list.h"
#include "../inc/const_iterator.h"


template <typename Type>
IteratorConst<Type>::IteratorConst(const IteratorConst<Type> & iterator)
{
    this->iter_pointer = iterator.iter_pointer;

    this->index_cur = iterator.index_cur;
    this->vector_size = iterator.vector_size;
}


template <typename Type>
IteratorConst<Type>::IteratorConst(const Vector<Type> & vector)
{
    this->iter_pointer = vector.data;

    this->index_cur = 0;
    this->vector_size = vector.size;
}


template <typename Type>
Type* IteratorConst<Type>::get_ptr() const
{
    std::shared_ptr<Type[]> tmp_pointer = this->iter_pointer.lock();

    return tmp_pointer.get() + index_cur;
}


template <typename Type>
const Type& IteratorConst<Type>::operator * () const
{
    check_validation(__LINE__);
    check_exception(__LINE__);

    return *get_ptr();
}


template <typename Type>
const Type& IteratorConst<Type>::operator -> () const
{
    check_validation(__LINE__);
    check_exception(__LINE__);

    return *get_ptr();
}


template <typename Type>
IteratorConst<Type>& IteratorConst<Type>::operator = (const IteratorConst<Type> &new_iterator) noexcept
{
    iter_pointer = new_iterator.iter_pointer;

    return *this;
}


// Compare
template <typename Type>
bool IteratorConst<Type>::operator == (const IteratorConst<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur == iterator.index_cur;
}


template <typename Type>
bool IteratorConst<Type>::operator != (const IteratorConst<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur != iterator.index_cur;
}


template <typename Type>
bool IteratorConst<Type>::operator <= (const IteratorConst<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur <= iterator.index_cur;
}


template <typename Type>
bool IteratorConst<Type>::operator < (const IteratorConst<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur < iterator.index_cur;
}


template <typename Type>
bool IteratorConst<Type>::operator >= (const IteratorConst<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur >= iterator.index_cur;
}


template <typename Type>
bool IteratorConst<Type>::operator > (const IteratorConst<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur > iterator.index_cur;
}


// Plus
template <typename Type>
IteratorConst<Type> IteratorConst<Type>::operator + (size_t move) const
{
    check_exception(__LINE__);

    IteratorConst<Type> new_iter(*this);
    new_iter += move;

    return new_iter;
}


template <typename Type>
IteratorConst<Type> & IteratorConst<Type>::operator += (size_t move)
{
    check_exception(__LINE__);

    index_cur += move;

    return *this;
}


template <typename Type>
IteratorConst<Type> & IteratorConst<Type>::operator ++ ()
{
    check_exception(__LINE__);

    index_cur++;

    return *this;
}


template <typename Type>
IteratorConst<Type> IteratorConst<Type>::operator ++ (int)
{
    check_exception(__LINE__);

    ++(*this);

    return *this;
}


// Minus
template <typename Type>
IteratorConst<Type> IteratorConst<Type>::operator - (size_t move) const
{
    check_exception(__LINE__);

    IteratorConst<Type> new_iter(*this);
    new_iter -= move;

    return new_iter;
}


template <typename Type>
IteratorConst<Type> & IteratorConst<Type>::operator -= (size_t move)
{
    check_exception(__LINE__);

    index_cur -= move;

    return *this;
}


template <typename Type>
IteratorConst<Type> & IteratorConst<Type>::operator -- ()
{
    check_exception(__LINE__);

    index_cur--;

    return *this;
}


template <typename Type>
IteratorConst<Type> IteratorConst<Type>::operator -- (int)
{
    check_exception(__LINE__);

    --(*this);

    return *this;
}


template <typename Type>
IteratorConst<Type>::operator bool () const
{
    check_exception(__LINE__);

    return !(index_cur >= vector_size || vector_size == 0);
}


// For exceptions
template <typename Type>
void IteratorConst<Type>::check_exception(int line) const
{
    if (iter_pointer.expired())
    {
        time_t current_time = time(NULL);

        throw ExceptDeletedObject(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}


template <typename Type>
void IteratorConst<Type>::check_validation(int line) const
{
    if (this->index_cur >= this->vector_size) // ??? - переменные?
    {
        time_t current_time = time(NULL);

        throw ExceptIteration(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}


#endif
