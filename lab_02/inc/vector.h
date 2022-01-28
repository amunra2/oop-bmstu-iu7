#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
#include <math.h>

#include "../inc/base_vector.h"
#include "../inc/const_iterator.h"
#include "../inc/iterator.h"
#include "../inc/errors_list.h"


template <typename Type>
class Vector: public BaseVector
{
public:
    friend class Iterator<Type>;

    friend class IteratorConst<Type>;

    //todo Constructors
    Vector ();

    Vector (std::initializer_list<Type> args); // по списку
    explicit Vector (size_t size);
    Vector(size_t size, const Type *arr);
    template <typename Type1>
    Vector(Type1 begin, Type1 end);

    virtual ~Vector () = default; // Destructor

    explicit Vector(const Vector<Type> &); // копирования
    Vector(Vector<Type> &&) noexcept; // переноса

    //todo Iterator

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;

    IteratorConst<Type> begin() const noexcept;
    IteratorConst<Type> end() const noexcept;
    IteratorConst<Type> cBegin() const noexcept;
    IteratorConst<Type> cEnd() const noexcept;

    //todo Additional

    Vector<Type> &operator = (std::initializer_list<Type> &args);
    Vector<Type> &operator = (const Vector<Type> &vector);
    Vector<Type> &operator = (Vector<Type> &&vector) noexcept;

    bool is_single() const;
    bool is_zero() const;

    template <typename Type1>
    Type1 get_length() const; // длина вектора

    template <typename Type1>
    Vector<Type1> get_norm() const; // нормирование
    
    bool check_collinear(const Vector<Type> &vector) const; // коллинеарность
    bool check_orthogonal(const Vector<Type> &vector) const; // ортогональность

    double get_angle(const Vector<Type> &vector) const;

    Vector<Type> negative();
    Vector<Type> operator - ();

    //todo Index
    Type &operator [] (size_t place);
    const Type &operator [] (size_t place) const;

    Type &at(size_t place);
    const Type &at(size_t place) const;

    void set(size_t place, const Type &elem);

    //todo Operations

    //todo Plus

    Vector<Type> operator + (const Vector<Type> &vector) const;
    Vector<Type> operator + (const Type &num) const;

    template<typename Type1>
    decltype(auto) operator + (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) operator + (const Type1 &num) const;

    Vector<Type> sum_vect(const Vector<Type> &vector) const;
    Vector<Type> sum_num(const Type &num) const;

    template<typename Type1>
    decltype(auto) sum_vect(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) sum_num(const Type1 &num) const;

    Vector<Type> &operator += (const Vector<Type> &vector);
    Vector<Type> &operator += (const Type &num);

    void sum_eq(const Vector<Type> &vector);
    void sum_eq(const Type &num);

    //todo Minus

    Vector<Type> operator - (const Vector<Type> &vector) const;
    Vector<Type> operator - (const Type &num) const;

    template<typename Type1>
    decltype(auto) operator - (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) operator - (const Type1 &num) const;

    Vector<Type> diff_vect(const Vector<Type> &vector) const;
    Vector<Type> diff_num(const Type &num) const;

    template<typename Type1>
    decltype(auto) diff_vect(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) diff_num(const Type1 &num) const;

    Vector<Type> &operator -= (const Vector<Type> &vector);
    Vector<Type> &operator -= (const Type &num);

    void diff_eq(const Vector<Type> &vector);
    void diff_eq(const Type &num);

    //todo Multi

    Vector<Type> operator * (const Vector<Type> &vector) const;
    Vector<Type> operator * (const Type &num) const;

    template<typename Type1>
    decltype(auto) operator * (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) operator * (const Type1 &num) const;

    Vector<Type> mult_vect(const Vector<Type> &vector) const;
    Vector<Type> mult_num(const Type &num) const;

    template<typename Type1>
    decltype(auto) mult_vect(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) mult_num(const Type1 &num) const;


    Vector<Type> &operator *= (const Vector<Type> &vector);
    Vector<Type> &operator *= (const Type &num);

    void mult_eq(const Vector<Type> &vector);
    void mult_eq(const Type &num);

    //todo Div

    Vector<Type> operator / (const Vector<Type> &vector) const;
    Vector<Type> operator / (const Type &num) const;

    template<typename Type1>
    decltype(auto) operator / (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) operator / (const Type1 &num) const;

    Vector<Type> div_vect(const Vector<Type> &vector) const;
    Vector<Type> div_num(const Type &num) const;

    template<typename Type1>
    decltype(auto) div_vect(const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) div_num(const Type1 &num) const;


    Vector<Type> &operator /= (const Vector<Type> &vector);
    Vector<Type> &operator /= (const Type &num);

    void div_eq(const Vector<Type> &vector);
    void div_eq(const Type &num);

    //todo mult - scalar & vector

    Vector<Type> operator ^ (const Vector<Type> &vector) const; // векторное произведие
    Vector<Type> vector_mult(const Vector<Type> &vector) const;

    Vector<Type> &operator ^= (const Vector<Type> &vector);
    void vector_mult_eq(const Vector<Type> &vector);

    //todo mult - &

    Type scalar_mult(const Vector<Type> &vector) const;
    Type operator & (const Vector<Type> &vector) const; // скалярное произведие

    //todo Comparsions

    bool operator == (const Vector<Type> &vector) const;
    bool is_equal(const Vector<Type> &vector) const;

    bool operator != (const Vector<Type> &vector) const;
    bool not_equal(const Vector<Type> &vector) const;

    //todo Utils

    Type summary();

protected:
    void allocate_memory(size_t vec_size);

    void check_size(const Vector<Type> &vector, int line) const;

    void check_size_vector_mul(const Vector<Type> &vector, int line) const;

private:
    std::shared_ptr<Type[]> data;
};


#include "../src/vector.hpp"


#endif
