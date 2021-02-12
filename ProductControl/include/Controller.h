#ifndef CONTROLLER_H
#define CONTROLLER_H


class Controller
{
    public:
        vector<User *> users;
        vector<Product *> products;
        Controller();
        virtual ~Controller();

    protected:

    private:
};

#endif // CONTROLLER_H
