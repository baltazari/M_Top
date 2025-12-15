#pragma once


#include "Process.h"
#include <vector>

namespace sys {
    class ProcessTable {
    public:
        void refresh();

        [[nodiscard]] const std::vector<Process> &processes() const {
            return processes_;
        }

        private:
        std::vector<Process> processes_;
    };
}
