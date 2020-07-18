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

// void funcName(T first, Args ... everythingElse)
// {
//     funcName( everythingElse... ); //recursive call
// }

template<typename T, typename ...Args>
void variadicHelper(T first, Args ... everythingElse)
{
    variadicHelper( everythingElse...);
    Wrapper wrapper; //6) 
    wrapper(first).print();
}

Constructor(Args&& ... args) :
member(std::forward<Args>(args)...)



// void func(int i)
//     {
//         std::cout << "i: " << i << std::endl;
        
//         if( i > 0 )
//         {
//             func(i-1); //calling itself with an updated value based on the input
//         }
        
//         std::cout << "done!" << std::endl;
//     }





template<typename ... Type>
struct Wrapper
{
    Wrapper(Type&& ... t) : val(std::forward<Type>(t)...) 
    { 
        std::cout << "Wrapper(" << typeid(val).name() << ")" << std::endl; 
    }

    print() // 5)
    {
        if ( variadicHelper(first) == 3.5)
        {
            std::cout <<  "Wrapper::print(3.5)" << std::endl;
        }
    }


};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    variadicHelper( 3, std::string("burgers"), 2.5, Point{3.f, 0.14f} );
}


