#include <iostream>
#include <utility>
#include "vector"
#include <math.h>


class Dict {
private:
    const double P = 3;

    std::string getHash(const std::string& value) const {
        int sum = 0;

        for (char i : value)
            sum += int(i) + 100;

        return std::to_string(sum % this->maxSize);
    }

    class Row {
    public:
        std::string key;
        std::vector<std::string> values;

        Row(const std::string& key, const std::string& value) {
            this->key = key;
            this->values.push_back(value);
        }

        Row() = default;
    };

    Row *table;
    int currentSize;
    int maxSize;

public:

    explicit Dict(int size) {
        this->maxSize = size;
        this->currentSize = 0;
        this->table = new Row[size];
    }

    void set (const std::string& key, const std::string& value) {
        int hash = std::stoi(getHash(key));
        if (this->currentSize <= this->maxSize) {
            if (!this->haveInTable(hash)) {
                this->table[hash] = *new Row(std::to_string(hash), value);
                this->currentSize++;
            } else {
                this->table[hash].values.push_back(value);
                this->currentSize++;
            }
        }
    }

    struct IndexOfAnswer {
        int answer;
        int count;
    };

    bool haveInTable (const int key) {
        return !(this->table[key].values.empty());
    }

    void deleteAt (const std::string& key) {
        std::string index = this->getHash(key);
        if (this->haveInTable(std::stoi(index))) {
            this->table[std::stoi(index)].key = "";
            this->table[std::stoi(index)].values.clear();
        }
    }

    void getAt (const std::string& key) {
      int hash = std::stoi(this->getHash(key));
      std::cout << "\nПоиск элемента с ключом <" << key << ">\n";
      if (this->haveInTable(hash)) {
          auto it = this->table[hash];
          if (it.values.size() == 1) std::cout << "["<< it.key << "]: " << it.values[0];
          else if (!it.values.empty()) {
              std:: cout << "["<< it.key << "]: ";
              std::cout << "{ ";
              for (int i = 0; i < it.values.size(); ++i) {
                  std::cout << it.values[i];
                  if (i + 1 != it.values.size()) std::cout << " | ";
              }
              std::cout << " }";
          }
          std::cout << '\n';

      } else std::cout << "Такого элемента нет!";
    }

    void print () {
        for (int i = 0; i < this->maxSize; i++) {
            if (!this->table[i].key.empty()) {
                auto it = this->table[i];
                if (this->table[i].values.size() == 1) {
                    std::cout << "["<< it.key << "]: " << it.values[0];
                } else if (!it.values.empty()) {
                    std::cout << "["<< it.key << "]: ";
                    std::cout << "{ ";
                    for (int j = 0; j < it.values.size(); ++j) {
                        std::cout << it.values[j];
                        if (j + 1 != it.values.size()) std::cout << " | ";
                    }
                    std::cout << " }";
                }
                std::cout << '\n';
            }
        }
    }
};


int main() {
    Dict* asd = new Dict(10);

    asd->set("это плохо", "Конформность");
    asd->set("ghbsj", "ibragimmmm");
    asd->set("number12", "this is number 12");
    asd->set("number12", "this шловапшщ number 12");
    asd->set("numbre12", "щывлщаыв");
    asd->set("доброе утро!", "ДОбрейшего!");
    asd->set("пожалуйста", "примите лабу)");

//    asd->deleteAt("ghbsj");

    asd->print();

    asd->getAt("ghbsj");

    return 0;
}
