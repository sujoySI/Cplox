#pragma once

#include "Cplox/common.hpp"

using Value = double;
//typedef double Value;

struct ValueArray {
    int capacity;
    int count;
    Value* values;
};

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);