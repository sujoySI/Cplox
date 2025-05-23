#pragma once

#include <string_view>
#include "Cplox/chunk.hpp"

void disassembleChunk(Chunk& chunk, std::string_view name);
int disassembleInstruction(Chunk& chunk, int offset);