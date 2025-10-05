#pragma once
#include "Metric.hpp"
#include "Storage.hpp"
#include <string>
#include <vector>
#include <memory>

class Profiler {
private:
    std::vector<Metric> metrics;
    std::unique_ptr<Storage> storage;

    std::string getCurrentTimestamp();
    void executeAndMeasure(const std::string& command, Metric& metric);

public:
    explicit Profiler(std::unique_ptr<Storage> st);
    void runCommand(const std::string& name, const std::string& command);
    void saveResults();
};
