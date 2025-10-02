#pragma once
#include "Storage.hpp"
#include <string>

class JsonStorage : public Storage {
private:
    std::string filepath;
public:
    explicit JsonStorage(const std::string& path);
    void save(const std::vector<Metric>& metrics) override;
};
