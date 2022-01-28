#ifndef CONST_ITERATOR_H

#define CONST_ITERATOR_H

#include <memory>
#include <time.h>

#include "../inc/errors_list.h"

template <typename Type> 
class Vector;

template <typename Type>
class IteratorConst: std::iterator<std::random_access_iterator_tag, int>
{
public:
    IteratorConst(const IteratorConst<Type> & iterator);

    IteratorConst(const Vector<Type> & vector);

    const Type & operator * () const;

    const Type & operator -> () const;


    // Operations

    IteratorConst<Type> & operator = (const IteratorConst<Type> &new_iterator) noexcept;

    bool operator == (const IteratorConst<Type> &iterator) const;
    bool operator != (const IteratorConst<Type> &iterator) const;

    bool operator < (const IteratorConst<Type> &iterator) const;
    bool operator <= (const IteratorConst<Type> &iterator) const;

    bool operator > (const IteratorConst<Type> &iterator) const;
    bool operator >= (const IteratorConst<Type> &iterator) const;

    IteratorConst<Type> operator + (size_t move) const;
    IteratorConst<Type> & operator += (size_t move);
    IteratorConst<Type> & operator ++ ();
    IteratorConst<Type> operator ++ (int);

    IteratorConst<Type> operator - (size_t move) const;
    IteratorConst<Type> & operator -= (size_t move);
    IteratorConst<Type> & operator -- ();
    IteratorConst<Type> operator -- (int);

    operator bool () const;

private:
    std::weak_ptr<Type[]> iter_pointer;

protected:
    size_t index_cur = 0;
    size_t vector_size = 0;

    Type* get_ptr() const;

    void check_exception(int line) const;
    void check_validation(int line) const;
};


#include "../src/const_iterator.hpp"


#endif
