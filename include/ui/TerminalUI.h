#pragma once

#include "system/ProcessTable.h"


namespace ui{
    class TerminalUI {
    public:
        void render(const sys::ProcessTable &table) const;
    };
}
