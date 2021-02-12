#ifndef USER_H
#define USER_H


class User
{
    public:
        string user_id;
        vector<Product *>  products;
        User();
        virtual ~User();

    protected:

    private:
};

#endif // USER_H
