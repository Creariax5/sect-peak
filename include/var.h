#ifndef VAR_H
#define VAR_H

#include <iostream>

class Var
{
public:
    static void log(std::string str);
    enum Direction
    {
        Up = 0,
        Down = 1,
        Right = 2,
        Left = 3,
    };
};

#endif // VAR_H
