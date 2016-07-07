#ifndef _H_ABSTRACTARGPARSE_
#define _H_ABSTRACTARGPARSE_

#include <string>

class AbstractArgParam
{
public:
	virtual std::string getShortOpt() = 0;
	virtual bool needsOpt() = 0;
	virtual bool setOpt(char* opt) = 0;
};

#endif
