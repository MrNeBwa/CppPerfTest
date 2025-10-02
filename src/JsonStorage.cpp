#include "JsonStorage.hpp"
#include <fstream>
#include <iostream>

JsonStorage::JsonStorage(const std::string& path) : filepath(path) {}

void JsonStorage::save(const std::vector<Metric>& metrics) {
    std::ofstream out(filepath);
    if (!out.is_open()) return;

    out << "[\n";
    for (size_t i = 0; i < metrics.size(); ++i) {
        const auto& m = metrics[i];
        out << "  {\n";
        out << "    \"name\": \"" << m.name << "\",\n";
        out << "    \"duration_ms\": " << m.duration_ms << ",\n";
        out << "    \"memory_kb\": " << m.memory_kb << ",\n";
        out << "    \"cpu_time_ms\": " << m.cpu_time_ms << ",\n";
        out << "    \"timestamp\": \"" << m.timestamp << "\"\n";
        out << "  }";
        if (i < metrics.size() - 1) out << ",";
        out << "\n";
    }
    out << "]\n";
}
