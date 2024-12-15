#include <iostream>
#include <string>
using namespace std;

struct BookNode {
    string title;
    string return_date;
    BookNode* next;

    BookNode(string title, string return_date) : title(title), return_date(return_date), next(nullptr) {}
};

struct MemberNode {
    string name;
    string member_id;
    BookNode* borrowed_books;
    MemberNode* next;

    MemberNode(string name, string member_id) : name(name), member_id(member_id), borrowed_books(nullptr), next(nullptr) {}
};

class LibraryManagement {
private:
    MemberNode* head;

public:
    LibraryManagement() : head(nullptr) {}

    void addMember(const string& name, const string& member_id) {
        MemberNode* newMember = new MemberNode(name, member_id);
        if (!head) {
            head = newMember;
        } else {
            MemberNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newMember;
        }
    }

    void addBook(const string& member_id, const string& title, const string& return_date) {
        MemberNode* current = head;
        while (current) {
            if (current->member_id == member_id) {
                BookNode* newBook = new BookNode(title, return_date);
                if (!current->borrowed_books) {
                    current->borrowed_books = newBook;
                } else {
                    BookNode* b = current->borrowed_books;
                    while (b->next) {
                        b = b->next;
                    }
                    b->next = newBook;
                }
                return;
            }
            current = current->next;
        }
    }

    void removeMember(const string& member_id) {
        MemberNode* current = head;
        MemberNode* prev = nullptr;

        while (current) {
            if (current->member_id == member_id) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }

                while (current->borrowed_books) {
                    BookNode* book = current->borrowed_books;
                    current->borrowed_books = book->next;
                    delete book;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void display() {
        MemberNode* current = head;
        while (current) {
            cout << "Anggota: " << current->name << " (ID: " << current->member_id << ")\n";
            BookNode* book = current->borrowed_books;
            while (book) {
                cout << "  - Buku: " << book->title << ", Pengembalian: " << book->return_date << "\n";
                book = book->next;
            }
            current = current->next;
        }
    }

    ~LibraryManagement() {
        while (head) {
            MemberNode* member = head;
            head = head->next;
            while (member->borrowed_books) {
                BookNode* book = member->borrowed_books;
                member->borrowed_books = book->next;
                delete book;
            }
            delete member;
        }
    }
};

int main() {
    LibraryManagement library;

    library.addMember("Rani", "A001");
    library.addMember("Dito", "A002");
    library.addMember("Vina", "A003");

    library.addBook("A001", "Pemrograman C++", "01/12/2024");
    library.addBook("A002", "Algoritma Pemrograman", "15/12/2024");
    library.addBook("A001", "Struktur Data", "10/12/2024");

    library.removeMember("A002");

    cout << "Data Anggota dan Buku yang Dipinjam:\n";
    library.display();

    return 0;
}
