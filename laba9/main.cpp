#include <iostream>
#include <vector>


template<class T>
struct Tree {
    T data;
    Tree *left;
    Tree *right;
};

template<class T>
void addInTree(T newData, Tree<T>*& tree) {
    if (tree == nullptr) {
        tree = new Tree<T>;
        tree->data = newData;
        tree->left = nullptr;
        tree->right = nullptr;
        return;
    }

    if (tree->data < newData) {
        addInTree(newData, tree->right);
    } else {
        addInTree(newData, tree->left);
    }
}

template<class T>
void printTree(Tree<T> *tree) {
    if (tree == nullptr) return;

    printTree(tree->left);
    std::cout << tree->data << ' ';
    printTree(tree->right);

}

const static std::string ch_ver_hor = "|— ", ch_udia_hor = "\\", ch_ver_spa = "| ";
template<class T>
void dump0(Tree<T> const * node, std::string const & prefix = " ", bool root = true, bool last = true) {
    std::cout << prefix << (root ? "" : (last ? ch_udia_hor : ch_ver_hor)) << (node ? std::to_string(node->data) : "") << std::endl;
    if (!node || (!node->left && !node->right))
        return;
    std::vector<Tree<T>*> v{node->left, node->right};
    for (size_t i = 0; i < v.size(); ++i)
        dump0(v[i], prefix + (root ? "" : (last ? " " : ch_ver_spa)), false, i + 1 >= v.size());
}

template<class T>
T deepSearch (T element, Tree<T> *tree, std::vector<T>& listCurrent, int &counter) {

    if (tree == nullptr) {
        return 0;
    }
    else if (tree->data == element) {
        return counter;
    }
    else if (tree->data != element) {
        counter++;
        if (element > tree->data) {
            deepSearch(element, tree->right, listCurrent, counter);
            listCurrent.push_back(tree->data);
        }
        else {
            deepSearch(element, tree->left, listCurrent, counter);
            listCurrent.push_back(tree->data);
        }
    }
    else std::cout << "None";
    return counter;
}

template<class T>
void searchbar(T d, Tree<T>* tree, std::vector<T> &vectorWithSteps,int &counter) {
    if (counter == 0)
        addInTree(d, tree);

    if (tree == nullptr || (tree->data == d && tree->right == nullptr)) std::cout << "Такого нет" << std::endl;
    else if (tree->data == d) std::cout << "Количетсво сравнений: " << counter << std::endl;
    counter++;
    if (tree->data != d) {
        if (d <= tree->data) {
            if (tree->left != nullptr) {
                vectorWithSteps.push_back(tree->data);
                searchbar(d, tree->left, vectorWithSteps, counter);
            }
        }
        else {
            vectorWithSteps.push_back(tree->data);
            if (tree->right != nullptr) {
                vectorWithSteps.push_back(tree->data);
                searchbar(d, tree->right, vectorWithSteps, counter);
            }
        }
    }
}


template<class T>
bool isEmptyTree (Tree<T>*& tree) {
    if (tree == nullptr) return true;
    return false;
}

template<class T>
Tree<T> * delItemTree(Tree<T>*& tree, T valueForDelete) {
    if (tree == nullptr) return tree;

    if (valueForDelete == tree->data) {
        Tree<T> *tmp = nullptr;
        if (tree->right == nullptr) {
            tmp = tree->left;
        } else {
            Tree<T>* ptr = tree->right;
            if (ptr->left == nullptr) {
                ptr->left = tree->left;
                tmp = ptr;
            } else {
                Tree<T> *pmin = ptr->left;
                while (pmin->left != nullptr) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = tree->left;
                pmin->right = tree->right;
                tmp = pmin;
            }
        }
        delete tree;
        return tmp;
    }
    else if (valueForDelete < tree->data)
        tree->left = delItemTree(tree->left, valueForDelete);
    else
        tree->right = delItemTree(tree->right, valueForDelete);
    return tree;
}

template<class T>
void clearTree(Tree<T> *&tree) { tree = nullptr; }

[[noreturn]] int start() {
    Tree<int> *tree = nullptr;
    while(true) {
        std::cout << '\n' <<
            "1. Добавить элемент\n"
            "2. Удалить элемент\n"
            "3. Проверить на пустоту\n"
            "4. Очистить дерево\n"
            "5. Поиск в глубину\n"
            "6. Вывести в порядке возрастания\n"
            "7. Выйти";
        std::cout << "\n> ";
        int menuPickNumber; std::cin >> menuPickNumber;
        if (menuPickNumber == 1) {
            int elem; std::cout << "Введите элемент: "; std::cin >> elem;
            addInTree(elem, tree);
        } else if (menuPickNumber == 2) {
            int elem; std::cout << "Введите элемент: "; std::cin >> elem;
            delItemTree(tree, elem);
        } else if (menuPickNumber == 3) {
            if (isEmptyTree(tree)) std::cout << "Дерево пустое!\n";
            else std::cout << "С днем не пустого дерева! (рождения)\n";
        } else if (menuPickNumber == 4) {
            clearTree(tree);
            std::cout << "Теперь дерево пустое!\n";
        } else if (menuPickNumber == 5) {
            int elem; std::cout << "Введите элемент: "; std::cin >> elem;
            std::vector<int> vectorWithSteps;
            int counter = 0;
            deepSearch(elem, tree, vectorWithSteps, counter);
            delItemTree(tree, elem);

            std::cout << "Путь: ";
            std::reverse(vectorWithSteps.begin(), vectorWithSteps.end());
            for (auto it = vectorWithSteps.begin(); it != vectorWithSteps.end(); it++) {
                std::cout << *it << "->";

                if (it + 1 == vectorWithSteps.end()) std::cout << elem;
            }

            std::cout << "\nКоличество сравнений: " << counter << std::endl;
        } else if(menuPickNumber == 6) {
            printTree(tree);
            std::cout << '\n';
        } else std::cout << "Такого пункта нет!" << std::endl;
        if (tree != nullptr) dump0(tree);
    }
}

int main () {
    start();
//    Tree<int>* tree = nullptr;
//    addInTree(6, tree);
//    addInTree(3, tree);
//    addInTree(2, tree);
//    addInTree(8, tree);
//    addInTree(5, tree);
//
//    std::vector<int> emp;
//    int counter;
//    deepSearchBarrier(2, tree, emp, counter);
//
//    std::reverse(emp.begin(), emp.end());
//    for (auto it = emp.begin(); it != emp.end() ; it++) {
//        std::cout << *it << ' ';
//    }
}