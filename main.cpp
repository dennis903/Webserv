#include "Config.hpp"

int       main(int argc, char *argv[])
{
    Config conf;
    std::vector<ServerConfig> servers;
    if (argc != 2)
        exit(1);
    conf.parseConfig(argv[1]);
    servers = conf.getServers();

    for (std::vector<ServerConfig>::iterator it = servers.begin(); it != servers.end(); it++)
    {
        ServerConfig server = *it;
        std::cout << "id : " << server.getID() << std::endl;
        std::cout << "{" << std::endl;
        std::cout << "}" << std::endl;
    }
    return (0);
}