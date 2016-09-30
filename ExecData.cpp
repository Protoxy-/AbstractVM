//
// ExecData.cpp for ListDataFunc in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Thu Feb 19 22:39:27 2015 Francois Hoertel
// Last update Thu Feb 19 22:39:40 2015 Francois Hoertel
//

#include "ExecData.hh"

ListExec::ListExec(t_exeList *elem)
{
	t_exeList *end;

	Begin = elem;
	end = elem;
	size = 0;
	while (end->next)
	{
		end = end->next;
		size++;
	}
	End = end;
}

ListExec::ListExec()
{
	Begin = NULL;
	End = NULL;
	size = 0;
}

ListExec::~ListExec()
{

}

void			ListExec::Add(t_exeData *data)
{
	t_exeList *chk = new t_exeList;
	t_exeList	*prev;

	if (size == 0)
	{
		chk->prev = NULL;
		chk->elem = data;
		chk->next = NULL;
		Begin = chk;
		End = chk;
	}
	else
	{
		prev = End;
		prev->next = chk;
		chk->elem = data;
		chk->prev = prev;
		chk->next = NULL;
		End = chk;
	}
	size++;
}

void			ListExec::Del(std::string const func)
{
	t_exeList 	*chk;
	int					i = 0;

	chk = End;
	while (chk)
	{
		if (chk && chk->elem->str_func == func)
		{
			(chk->next ? chk->next->prev = chk->prev : 0);
			(chk->prev ? chk->prev->next = chk->next : 0);
			if (i == 0)
				End = chk->prev;
			break;
		}
		chk = chk->prev;
		i++;
	}
}

void 			ListExec::DelAll(std::string const func)
{
	t_exeList 	*chk;
	int					i = 0;

	chk = End;
	while (chk)
	{
		if (chk && chk->elem->str_func == func)
		{
			(chk->next ? chk->next->prev = chk->prev : 0);
			(chk->prev ? chk->prev->next = chk->next : 0);
		}
		chk = chk->prev;
		i++;
	}
	size = 0;
	chk = Begin;
	while (chk->next)
	{
		chk = chk->next;
		size++;
	}
	End = chk;
}

t_exeList 		*ListExec::PopBegin() const
{
	return Begin;
}

t_exeList 			*ListExec::PopEnd() const
{
	return End;
}

int 						ListExec::Size() const
{
	return (size);
}