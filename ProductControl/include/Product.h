#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
    public:
        string prod_id;
        string categeory;
        string status;
        int quantity;
        int purchase_quantity;
        Product(string id,string cat);
        virtual ~Product();

    protected:

    private:
};

#endif // PRODUCT_H
