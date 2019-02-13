//
// Created by Casper Skjærris on 2019-02-08.
//

#ifndef HELLOJNA_CHELLOJNA_H
#define HELLOJNA_CHELLOJNA_H

extern "C" {
struct CHelloRequest {
    const char* name;
    const char* message;
};
struct CHelloResponse {
    const char* message;
};

void sayHello(const char *name);
struct CHelloResponse hello(const char *message);
struct CHelloResponse helloTest(const struct CHelloRequest &request);
}


#endif //HELLOJNA_CHELLOJNA_H
