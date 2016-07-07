#include "ArgParser.hpp"

#include <iostream>

void ArgParser::addParameter(AbstractArgParam *p)
{
	parameters.push_back(p);
}

void ArgParser::parse(int argc, char **argv)
{
	bool recognized;
	for(unsigned int i = 1; i < argc; i++)
	{
		recognized = false;
		for(std::vector<AbstractArgParam *>::iterator it = parameters.begin(); it != parameters.end(); ++it)
		{
			if(argv[i] == (*it)->getShortOpt())
			{
				recognized = true;
				if((*it)->needsOpt())
					if(i+1 < argc)
					{
						if((*it)->setOpt(argv[i+1]))
							i++;
					}
					else
					{
						std::cerr << "[!] Option '" << (*it)->getShortOpt() << "' needs a parameter..." << std::endl;
						throw std::exception();
					}
			}
		}
		if(!recognized)
		{
			std::cerr << "[!] Unrecognized option '" << argv[i] << "'..." << std::endl;
			throw std::exception();
		}
	}
}
