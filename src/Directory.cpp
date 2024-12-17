#include "Directory.h"

File Directory::getFile(int index) const
{
    if (index >= 0 && index < files.size()) {
        return files[index];
    }
    else {
        return File();
    }
}

size_t Directory::directorySize() const
{
    size_t size = 0;
    if (isEmpty()) {
        return 0;
    }
    else {
        int i;
        for (i = 0; i < files.size(); i++) {
            size += files[i].fileSize();
        }
    }
    return size;

}


bool Directory::isEmpty() const
{
    if (files.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

size_t Directory::numFiles() const
{
    return files.size();
}

void Directory::newFile(const File& file)
{
    files.push_back(file);
}

void Directory::removeFile(int index)
{
    if (index < files.size() && 0 <= index) {
        files.erase(files.begin() + index);
    }

}

void Directory::removeFile(File& file)
{
    std::vector<File>::iterator it;
    for (it = files.begin(); it != files.end(); it++)
    {
        if (*it == file)
        {
            files.erase(it);
            return;
        }
    }


}

void Directory::removeBiggestFile()
{

    if (isEmpty()) {
        return;
    }
    size_t size = 0;
    int index = 0;
    int i;
    for (i = 0; i < files.size(); i++) {
        if (files[i].fileSize() > size) {
            size = files[i].fileSize();
            index = i;
        }
    }
    removeFile(index);

}
