#include "simpleDLL.h"


int multiply(double a, double b, double &result){
    result = a*b;
    return 0;
}

int sumArray(double a [], int length, double &result){
    result = 0;
    for(int i=0;i < length;i++){
        result +=a[i];
    }
    return 0;
}

char* getVersion(){
    string v = "1.2.3";
    char* version = new char[v.length() +1];
    strcpy(version, v.c_str());
    return version;
}

int addValue(double a [], int length, double value){
    for(int i = 0;i < length;i++){
        a[i] +=value;
    }
    return 0;
}


int initFoo(double initialState){
    foo = new Foo();
    foo->init(initialState);
    return 0;
}

char* getFooVersion(){
    return foo->getVersion();
}

double getFooState(){
    return foo->getState();
}