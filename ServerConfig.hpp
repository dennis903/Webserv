#ifndef SERVERCONFIG_HPP
# define SERVERCONFIG_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <vector>

class	ServerConfig
{
	private:
		bool	isValidDirective(std::string temp);
		int		id;
		std::string listen;
		std::vector<ServerConfig> locations;
		std::string root;
		std::string error;
		std::vector<std::string> method;
		std::vector<std::string> index;
		std::vector<std::string> ServerName;
		std::string uri;
	public:
		ServerConfig();
		~ServerConfig();

		void	setID(int _id);
		int		getID() const;
		void	initServer(std::vector<std::string>::iterator &it);
		void	getDirective(std::vector<std::string>::iterator &it);
		void	parseListen(std::vector<std::string>::iterator &it);
		void	parseLocations(std::vector<std::string>::iterator &it);
		void	parseRoot(std::vector<std::string>::iterator &it);
		void	parseMethod(std::vector<std::string>::iterator &it);
		void	parseIndex(std::vector<std::string>::iterator &it);
		void	parseServerName(std::vector<std::string>::iterator &it);
		void	loopLocation(std::vector<std::string>::iterator &it, ServerConfig &loc);
};
#endif

