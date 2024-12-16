#ifndef __TOOLS_HPP
#define __TOOLS_HPP
#include <string>
#include <vector>
#include <filesystem>


class PathTool
{
    public:
    std::string prefix; 
    std::string suffix; 
    
    bool getPublicPathPart(std::vector<std::filesystem::path> & );

};


#endif
