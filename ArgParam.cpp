#include "ArgParam.hpp"

template<class T>
ArgParam<T>::ArgParam(std::string shortoption) : set(false)
{
	shortopt = "-" + shortoption;
}

template<class T>
std::string ArgParam<T>::getShortOpt()
{
	return shortopt;
}

template<class T>
bool ArgParam<T>::needsOpt()
{
	return true;
}

template<>
bool ArgParam<bool>::needsOpt()
{
	return false;
}

template<>
bool ArgParam<std::string>::setOpt(char* opt)
{
	set = true;
	value = std::string(opt);
	return true;
}

template<class T>
bool ArgParam<T>::isSet()
{
	return set;
}

template<class T>
T ArgParam<T>::getValue()
{
	return value;
}

template class ArgParam<std::string>;
