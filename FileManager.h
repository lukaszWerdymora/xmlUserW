#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"
#include "Markup.h"
using namespace std;

class FileManager {
    CMarkup xml;

    const string NAME_FILE="xmlUser.xml";


public:
    int returnLastID (CMarkup &xml);//zmien na private
    void loadFile(CMarkup &xml);
    FileManager (string fileName) : NAME_FILE (fileName){};
    void loadUsersFromFile (CMarkup xml);
    void saveUserToFile (User user);

};
#endif // FILEMANAGER_H
