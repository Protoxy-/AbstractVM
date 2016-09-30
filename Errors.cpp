//
// Errors.cpp for Error in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Tue Feb 17 17:24:08 2015 Francois Hoertel
// Last update Tue Feb 17 17:24:10 2015 Francois Hoertel
//

#include "Errors.hh"

GErrors::GErrors(std::string const &message, std::string const &component)
  : _message(message), _component(component)
{
}

GErrors::~GErrors() throw()
{
}

std::string const & GErrors::getComponent() const
{
  return (_component);
}

const char* 		GErrors::what() const throw()
{
  return (_message.c_str());
}

