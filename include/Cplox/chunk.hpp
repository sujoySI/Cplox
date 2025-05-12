#pragma once

#include "Cplox/common.hpp"
#include "Cplox/value.hpp"

enum class OpCode: uint8_t {
    OP_CONSTANT,
    OP_RETURN,
};

struct Chunk{
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
};

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
