#ifndef HELLOJNA_LIBRARY_H
#define HELLOJNA_LIBRARY_H

#include <iostream>
#include <string>
using namespace std;

struct HelloRequest {
    string name;
    string message;
};

struct HelloResponse {
    string message;
};

class Hello {
public:
    void sayHello(const string &name) const;
    struct HelloResponse hello(const struct HelloRequest &request);
};


#endif