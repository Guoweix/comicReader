#include <book.hpp>


bool book::isPicture(std::filesystem::directory_entry tar)
{
    return tar.is_regular_file()&&(tar.path().extension().string()=="png"||
        tar.path().extension().string()=="jpg"||
        tar.path().extension().string()=="jpeg"||
        tar.path().extension().string()=="webp"
        );
}

bool book::isCompressed(std::filesystem::directory_entry tar)
{
    return tar.is_regular_file()&&(tar.path().extension().string()=="zip"||
        tar.path().extension().string()=="rar"||
        tar.path().extension().string()=="7z"
        );
}

ErrorType book::init(std::string path)
{

    bookPath=std::filesystem::path(path);
    if(!std::filesystem::exists(bookPath))
    {
        return CAN_NOT_FIND_PATH; 
    }
    type=shortManga;
    bool hasSurface;
    std::filesystem::path surfacePath;
    //如果有子文件夹或者压缩包，则认为这是一个长篇漫画，里面章节按文件夹划分。
    for (const auto& entry : std::filesystem::recursive_directory_iterator(bookPath)) 
    {
        if(entry.is_directory()|| isCompressed(entry))
        {
            type=longFormManga;
            chapter.push_back(entry.path());
        }
        else if(!hasSurface&&isPicture(entry))
        {
            hasSurface=true;
            surfacePath=entry.path();
        }
    }
    
    if (type==longFormManga) 
    {
        if (hasSurface) {
            head=surfacePath;
        }
        


        
    }
    

    return SUCCESS;
}