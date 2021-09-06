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

	size_t			stoi(std::string &str)
	{
		int			i;
		int			sign;
		size_t		result;

		i = 0;
		result = 0;
		sign = 1;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		return (result * sign);
	}
}