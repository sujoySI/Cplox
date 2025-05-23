#pragma once

#include "Cplox/common.hpp"

enum class OpCode: uint8_t {
    OP_CONSTANT,
    OP_RETURN,
};

struct Chunk{
    std::vector<uint8_t> code;
    std::vector<int32_t> lines;
    std::vector<double> constants;

    inline void addCode(uint8_t byte, int32_t line){
        code.push_back(byte);
        lines.push_back(line);
    }

    [[nodiscard]] inline size_t addConstants(double constant){
        constants.push_back(constant);
        return constants.size()-1;
    }
};