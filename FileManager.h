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
    User loadUserFromFile (CMarkup &xml);
public:

    int returnLastID ();//zmien na private zwrot Id oststniego uzytkownika ma sie odbywac po vector
    //vector <User> loadFromFileToVectorAllUsers (CMarkup &xml);
    vector <User> loadAllUsersFromFileToVector();
    void loadFile(CMarkup &xml);
    FileManager (string fileName) : NAME_FILE (fileName){};
    void loadUsersFromFile (CMarkup xml);
    void saveUserToFile (User user);

};
#endif // FILEMANAGER_H
