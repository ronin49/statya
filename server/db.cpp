#include <iostream>
#include <stdexcept>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

int add_task(std::string title, std::string description) {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        // sql::Statement* stmt;
        sql::PreparedStatement* pstmt;
        // sql::ResultSet* res;

        // Connect to MariaDB
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "lol");

        // Select database
        con->setSchema("testdb");

        // Insert new user
        pstmt = con->prepareStatement("INSERT INTO task(title, description) VALUES (?, ?)");
        pstmt->setString(1, title);
        pstmt->setString(2, description);
        pstmt->execute();
        delete pstmt;

        // Select and display users
        // stmt = con->createStatement();
        // res = stmt->executeQuery("SELECT id, name, age FROM users");

        // while (res->next()) {
        //     std::cout << "ID: " << res->getInt("id")
        //               << ", Name: " << res->getString("name")
        //               << ", Age: " << res->getInt("age") << std::endl;
        // }

        // Cleanup
        // delete res;
        // delete stmt;
        delete con;
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
