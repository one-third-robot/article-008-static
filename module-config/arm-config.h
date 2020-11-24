#pragma once

#include <stdint.h>
#include <string>
#include <yaml-cpp/yaml.h>

struct ArmConfigNoStatic {
    std::string port;
    int baud;
    int offset;
    double max_angle;

    void readYAML(const YAML::Node node);
    void readYAML(const std::string file_name);
};

struct ArmConfigStatic {
    std::string port;
    int baud;
    int offset;
    double max_angle;

    static ArmConfigStatic readYAML(const YAML::Node node);
    static ArmConfigStatic readYAML(const std::string file_name);
};
