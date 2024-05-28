#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Wt/Dbo/WtSqlTraits.h>
#include <iostream>
#include <string>
#include <memory>

class Publisher;
class Book;
class Shop;
class Stock;
class Sale;

class Publisher {
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Book {
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "id_publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Shop {
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
    }
};

class Stock {
public:
    int count;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book, "id_book");
        Wt::Dbo::belongsTo(a, shop, "id_shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale {
public:
    float price;
    Wt::WDate dateSale;
    int count;
    Wt::Dbo::ptr<Stock> stock;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, dateSale, "date_sale");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock, "id_stock");
    }
};

void createTables(Wt::Dbo::Session& session) {
    session.createTables();
}

void insertTestData(Wt::Dbo::Session& session) {
    Wt::Dbo::Transaction transaction(session);

    Wt::Dbo::ptr<Publisher> publisher = session.add(std::unique_ptr<Publisher>(new Publisher()));
    publisher.modify()->name = "Sample Publisher";

    Wt::Dbo::ptr<Book> book1 = session.add(std::unique_ptr<Book>(new Book()));
    book1.modify()->title = "Sample Book 1";
    book1.modify()->publisher = publisher;

    Wt::Dbo::ptr<Book> book2 = session.add(std::unique_ptr<Book>(new Book()));
    book2.modify()->title = "Sample Book 2";
    book2.modify()->publisher = publisher;

    Wt::Dbo::ptr<Shop> shop1 = session.add(std::unique_ptr<Shop>(new Shop()));
    shop1.modify()->name = "Sample Shop 1";

    Wt::Dbo::ptr<Shop> shop2 = session.add(std::unique_ptr<Shop>(new Shop()));
    shop2.modify()->name = "Sample Shop 2";

    Wt::Dbo::ptr<Stock> stock1 = session.add(std::unique_ptr<Stock>(new Stock()));
    stock1.modify()->count = 10;
    stock1.modify()->book = book1;
    stock1.modify()->shop = shop1;

    Wt::Dbo::ptr<Stock> stock2 = session.add(std::unique_ptr<Stock>(new Stock()));
    stock2.modify()->count = 5;
    stock2.modify()->book = book2;
    stock2.modify()->shop = shop2;

    transaction.commit();
}

void findShopsByPublisher(Wt::Dbo::Session& session, const std::string& publisherName) {
    Wt::Dbo::Transaction transaction(session);

    Wt::Dbo::collection<Wt::Dbo::ptr<Shop>> shops = session.find<Shop>().where("id IN (SELECT id_shop FROM stock WHERE id_book IN (SELECT id FROM book WHERE id_publisher IN (SELECT id FROM publisher WHERE name = ?)))").bind(publisherName);

    std::cout << "Shops selling books by publisher " << publisherName << ":\n";
    for (const Wt::Dbo::ptr<Shop>& shop : shops) {
        std::cout << shop->name << "\n";
    }
}

int main() {
    try {
        Wt::Dbo::backend::Postgres connection("host=localhost port=5432 dbname=lesson21 user=myuser password=mypass");
        Wt::Dbo::Session session;
        session.setConnection(connection);

        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");

        createTables(session);
        insertTestData(session);

        std::string publisherName;
        std::cout << "Enter publisher name: ";
        std::cin >> publisherName;

        findShopsByPublisher(session, publisherName);
    }
    catch (const Wt::Dbo::Exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
