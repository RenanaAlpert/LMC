#include "Assembly.h"
#include <vector>

namespace experis
{

std::vector<std::string> Split(const std::string& a_toSplit, const char a_howSplit)
{
    std::vector<std::string> partsOfString{};
	int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= a_toSplit.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (a_toSplit[i] == a_howSplit || i == a_toSplit.size()) {
            endIndex = i;
            std::string temp;
            temp.append(a_toSplit, startIndex, endIndex - startIndex);
            partsOfString.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return partsOfString;
}

Command AssemblyToBinary(const std::string& a_command)
{
	std::vector<std::string> partsOfCommand  = Split(a_command, ' ');
}

}