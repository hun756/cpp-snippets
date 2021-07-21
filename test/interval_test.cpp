#include "../src/algorithm/interval.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <random>

namespace App
{
    static void Run(std::vector<std::string> args)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 100);

        int i = 0;
        
        Timer::setInterVal([&mt, &dist, &i] {
            std::cout << "Random value : " << dist(mt) << '\n';
            ++i;
            if (i >= 20) {
                Timer::isRunning = false;
                // std::exit(EXIT_SUCCESS);
            }
        }, 200);

        while (Timer::isRunning.load());

        std::cout << "Program is terminated.. !" << std::endl;
        std::exit(EXIT_SUCCESS);
    }
}

int main(int argc, const char *argv[])
{
    App::Run({argv + 1, argc + argv});
}