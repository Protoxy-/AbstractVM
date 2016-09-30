//
// Errors.hpp for Errors in /home/dayrie_l/rendu/piscine_cpp_d14a/ex00
//
// Made by Lucas Dayries
// Login   <dayrie_l@epitech.net>
//
// Started on  Tue Jan 20 17:39:10 2015 Lucas Dayries
// Last update Tue Jan 20 17:39:10 2015 Lucas Dayries
//

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");


        virtual std::string const &getComponent() const;
        const char* what() const throw();
        ~NasaError() throw();

    protected:
        std::string _message;
      std::string  _component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
        ~MissionCriticalError() throw();
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
        ~LifeCriticalError() throw();

};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
        ~UserError() throw();

};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        ~CommunicationError() throw();
        virtual std::string const &getComponent() const;
    private:
        std::string const ret;
};

#endif
