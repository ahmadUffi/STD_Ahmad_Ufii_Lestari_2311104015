#include <iostream>
#include <string>
using namespace std;

struct ProjectNode {
    string name;
    int duration;
    ProjectNode* next;

    ProjectNode(string name, int duration) : name(name), duration(duration), next(nullptr) {}
};

struct EmployeeNode {
    string name;
    string emp_id;
    ProjectNode* projects;
    EmployeeNode* next;

    EmployeeNode(string name, string emp_id) : name(name), emp_id(emp_id), projects(nullptr), next(nullptr) {}
};

class EmployeeProjectManagement {
private:
    EmployeeNode* head;

public:
    EmployeeProjectManagement() : head(nullptr) {}

    void addEmployee(const string& name, const string& emp_id) {
        EmployeeNode* newEmployee = new EmployeeNode(name, emp_id);
        if (!head) {
            head = newEmployee;
        } else {
            EmployeeNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newEmployee;
        }
    }

    void addProject(const string& emp_id, const string& project_name, int duration) {
        EmployeeNode* current = head;
        while (current) {
            if (current->emp_id == emp_id) {
                ProjectNode* newProject = new ProjectNode(project_name, duration);
                if (!current->projects) {
                    current->projects = newProject;
                } else {
                    ProjectNode* p = current->projects;
                    while (p->next) {
                        p = p->next;
                    }
                    p->next = newProject;
                }
                return;
            }
            current = current->next;
        }
    }

    void removeProject(const string& emp_id, const string& project_name) {
        EmployeeNode* current = head;
        while (current) {
            if (current->emp_id == emp_id) {
                ProjectNode* p = current->projects;
                ProjectNode* prev = nullptr;
                while (p) {
                    if (p->name == project_name) {
                        if (prev) {
                            prev->next = p->next;
                        } else {
                            current->projects = p->next;
                        }
                        delete p;
                        return;
                    }
                    prev = p;
                    p = p->next;
                }
            }
            current = current->next;
        }
    }

    void display() {
        EmployeeNode* current = head;
        while (current) {
            cout << "Pegawai: " << current->name << " (ID: " << current->emp_id << ")\n";
            ProjectNode* project = current->projects;
            while (project) {
                cout << "  - Proyek: " << project->name << ", Durasi: " << project->duration << " bulan\n";
                project = project->next;
            }
            current = current->next;
        }
    }

    EmployeeProjectManagement() {
        while (head) {
            EmployeeNode* emp = head;
            head = head->next;
            while (emp->projects) {
                ProjectNode* proj = emp->projects;
                emp->projects = proj->next;
                delete proj;
            }
            delete emp;
        }
    }
};

int main() {
    EmployeeProjectManagement manager;

    manager.addEmployee("Andi", "P001");
    manager.addEmployee("Budi", "P002");
    manager.addEmployee("Citra", "P003");

    manager.addProject("P001", "Aplikasi Mobile", 12);
    manager.addProject("P002", "Sistem Akuntansi", 8);
    manager.addProject("P003", "E-commerce", 10);
    manager.addProject("P001", "Analisis Data", 6);

    manager.removeProject("P001", "Aplikasi Mobile");

    cout << "Data Pegawai dan Proyek:\n";
    manager.display();

    return 0;
}