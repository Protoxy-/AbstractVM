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

class errExcept : public std::exception
{
protected:
	std::string	_message;
	std::string	_component;

public:
	errExcept(std::string const &message, std::string const &component = "Unknown");
	~errExcept() throw();

    virtual std::string const 	&getComponent() const;
    const char* 				what() const throw();
};

class errEmpty : public std::exception
{
protected:
	std::string	_message;
	std::string	_component;

public:
	errEmpty(std::string const &message, std::string const &component = "Unknown");
	~errEmpty() throw();

    virtual std::string const 	&getComponent() const;
    const char* 				what() const throw();
};

class errAbort : public std::exception
{
protected:
	std::string	_message;
	std::string	_component;

public:
	errAbort(std::string const &message, std::string const &component = "Unknown");
	~errAbort() throw();

    virtual std::string const 	&getComponent() const;
    const char* 				what() const throw();
};

class errGeneral : public errExcept
{
public:
	errGeneral(std::string const &message, std::string const &component = "General");
	~errGeneral() throw();
};

class errSyntax : public errExcept
{
public:
	errSyntax(std::string const &message, std::string const &component = "Syntax");
	~errSyntax() throw();
};

class errInstruct : public errExcept
{
public:
	errInstruct(std::string const &message, std::string const &component = "Instruct");
	~errInstruct() throw();
};

class errOverflow : public errExcept
{
public:
	errOverflow(std::string const &message, std::string const &component = "OverFlow");
	~errOverflow() throw();
};

class errUnderflow : public errExcept
{
public:
	errUnderflow(std::string const &message, std::string const &component = "UnderFlow");
	~errUnderflow() throw();
};

class errPileEmpty : public errExcept
{
public:
	errPileEmpty(std::string const &message, std::string const &component = "PileEmpty");
	~errPileEmpty() throw();
};

class errExit : public errExcept
{
public:
	errExit(std::string const &message, std::string const &component = "Exit");
	~errExit() throw();
};

class errDivision : public errExcept
{
public:
	errDivision(std::string const &message, std::string const &component = "Division");
	~errDivision() throw();
};

class errAssert : public errExcept
{
public:
	errAssert(std::string const &message, std::string const &component = "Assert");
	~errAssert() throw();
};

class errPileLow : public errExcept
{
public:
	errPileLow(std::string const &message, std::string const &component = "PileLow");
	~errPileLow() throw();
};

#endif