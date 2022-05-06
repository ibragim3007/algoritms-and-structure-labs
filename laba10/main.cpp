#include <iostream>
#include <utility>
#include "vector"
#include <math.h>


class Dict {
private:
    const double P = 3;

    std::string getHash(const std::string& value) const {
        int sum = 0;

        for (int i = 0; i < value.length(); i++)
            sum += value.length() + pow(this->P, i);

        return std::to_string(sum % 1000);
    }

    class Row {
    public:
        std::string key;
        std::vector<std::string> values;

        Row(std::string key, const std::string& value) {
            this->key = std::move(key);
            this->values.push_back(value);
        }
    };

    std::vector<Row>* table =  new std::vector<Row>();

public:

    void set (const std::string& key, const std::string& value) {
        std::string hash = getHash(key);
        int index = indexOf(hash);

        if (index == -1)
            this->table->push_back(*new Row(hash, value));
        else
            this->table->at(index).values.push_back(value);
    }

    int indexOf (const std::string& key) {
        for (int i = 0; i < table->size(); i++)
            if (this->table->at(i).key == key)
                return i;

        return -1;
    }

    void deleteAt (const std::string& key) {
        std::string hash = this->getHash(key);
        int index = this->indexOf(hash);

        if (index != 1) {
            this->table->erase(table->begin() + index);
        }
    }

    void getAt (const std::string& key) {
      std::string hash = this->getHash(key);
      int index = this->indexOf(hash);

      int counter = 0;

      if (index != -1) {
          std::cout << "Поиск: \n";
          counter++;

          auto it = this->table->at(index);

          if (it.values.size() == 1) {
              std::cout << "["<< it.key << "]: " << it.values[0];
          } else if (!it.values.empty()) {
              std:: cout << "["<< it.key << "]: ";
              std::cout << "(";
              for (int i = 0; i < it.values.size(); ++i) {
                  std::cout << it.values[i];
                  if (i + 1 != it.values.size()) std::cout << ", ";
              }
              std::cout << ")";
          }
          std::cout << '\n';

          std::cout << "Сравнений: " << counter;
      } else std::cout << "Такого элемента нет!";
    }

    void print () {
        for (auto it = table->begin(); it != table->end(); it++) {
            if (it->values.size() == 1) {
                std::cout << "["<< it->key << "]: " << it->values[0];
            } else if (!it->values.empty()) {
                std:: cout << "["<< it->key << "]: ";
                std::cout << "(";
                for (int i = 0; i < it->values.size(); ++i) {
                    std::cout << it->values[i];
                    if (i + 1 != it->values.size()) std::cout << ", ";
                }
                std::cout << ")";
            }
            std::cout << '\n';
        }
    }
};


int main() {
    Dict* asd = new Dict();

    asd->set("это плохо", "Конформность");
    asd->set("Нет, в красноречии истинный успех!", "Но в этом, признаюсь, я поотстал от всех");
    asd->set("chelo", "ibragimmmm");
    asd->set("number1", "this is number 1");
    asd->set("number12", "this is number 32");

    asd->deleteAt("number1");

//    asd->deleteAt("как у вас дела");

    asd->print();


    asd->getAt("chel");

    return 0;
}
