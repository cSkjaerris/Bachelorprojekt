#ifndef SIMPLEDLL_LIBRARY_H
#define SIMPLEDLL_LIBRARY_H

#include <iostream>
#include <stdexcept>
#include "Foo.h"

using namespace std;

Foo* foo;

extern "C"{
    //Simple dll commands (references in arguments)
    int multiply(double a, double b,double &result);
    int sumArray(double a [], int length, double &result);
    char* getVersion();
    int addValue(double a [],int length, double value);

    //Foo commands (Pointers)
    int initFoo(double initialState);
    char* getFooVersion();
    double getFooState();
}

#endif