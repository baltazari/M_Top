#include "system/ProcessTable.h"
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

namespace sys {
    namespace {
        bool isAllDigits(const std::string &str) {
            return !str.empty() && std::all_of(str.begin(), str.end(), [](unsigned char new_char) {
                return std::isdigit(new_char);
            });
        }
    }

    void ProcessTable::refresh() {
        processes_.clear();
        for (const auto &entry: fs::directory_iterator("/proc")) {
            if (!entry.is_directory())
                continue;
            const auto fname = entry.path().filename().string();
            if (!isAllDigits(fname))
                continue;

            int pid = 0;
            try {
                pid = std::stoi(fname);
            } catch (...) {
                continue;
            }

            //Read memory usage from /proc/<pid>/comm
            const auto commPath = entry.path() / "comm";
            std::ifstream commFile(commPath);
            if (!commFile)
                continue;

            std::string name;
            std::getline(commFile, name);
            if (name.empty())
                name = "?";

            long memKb = 0;
            const auto statusPath = entry.path() / "status";
            std::ifstream statusFile(statusPath);
            if (statusFile) {
                std::string key;
                while (statusFile >> key) {
                    if (key == "VmRSS:") {
                        statusFile >> memKb;
                        break;
                    } else {
                        std::string restOfLine;
                        std::getline(statusFile, restOfLine);
                    }
                }
            }
            processes_.push_back(Process{pid, name, memKb});
        }

        //sort by memory usage descending
        std::sort(processes_.begin(), processes_.end(), [](const Process &a, const Process &b) {
            return a.memoryKB > b.memoryKB;

        });
    }
}
