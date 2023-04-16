#ifndef VECTOR2D_H_INCLUDED
#define VECTOR2D_H_INCLUDED
#include <iostream>

template <typename T>
class Vector2D;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& obj);

template <typename T>
class Vector2D
{
public:
    T x;
    T y;
    Vector2D<T>(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    Vector2D<T>(T num)
    {
        this->x = num;
        this->y = num;
    }
    Vector2D<T> operator+(const Vector2D<T>& obj);
    Vector2D<T>& operator+=(const Vector2D<T>& obj);
    Vector2D<T> operator*(float num);
    Vector2D<T>& operator*=(float num);
    bool operator==(const Vector2D<T>& obj);
    friend std::ostream& operator<< <>( std::ostream& os, const Vector2D& obj ) ;
};


template <typename T>
Vector2D<T>& Vector2D<T>::operator*=(float num)
{
    x *= num;
    y *= num;
    return *this;
}

template <typename T>
Vector2D<T> Vector2D<T>::operator*(float num)
{
    Vector2D<T> tmp(*this);
    tmp.x *= num;
    tmp.y *= num;
    return tmp;
}

template <typename T>
bool Vector2D<T>::operator==(const Vector2D<T>& obj)
{
    return (x == obj.x && y == obj.y);
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T>& obj)
{
    this->x += obj.x;
    this->y += obj.y;
    return *this;
}

template <typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& obj)
{
    Vector2D<T> tmp(*this);
    tmp += obj;
    return tmp;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& obj)
{
    std::cout << "x = " << obj.x << " y = " << obj.y << std::endl;
    return os;
}

#endif // VECTOR2D_H_INCLUDED
