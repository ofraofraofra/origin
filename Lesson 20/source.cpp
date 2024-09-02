#include <iostream>
#include <pqxx/pqxx> 

class ClientManager {
public:
    ClientManager(const std::string& connectionString)
        : conn(connectionString) {}

    void createTables() {
        pqxx::work txn(conn);
        txn.exec("CREATE TABLE IF NOT EXISTS clients ("
                 "id SERIAL PRIMARY KEY,"
                 "first_name VARCHAR(50),"
                 "last_name VARCHAR(50),"
                 "email VARCHAR(100));");
        txn.exec("CREATE TABLE IF NOT EXISTS phones ("
                 "id SERIAL PRIMARY KEY,"
                 "client_id INT REFERENCES clients(id) ON DELETE CASCADE,"
                 "phone_number VARCHAR(20));");
        txn.commit();
    }

    void addClient(const std::string& firstName, const std::string& lastName, const std::string& email) {
        pqxx::work txn(conn);
        txn.exec("INSERT INTO clients (first_name, last_name, email) VALUES (" +
                 txn.quote(firstName) + ", " +
                 txn.quote(lastName) + ", " +
                 txn.quote(email) + ");");
        txn.commit();
    }

    void addPhone(int clientId, const std::string& phoneNumber) {
        pqxx::work txn(conn);
        txn.exec("INSERT INTO phones (client_id, phone_number) VALUES (" +
                 txn.quote(clientId) + ", " +
                 txn.quote(phoneNumber) + ");");
        txn.commit();
    }

    void updateClient(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email) {
        pqxx::work txn(conn);
        txn.exec("UPDATE clients SET first_name = " + txn.quote(firstName) + 
                 ", last_name = " + txn.quote(lastName) + 
                 ", email = " + txn.quote(email) + 
                 " WHERE id = " + txn.quote(clientId) + ";");
        txn.commit();
    }

    void deletePhone(int phoneId) {
        pqxx::work txn(conn);
        txn.exec("DELETE FROM phones WHERE id = " + txn.quote(phoneId) + ";");
        txn.commit();
    }

    void deleteClient(int clientId) {
        pqxx::work txn(conn);
        txn.exec("DELETE FROM clients WHERE id = " + txn.quote(clientId) + ";");
        txn.commit();
    }

    void findClient(const std::string& query) {
        pqxx::work txn(conn);
        pqxx::result result = txn.exec("SELECT c.id, c.first_name, c.last_name, c.email, p.phone_number FROM clients c "
                                       "LEFT JOIN phones p ON c.id = p.client_id WHERE "
                                       "c.first_name ILIKE " + txn.quote("%" + query + "%") + 
                                       " OR c.last_name ILIKE " + txn.quote("%" + query + "%") +
                                       " OR c.email ILIKE " + txn.quote("%" + query + "%") +
                                       " OR p.phone_number ILIKE " + txn.quote("%" + query + "%") + ";");
        for (auto row : result) {
            std::cout << "ID: " << row["id"].c_str()
                      << ", Name: " << row["first_name"].c_str() << " " << row["last_name"].c_str()
                      << ", Email: " << row["email"].c_str()
                      << ", Phone: " << row["phone_number"].c_str() << std::endl;
        }
    }

private:
    pqxx::connection conn;
};

int main() {
    const std::string connectionString = "dbname=mydatabase user=myuser password=mypassword hostaddr=127.0.0.1 port=5432";

    ClientManager cm(connectionString);

    cm.createTables();
    cm.addClient("John", "Doe", "john.doe@example.com");
    cm.addPhone(1, "+123456789");
    cm.updateClient(1, "Johnny", "Doe", "johnny.doe@example.com");
    cm.findClient("Johnny");
    cm.deletePhone(1);
    cm.deleteClient(1);

    return 0;
}
