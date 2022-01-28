#ifndef VECTOR_HPP

#define VECTOR_HPP

#include "../inc/vector.h"

// Constructors

template<typename Type>
Vector<Type>::Vector (std::initializer_list<Type> args)  // initializer_list
{
    this->size = size_t(args.size());

    this->allocate_memory(size);

    Iterator<Type> iter = this->begin();

    for (auto elem : args)
    {
        *iter = elem;
        iter++;
    }
}


template<typename Type>
Vector<Type>::Vector (size_t size_vect)
{
    this->allocate_memory(size_vect);

    this->size = size_vect;

    Iterator<Type> iter_cur = this->begin();

    for (; iter_cur; iter_cur++)
    {
        *iter_cur = 0;
    }
}


template<typename Type>
Vector<Type>::Vector(size_t size_vect, const Type *arr)
{
    if (size_vect == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    if (!arr)
    {
        time_t current_time = time(NULL);

        throw ExceptCopyArr(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->allocate_memory(size_vect);

    this->size = size_vect;

    Iterator<Type> iter_to = this->begin();

    for (size_t i_from = 0; iter_to; iter_to++, i_from++)
    {
        *iter_to = arr[i_from];
    }
}


template <typename Type>
template <typename Type1>
Vector<Type>::Vector(Type1 begin, Type1 end)
{
    Type1 tmp = begin;

    int i = 0;

    for (auto iter = begin; iter != end; iter++)
    {
        i++;
    }

    this->size = i;
    this->allocate_memory(size);

    i = 0;

    for (auto iter = begin; iter != end; iter++)
    {
        this->data[i++] = *iter;
    }
}


template<typename Type>
Vector<Type>::Vector ()
{
    this->size = 0;

    this->allocate_memory(this->size);
}


template <typename Type>
Vector<Type>::Vector(const Vector<Type> & vector): BaseVector(vector.size)
{
    *this = vector;
}


template <typename Type>
Vector<Type>::Vector(Vector<Type> && vector) noexcept : BaseVector(vector.size)
{
    this->size = vector.size;

    vector.data = nullptr;
}


// Iterator

template<typename Type>
IteratorConst<Type> Vector<Type>::cBegin() const noexcept
{
    IteratorConst<Type> iterator_begin(*this);

    return iterator_begin;
}


template<typename Type>
IteratorConst<Type> Vector<Type>::cEnd() const noexcept
{
    IteratorConst<Type> iterator_end(*this);

    return iterator_end + this->size;
}


template<typename Type>
IteratorConst<Type> Vector<Type>::begin() const noexcept
{
    IteratorConst<Type> iterator_begin(*this);

    return iterator_begin;
}


template<typename Type>
IteratorConst<Type> Vector<Type>::end() const noexcept
{
    IteratorConst<Type> iterator_end(*this);

    return iterator_end + this->size;
}


template<typename Type>
Iterator<Type> Vector<Type>::begin() noexcept
{
    Iterator<Type> iterator_begin(*this);

    return iterator_begin;
}


template<typename Type>
Iterator<Type> Vector<Type>::end() noexcept
{
    Iterator<Type> iterator_end(*this);

    return iterator_end + this->size;
}

// Actions

// Plus

template<typename Type>
Vector<Type> &Vector<Type>::operator += (const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->sum_vect(vector);

    return *this;
}


template<typename Type>
Vector<Type> &Vector<Type>::operator += (const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->sum_num(num);

    return *this;
}


template<typename Type>
Vector<Type> Vector<Type>::operator + (const Vector<Type> &vector) const
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->sum_vect(vector);
}


template<typename Type>
Vector<Type> Vector<Type>::operator + (const Type &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->sum_num(num);
}


template<typename Type>
Vector<Type> Vector<Type>::sum_vect(const Vector<Type> &vector) const
{
    Vector<Type> res(*this);

    IteratorConst<Type> iter_cur = vector.begin();
    Iterator<Type> iter_begin = res.begin();

    for (; iter_cur; iter_begin++, iter_cur++)
    {
        *iter_begin = *iter_begin + *iter_cur;
    }

    return res;
}


template<typename Type>
Vector<Type> Vector<Type>::sum_num(const Type &num) const
{
    Vector<Type> res(*this);

    Iterator<Type> iter_begin = res.begin();

    for (; iter_begin; iter_begin++)
    {
        *iter_begin = *iter_begin + num;
    }

    return res;
}


template<typename Type>
void Vector<Type>::sum_eq(const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->sum_vect(vector);
}



template<typename Type>
void Vector<Type>::sum_eq(const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->sum_num(num);
}


template <typename Type>
template <typename Type1>
decltype(auto) Vector<Type>::operator + (const Type1 &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        std::cout << this->size << std::endl;

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->sum_num(num);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator + (const Vector<Type1> &vector) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->sum_vect(vector);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sum_vect(const Vector<Type1> &vector) const
{
    Vector<decltype(this->data[0] + vector.at(0))> res(*this);

    Iterator<decltype(this->data[0] + vector.at(0))> iter_to = res.begin();
    IteratorConst<Type1> iter_from = vector.begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_to + *iter_from;
    }

    return res;
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sum_num(const Type1 &num) const
{
    Vector<decltype(this->data[0] + num)> res(this->size);

    Iterator<decltype(this->data[0] + num)> iter_to = res.begin();
    IteratorConst<Type> iter_from = this->begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_from + num;
    }

    return res;
}

// Minus

template<typename Type>
Vector<Type> &Vector<Type>::operator -= (const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->diff_vect(vector);

    return *this;
}


template<typename Type>
Vector<Type> &Vector<Type>::operator -= (const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->diff_num(num);

    return *this;
}


template<typename Type>
Vector<Type> Vector<Type>::operator - (const Vector<Type> &vector) const
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->diff_vect(vector);
}


template<typename Type>
Vector<Type> Vector<Type>::operator - (const Type &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->diff_num(num);
}


template<typename Type>
Vector<Type> Vector<Type>::diff_vect(const Vector<Type> &vector) const
{
    Vector<Type> res(*this);

    IteratorConst<Type> iter_cur = vector.begin();
    Iterator<Type> iter_begin = res.begin();

    for (; iter_cur; iter_begin++, iter_cur++)
    {
        *iter_begin = *iter_begin - *iter_cur;
    }

    return res;
}


template<typename Type>
Vector<Type> Vector<Type>::diff_num(const Type &num) const
{
    Vector<Type> res(*this);

    Iterator<Type> iter_begin = res.begin();

    for (; iter_begin; iter_begin++)
    {
        *iter_begin = *iter_begin - num;
    }

    return res;
}


template<typename Type>
void Vector<Type>::diff_eq(const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->diff_vect(vector);
}



template<typename Type>
void Vector<Type>::diff_eq(const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->diff_num(num);
}


template <typename Type>
template <typename Type1>
decltype(auto) Vector<Type>::operator - (const Type1 &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        std::cout << this->size << std::endl;

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->diff_num(num);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator - (const Vector<Type1> &vector) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->diff_vect(vector);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::diff_vect(const Vector<Type1> &vector) const
{
    Vector<decltype(this->data[0] + vector.at(0))> res(*this);

    Iterator<decltype(this->data[0] + vector.at(0))> iter_to = res.begin();
    IteratorConst<Type1> iter_from = vector.begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_to - *iter_from;
    }

    return res;
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::diff_num(const Type1 &num) const
{
    Vector<decltype(this->data[0] + num)> res(this->size);

    Iterator<decltype(this->data[0] + num)> iter_to = res.begin();
    IteratorConst<Type> iter_from = this->begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_from - num;
    }

    return res;
}


// Multi

template<typename Type>
Vector<Type> &Vector<Type>::operator *= (const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->mult_vect(vector);

    return *this;
}


template<typename Type>
Vector<Type> &Vector<Type>::operator *= (const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->mult_num(num);

    return *this;
}


template<typename Type>
Vector<Type> Vector<Type>::operator * (const Vector<Type> &vector) const
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->mult_vect(vector);
}


template<typename Type>
Vector<Type> Vector<Type>::operator * (const Type &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->mult_num(num);
}


template<typename Type>
Vector<Type> Vector<Type>::mult_vect(const Vector<Type> &vector) const
{
    Vector<Type> res(*this);

    IteratorConst<Type> iter_cur = vector.begin();
    Iterator<Type> iter_begin = res.begin();

    for (; iter_cur; iter_begin++, iter_cur++)
    {
        *iter_begin = *iter_begin * *iter_cur;
    }

    return res;
}


template<typename Type>
Vector<Type> Vector<Type>::mult_num(const Type &num) const
{
    Vector<Type> res(*this);

    Iterator<Type> iter_begin = res.begin();

    for (; iter_begin; iter_begin++)
    {
        *iter_begin = *iter_begin * num;
    }

    return res;
}


template<typename Type>
void Vector<Type>::mult_eq(const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->mult_vect(vector);
}



template<typename Type>
void Vector<Type>::mult_eq(const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->mult_num(num);
}


template <typename Type>
template <typename Type1>
decltype(auto) Vector<Type>::operator * (const Type1 &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        std::cout << this->size << std::endl;

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->mult_num(num);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator * (const Vector<Type1> &vector) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->mult_vect(vector);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::mult_vect(const Vector<Type1> &vector) const
{
    Vector<decltype(this->data[0] + vector.at(0))> res(*this);

    Iterator<decltype(this->data[0] + vector.at(0))> iter_to = res.begin();
    IteratorConst<Type1> iter_from = vector.begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_to * *iter_from;
    }

    return res;
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::mult_num(const Type1 &num) const
{
    Vector<decltype(this->data[0] + num)> res(this->size);

    Iterator<decltype(this->data[0] + num)> iter_to = res.begin();
    IteratorConst<Type> iter_from = this->begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_from * num;
    }

    return res;
}


// Divide


template<typename Type>
Vector<Type> &Vector<Type>::operator /= (const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->div_vect(vector);

    return *this;
}


template<typename Type>
Vector<Type> &Vector<Type>::operator /= (const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->div_num(num);

    return *this;
}


template<typename Type>
Vector<Type> Vector<Type>::operator / (const Vector<Type> &vector) const
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->div_vect(vector);
}


template<typename Type>
Vector<Type> Vector<Type>::operator / (const Type &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->div_num(num);
}


template<typename Type>
Vector<Type> Vector<Type>::div_vect(const Vector<Type> &vector) const
{
    Vector<Type> res(*this);

    IteratorConst<Type> iter_cur = vector.begin();
    Iterator<Type> iter_begin = res.begin();

    for (; iter_cur; iter_begin++, iter_cur++)
    {
        if (*iter_cur == 0)
        {
            time_t current_time = time(NULL);

            throw ExceptDivisionByZero(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
        }

        *iter_begin = *iter_begin / *iter_cur;
    }

    return res;
}


template<typename Type>
Vector<Type> Vector<Type>::div_num(const Type &num) const
{
    if (num == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptDivisionByZero(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    Vector<Type> res(*this);

    Iterator<Type> iter_begin = res.begin();

    for (; iter_begin; iter_begin++)
    {
        *iter_begin = *iter_begin / num;
    }

    return res;
}


template<typename Type>
void Vector<Type>::div_eq(const Vector<Type> &vector)
{
    if (this->size == 0 || vector.size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    this->check_size(vector, __LINE__);

    *this = this->div_vect(vector);
}



template<typename Type>
void Vector<Type>::div_eq(const Type &num)
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    *this = this->div_num(num);
}


template <typename Type>
template <typename Type1>
decltype(auto) Vector<Type>::operator / (const Type1 &num) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        std::cout << this->size << std::endl;

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->div_num(num);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator / (const Vector<Type1> &vector) const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    return this->div_vect(vector);
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::div_vect(const Vector<Type1> &vector) const
{
    Vector<decltype(this->data[0] + vector.at(0))> res(*this);

    Iterator<decltype(this->data[0] + vector.at(0))> iter_to = res.begin();
    IteratorConst<Type1> iter_from = vector.begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        if (*iter_from == 0)
        {
            time_t current_time = time(NULL);

            throw ExceptDivisionByZero(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
        }

        *iter_to = *iter_to / *iter_from;
    }

    return res;
}


template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::div_num(const Type1 &num) const
{
    if (num == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptDivisionByZero(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    Vector<decltype(this->data[0] + num)> res(this->size);

    Iterator<decltype(this->data[0] + num)> iter_to = res.begin();
    IteratorConst<Type> iter_from = this->begin();

    for (; iter_to; iter_from++, iter_to++)
    {
        *iter_to = *iter_from / num;
    }

    return res;
}


// Vect and scalar

template <typename Type>
Type Vector<Type>::scalar_mult(const Vector<Type> &vector) const
{
    check_size(vector, __LINE__);

    Type res = this->mult_vect(vector).summary();

    return res;
}


template <typename Type>
Type Vector<Type>::operator & (const Vector<Type> &vector) const
{
    return this->scalar_mult(vector);
}


template <typename Type>
Vector<Type> Vector<Type>::vector_mult(const Vector<Type> &vector) const
{
    check_size_vector_mul(vector, __LINE__);

    Type x = -this->data[1] * vector.data[2] + this->data[2] * vector.data[1];
    Type y = -this->data[2] * vector.data[0] + this->data[0] * vector.data[2];
    Type z = -this->data[0] * vector.data[1] + this->data[1] * vector.data[0];

    Vector<Type> res = {-x, -y, -z};

    return res;
}


template <typename Type>
Vector<Type> Vector<Type>::operator ^ (const Vector<Type> &vector) const
{
    return this->vector_mult(vector);
}


template <typename Type>
void Vector<Type>::vector_mult_eq(const Vector<Type> &vector)
{
    *this = this->vector_mult(vector);
}


template <typename Type>
Vector<Type> &Vector<Type>::operator ^= (const Vector<Type> &vector)
{
    this->vector_mult_eq(vector);

    return *this;
}


// Additional

template<typename Type>
Vector<Type> &Vector<Type>::operator = (const Vector<Type> &vector)
{
    this->size = vector.size;

    this->allocate_memory(size);

    Iterator<Type> iter_to(*this);
    Iterator<Type> iter_from(vector);

    for (; iter_to; iter_to++, iter_from++)
    {
        *iter_to = *iter_from;
    }

    return *this;
}


template <typename Type>
Vector<Type> &Vector<Type>::operator = (std::initializer_list<Type> &args)
{
    this->size = args.size();

    this->allocate_memory(size);

    Iterator<Type> iter = this->begin();

    for (auto elem : args)
    {
        *iter = elem;
        iter++;
    }

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator = (Vector<Type> &&vector) noexcept
{
    this->size = vector.size;
    this->allocate_memory(size);

    this->data = vector.data;

    vector.data.reset();

    return *this;
}


template <typename Type>
bool Vector<Type>::is_single() const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    IteratorConst<Type> iter = this->begin();

    bool single = true;

    for (; iter && single; iter++) // ???
    {
        if (*iter != 1)
        {
            single = false;
        }
    }

    return single;
}


template <typename Type>
bool Vector<Type>::is_zero() const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    IteratorConst<Type> iter = this->begin();

    bool zero = true;

    for (; iter && zero; iter++)
    {
        if (*iter != 0)
        {
            zero = false;
        }
    }

    return zero;
}


template<typename Type>
template<typename Type1>
Type1 Vector<Type>::get_length() const
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    Type1 res = 0;

    IteratorConst<Type> iter = this->begin();

    for (; iter; iter++)
    {
        res += (*iter * *iter);
    }

    return sqrt(res);
}


template<typename Type>
template<typename Type1>
Vector<Type1> Vector<Type>::get_norm() const
{
    Vector<Type1> normed_vector(size);

    Type1 length = this->get_length<Type1>();

    IteratorConst<Type> iter_from = this->begin();
    Iterator<Type1> iter_to = normed_vector.begin();

    for (; iter_from; iter_from++, iter_to++)
    {
        *iter_to = *iter_from / length;
    }

    return normed_vector;
}


template<typename Type>
bool Vector<Type>::check_collinear(const Vector<Type> &vector) const
{
    if (this->get_angle(vector) < __FLT_EPSILON__)
    {
        return true;
    }

    return false;
}


template<typename Type>
bool Vector<Type>::check_orthogonal(const Vector<Type> &vector) const
{
    if (this->get_angle(vector) - 90 < __FLT_EPSILON__)
    {
        return true;
    }

    return false;
}


template<typename Type>
double Vector<Type>::get_angle(const Vector<Type> &vector) const
{
    if (this->get_length<double>() == 0 || vector.get_length<double>() == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptDivisionByZero(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    double angle = (*this & vector) / (this->get_length<double>() * vector.get_length<double>());

    return acos(angle) * 180 / M_PI;
}


template<typename Type>
Vector<Type> Vector<Type>::negative()
{
    Vector<Type> negative_vect(*this);

    Iterator<Type> iter = negative_vect.begin();

    for (; iter; iter++)
    {
        *iter = -*iter;
    }

    return negative_vect;
}



template<typename Type>
Vector<Type> Vector<Type>::operator - ()
{
    return this->negative();
}


// Index

template <typename Type>
Type & Vector<Type>::at(size_t place)
{
    if (place >= size || place < 0)
    {
        time_t current_time = time(NULL);

        throw ExceptIteration(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    Iterator<Type> iter = this->begin();

    for (size_t i = 0; i < place; iter++, i++) { }

    return *iter;
}


template <typename Type>
const Type & Vector<Type>::at(size_t place) const
{
    if (place >= size || place < 0)
    {
        time_t current_time = time(NULL);

        throw ExceptIteration(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    IteratorConst<Type> iter = this->begin();

    for (size_t i = 0; i < place; iter++, i++) { }

    return *iter;
}


template <typename Type>
Type &Vector<Type>::operator [] (size_t index)
{
    return this->at(index);
}


template <typename Type>
const Type &Vector<Type>::operator [] (size_t index) const
{
    return this->at(index);
}


template <typename Type>
void Vector<Type>::set(size_t place, const Type &elem)
{
    if (place >= size || place < 0)
    {
        time_t current_time = time(NULL);

        throw ExceptIteration(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    at(place) = elem;
}


// Comparsions

template<typename Type>
bool Vector<Type>::is_equal(const Vector<Type> &vector) const
{
    if (this->size != vector.size)
    {
        return false;
    }

    bool equal = true;

    IteratorConst<Type> iter_from = this->begin();
    IteratorConst<Type> iter_to = vector.begin();

    for (; iter_from && equal; iter_from++, iter_to++)
    {
        if (std::abs(*iter_from - *iter_to) > __FLT_EPSILON__)
        {
            equal = false;
        }
    }

    return equal;
}


template<typename Type>
bool Vector<Type>::operator == (const Vector<Type> &vector) const
{
    return this->is_equal(vector);
}

template<typename Type>
bool Vector<Type>::not_equal(const Vector<Type> &vector) const
{
    return !(this->is_equal(vector));
}


template<typename Type>
bool Vector<Type>::operator != (const Vector<Type> &vector) const
{
    return this->not_equal(vector);
}

//! Temporary

template<typename Type>
void Vector<Type>::allocate_memory(size_t vec_size)
{
    try
    {
        this->data.reset(new Type[vec_size]);
    }
    catch (std::bad_alloc &except)
    {
        time_t current_time = time(NULL);

        throw ExceptMemory(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }
}


template<typename Type>
std::ostream &operator << (std::ostream &os, const Vector<Type> &vector)
{
    IteratorConst<Type> iter = vector.begin();

    if (!iter)
    {
        os << "Vector is empty";

        return os;
    }

    os << "{" << *iter;

    for (iter++; iter; iter++)
    {
        os << ", " << *iter;
    }

    os << "}" ;

    return os;
}


template<typename Type>
void Vector<Type>::check_size(const Vector<Type> &vector, int line) const
{
    if (this->size != vector.size)
    {
        time_t current_time = time(NULL);

        throw ExceptSize(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}


template <typename Type>
Type Vector<Type>::summary()
{
    if (this->size == 0)
    {
        time_t current_time = time(NULL);

        throw ExceptEmptyVector(__FILE__, typeid(*this).name(), __LINE__, ctime(&current_time));
    }

    Type sum = 0;

    Iterator<Type> iter = this->begin();

    for (; iter; iter++)
    {
        sum += *iter;
    }

    return sum;
}

template <typename Type>
void Vector<Type>::check_size_vector_mul(const Vector<Type> &vector, int line) const
{
    if (this->size != 3 || vector.size != 3)
    {
        time_t current_time = time(NULL);

        throw ExceptSize(__FILE__, typeid(*this).name(), line, ctime(&current_time));
    }
}

#endif
