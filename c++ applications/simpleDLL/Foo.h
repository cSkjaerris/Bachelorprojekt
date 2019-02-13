//
// Created by Casper Skjærris on 2019-02-13.
//

#ifndef SIMPLEDLL_FOO_H
#define SIMPLEDLL_FOO_H

#include <string>

class Foo {
private:
    char* m_version;
    double m_state;

public:
    Foo();
    int init(double initialState);
    char* getVersion();
    double getState();
};


#endif //SIMPLEDLL_FOO_H
