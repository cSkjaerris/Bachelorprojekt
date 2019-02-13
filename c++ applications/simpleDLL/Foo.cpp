//
// Created by Casper Skjærris on 2019-02-13.
//

#include "Foo.h"
using namespace std;
Foo::Foo() {
    string v = "4.5.6";
    char* version = new char[v.length() +1];
    strcpy(version, v.c_str());
    m_version = version;
}

int Foo::init(double initialState) {
    m_state = initialState;
    return 0;
}

char* Foo::getVersion() {
    return m_version;
}

double Foo::getState() {
    m_state += 0.1;
    return m_state;
}
