//
// Parser.cpp for Parser in /home/hoerte_f/rendu/cpp_abstractvm
// 
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
// 
// Started on  Thu Feb 12 11:33:46 2015 Francois Hoertel
// Last update Thu Feb 12 11:33:48 2015 Francois Hoertel
//

#include "Parser.hh"

Parser::Parser(std::string const file_name)
{
	funcList = new ListExec();

	InitTables();
	try
	{
		if (file_name[0] == '+')
		{
			InitCodeFile(file_name);
			fileWrite = 1;
		  ReadInput();
		}
		else if (file_name != "")
			ReadFile(file_name);
		else
		  ReadInput();			
	}
	catch (errGeneral &e)
	{
		if (fileWrite == 1)
			codeFile.close();
		MsgErr(e.what());
	}
	catch (errAbort &e)
	{
		std::cout << "Abort : " << e.what() << std::endl;
	}
}

Parser::~Parser()
{
}

void		Parser::MsgErr(std::string const msg) const
{
	if (msg[0] == ':')
		std::cerr << "Line " << (linePos + 1) << " | ";
	if (msg[0] == '-')
		std::cerr << msg << std::endl;
	else
		std::cerr << "Error " << (msg[0] == ':' ? "" : ": ") << msg << std::endl;
}

void 	Parser::InitTables()
{
	funcName = new std::string[12];

	funcName[0] = "push";
	funcName[1] = "pop";
	funcName[2] = "dump";
	funcName[3] = "assert";
	funcName[4] = "add";
	funcName[5] = "sub";
	funcName[6] = "mul";
	funcName[7] = "div";
	funcName[8] = "mod";
	funcName[9] = "print";
	funcName[10] = "exit";
}

void	Parser::CheckFunction(t_exeData *data, std::string const func) const
{
	int 	chk = 0;
	int 	i = 0;

	while (i < 11)
	{
		if (func == funcName[i])
			chk++;
		i++;
	}
	if (chk == 0)
		throw errInstruct(": The function \"" + func + "\" doesn't exist");
}

void		Parser::CheckType(t_exeData *data, std::string const type) const
{
	if (type == "int8")
	{
		data->size_type = "128";
		data->num_type = 0;
	}
	else if (type == "int16")
	{
		data->size_type = "32767";
		data->num_type = 1;
	}
	else if (type == "int32")
	{
		data->size_type = "2147483648";
		data->num_type = 2;
	}
	else if (type == "float")
	{
		data->size_type = "340282";
		data->num_type = 3;
	}
	else if (type == "double")
	{
		data->size_type = "179769";
		data->num_type = 4;
	}
	else
		throw errInstruct(": The type \"" + type + "\" doesn't exist");
}

void	 	Parser::CheckValue(t_exeData *data, std::string const value) const
{
	int 		err = 0;
	int 		i = 0;
	int 		j = 0;

	while (value[i] != '\0')
	{
		if ((value[i] >= '0' && value[i] <= '9') || value[i] == '-' || value[i] == '.')
			j++;
		i++;
	}
	if (j != i)
		throw errSyntax(": the argument \"" + value + "\" is not a valid number");
	j = (value[0] == '-' ? 1 : 0);
	if (value.size() - j > data->size_type.size())
		err = 1;
	if (err == 0 && value.size() - j == data->size_type.size())
	{
		i = 0;
		while (value[i + j] != '\0')
		{
			if (value[i + j] > data->size_type[i])
				{
					err = 1;
					break;
				}
			if (j == 0 && i == static_cast<int>(value.size()) - 1 && value[i + j] > data->size_type[i] - 1)
				{
					err = 1;
					break;
				}
			if (value[i + j] < data->size_type[i])
				break;
			i++;
		}
	}
	if (err == 1)
	{
		if (j == 0)
			throw errOverflow(": the value \"" + value + "\" is to big, absolute value : " + data->size_type);
		else
			throw errUnderflow(": the value \"" + value + "\" is to low, absolute value : -" + data->size_type);
	}
	data->value = value;
}

void		Parser::CheckFloatAbolute(t_exeData *data, std::string const value, int const neg) const
{
	int 	err;
	int 	i;
	int 	j;

	err = 0;
	j = neg;
	i = 0;
	while (data->size_type[i] && value[i + j] && value[i + j] != 'e')
	{
		if (value[i + j] == '.')
			j++;
		if (value[i + j] > data->size_type[i])
			{
				err = 1;
				break;
			}
		if (value[i + j] < data->size_type[i])
			break;
		i++;
		if (data->size_type[i] == 'e')
			break;
	}
	if (err == 1)
		throw errOverflow(": the value \"" + value + "\" is infinite, absolute value : " +
											(data->str_type == "float" ? "3.40282e+-38" : "1.79769e+-308"));
}

void 		Parser::CheckFloatValue(t_exeData *data, std::string const value) const
{
	std::string 	chk = "";
	int 					nb;
	int 					dot;
	int 					neg;
	int 					ex;
	int 					ex_max;
	int 					i = 0;
	int 					j = 0;

	ex = 0;
	while (value[i] != '\0')
	{
		if ((value[i] >= '0' && value[i] <= '9') || value[i] == '-' || value[i] == '.'
				|| value[i] == 'e' || value[i] == '+')
			j++;
		if (value[i] == 'e')
			ex = 1;
		if (i != 0 && ex == 0 && (value[i] == '+' || value[i] == '-'))
			throw errSyntax(": Syntax error on \"" + value + "\", the \'" + value[i] + "\' is not permited");
		i++;
	}
	if (j != i)
		throw errSyntax(": Syntax error on \"" + value + "\"");
	neg = (value[0] == '-' ? 1 : 0);
	dot = 0;
	nb = neg;
	while (value[nb] && value[nb] != 'e' && value[nb] != '+')
	{
		if (value[nb] == '.')
			dot = nb;
		nb++;
	}
	nb -= neg + (dot != 0 ? 1 : 0);
	dot = (dot == 0 ? nb : dot - neg);
	ex_max = (data->str_type == "float" ? 38 : 308);
	if (nb == 0)
		throw errSyntax(": Syntax error on \"" + value + "\", nothing is inside");
	if (nb > ex_max)
		throw errOverflow(": the value \"" + value + "\" is infinite, absolute value : " +
											(data->str_type == "float" ? "3.40282e+-38" : "1.79769e+-308"));
	if (ex == 1)
	{
		std::cout << dot << std::endl;
		i = nb + (dot != nb ? 1 : 0) + neg;
		while (value[i] == 'e' || value[i] == '+' || value[i] == '-')
			i++;
		while (value[i] != '\0')
		{
			chk += value[i];
			i++;
		}
		std::stringstream convert(chk);
		convert >> ex;
		if (ex + (nb - (nb - dot)) > ex_max + 1)
			throw errOverflow(": the value \"" + value + "\" is infinite, absolute value : " +
											(data->str_type == "float" ? "3.40282e+-38" : "1.79769e+-308"));
	}
	if (ex + (nb - (nb - dot)) > ex_max)
		CheckFloatAbolute(data, value, neg);
	data->value = value;
}

void	Parser::CheckLineError(t_exeData const *data) const
{
	if ((data->str_func == "push" || data->str_func == "assert") && data->str_type == "")
		throw errSyntax(": \"" + data->str_func + "\" need value in parameter");
	if (data->str_func != "push" && data->str_func != "assert" && data->str_type != "")
		throw errSyntax(": \"" + data->str_func + "\" have no value in parameter");
}

std::string 	*Parser::ParseString(std::string line)
{
	std::string	*chk = new std::string[4];
	int					i = 0;
	int					j = 0;
	int					k = 0;

	if (line == "")
		throw errEmpty("");
	while (line[i] != ';' && line[i] != '\n' && line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '(')
			i++;
		chk[j] = "";
		k = 0;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '(' && line[i] != ')' &&
					 line[i] != ';' && line[i] != '\n' && line[i] != '\0')
		{
			chk[j] += line[i];
			k++;
			i++;
		}
		if (j == 2 && chk[1] != "" && chk[2] == "")
			throw errInstruct(": no value for the type \"" + chk[1] + "\"");
		if (j == 2 && chk[2] != "" && line[i] != ')')
			throw errSyntax(": a ')' is missing");
		j += (chk[j] != "" ? 1 : 0);
		if (line[i] == '\n' || line[i] == '\0' || j > 2)
			break;
		i++;
	}
	return (chk);
}

void		Parser::GetData(std::string line)
{
	t_exeData		*data = new t_exeData;
	std::string	*chk;

	chk = ParseString(line);
	if (chk[0] == "")
		throw errEmpty("");
	CheckFunction(data, chk[0]);
	data->str_func = chk[0];
	if (chk[1] != "")
	{
		CheckType(data, chk[1]);
		data->str_type = chk[1];
		if (data->str_type == "float" || data->str_type == "double")
			CheckFloatValue(data, chk[2]);
		else
			CheckValue(data, chk[2]);
	}
	CheckLineError(data);
	funcList->Add(data);
}

void	 	Parser::CheckGeneralError()
{
	t_exeList 	*chk = funcList->PopBegin();
	int 				err[3];

	err[0] = 0;
	if (chk == NULL)
		throw errGeneral("Commandes lines are empty !");
	while (chk)
	{
		if (chk->elem->str_func == "exit")
			err[0]++;
		chk = chk->next;
	}
	if (err[0] == 0)
		throw errGeneral("No \"exit\" function !");
	if (err[0] > 1)
	{
		funcList->DelAll("exit");
		throw errGeneral("To mutch \"exit\" functions !");
	}
}

void		Parser::InitCodeFile(std::string const file_name)
{
	std::ifstream 	exist;
	std::string 		tmp;
	std::string 		chk;
	int 						i;

	tmp = "";
	i = 1;
	while (file_name[i])
	{
		tmp += file_name[i];
		i++;
	}
	tmp += ".avm";
	exist.open(tmp.c_str());
	if (exist)
	{
		exist.close();
		std::cout << "The file already exist, do you want overwrite on it ? : [y/n]" << std::endl;
		std::cin >> chk;
		if (chk[0] != 'y' && chk[0] != 'Y')
			throw errAbort("See you soon");
  }
	codeFile.open(tmp.c_str(), std::ios::trunc);
	if (codeFile.is_open() == false)
		throw errAbort("The file can't be created");
}

void		Parser::ReadFile(std::string const file_name)
{
	std::ifstream file(file_name.c_str());
	std::string		line;
	int 					err = 0;

	linePos = 0;
	if (file.is_open())
	{
		while (getline(file, line))
			{
				try
				{
					GetData(line);
				}
				catch (errExcept &e)
				{
					MsgErr(e.what());
					err = 1;
				}
				catch (errEmpty &e) {}
				linePos++;
			}
		file.close();
		if (err == 1)
			throw errGeneral("- Can't execute the the programme, too much errors -");
	}
	else
		throw errGeneral("The file \"" + file_name + "\" doesn't exist");
	try
	{
		CheckGeneralError();
	}
	catch (errGeneral &e)
	{
		MsgErr(e.what());
	}
	Executer 	execute(funcList, funcName);
}

int 	Parser::InputEnd(std::string line)
{
	int 	i = 0;

	while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] == ';' && line[i + 1] == ';')
				return (1);
			i++;
		}
	return (0);
}

void 	Parser::ReadInput()
{
	char 				*input;
	std::string line;
	int 				end;
	int 				err;

	linePos = 0;
	while (42)
	{
		readInput:
		std::cin.getline(input, 512);
		line = input;
		err = 0;
		end = InputEnd(line);
		try
		{
			GetData(line);
		}
		catch (errExcept &e)
		{
			MsgErr(e.what());
			err = 1;
		}		
		catch (errEmpty &e) {}
		if (err == 0 && fileWrite == 1 && codeFile.is_open())
			codeFile << line.c_str() << '\n';
		if (end == 1)
			break;
		if (err == 0)
			linePos++;
	}
	try
	{
		CheckGeneralError();
	}
	catch (errGeneral &e)
	{
		MsgErr(e.what());
		goto readInput;
	}
	if (fileWrite == 1 && codeFile.is_open())
		codeFile.close();
	Executer 	execute(funcList, funcName);
	return ;
}