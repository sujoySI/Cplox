#pragma once

#include "Cplox/common.hpp"

enum class OpCode: uint8_t {
    OP_RETURN,
};

struct Chunk{
    int count;
    int capacity;
    uint8_t* code;
};

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
