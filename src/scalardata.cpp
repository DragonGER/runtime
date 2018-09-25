#include "scalardata.h"
#include <sstream>
#include <iomanip>

int sqf::scalardata::decimals = -1;

std::string sqf::scalardata::tosqf(void) const
{
	if (decimals == -1)
	{
		auto bufflen = std::snprintf(0, 0, "%g", mvalue) + 1;
		auto buff = new char[bufflen];
		std::snprintf(buff, bufflen, "%g", mvalue);
		auto str = std::string(buff, bufflen);
		delete[] buff;
		return str;
	}
	else
	{
		auto bufflen = std::snprintf(0, 0, "%0.*f", decimals, mvalue) + 1;
		auto buff = new char[bufflen];
		std::snprintf(buff, bufflen, "%0.*f", decimals, mvalue);
		auto str = std::string(buff, bufflen);
		delete[] buff;
		return str;
	}
}
