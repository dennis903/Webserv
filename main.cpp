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
        std::cout << "listen : " << server.getListen() << std::endl;
        if (server.getLocations().empty() == 0)
        {
            for (unsigned long i = 0; i < server.getLocations().size(); i++)
			{
				ServerConfig	temp = server.getLocations().at(i);
                std::cout << "	location {" << std::endl;
				std::cout << "		client_max_body_size : " << temp.getClientMaxBodySize() << std::endl;
				std::cout << "		uri : " << temp.getUri() << std::endl;
				std::cout << "		root : " << temp.getRoot() << std::endl;
				if (temp.getIndex().empty() == 0)
					std::cout << "		index : " << temp.getIndex().at(0) << std::endl;
				std::cout << "		method : " << temp.getMethod().at(0) << std::endl;
				std::cout << "				}" << std::endl;
            }
        }
        std::cout << "}" << std::endl;
    }
    return (0);
}