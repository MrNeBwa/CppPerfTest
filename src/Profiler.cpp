#include "Profiler.hpp"
#include <chrono>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <sstream>

Profiler::Profiler(std::unique_ptr<Storage> st) : storage(std::move(st)) {}

std::string Profiler::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Profiler::executeAndMeasure(const std::string& command, Metric& metric) {
    auto start_time = std::chrono::high_resolution_clock::now();

    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command.c_str(), nullptr);
        exit(1);
    }

    int status;
    struct rusage usage;
    wait4(pid, &status, 0, &usage);

    auto end_time = std::chrono::high_resolution_clock::now();
    metric.duration_ms = std::chrono::duration<double, std::milli>(end_time - start_time).count();
    metric.memory_kb = usage.ru_maxrss;
    metric.cpu_time_ms = (usage.ru_utime.tv_sec * 1000.0 + usage.ru_utime.tv_usec / 1000.0) +
                         (usage.ru_stime.tv_sec * 1000.0 + usage.ru_stime.tv_usec / 1000.0);
}

void Profiler::runCommand(const std::string& name, const std::string& command) {
    Metric m;
    m.name = name;
    m.timestamp = getCurrentTimestamp();
    executeAndMeasure(command, m);
    metrics.push_back(m);
}

void Profiler::saveResults() {
    if (storage) {
        storage->save(metrics);
        std::cout << "Results saved successfully.\n";
    }
}
