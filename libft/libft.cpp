#include <iostream>
#include <string>
namespace ft
{
	std::string		getline(std::string &str1)
	{
		size_t		idx;
		std::string	line;

		idx = str1.find("\n");
		if (idx != std::string::npos)
		{
			line = str1.substr(0, idx);
			str1 = str1.substr(idx + 1, str1.size());
		}
		else
		{
			line = str1.substr(0, str1.size());
			str1 = str1.substr(str1.size());
		}
		return (line);
	}
}