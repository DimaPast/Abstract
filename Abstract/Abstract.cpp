#include <iostream>
#include <string>


class Table {
public:
    virtual void info() const = 0;
};


class Chair {
public:
    virtual void info() const = 0;
};


class FurnitureFactory {
public:
    virtual Table* createTable() const = 0;
    virtual Chair* createChair() const = 0;
};


class WoodenTable : public Table {
public:
    void info() const override {
        std::cout << "Wooden Table\n";
    }
};


class WoodenChair : public Chair {
public:
    void info() const override {
        std::cout << "Wooden Chair\n";
    }
};


class WoodenFurnitureFactory : public FurnitureFactory {
public:
    Table* createTable() const override {
        return new WoodenTable();
    }

    Chair* createChair() const override {
        return new WoodenChair();
    }
};


class MetalTable : public Table {
public:
    void info() const override {
        std::cout << "Metal Table\n";
    }
};


class MetalChair : public Chair {
public:
    void info() const override {
        std::cout << "Metal Chair\n";
    }
};


class MetalFurnitureFactory : public FurnitureFactory {
public:
    Table* createTable() const override {
        return new MetalTable();
    }

    Chair* createChair() const override {
        return new MetalChair();
    }
};

int main() {
    
    FurnitureFactory* woodenFactory = new WoodenFurnitureFactory();

    Table* woodenTable = woodenFactory->createTable();
    Chair* woodenChair = woodenFactory->createChair();

    woodenTable->info();
    woodenChair->info();

    delete woodenTable;
    delete woodenChair;
    delete woodenFactory;


    FurnitureFactory* metalFactory = new MetalFurnitureFactory();

    Table* metalTable = metalFactory->createTable();
    Chair* metalChair = metalFactory->createChair();

    metalTable->info();
    metalChair->info();

    delete metalTable;
    delete metalChair;
    delete metalFactory;

    return 0;
}
