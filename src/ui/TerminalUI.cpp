#include "ui/TerminalUI.h"
#include <iomanip>
#include <iostream>


namespace ui {
    void TerminalUI::render(const sys::ProcessTable &table) const {
        constexpr int l_Pid = 8, l_Name = 30, l_Mem = 10;
        //Clear screen and move cursor to top-left
        std::cout << "\033[2J\033[H";

        std::cout << "cpp-process-manager (M_Top)\n";
        std::cout << "Press Ctrl+C to exit. \n\n";

        std::cout << std::left
                << std::setw(l_Pid) << "PID"
                << std::setw(l_Name) << "NAME"
                << std::setw(l_Mem) << "MEM(KB)"
                << "\n";
        std::cout << std::string(l_Pid + l_Name + l_Mem, '-') << "\n";
        const auto &processes = table.processes();

        const std::size_t maxRows = 25;
        std::size_t count = 0;
        for (const auto &p: processes) {
            if (count++ >= maxRows)
                break;

            std::cout << std::left
                    << std::setw(8) << p.pid
                    << std::setw(30) << p.name.substr(0, 28)
                    << std::setw(10) << p.memoryKB
                    << "\n";
        }

        std::cout << "\nTotal processes: " << processes.size() << std::endl;
    }
}
