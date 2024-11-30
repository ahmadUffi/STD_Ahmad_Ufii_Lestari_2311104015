#include <iostream>
#include <limits>
using namespace std;

struct Pohon {
    int data;  // Changed to int for BST validation
    Pohon *left, *right, *parent;

    Pohon(int d, Pohon *l = NULL, Pohon *r = NULL, Pohon *p = NULL) 
        : data(d), left(l), right(r), parent(p) {}
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(int data) {
    if(isEmpty()) {
        root = new Pohon(data, NULL, NULL, NULL);
        cout << "\nNode " << data << " berhasil dibuat menjadi root" << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(int data, Pohon *node) {
    if(isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child di kiri" << endl;
        return NULL;
    }
    baru = new Pohon(data, NULL, NULL, node);
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kiri " << node->data << endl;
    return baru;
}

Pohon *insertRight(int data, Pohon *node) {
    if(isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child di kanan" << endl;
        return NULL;
    }
    baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kanan " << node->data << endl;
    return baru;
}

// New function to display child nodes
void tampilkanChild(Pohon *node) {
    if (!node) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }
    
    cout << "Node " << node->data << " memiliki:" << endl;
    if (node->left)
        cout << "- Child kiri: " << node->left->data << endl;
    else
        cout << "- Tidak ada child kiri" << endl;
        
    if (node->right)
        cout << "- Child kanan: " << node->right->data << endl;
    else
        cout << "- Tidak ada child kanan" << endl;
}

// New function to display descendants recursively
void tampilkanDescendant(Pohon *node, int level = 0) {
    if (!node) return;
    
    if (level > 0) {
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "└─ " << node->data << endl;
    }
    
    tampilkanDescendant(node->left, level + 1);
    tampilkanDescendant(node->right, level + 1);
}

// New function to validate BST
bool is_valid_bst(Pohon *node, int min_val = INT_MIN, int max_val = INT_MAX) {
    if (!node) return true;
    
    if (node->data <= min_val || node->data >= max_val)
        return false;
        
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// New function to count leaf nodes
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    
    if (!node->left && !node->right)
        return 1;
        
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Function to find node by value
Pohon* findNode(Pohon* node, int value) {
    if (!node) return NULL;
    if (node->data == value) return node;
    
    Pohon* leftResult = findNode(node->left, value);
    if (leftResult) return leftResult;
    
    return findNode(node->right, value);
}

int main() {
    init();
    int choice, data, parentValue;
    Pohon* selectedNode;
    
    while (true) {
        cout << "\n=== MENU PROGRAM BINARY TREE ===" << endl;
        cout << "1. Buat Root" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Tampilkan Child dari Node" << endl;
        cout << "5. Tampilkan Descendant dari Node" << endl;
        cout << "6. Cek Validitas BST" << endl;
        cout << "7. Hitung Jumlah Daun" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Masukkan nilai root: ";
                cin >> data;
                buatNode(data);
                break;
                
            case 2:
                if(isEmpty()) {
                    cout << "Buat root terlebih dahulu!" << endl;
                    break;
                }
                cout << "Masukkan nilai node: ";
                cin >> data;
                cout << "Masukkan nilai parent: ";
                cin >> parentValue;
                selectedNode = findNode(root, parentValue);
                if(selectedNode)
                    insertLeft(data, selectedNode);
                else
                    cout << "Parent node tidak ditemukan!" << endl;
                break;
                
            case 3:
                if(isEmpty()) {
                    cout << "Buat root terlebih dahulu!" << endl;
                    break;
                }
                cout << "Masukkan nilai node: ";
                cin >> data;
                cout << "Masukkan nilai parent: ";
                cin >> parentValue;
                selectedNode = findNode(root, parentValue);
                if(selectedNode)
                    insertRight(data, selectedNode);
                else
                    cout << "Parent node tidak ditemukan!" << endl;
                break;
                
            case 4:
                if(isEmpty()) {
                    cout << "Pohon masih kosong!" << endl;
                    break;
                }
                cout << "Masukkan nilai node yang ingin dilihat child-nya: ";
                cin >> data;
                selectedNode = findNode(root, data);
                if(selectedNode)
                    tampilkanChild(selectedNode);
                else
                    cout << "Node tidak ditemukan!" << endl;
                break;
                
            case 5:
                if(isEmpty()) {
                    cout << "Pohon masih kosong!" << endl;
                    break;
                }
                cout << "Masukkan nilai node yang ingin dilihat descendant-nya: ";
                cin >> data;
                selectedNode = findNode(root, data);
                if(selectedNode) {
                    cout << "Descendants dari node " << data << ":" << endl;
                    tampilkanDescendant(selectedNode);
                } else
                    cout << "Node tidak ditemukan!" << endl;
                break;
                
            case 6:
                if(isEmpty()) {
                    cout << "Pohon masih kosong!" << endl;
                    break;
                }
                if(is_valid_bst(root))
                    cout << "Pohon adalah Binary Search Tree yang valid" << endl;
                else
                    cout << "Pohon BUKAN Binary Search Tree yang valid" << endl;
                break;
                
            case 7:
                if(isEmpty()) {
                    cout << "Pohon masih kosong!" << endl;
                    break;
                }
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
                
            case 8:
                cout << "Program selesai." << endl;
                return 0;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    
    return 0;
}