#include <thread>
#include <functional>
#include <chrono>
#include <atomic>

namespace Timer
{
    std::atomic<bool> isRunning{true};

    template <typename F>
    void setInterVal(F func, unsigned int interval)
    {
        isRunning = true;
        std::thread([func, interval]()
                    {
                        while (isRunning.load())
                        {
                            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                            if(!isRunning.load()) return;
                            func();
                        }
                    })
            .detach();
    }
}