#include "User.h"

User::User(string id)
{
    this->user_id = id;
    this->products = vector<Product *> ();
}

User::~User()
{
    //dtor
}
