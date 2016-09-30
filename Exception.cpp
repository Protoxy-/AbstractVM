//
// Errors.cpp for Error in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Tue Feb 17 17:24:08 2015 Francois Hoertel
// Last update Tue Feb 17 17:24:10 2015 Francois Hoertel
//

#include "Exception.hh"

errExcept::errExcept(std::string const &message, std::string const &component)
  : _message(message), _component(component)
{}

errExcept::~errExcept() throw()
{}

std::string const & errExcept::getComponent() const
{
  return (_component);
}

const char* 		errExcept::what() const throw()
{
  return (_message.c_str());
}

errEmpty::errEmpty(std::string const &message, std::string const &component)
  : _message(message), _component(component)
{}

errEmpty::~errEmpty() throw()
{}

std::string const & errEmpty::getComponent() const
{
  return (_component);
}

const char* 		errEmpty::what() const throw()
{
  return (_message.c_str());
}

errAbort::errAbort(std::string const &message, std::string const &component)
  : _message(message), _component(component)
{}

errAbort::~errAbort() throw()
{}

std::string const & errAbort::getComponent() const
{
  return (_component);
}

const char* 		errAbort::what() const throw()
{
  return (_message.c_str());
}

errGeneral::errGeneral(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errGeneral::~errGeneral() throw()
{}

errSyntax::errSyntax(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errSyntax::~errSyntax() throw()
{}

errInstruct::errInstruct(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errInstruct::~errInstruct() throw()
{}

errOverflow::errOverflow(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errOverflow::~errOverflow() throw()
{}

errUnderflow::errUnderflow(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errUnderflow::~errUnderflow() throw()
{}

errPileEmpty::errPileEmpty(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errPileEmpty::~errPileEmpty() throw()
{}

errExit::errExit(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errExit::~errExit() throw()
{}

errDivision::errDivision(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errDivision::~errDivision() throw()
{}

errAssert::errAssert(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errAssert::~errAssert() throw()
{}

errPileLow::errPileLow(std::string const &message, std::string const &component)
	: errExcept(message, component)
{}

errPileLow::~errPileLow() throw()
{}
