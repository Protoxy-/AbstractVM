//
// ParserMain.cpp for ParserMain in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Thu Feb 12 14:58:11 2015 Francois Hoertel
// Last update Thu Feb 12 14:58:13 2015 Francois Hoertel
//

#include "Parser.hh"
#include "Errors.hh"

int		main(int ac, char **av)
{
	std::string 	file;
	if (ac != 2)
		{
			std::cout << "A file is needed for execute" << std::endl;
			return -1;
		}
	file = av[1];
	Parser parser(file);
}