#ifndef __BOOK_CPP__
#define __BOOK_CPP__

#include <filesystem>
#include <vector>
#include <error.hpp>


class book 
{
    enum:int 
    {
        longFormManga=0, 
        shortManga=1,
    };

    std::filesystem::path bookPath;
    std::vector<std::filesystem::path> chapter;
    std::filesystem::path head;
    int type;

    public:
    ErrorType init(std::string);
    bool isPicture(std::filesystem::directory_entry);
    bool isCompressed(std::filesystem::directory_entry);


};

#endif
