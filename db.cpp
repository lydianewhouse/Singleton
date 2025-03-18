//db.cpp
#include "db.h"

//Initializes to be nullptr the first time
Database* Database::instance = nullptr;

Database::Database(std::string input_db, std::string input_username, std::string input_password)
{
    //Initializes all variables
    db = input_db;
    username = input_username;
    password = input_password;
    connected = true;
}

Database::~Database()
{
    connected = false;
}

Database* Database::getInstance(std::string input_database, std::string input_username, std::string input_password)
{
    //Check if instance doesn't exist, if so, create instance
    if (instance == nullptr)
    {
        //Creates space for instance
        instance = new Database(input_database, input_username, input_password);

        return instance;
    }
    else
    {
        //Check if inputs match the existing instance
        if (input_database == instance->get_db() && input_username == instance->get_username() && input_password == instance->get_password())
        {
            return instance;
        }
        else
        {
            //Invalid arguments
            throw std::runtime_error("invalid database name, usernae, or password");
        }
    }
}


void Database::connect()
{
    connected = true;
}

void Database::disconnect()
{
    connected = false;
}

bool Database::isConnected()
{
    return connected;
}


void* Database::operator new(size_t size)
{
    //Creates new database with malloc
    std::cout << "overloaded new ";
    void * new_database = malloc(size);

    //Check if unable to allocate
    if (new_database == NULL)
    {
        throw std::bad_alloc();
    }

    return new_database;
}

void Database::operator delete(void* new_database)
{
    std::cout << "overloaded delete ";

    free(new_database);
}




void Database::set_username(std::string new_username)
{
    username = new_username;
}



std::string Database::get_username()
{
    return username;
}

void Database::set_password(std::string new_password)
{
    password = new_password;
}

std::string Database::get_password()
{
    return password;
}

void Database::set_db(std::string new_db)
{
    db = new_db;
}

std::string Database::get_db()
{
    return db;
}


void Database::resetInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}


