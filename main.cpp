/*
 Project 9: Part 1/1
 Chapter 5 Part 7 Task

 Create a branch named Part1

Purpose:  This project will teach you about variadic templates and recursive templates, one of the last areas needing discussion while learning C++

 
1) read Instructions.cpp

Make the following program work, which makes use of Variadic templates and Recursion
 */
 
#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>

struct Point
{
    Point(float _x, float _y) : x(_x), y(_y) { }
    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }
    std::string toString() const
    {
        std::string str;
        str +="Point { x: ";
        str += std::to_string(x);
        str += ", y: ";
        str += std::to_string(y);
        str += " }";
        return str;
    }
private:
    float x{0}, y{0};
};

template<typename Type>
struct Wrapper
{
    Wrapper(Type&& t) : val(std::move(t)) 
    { 
        std::cout << "Wrapper(" << typeid(val).name() << ")" << std::endl; 
    }

    void print() // 5)
    {
        std::cout <<  "Wrapper::print(" << val << ")" << std::endl;
    }
    Type val;
};

template<>
struct Wrapper<Point>
{
    Wrapper(Point&& t) : val(std::move(t))
    {
        std::cout << "Wrapper(" << typeid(val).name() << ")" << std::endl;
    }

    void print()
    {
        std::cout <<  "Wrapper::print(" << val.toString() << ")" << std::endl;
    }
    Point val;
};

void variadicHelper()
{
    std::cout << "done\n";
}
//+++++++++SINGLE TEMPLATE++++++++++++++++
// template<typename T>
// void variadicHelper(T&& first)
// {
//     Wrapper wrapper(std::forward<T>(first) );
//     wrapper.print();
// }

//+++++++++VARIADIC TEMPLATE+++++++++++++++
template<typename T, typename ...Args>
void variadicHelper(T&& first, Args&& ... everythingElse) // how do I remove 1st element?!
{
    Wrapper wrapper (std::forward<T>(first) ); //6) 
    wrapper.print();
    variadicHelper( std::forward<Args>(everythingElse) ...); // recursive call
}

int main()
{
    variadicHelper( 3, std::string("burgers"), 2.5, Point{3.f, 0.14f} );   
}

