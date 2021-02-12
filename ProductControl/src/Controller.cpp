#include "Controller.h"

Controller::Controller()
{
   this->users = vector<User *> ();
   this->products = vector<Product *> ();
}

Controller::~Controller()
{
    //dtor
}

void Controller::addProduct(string pd,string ct)
{
    Product * pd = this->getProduct(pd,cd);
    if(pd){
        pd->quantity++;
    }
    else{
        Product * prod = new Product(pd,ct);
        this->products.push_back(prod);
    }
}

void Controller::buyProduct(string user,string pd,string cd){
    Product * pd = this->getProduct(pd,cd);
    User * userid = this->getUser(user);
    if(pd && pd->quantity>0){
        if(userid==NULL){
            userid = new User(user);
            pd->purchase_quantity++;
        }
        userid->products.push_back(pd);
        pd->quantity--;
        pd->purchase_quantity++;
    }
    else{
        cout<<"no product";
    }
}

void Controller::returnProduct(string user,string pd,string cd){
    User * user = this->getUser(user);
    if(user){
        for(auto i:user->products){
           if(i->prod_id == pd && i->categeory==cd){
              i->purchace_quantity--;
           }
       }
    }
    else{
        cout<<"No user";
    }
}

void Controller::Blacklist(string user){
    User * user = this->getUser(user);
    if(user){
        for(auto i:user->products){
            i->purchase_quantity--;
        }
    }
    else{
        cout<<"No user"';
    }
}

void Controller::BestSellingProduct(){
    map<string,vector<Product *>> map_product;
    for(auto i:this->products){

    }
}
