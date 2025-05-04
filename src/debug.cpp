#include <cstdio>
#include <fmt/core.h>
#include "Cplox/debug.hpp"
#include "Cplox/chunk.hpp"
#include <string_view>
#include "fmt/base.h"

void disassembleChunk(Chunk* chunk, const char* name){
    fmt::println("== {} ==", name);
    for(int offset = 0; offset < chunk->count; ) {
        offset = disassembleInstruction(chunk, offset);
    }
}

//const char* , size -> string_view
int simpleInstruction(std::string_view name, int offset) {
    fmt::println("{}", name);
    return offset + 1;
}

int disassembleInstruction(Chunk* chunk, int offset){
    fmt::print("{:04d} ", offset);

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case static_cast<uint8_t>(OpCode::OP_RETURN): {
            return simpleInstruction("OP_RETURN", offset);
        }
        default: {
            fmt::println("Unknown opcode {}", instruction);
            return offset + 1;
        }
    }
}