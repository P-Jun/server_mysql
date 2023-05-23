#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

const string server = "tcp://3.39.231.59:3306";
const string username = "root";
const string password = "example";

const string schema = "test";

int main() {
    try {
        sql::Driver* driver;
        sql::Connection* con;
        sql::ResultSet* res;
        sql::PreparedStatement* pstmt;

        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema(schema);

        pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
        pstmt->setInt(1, 19);
        pstmt->executeUpdate();
        delete pstmt;

        /* Select in ascending order */
        pstmt = con->prepareStatement("SELECT * FROM test WHERE id = ?");
        pstmt->setInt(1, 17);
        res = pstmt->executeQuery();

        res->last();
        int rowCount = res->getRow();
        res->beforeFirst();

        cout << "row_count : " << rowCount << '\n';
        while (res->next())
            cout << "res : " << res->getInt("id") << endl;
        delete res;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Could not connect to server.\nError message: " << e.what() << '\n';
        system("pause");
        exit(1);
    }

    cout << endl;

    return EXIT_SUCCESS;
}