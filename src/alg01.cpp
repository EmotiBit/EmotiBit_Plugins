#include "alg01.h"

int Rounder::round(double num) {
    return static_cast<int>(std::round(num));
}

#include "export_to_pyd.h"
