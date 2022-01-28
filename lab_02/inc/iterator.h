#ifndef ITERATOR_H

#define ITERATOR_H

#include <memory>
#include <time.h>

#include "../inc/errors_list.h"


template <typename Type>
class Vector;

template <typename Type>
class Iterator: std::iterator<std::random_access_iterator_tag, int>
{
public:
    Iterator(const Iterator<Type> & iterator) noexcept;

    Iterator(const Vector<Type> & vector) noexcept;

    Type & operator * ();
    const Type & operator * () const;

    Type & operator -> ();
    const Type & operator -> () const;

    operator bool ();


    // Operations

    Iterator<Type> & operator = (const Iterator<Type> &new_iterator) noexcept;

    bool operator == (const Iterator<Type> &iterator) const;
    bool operator != (const Iterator<Type> &iterator) const;

    bool operator < (const Iterator<Type> &iterator) const;
    bool operator <= (const Iterator<Type> &iterator) const;

    bool operator > (const Iterator<Type> &iterator) const;
    bool operator >= (const Iterator<Type> &iterator) const;

    Iterator<Type> operator + (size_t move) const;
    Iterator<Type> & operator += (size_t move);
    Iterator<Type> & operator ++ ();
    Iterator<Type> operator ++ (int);

    Iterator<Type> operator - (size_t move) const;
    Iterator<Type> & operator -= (size_t move);
    Iterator<Type> & operator -- ();
    Iterator<Type> operator -- (int);

private:
    std::weak_ptr<Type[]> iter_pointer;

protected:
    size_t index_cur = 0;
    size_t vector_size = 0;

    Type* get_ptr() const;

    void check_exception(int line) const;
    void check_validation(int line) const;
};


#include "../src/iterator.hpp"









#endif
