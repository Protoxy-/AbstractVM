//
// Executer.cpp for Executer in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Fri Feb 20 23:56:57 2015 Francois Hoertel
// Last update Fri Feb 20 23:56:58 2015 Francois Hoertel
//

#include "Executer.hh"
#include <sstream>

Executer::Executer(ListExec const *list, std::string const *func_name)
{
	funcList = list;
	funcName = func_name;
	try
	{
	Exe();
	}
	catch (errAbort &e)
	{
	}
}

Executer::~Executer()
{

}

IOperand 		*Executer::GetValueType(t_exeList const *exe)
{
	switch (exe->elem->num_type)
	{
		case 0 :
			return (stk.createInt8(exe->elem->value));
		case 1 :
			return (stk.createInt16(exe->elem->value));
		case 2 :
			return (stk.createInt32(exe->elem->value));
		case 3 :
			return (stk.createFloat(exe->elem->value));
		case 4 :
			return (stk.createDouble(exe->elem->value));
	}
}

int 		Executer::GetFuncPos(std::string const func)
{
	int 	i = 0;
	int 	j = -1;

	while (i < 11)
	{
		if (func == funcName[i])
			j = i;
		i++;
	}
	return (j);
}

void		Executer::DoFunc(t_exeList const *exe)
{
	switch (GetFuncPos(exe->elem->str_func))
	{
		case 0 :
		{
			stk.push(GetValueType(exe));
			break;
		}
		case 1 :
			stk.pop();
			break;
		case 2 :
			stk.dump();
			break;
		case 3 :
		{
			stk.assert(GetValueType(exe));
			break;
		}
		case 4 :
			stk.add();
			break;
		case 5 :
			stk.sub();
			break;
		case 6 :
			stk.mul();
			break;
		case 7 :
			stk.div();
			break;
		case 8 :
			stk.mod();
			break;
		case 9 :
			stk.print();
			break;
		case 10 :
			throw errAbort("exit");
		default :
			break;
	}
}

void		Executer::Exe()
{
	t_exeList *exe;
	int 			i = 0;

	std::cout << "-[Execution]-" << std::endl;
	exe = funcList->PopBegin();
	while(exe)
	{
		try
		{
			DoFunc(exe);
		}
		catch (errExcept &e)
		{
			std::cout << "Line " << (i + 1) << " | Exe error : " << e.what() << std::endl;
			throw errAbort("");
		}
		exe = exe->next;
		i++;
	}
}