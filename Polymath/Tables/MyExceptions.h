#pragma once
#include <string>

class MyExcepions
{
public:
	std::string message;
};

class NothingFoundExeption : public MyExcepions
{
public:
	NothingFoundExeption(const std::string& _message) { message = _message; }
};

class AddExeption : public MyExcepions
{
public:
	AddExeption(const std::string& _message) { message = _message; }
};

class EmptyTableExeption : public MyExcepions
{
public:
	EmptyTableExeption(const std::string& _message) { message = _message; }
};

class NoPolyExeption : public MyExcepions
{
public:
	NoPolyExeption(const std::string& _message) { message = _message; }
};

