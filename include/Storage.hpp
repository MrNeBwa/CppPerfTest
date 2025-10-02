#pragma once
#include <vector>
#include "Metric.hpp"

class Storage {
public:
    virtual ~Storage() = default;
    virtual void save(const std::vector<Metric>& metrics) = 0;
};
