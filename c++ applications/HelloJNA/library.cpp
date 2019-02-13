#include "library.h"

void Hello::sayHello(const string &name) const {
    cout << "Hello, " << name << endl;
}

struct HelloResponse Hello::hello(const struct HelloRequest &request) {
    HelloResponse res;
    res.message = request.message + ", " + request.name;
    return res;
}