#include <fmt/core.h>
#include "Cplox/common.hpp"
#include "Cplox/chunk.hpp"
#include "Cplox/debug.hpp"

int main(int argc, const char* argv[])
{
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, static_cast<uint8_t>(OpCode::OP_RETURN));
//    fmt::print("sjdcjxhjdchj {}",78);
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}