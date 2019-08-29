#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"
#include "Markup.h"
#include "helpMethods.h"
#include <vector>
using namespace std;

class FileManager {
    CMarkup xml;

    const string NAME_FILE="xmlUser.xml";


public:
    User loadUserFromFile (CMarkup &xml);//zmien na private
    int returnLastID (CMarkup &xml);//zmien na private
    vector <User> loadFromFileToVectorAllUsers (CMarkup &xml);
    void loadFile(CMarkup &xml);
    FileManager (string fileName) : NAME_FILE (fileName){};
    void loadUsersFromFile (CMarkup xml);
    void saveUserToFile (User user);

};
#endif // FILEMANAGER_H
