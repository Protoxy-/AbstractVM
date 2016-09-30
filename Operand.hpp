//
// Operand.hh for Operand in /home/dayrie_l/rendu/cpp_abstractvm
// 
// Made by Lucas Dayries
// Login   <dayrie_l@epitech.net>
// 
// Started on  Thu Feb 19 14:24:35 2015 Lucas Dayries
// Last update Thu Feb 26 15:19:34 2015 Lucas Dayries
//

#ifndef OPERAND_HH_
# define OPERAND_HH_

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "IOperand.hh"

template <typename T>
class Operand : public IOperand
{
public:
  Operand(eOperandType type);
  Operand(const std::string &value, eOperandType type);
  Operand(Operand const &other);
  Operand& operator=(Operand const &other);
  virtual ~Operand();

  Operand* clone() const;
  virtual std::string const &toString() const;
  virtual int getPrecision() const;
  virtual eOperandType getType() const;

  virtual IOperand *operator+(const IOperand &rhs) const;
  virtual IOperand *operator-(const IOperand &rhs) const;
  virtual IOperand *operator*(const IOperand &rhs) const;
  virtual IOperand *operator/(const IOperand &rhs) const;
  inline virtual IOperand *operator%(const IOperand &rhs) const;

private:
  T value;
  std::string str;
  eOperandType type;
};

template <typename T>
Operand<T>::Operand(const std::string &value, eOperandType type)
  : str(value), type(type)
{
  std::stringstream sstr;

  sstr.str(value);
  sstr >> this->value;
}

template <typename T>
Operand<T>::Operand(Operand const &other)
  : value(other.value), type(other.type), str(other.str)
{
}

template <typename T>
Operand<T>* Operand<T>::clone() const
{
  return (new Operand<T>(this->toString(), this->type));
}

template <typename T>
Operand<T>& Operand<T>::operator=(Operand const &other)
{
  value = other.value;
  type = other.type;
  str = other.str;
  return (*this);
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
std::string const &Operand<T>::toString() const
{
  return (str);
}

template <typename T>
int Operand<T>::getPrecision() const
{
  return (static_cast<int>(type));
}

template <typename T>
eOperandType Operand<T>::getType() const
{
  return (type);
}

template <typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const
{
  Operand *res;
  double tmp;
  std::stringstream str;

  str.str(rhs.toString());
  str >> tmp;
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = value + tmp;
  str.clear();
  str << res->value;
  res->str = str.str();
  return (res);
}

template <typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const
{
  Operand *res;
  double tmp;
  std::stringstream str;

  str.str(rhs.toString());
  str >> tmp;
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = value - tmp;
  str.clear();
  str << res->value;
  res->str = str.str();
  return (res);
}

template <typename T>
IOperand*               Operand<T>::operator/(const IOperand &rhs) const
{
  Operand       *res;
  int           tmp;
  std::stringstream     a;

  a.str(rhs.toString());
  a >> tmp;
  if (tmp == 0)
    throw errDivision("can't divide by 0");
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value / tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <typename T>
inline IOperand*               Operand<T>::operator%(const IOperand &rhs) const
{
  Operand       *res;
  int           tmp;
  std::stringstream     a;

  a.str(rhs.toString());
  a >> tmp;
  if (tmp == 0)
    throw errDivision("can't divide by 0");
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = value % tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <>
inline IOperand*		Operand<float>::operator%(const IOperand &rhs) const
{
  Operand       *res;
  int           tmp;
  std::stringstream     a;

  a.str(rhs.toString());
  a >> tmp;
  if (tmp == 0)
    throw errDivision("can't divide by 0");
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = fmodf(value, tmp);
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <>
inline IOperand*		Operand<double>::operator%(const IOperand &rhs) const
{
  Operand       *res;
  int           tmp;
  std::stringstream     a;

  a.str(rhs.toString());
  a >> tmp;
  if (tmp == 0)
    throw errDivision("can't divide by 0");
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = fmod(value, tmp);
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <typename T>
IOperand *Operand<T>::operator*(const IOperand &rhs) const
{
  Operand *res;
  double tmp;
  std::stringstream str;

  str.str(rhs.toString());
  str >> tmp;
  res = (rhs.getPrecision() > this->getPrecision() ?
         static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value * tmp;
  str.clear();
  str << res->value;
  res->str = str.str();
  return (res);
}

#endif /* !OPERAND_HH_ */
