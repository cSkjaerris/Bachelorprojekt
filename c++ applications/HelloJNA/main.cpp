//
// Created by Casper Skjærris on 2019-02-08.
//
#include <iostream>
#include "CHelloJNA.h"
#include "library.h"

int main(){
    sayHello("testName");
    CHelloRequest req ={};
    req.name = "Request name";
    req.message = "Some message";
    CHelloResponse res;
    res = hello("hej");
    cout << res.message << endl;
    CHelloResponse res2;
    res2 = helloTest(req);
    //CHelloResponse res2 = helloTest(req);
    cout << res2.message << endl;
    return 0;
}