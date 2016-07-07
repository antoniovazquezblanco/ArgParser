#ifndef _H_ARGPARSE_
#define _H_ARGPARSE_

#include "AbstractArgParam.hpp"
#include "ArgParam.hpp"

#include <vector>

class ArgParser
{
public:
	void addParameter(AbstractArgParam *p);
	void parse(int argc, char **argv);

private:
	std::vector<AbstractArgParam *> parameters;
};

#endif
