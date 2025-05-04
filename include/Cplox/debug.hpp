#pragma once

#include "Cplox/chunk.hpp"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);