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
#include "Exception.hh"

int		main(int ac, char **av)
{
	std::string 	file;

	file = (ac == 2 ? av[1] : "");
	Parser parser(file);
	return (0);
}