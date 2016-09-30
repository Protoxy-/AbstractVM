//
// ExecData.hh for Data in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Thu Feb 19 22:04:26 2015 Francois Hoertel
// Last update Thu Feb 19 22:06:38 2015 Francois Hoertel
//

#ifndef EXECDATA_HH
#define EXECDATA_HH

#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

typedef struct  s_exeData
{
  std::string   str_func;
  std::string   str_type;
  std::string   size_type;
  int 			num_type;
  std::string   value;  
}               t_exeData;

typedef struct 			s_exeList
{
	struct s_exeList	*prev;
	t_exeData			*elem;
	struct s_exeList	*next;
}						t_exeList;

class 			ListExec
{
public:
	t_exeList 	*Begin;
	t_exeList	*End;
	int 		size;

	ListExec(t_exeList *);
	ListExec();
	~ListExec();

	virtual void		Add(t_exeData *);
	virtual void		Del(std::string const);
	virtual void		DelAll(std::string const);
	virtual t_exeList	*PopBegin() const;
	virtual t_exeList	*PopEnd() const;
	virtual int 		Size() const;
};

#endif