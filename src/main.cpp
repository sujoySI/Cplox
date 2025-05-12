#include <fmt/core.h>
#include "Cplox/common.hpp"
#include "Cplox/chunk.hpp"
#include "Cplox/debug.hpp"

int main(int argc, const char* argv[])
{
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, static_cast<uint8_t>(OpCode::OP_CONSTANT), 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, static_cast<uint8_t>(OpCode::OP_RETURN), 123);
//    fmt::print("sjdcjxhjdchj {}",78);
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}