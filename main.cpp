#include "Config.hpp"

int       main(int argc, char *argv[])
{
    Config conf;

    if (argc != 2)
        exit(1);
    conf.parseConfig(argv[1]);
    return (0);
}