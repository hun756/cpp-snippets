#ifndef ALGORITHM_INTERVAL_HPP_oLPSth
#define ALGORITHM_INTERVAL_HPP_oLPSth

#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>

namespace Timer
{
    class SetIntervalManager
    {
    public:
        SetIntervalManager() : done(false) { work_thread = std::thread(&SetIntervalManager::worker, this); }

        ~SetIntervalManager()
        {
            done = true;
            cv.notify_one();
            if (work_thread.joinable()) {
                work_thread.join();
            }
        }

        template <typename Function, typename... Args>
        void setInterval(unsigned int interval, Function&& f, Args&&... args)
        {
            std::function<void()> task = std::bind(std::forward<Function>(f), std::forward<Args>(args)...);
            std::lock_guard<std::mutex> lock(tasks_mutex);
            tasks.emplace_back(task, interval, std::chrono::steady_clock::now() + std::chrono::milliseconds(interval));
            cv.notify_one();
        }

    private:
        struct Task {
            std::function<void()> taskFunction;
            unsigned int interval;
            std::chrono::steady_clock::time_point nextRun;

            Task(std::function<void()> func, unsigned int interval, std::chrono::steady_clock::time_point firstRun)
                : taskFunction(std::move(func)), interval(interval), nextRun(firstRun)
            {
            }
        };

        std::vector<Task> tasks;
        std::mutex tasks_mutex;
        std::condition_variable cv;
        std::atomic<bool> done;
        std::thread work_thread;

        void worker()
        {
            while (!done) {
                std::unique_lock<std::mutex> lock(tasks_mutex);
                if (!cv.wait_for(lock, std::chrono::milliseconds(1), [this] {
                        auto now = std::chrono::steady_clock::now();
                        return done || std::any_of(tasks.begin(), tasks.end(),
                                                   [&now](const Task& task) { return now >= task.nextRun; });
                    })) {
                    continue;
                }

                if (done)
                    break;

                auto now = std::chrono::steady_clock::now();
                for (auto& task : tasks) {
                    if (now >= task.nextRun) {
                        std::thread([task] { task.taskFunction(); }).detach();
                        task.nextRun += std::chrono::milliseconds(task.interval);
                    }
                }
            }
        }
    };
} // namespace Timer

#endif /* End of include guard: ALGORITHM_INTERVAL_HPP_oLPSth */
