#include "app/Application.h"

#include <chrono>
#include <thread>



namespace app {
    void Application::run() {
        using namespace  std ::chrono_literals;

        while (true) {
            processTable_.refresh();
            ui_.render(processTable_);

            std::this_thread::sleep_for(1s);
        }
    }
}
