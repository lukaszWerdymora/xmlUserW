#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileManager.h"
#include <vector>

using namespace std;

class UserManager {
    vector <User> users;
    FileManager fileManager;
    int idLoggedUser;
    int returnIdNewUser();

public:
    UserManager (string fileNameWithUsers) : fileManager (fileNameWithUsers){
    idLoggedUser=0;
    users=fileManager.loadAllUsersFromFileToVector();
    };
    User getDataNewUser();//zmien to pozniej na private

    void addUserToVector();
    void registerUser();
    void wyswietl ();
    int loggingUser();
    void loggedOut();
    bool ifAnyUserIsLogg();
    void changingPassword();


};

#endif // USERMANAGER_H
