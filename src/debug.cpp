#include <cstdio>
#include <fmt/core.h>
#include "fmt/core.h"
#include "Cplox/debug.hpp"
#include "Cplox/chunk.hpp"


void disassembleChunk(Chunk& chunk, std::string_view name){
    fmt::print("== {} ==\n", name);

    for(int offset = 0; offset < chunk.code.size(); ) {
        offset = disassembleInstruction(chunk, offset);
    }
}

static int constantInstruction(std::string_view name, Chunk& chunk, int offset){
    uint8_t constant = chunk.code[offset + 1];
    fmt::print("{:<16} {:4d} '", name, constant);
    fmt::print("{}",chunk.constants[constant]);
    fmt::print("'\n");
    return offset + 2;
}

//const char* , size -> string_view
int simpleInstruction(std::string_view name, int offset) {
    fmt::print("{}\n", name);

    return offset + 1;
}

int disassembleInstruction(Chunk& chunk, int offset){
    fmt::print("{:04d} ", offset);
    if(offset > 0 && chunk.lines[offset] == chunk.lines[offset - 1]){
        fmt::print("   | ");
    } else {
        fmt::print("{:04d} ", chunk.lines[offset]);
    }
    uint8_t instruction = chunk.code[offset];
    switch (instruction) {
        case static_cast<uint8_t>(OpCode::OP_RETURN): {
            return simpleInstruction("OP_RETURN", offset);
        }
        case static_cast<uint8_t>(OpCode::OP_CONSTANT): {
            return constantInstruction("OP_CONSTANT", chunk, offset);
        }
        default: {
            fmt::print("Unknown opcode {}\n", instruction);
            return offset + 1;
        }
    }
}