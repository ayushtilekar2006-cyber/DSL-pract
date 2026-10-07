#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];
    int count; // Track number of stored elements

public:
    HashTable() : count(0) {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    // Hash function handling negative numbers
    int hashFunction(int key) {
        int idx = key % SIZE;
        return (idx < 0) ? (idx + SIZE) : idx;
    }

    // Insert a key with overflow and duplicate checks
    bool insert(int key) {
        if (count == SIZE) {
            cout << "Hash Table is full! Cannot insert " << key << endl;
            return false;
        }

        int index = hashFunction(key);

        // Linear probing
        while (table[index] != -1) {
            if (table[index] == key) {
                // Key already exists; no duplicate inserted
                return false; 
            }
            index = (index + 1) % SIZE;
        }

        table[index] = key;
        count++;
        return true;
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            index = (index + 1) % SIZE;

            if (index == start)
                break;
        }

        return false;
    }

    // Display hash table
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(25);
    ht.insert(35);
    ht.insert(15);
    ht.insert(42);
    ht.insert(22);

    ht.display();

    int key;
    cout << "\nEnter key to search: ";
    if (cin >> key) {
        if (ht.search(key))
            cout << "Key found!\n";
        else
            cout << "Key not found!\n";
    }

    return 0;
}