#include <iostream>
using namespace std;

// Struktur untuk node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Kelas LinkedList
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert node di depan
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert node di belakang
    void insertBack(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Cetak linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Hapus node dengan nilai tertentu
    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Cari node dengan nilai tertentu
    bool searchNode(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Hitung panjang linked list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\nOperasi Linked List:\n";
        cout << "1. Tambah node di depan\n";
        cout << "2. Tambah node di belakang\n";
        cout << "3. Cetak linked list\n";
        cout << "4. Hapus node dengan nilai tertentu\n";
        cout << "5. Cari node dengan nilai tertentu\n";
        cout << "6. Cetak panjang linked list\n";
        cout << "7. Keluar\n";
        cout << "Pilih operasi: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                list.insertFront(value);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> value;
                list.insertBack(value);
                break;
            case 3:
                cout << "Isi linked list: ";
                list.printList();
                break;
            case 4:
                cout << "Masukkan nilai yang akan dihapus: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 5:
                cout << "Masukkan nilai yang akan dicari: ";
                cin >> value;
                if (list.searchNode(value))
                    cout << "Node dengan nilai " << value << " ditemukan.\n";
                else
                    cout << "Node dengan nilai " << value << " tidak ditemukan.\n";
                break;
            case 6:
                cout << "Panjang linked list: " << list.length() << endl;
                break;
            case 7:
                cout << "Terima kasih, program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}