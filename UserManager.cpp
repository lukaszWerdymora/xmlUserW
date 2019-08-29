#include "UserManager.h"
void UserManager :: registerUser(){
    User user;

    user=getDataNewUser();
    users.push_back(user);
    fileManager.saveUserToFile (user);
}
User UserManager :: getDataNewUser (){
    User user;

    cout<<"Podaj dane uzytkownika do rejestracji: \n";
    user.setId (5);
    user.setLogin("Buzz");
    user.setName ("Maciej");
    user.setSurname ("Brzoza123");
    user.setPassword ("tajne");

    return user;
}
void UserManager :: addUserToVector(){
    User user;
    user=getDataNewUser();
    users.push_back(user);
}
void UserManager :: wyswietl (){
    //cout<<users.size();
    for (int i=0; i<users.size(); i++){

        cout<<users[i].getId()<<endl;
        cout<<users[i].getName()<<endl;
        cout<<users[i].getSurname()<<endl;
        cout<<users[i].getPassword()<<endl;
    }

}

/*
    void setId (int id);
    void setLogin (string login);
    void setName (string name);
    void setSurname (string surname);
    void setPassword (string password);
*/
