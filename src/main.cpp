#include <fmt/core.h>
#include "Cplox/common.hpp"
#include "Cplox/chunk.hpp"
#include "Cplox/debug.hpp"

int main(int argc, const char* argv[])
{
    Chunk chunk{};
    auto constant = chunk.addConstants(1.2);
    chunk.addCode(static_cast<uint8_t>(OpCode::OP_CONSTANT), 123);
    chunk.addCode(constant, 123);
    chunk.addCode(static_cast<uint8_t>(OpCode::OP_RETURN), 123);
//    fmt::print("sjdcjxhjdchj {}",78);
    disassembleChunk(chunk, "test chunk");
    return 0;
}