#ifndef USER_H
# define USER_H
#include <iostream>

using namespace std;

class User {
    int id;
    string login, name, surname, password;

public:
    void setId (int id);
    void setLogin (string login);
    void setName (string name);
    void setSurname (string surname);
    void setPassword (string password);

    int getId ();
    string getLogin ();
    string getName ();
    string getSurname ();
    string getPassword ();
};
#endif // USER_H
