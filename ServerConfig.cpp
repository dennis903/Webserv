#include "ServerConfig.hpp"

ServerConfig::ServerConfig()
{
}

ServerConfig::~ServerConfig()
{
}

bool	ServerConfig::isValidDirective(std::string temp)
{
	if (!temp.compare("listen") ||
		!temp.compare("location") ||
		!temp.compare("root") ||
		!temp.compare("method") ||
		!temp.compare("index") ||
		!temp.compare("server_name"))
		return (true);
	else
		return (false);
}

void	ServerConfig::initServer(std::vector<std::string>::iterator &it)
{
	// if (*it != "{")
		//error
	while (*(++it) != "}")
	{
		if (isValidDirective(*it))
			getDirective(it);
	}
}

void	ServerConfig::getDirective(std::vector<std::string>::iterator &it)
{
	std::string		temp;

	temp = *it;
	if (!temp.compare("listen"))
		this->parseListen(++it);		
	else if (!temp.compare("location"))
		this->parseLocations(++it);
	else if (!temp.compare("root"))
		this->parseRoot(++it);
	else if (!temp.compare("method"))
		this->parseMethod(++it);
	else if (!temp.compare("index"))
		this->parseIndex(++it);
	else if (!temp.compare("server_name"))
		this->parseServerName(++it);
}

void	ServerConfig::parseListen(std::vector<std::string>::iterator &it)
{
	std::string temp = *it;

	this->listen = temp;
	it++;
	if (*it == ";")
		it++;
}

void	ServerConfig::parseLocations(std::vector<std::string>::iterator &it)
{
	std::cout << loc.getID() << std::endl;
	// ServerConfig loc;

	// loc = *this;
	// loc.loopLocation(it, loc);
}

void	ServerConfig::loopLocation(std::vector<std::string>::iterator &it, ServerConfig &loc)
{
	// this->uri = *it++;
	// // if (*it != "{")
	// // 	error
	// while (*(++it) != "}")
	// {
	// 	if (isValidDirective(*it))
	// 		getDirective(it);
	// }
	// locations.push_back(loc);
}

void	ServerConfig::parseRoot(std::vector<std::string>::iterator &it)
{
	// std::string temp = *it;

	// this->root = temp;
	// it++;
	// if (*it == ";")
	// 	it++;
}

void	ServerConfig::parseMethod(std::vector<std::string>::iterator &it)
{
	// std::string temp;

	// while (1)
	// {
	// 	temp = *it;
	// 	if (temp.find(',', temp.length() - 1) != std::string::npos)
	// 	{
	// 		temp.erase(temp.length() - 1);
	// 		this->method.push_back(temp);
	// 	}
	// 	else if (temp.find(',', temp.length() - 1) == std::string::npos)
	// 	{
	// 		this->method.push_back(temp);
	// 		it++;
	// 		if (*it == ";")
	// 			it++;
	// 		break ;
	// 	}
	// 	it++;
	// }
}

void	ServerConfig::parseIndex(std::vector<std::string>::iterator &it)
{
	// while (*it != ";")
	// 	this->index.push_back(*it++);
}

void	ServerConfig::parseServerName(std::vector<std::string>::iterator &it)
{
	// while (*it != ";")
	// 	ServerName.push_back(*it++);
}

int	ServerConfig::getID() const
{
	return (this->id);
}

void	ServerConfig::setID(int _id)
{
	this->id = _id;
}