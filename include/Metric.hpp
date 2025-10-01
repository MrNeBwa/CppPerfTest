#pragma once
#include <string>

struct Metric {
    std::string name;
    double duration_ms;
    double memory_kb;
    double cpu_time_ms;
    std::string timestamp;
};
