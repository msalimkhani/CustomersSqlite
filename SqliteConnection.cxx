#include "SqliteConnection.h"
namespace Sqlite
{
    void SqliteConnection::close()
    {
        sqlite3_close(db);
    }
    int SqliteConnection::open()
    {
        this->rc = sqlite3_open(dbName, &db);
        if(this->rc)
        {
            cerr << "Can't Open database: " << sqlite3_errmsg(db) << endl;
            return(0);
        }
        else 
        {
            cout << "Opened Database Successfully" << endl;
            return rc;
        }
    }
    string SqliteConnection::GetDbName()
    {
        return string(dbName);
    }
    void SqliteConnection::log(string msg)
    {
        if( rc != SQLITE_OK)
        {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else
        {
            cout << msg << endl;
        }
    }
    void SqliteConnection::execute(string query, string msg, int (*callback)(void *Notused, int argc, char **argv, char **azColName))
    {
        this->rc = sqlite3_exec(db, query.c_str(), callback, 0, &this->zErrMsg);
        this->log(msg);
    }
    SqliteConnection::SqliteConnection(const char* dbPath)
    {
        this->dbName = dbPath;
    }
    
    SqliteConnection::~SqliteConnection()
    {
        free(db);
        delete zErrMsg;
        delete dbName;
    }
} // namespace Sqlite
