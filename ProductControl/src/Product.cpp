#include "Product.h"

Product::Product(string id, string cat)
{
   this->prod_id = id;
   this->categeory = cat;
   this->status = "added";
   this->quantity =1;
   this->purchase_quantity =0;
}

Product::~Product()
{
    //dtor
}
