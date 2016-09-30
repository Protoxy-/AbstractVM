//
// Stack.hh for Stack in /home/dayrie_l/rendu/cpp_abstractvm
// 
// Made by Lucas Dayries
// Login   <dayrie_l@epitech.net>
// 
// Started on  Thu Feb 26 10:46:00 2015 Lucas Dayries
// Last update Thu Feb 26 15:12:51 2015 Lucas Dayries
//

#ifndef STACK_HH_
# define STACK_HH_

#include <iostream>
#include <deque>
#include <map>
#include <string>
#include "Operand.hpp"

class Stack
{
public:
  Stack();
  Stack(Stack const &other);
  Stack& operator=(Stack const &other);
  ~Stack();

  void functionCall(std::string str1, std::string str2 = "");


  std::deque<IOperand *> stack;
  std::map<std::string, void (Stack::*)()> function;
  std::map<std::string, IOperand* (Stack::*)(std::string const&)> functionType;

  void push(IOperand *arg);
  void pop();
  void dump();
  void assert(IOperand *arg);
  void add();
  void sub();
  void mul();
  void div();
  void mod();
  void print();

  IOperand *createInt8(std::string const& value);
  IOperand *createInt16(std::string const& value);
  IOperand *createInt32(std::string const& value);
  IOperand *createFloat(std::string const& value);
  IOperand *createDouble(std::string const& value);
};

#endif /* !STACK_HH_ */
