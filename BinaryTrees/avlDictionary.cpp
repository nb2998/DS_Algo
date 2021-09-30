#include <iostream>

using namespace std;

struct TreeNode {
    string key;
    string meaning;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string key, string meaning) {
        this -> key = key;
        this -> meaning = meaning;
        this -> height = 1;
        this -> left = NULL;
        this -> right = NULL;
    }
};

class Tree {
    TreeNode *root;

    int max(int a, int b) { return (a > b) ? a : b; }

    int height(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return node -> height;
    }

    int getBalance(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        return height(node -> left) - height(node -> right);
    }

    TreeNode *rightRotate(TreeNode *y) {
        TreeNode *x = y -> left;
        TreeNode *T2 = x -> right;

        x -> right = y;
        y -> left = T2;

        y -> height = max(height(y -> left), height(y -> right)) + 1;
        x -> height = max(height(x -> left), height(x -> right)) + 1;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x) {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        y -> left = x;
        x -> right = T2;

        x -> height = max(height(x -> left), height(x -> right)) + 1;
        y -> height = max(height(y -> left), height(y -> right)) + 1;

        return y;
    }

    bool notBalanced(TreeNode *node) {
        int balance = getBalance(node);
        if (balance > 1 || balance < -1) {
            return true;
        }
        return false;
    }

    TreeNode *rotate(TreeNode *node) {
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node -> left) >= 1)
            return rightRotate(node);

        if (balance < -1 && getBalance(node -> right) <= -1)
            return leftRotate(node);

        if (balance > 1 && getBalance(node -> left) <= -1)
        {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node -> right) >= 1)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    TreeNode *rotateIfNotBalanced(TreeNode *node) {
        if (notBalanced(node)) {
            return rotate(node);
        }
        return node;
    }

    TreeNode *insert(TreeNode *node, string key, string meaning) {
        if (node == NULL) {
            return new TreeNode(key, meaning);
        } else if (key < node -> key) {
            node -> left = insert(node -> left, key, meaning);
        } else if (key > node -> key) {
            node -> right = insert(node -> right, key, meaning);
        } else {
            return node;
        }

        node -> height = 1 + max(height(node -> left), height(node -> right));

        return rotateIfNotBalanced(node);
    }

    TreeNode *searchKey(TreeNode *node, string key) {
        if (node == NULL) {
            return NULL;
        } else if (node -> key == key) {
            return node;
        } else if (key < node -> key) {
            return searchKey(node -> left, key);
        } else if (key > node -> key) {
            return searchKey(node -> right, key);
        }
    }

    TreeNode *deleteKey(TreeNode *node, string key) {
        TreeNode *returnNode;

        if (key < node -> key) {
            node -> left = deleteKey(node -> left, key);
            returnNode = node;
        } else if (key > node -> key) {
            node -> right = deleteKey(node -> right, key);
            returnNode = node;
        } else {
            if (node -> left == NULL && node -> right == NULL) {
                delete node;
                return NULL;
            } else if (node -> left == NULL && node -> right != NULL) {
                returnNode = node -> right;
                delete node;
            } else if (node -> left != NULL && node -> right == NULL) {
                returnNode = node -> left;
                delete node;
            } else {
                TreeNode *temp = node -> left;

                while (temp -> right != NULL) {
                    temp = temp -> right;
                }

                node -> key = temp -> key;
                node -> meaning = temp -> meaning;
                node -> left = deleteKey(node -> left, temp -> key);

                returnNode = node;
            }
        }

         return rotateIfNotBalanced(returnNode);
    }

    void displayInorder(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        displayInorder(node -> left);
        cout << node -> key << " : " << node -> meaning << endl << endl;
        displayInorder(node -> right);
    }

    void displayReverseInorder(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        displayReverseInorder(node -> right);
        cout << node -> key << " : " << node -> meaning << endl << endl;
        displayReverseInorder(node -> left);
    }

    void displayPreorder(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        cout << node -> key << " : " << node -> meaning << endl << endl;
        displayPreorder(node -> left);
        displayPreorder(node -> right);
    }

public:
    Tree() {
        root = NULL;
    }

    void create(string key, string meaning) {
        root = insert(root, key, meaning);
    }

    void update(string key, string meaning) {
        TreeNode *temp = searchKey(root, key);
        temp -> meaning = meaning;
    }

    bool exists(string key) {
        if (searchKey(root, key) == NULL)
            return false;
        return true;
    }

    void deleteWord(string key) {
        if (searchKey(root, key) == NULL) {
            return;
        }
        root = deleteKey(root, key);
    }

    void display() {
        displayInorder(root);
    }

    void displayAscending() {
        displayInorder(root);
    }

    void displayDescending() {
        displayReverseInorder(root);
    }

    void displayPre() {
        displayPreorder(root);
    }

};


int main() {

    Tree tree;
    string word, meaning;
    char choice;

    do {
        cout << "Enter one of the following :- " << endl;
        cout << "1. Add a word \n2. Update a word \n3. Delete a word \n4. Print dictionary in ascending order";
        cout << "\n5. Print dictionary in descending order \nq. Quit" << endl;

        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter the word to be added : ";
            ws(cin);
            getline(cin, word);
            cout << "Enter its meaning : ";
            getline(cin, meaning);
            tree.create(word, meaning);
            break;

        case '2':
            cout << "Enter word whose meaning is to be updated : ";
            ws(cin);
            getline(cin, word);

            if (!tree.exists(word)) {
                cout << endl << "Word not found" << endl << endl;
                break;
            }

            cout << "Enter the new meaning of the word : ";
            getline(cin, meaning);

            break;

        case '3':
            cout << "Enter the word to be deleted : ";
            ws(cin);
            getline(cin, word);
            if (!tree.exists(word)) {
                cout << endl << "Word not found" << endl << endl;
                break;
            }
            tree.deleteWord(word);
            break;

        case '4':
            cout << endl << endl;
            tree.displayAscending();
            cout << endl << endl;
            break;

        case '5':
            cout << endl << endl;
            tree.displayDescending();
            cout << endl << endl;
            break;

        case 'q':
            break;

        default:
            cout << "Please enter valid input" << endl;
            break;
        }
    } while(choice != 'q');




    return 0;


}


