//
// Stack.cpp for Stack in /home/dayrie_l/rendu/cpp_abstractvm
// 
// Made by Lucas Dayries
// Login   <dayrie_l@epitech.net>
// 
// Started on  Thu Feb 26 15:25:12 2015 Lucas Dayries
// Last update Thu Feb 26 15:34:42 2015 Lucas Dayries
//

#include <string>
#include <iterator>
#include <sys/types.h>

#include "Exception.hh"
#include "IOperand.hh"
#include "Operand.hpp"
#include "Stack.hh"

Stack::Stack()
{
  function["pop"] = &Stack::pop;
  function["dump"] = &Stack::dump;
  function["add"] = &Stack::add;
  function["sub"] = &Stack::sub;
  function["mul"] = &Stack::mul;
  function["div"] = &Stack::div;
  function["mod"] = &Stack::mod;
  function["print"] = &Stack::print;
  functionType["int8"] = &Stack::createInt8;
  functionType["int16"] = &Stack::createInt16;
  functionType["int32"] = &Stack::createInt32;
  functionType["float"] = &Stack::createFloat;
  functionType["double"] = &Stack::createDouble;
}

Stack::~Stack()
{
  while (stack.size() != 0)
    {
      delete stack.front();
      stack.pop_front();
    }
}

IOperand        *Stack::createInt8(std::string const& value)
{
  return (new Operand<int16_t>(value, Int8));
}

IOperand        *Stack::createInt16(std::string const& value)
{
  return (new Operand<int16_t>(value, Int16));
}

IOperand        *Stack::createInt32(std::string const& value)
{
  return (new Operand<int32_t>(value, Int32));
}

IOperand        *Stack::createFloat(std::string const& value)
{
  return (new Operand<float>(value, Float));
}

IOperand        *Stack::createDouble(std::string const& value)
{
  return (new Operand<double>(value, Double));
}

void            Stack::push(IOperand *val)
{
  stack.push_front(val);
}

void            Stack::pop()
{
  if (stack.empty())
    throw errPileEmpty("the stack is empty");
  delete stack.front();
  stack.pop_front();
}

void            Stack::dump()
{
  std::deque<IOperand *>::iterator      it;

  it = stack.begin();
  while (it != stack.end())
  {
    std::cout << (*it)->toString() << std::endl;
    ++it;
  }
}

void            Stack::assert(IOperand *val)
{
  if (stack.empty())
    throw errPileEmpty("the stack is empty");
  if (val->getPrecision() == stack.front()->getPrecision() &&
      val->toString() == stack.front()->toString())
    return ;
  else
  {
    delete val;
    throw errAssert("assert problem");
  }
}

void            Stack::add()
{
  IOperand      *op1;
  IOperand      *op2;
  IOperand      *res;
  
  if (stack.size() < 2)
    throw errPileLow("the stack need 2 minimum values");
  op1 = stack.front();
  stack.pop_front();
  op2 = stack.front();
  stack.pop_front();
  res = *op1 + *op2;
  stack.push_front(res);
  delete op1;
  delete op2;
}

void            Stack::sub()
{
  IOperand      *op1;
  IOperand      *op2;
  IOperand      *res;

  if (stack.size() < 2)
    throw errPileLow("the stack need 2 minimum values");
  op1 = stack.front();
  stack.pop_front();
  op2 = stack.front();
  stack.pop_front();
  res = *op2 - *op1;
  stack.push_front(res);
  delete op1;
  delete op2;
}

void            Stack::mul()
{
  IOperand      *op1;
  IOperand      *op2;
  IOperand      *res;

  if (stack.size() < 2)
    throw errPileLow("the stack need 2 minimum values");
  op1 = stack.front();
  stack.pop_front();
  op2 = stack.front();
  stack.pop_front();
  res = *op1 * *op2;
  stack.push_front(res);
  delete op1;
  delete op2;
}

void            Stack::div()
{
  IOperand      *op1;
  IOperand      *op2;
  IOperand      *res;

  if (stack.size() < 2)
    throw errPileLow("the stack need 2 minimum values");
  op1 = stack.front();
  stack.pop_front();
  op2 = stack.front();
  stack.pop_front();
  res = *op2 / *op1;
  stack.push_front(res);
  delete op1;
  delete op2;
}

void            Stack::mod()
{
  IOperand      *op1;
  IOperand      *op2;
  IOperand      *res;

  if (stack.size() < 2)
    throw errPileLow("the stack need 2 minimum values");
  op1 = stack.front();
  stack.pop_front();
  op2 = stack.front();
  stack.pop_front();
  res = *op2 % *op1;
  stack.push_front(res);
  delete op1;
  delete op2;
}

void            Stack::print()
{
  std::stringstream     ss;
  short                 tmp;
  char                  c;

  if (stack.size() < 1)
    throw errPileEmpty("the stack is empty");
  if (stack.front()->getType() == Int8)
  {
    ss.str(stack.front()->toString());
    ss >> tmp;
    c = tmp;
    std::cout << c << std::endl;
  }
  else
    throw errPileEmpty("the value on the top is not a \"int8\"");
}
