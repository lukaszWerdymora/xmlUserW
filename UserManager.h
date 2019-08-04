#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileManager.h"
#include <vector>

using namespace std;

class UserManager {
    vector <User> users;
    FileManager fileManager;

public:
    UserManager (string fileNameWithUsers) : fileManager (fileNameWithUsers){};
    User getDataNewUser();//zmien to pozniej na private

    void addUserToVector();
    void registerUser();
    void wyswietl ();
};

#endif // USERMANAGER_H
