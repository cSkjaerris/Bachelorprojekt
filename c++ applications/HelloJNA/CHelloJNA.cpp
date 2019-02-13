//
// Created by Casper Skjærris on 2019-02-08.
//

#include "CHelloJNA.h"
#include "library.h"

void sayHello(const char* name){
    Hello h;
    h.sayHello(string(name));
}

struct CHelloResponse helloTest(const struct CHelloRequest &request){
    HelloRequest req;
    req.name = string(request.name);
    req.message = string(request.message);

    Hello h;
    HelloResponse res = h.hello(req);
    CHelloResponse response;
    response.message = res.message.c_str();
    return response;
}

struct CHelloResponse hello(const char* message){
    CHelloResponse response;
    response.message = message;
    return response;

}