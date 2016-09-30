//
// Executer.hpp for Executer in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Fri Feb 20 23:57:14 2015 Francois Hoertel
// Last update Fri Feb 20 23:57:54 2015 Francois Hoertel
//

#ifndef EXECUTER_HH
#define EXECUTER_HH

#include "Exception.hh"
#include "ExecData.hh"
#include "Stack.hh"

class Executer
{
	ListExec const			*funcList;
  std::string const 	*funcName;
	Stack 							stk;

public:
	Executer(ListExec const *, std::string const *);
	~Executer();

	IOperand 	*GetValueType(t_exeList const *);
	int 			GetFuncPos(std::string const);
	void			DoFunc(t_exeList const *);
	void 			Exe();
};

#endif