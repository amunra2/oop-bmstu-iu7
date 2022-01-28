#ifndef ITERATOR_HPP

#define ITERATOR_HPP

#include "../inc/errors_list.h"
#include "../inc/iterator.h"



template <typename Type>
Iterator<Type>::Iterator(const Iterator<Type> & iterator) noexcept
{
    this->iter_pointer = iterator.iter_pointer;

    this->index_cur = iterator.index_cur;
    this->vector_size = iterator.vector_size;
}


template <typename Type>
Iterator<Type>::Iterator(const Vector<Type> & vector) noexcept
{
    this->iter_pointer = vector.data;

    this->index_cur = 0;
    this->vector_size = vector.size;
}


template <typename Type>
Type* Iterator<Type>::get_ptr() const
{
    std::shared_ptr<Type[]> tmp_pointer = this->iter_pointer.lock();

    return tmp_pointer.get() + index_cur;
}


template <typename Type>
Type& Iterator<Type>::operator * ()
{
    check_validation(__LINE__);
    check_exception(__LINE__);

    return *get_ptr();
}


template <typename Type>
const Type& Iterator<Type>::operator * () const
{
    check_validation(__LINE__);
    check_exception(__LINE__);

    return *get_ptr();
}


template <typename Type>
Type& Iterator<Type>::operator -> ()
{
    check_validation(__LINE__);
    check_exception(__LINE__);

    return *get_ptr();
}


template <typename Type>
const Type& Iterator<Type>::operator -> () const
{
    check_validation(__LINE__);
    check_exception(__LINE__);

    return *get_ptr();
}


template <typename Type>
Iterator<Type>& Iterator<Type>::operator = (const Iterator<Type> &new_iterator) noexcept
{
    iter_pointer = new_iterator.iter_pointer;

    return *this;
}


// Compare
template <typename Type>
bool Iterator<Type>::operator == (const Iterator<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur == iterator.index_cur;
}


template <typename Type>
bool Iterator<Type>::operator != (const Iterator<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur != iterator.index_cur;
}


template <typename Type>
bool Iterator<Type>::operator <= (const Iterator<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur <= iterator.index_cur;
}


template <typename Type>
bool Iterator<Type>::operator < (const Iterator<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur < iterator.index_cur;
}


template <typename Type>
bool Iterator<Type>::operator >= (const Iterator<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur >= iterator.index_cur;
}


template <typename Type>
bool Iterator<Type>::operator > (const Iterator<Type> &iterator) const
{
    check_exception(__LINE__);

    return this->index_cur > iterator.index_cur;
}


// Plus
template <typename Type>
Iterator<Type> Iterator<Type>::operator + (size_t move) const
{
    check_exception(__LINE__);

    Iterator<Type> new_iter(*this);
    new_iter += move;

    return new_iter;
}


template <typename Type>
Iterator<Type> & Iterator<Type>::operator += (size_t move)
{
    check_exception(__LINE__);

    index_cur += move;

    return *this;
}


template <typename Type>
Iterator<Type> & Iterator<Type>::operator ++ ()
{
    check_exception(__LINE__);

    index_cur++;

    return *this;
}


template <typename Type>
Iterator<Type> Iterator<Type>::operator ++ (int)
{
    check_exception(__LINE__);

    ++(*this);

    return *this;
}


// Minus
template <typename Type>
Iterator<Type> Iterator<Type>::operator - (size_t move) const
{
    check_exception(__LINE__);

    Iterator<Type> new_iter(*this);
    new_iter -= move;

    return new_iter;
}


template <typename Type>
Iterator<Type> & Iterator<Type>::operator -= (size_t move)
{
    check_exception(__LINE__);

    index_cur -= move;

    return *this;
}


template <typename Type>
Iterator<Type> & Iterator<Type>::operator -- ()
{
    check_exception(__LINE__);

    index_cur--;

    return *this;
}


template <typename Type>
Iterator<Type> Iterator<Type>::operator -- (int)
{
    check_exception(__LINE__);

    --(*this);

    return *this;
}


template <typename Type>
Iterator<Type>::operator bool ()
{
    check_exception(__LINE__);

    return !(index_cur >= vector_size || vector_size == 0);
}


// For exceptions
template <typename Type>
void Iterator<Type>::check_exception(int line) const
{
    if (iter_pointer.expired())
    {
        time_t current_time = time(NULL);

        throw ExceptDeletedObject(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}


template <typename Type>
void Iterator<Type>::check_validation(int line) const
{
    if (this->index_cur >= this->vector_size) // ??? - переменные?
    {
        time_t current_time = time(NULL);

        throw ExceptIteration(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}



#endif
