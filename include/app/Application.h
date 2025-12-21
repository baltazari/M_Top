#pragma once

#include "system/ProcessTable.h"
#include "ui/TerminalUI.h"


namespace app {
    class Application {
    public:
        void run();
    private:
        sys::ProcessTable processTable_;
        ui::TerminalUI ui_;
    };
}