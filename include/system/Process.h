#pragma once

#include <string>

namespace sys {
    struct Process {
        int pid{};
        std::string name;
        long memoryKB{};
    };
}
