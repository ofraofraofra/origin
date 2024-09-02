#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Wt/Dbo/WtSqlTraits.h>
#include <iostream>
#include <string>
#include <memory>
#include <chrono>

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
        Wt::Dbo::belongsTo(a, publisher, "publisher");
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
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};


class Sale {
public:
    float price;
    std::chrono::system_clock::time_point dateSale; 
    int count;
    Wt::Dbo::ptr<Stock> stock;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, dateSale, "date_sale"); 
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock, "stock");
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

    Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ?").bind(publisherName);

    if (!publisher) {
        std::cout << "Publisher not found.\n";
        return;
    }

    std::set<std::string> shopNames;

    for (const auto& book : publisher->books) {
        for (const auto& stock : book->stocks) {
            shopNames.insert(stock->shop->name);
        }
    }

    std::cout << "Shops selling books by publisher " << publisherName << ":\n";
    for (const auto& shopName : shopNames) {
        std::cout << shopName << "\n";
    }
}

int main() {
    try {
       
        std::unique_ptr<Wt::Dbo::backend::Postgres> connection(new Wt::Dbo::backend::Postgres("host=localhost port=5432 dbname=mydb user=myuser password=mypass"));
        Wt::Dbo::Session session;
        session.setConnection(std::move(connection));

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

    return 0;
}
