#include <iostream>
#include "sqlite3.h"
#include <string>
using namespace std;
namespace Sqlite
{
    class SqliteConnection
    {
    private:
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        const char *dbName;
        void log(string msg);
    public:
        SqliteConnection(const char* dbPath);
        int open();
        string GetDbName();
        void close();
        void execute(string query, string msg, int (*callback)(void *Notused, int argc, char **argv, char **azColName));
        ~SqliteConnection();
    };
    
    
    
} // namespace Sqlite
