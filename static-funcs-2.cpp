#include "module-config/arm-config.h"

#include <atomic>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <yaml-cpp/yaml.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "usage:" << std::endl;
        std::cout << "   $ " << argv[0] << " YAML_FILE" << std::endl;
        std::cout << "for example:" << std::endl;
        std::cout << "   $ cd build/" << std::endl;
        std::cout << "   $ ./static-funcs-2 ../config_file.yml" << std::endl;
        return -1;
    }
    const std::string file_name(argv[1]);

    // ---------------------
    ArmConfigNoStatic config_no_static;
    config_no_static.readYAML(argv[1]);
    std::cout << std::endl << "-------------------" << std::endl;
    std::cout << "port: " << config_no_static.port << std::endl;
    std::cout << "baud: " << config_no_static.baud << std::endl;
    std::cout << "offset: " << config_no_static.offset << std::endl;
    std::cout << "max_angle: " << config_no_static.max_angle << std::endl;

    // ---------------------
    ArmConfigStatic config_static = ArmConfigStatic::readYAML(file_name);
    std::cout << std::endl << "-------------------" << std::endl;
    std::cout << "port: " << config_static.port << std::endl;
    std::cout << "baud: " << config_static.baud << std::endl;
    std::cout << "offset: " << config_static.offset << std::endl;
    std::cout << "max_angle: " << config_static.max_angle << std::endl;
    return 0;
}
