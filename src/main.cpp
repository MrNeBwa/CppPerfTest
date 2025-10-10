#include "Profiler.hpp"
#include "JsonStorage.hpp"
#include <iostream>

void printHelp() {
    std::cout << "Usage: CppPerfTrack <task_name> <command>\n";
    std::cout << "Example: CppPerfTrack 'ls_test' 'ls -la'\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printHelp();
        return 1;
    }

    std::string taskName = argv[1];
    std::string command = argv[2];

    auto storage = std::make_unique<JsonStorage>("metrics.json");
    Profiler profiler(std::move(storage));

    std::cout << "Running task: " << taskName << "\n";
    profiler.runCommand(taskName, command);
    profiler.saveResults();

    return 0;
}
