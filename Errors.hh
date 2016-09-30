//
// Errors.hh for Error in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Tue Feb 17 17:03:39 2015 Francois Hoertel
// Last update Tue Feb 17 17:03:43 2015 Francois Hoertel
//

#ifndef ERRORS_HH_
#define ERRORS_HH_

#include <string>

class GErrors : public std::exception
{
protected:
	std::string	_message;
	std::string	_component;

public:
	GErrors(std::string const &message, std::string const &component = "Unknown");
	~GErrors() throw();

    virtual std::string const 	&getComponent() const;
    const char* 				what() const throw();
};


#endif