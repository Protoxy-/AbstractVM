//
// Parser.hh for Parser in /home/hoerte_f/rendu/cpp_abstractvm
//
// Made by Francois Hoertel
// Login   <hoerte_f@epitech.net>
//
// Started on  Thu Feb 12 11:28:35 2015 Francois Hoertel
// Last update Thu Feb 12 11:28:36 2015 Francois Hoertel
//

#ifndef PARSER_HH_
#define PARSER_HH_

#include "Exception.hh"
#include "ExecData.hh"
#include "Executer.hh"

class Parser
{
  ListExec                *funcList;
  std::string             *funcName;
  std::ofstream           codeFile;
  int                     fileWrite;
  int                     linePos;

public:
	Parser(std::string const);
	~Parser();

  void   MsgErr(std::string const) const;
  void   InitTables();
  void   CheckFunction(t_exeData *, std::string const) const;
  void   CheckType(t_exeData *, std::string const) const;
  void   CheckValue(t_exeData *, std::string const) const;
  void   CheckFloatAbolute(t_exeData *, std::string const, int const) const;
  void   CheckFloatValue(t_exeData *, std::string const) const;
  void   CheckLineError(t_exeData const *) const;

  std::string   *ParseString(std::string line);
  void          GetData(std::string);

  void   CheckGeneralError();
  void   InitCodeFile(std::string const);
  void   WriteCodeFile();

  void   ReadFile(std::string const);
  int    InputEnd(std::string);
  void   ReadInput();
};

#endif