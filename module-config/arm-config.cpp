#include "arm-config.h"
#include <iostream>

void ArmConfigNoStatic::readYAML(const YAML::Node node) {
    port      = node["port"].as<std::string>("port_default");
    baud      = node["baud"].as<int>(921600);
    offset    = node["offset"].as<int>(1);
    max_angle = node["max_angle"].as<double>(2);
}

void ArmConfigNoStatic::readYAML(const std::string file_name) {
    const std::string config_file(file_name);
    auto config_node = YAML::LoadFile(config_file);
    readYAML(config_node["module"]["arm"]);
}

ArmConfigStatic ArmConfigStatic::readYAML(const YAML::Node node) {
    ArmConfigStatic config;
    config.port      = node["port"].as<std::string>("port_default");
    config.baud      = node["baud"].as<int>(115200);
    config.offset    = node["offset"].as<int>(0);
    config.max_angle = node["max_angle"].as<double>(3.1415926);
    return config;
}

ArmConfigStatic ArmConfigStatic::readYAML(const std::string file_name) {
    const std::string config_file(file_name);
    auto config_node = YAML::LoadFile(config_file);
    return ArmConfigStatic::readYAML(config_node["module"]["arm"]);
}
