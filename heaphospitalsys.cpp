#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
    Patient* hashNext;
};

// Global variables
Patient* head = NULL;
const int SIZE = 10;
Patient* hashTable[SIZE] = {NULL}; // Hash table array initialized to NULL

// Simple Hash Function
int hashFunction(int id)
{
    return id % SIZE;
}

// Function to register a patient
void registerPatient()
{
    Patient* p = new Patient;
    cout << "Enter Patient ID : ";
    cin >> p->id;
    
    int index = hashFunction(p->id);
    Patient* temp = hashTable[index];
    
    // Check for duplicate ID in hash table
    while (temp != NULL)
    {
        if (temp->id == p->id)
        {
            cout << "Patient ID already exists \n";
            delete p;
            return;
        }
        temp = temp->hashNext;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter Patient Name: ";
    getline(cin, p->name);
    
    cout << "Enter your Age : ";
    cin >> p->age;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter the Disease : ";
    getline(cin, p->disease);

    // Insert into Linked List (at head)
    p->next = head;
    head = p;

    // Insert into Hash Table (at index head)
    p->hashNext = hashTable[index];
    hashTable[index] = p;

    cout << "Patient Registered Successfully!\n";
}

// Function to search a patient
void searchPatient()
{
    int id;
    cout << "Enter Patient ID to search : ";
    cin >> id;
    int index = hashFunction(id);
    Patient* temp = hashTable[index];
    
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\n--- Patient Found ---" << endl;
            cout << "ID : " << temp->id << endl;
            cout << "NAME : " << temp->name << endl;
            cout << "AGE : " << temp->age << endl;
            cout << "DISEASE : " << temp->disease << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "PATIENT NOT FOUND!\n"; 
}

// Function to display all patients
void display_Patient()
{
    Patient* temp = head;

    if (temp == NULL)
    {
        cout << "NO Patient records Available \n";
        return;
    }
    
    cout << "\n ----------- PATIENTS RECORD ------------- \n";
    while (temp != NULL)
    {
        cout << "Patient ID : " << temp->id << endl;
        cout << "Patient NAME : " << temp->name << endl;
        cout << "Patient AGE : " << temp->age << endl;
        cout << "Patient DISEASE : " << temp->disease << endl;
        cout << "-----------------------------------------\n";
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n ------------ HOSPITAL MANAGEMENT SYSTEM -------------- \n";
        cout << "1. Register a Patient  \n";
        cout << "2. Search Patient  \n";
        cout << "3. Display ALL Patients  \n";
        cout << "4. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                registerPatient();
                break;
            case 2:
                searchPatient();
                break;
            case 3:
                display_Patient();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
