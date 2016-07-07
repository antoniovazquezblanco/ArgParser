#ifndef _H_ARGPARAM_
#define _H_ARGPARAM_

#include "AbstractArgParam.hpp"

#include <string>

template<class T>
class ArgParam : public AbstractArgParam
{
public:
	ArgParam(std::string shortoption);

	std::string getShortOpt();

	bool needsOpt();
	bool setOpt(char* opt);
	bool isSet();

	T getValue();

private:
	std::string shortopt;
	std::string opt;
	bool set;
	T value;
};

#endif
