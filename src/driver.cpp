#include "alg01.h"
#include<iostream>

int main() {
    // This file is specifically to show that the DLL example works.
    Rounder r;
    double num = 5.223;
    std::cout << r.round(num) << std::endl;
    // TODO: Test the DLL without the file and instead build it inside the OFAPP information.
}
