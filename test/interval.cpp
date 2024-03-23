#define CATCH_CONFIG_MAIN

#include "../src/algorithm/interval.hpp"
#include "../external/catch2/catch.hpp"

#include <atomic>
#include <string>
#include <thread>

using Timer::SetIntervalManager;

TEST_CASE("SetIntervalManager functionality", "[setInterval]")
{
    SetIntervalManager manager;

    SECTION("Single function execution at interval")
    {
        std::atomic<int> counter(0);
        manager.setInterval(100, [&counter]() -> void { counter++; });

        std::this_thread::sleep_for(std::chrono::milliseconds(350));
        REQUIRE(counter >= 3);
    }

    SECTION("Multiple functions execution at different intervals")
    {
        std::atomic<int> counter1(0);
        std::atomic<int> counter2(0);
        manager.setInterval(50, [&counter1]() -> void { counter1++; });
        manager.setInterval(100, [&counter2]() -> void { counter2++; });

        std::this_thread::sleep_for(std::chrono::milliseconds(210));
        REQUIRE(counter1 >= 4);
        REQUIRE(counter2 >= 2);
    }

    SECTION("Function with parameters")
    {
        std::atomic<int> result(0);
        int addend1 = 5, addend2 = 10;
        manager.setInterval(100, [&result, addend1, addend2]() -> void { result = addend1 + addend2; });

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        REQUIRE(result == 15);
    }

    SECTION("No execution before interval")
    {
        std::atomic<int> counter(0);
        manager.setInterval(200, [&counter]() -> void { counter++; });

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        REQUIRE(counter == 0);
    }
}
