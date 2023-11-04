#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct KeyValue {
    int key;
    int value;
};

struct KeyValue hashTable[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    
    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
    printf("Key-value pair (%d, %d) inserted at index %d.\n", key, value, index);
}

int search(int key) {
    int index = hash(key);
    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) 
            return hashTable[index].value;

        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

int main() {
    initializeHashTable();
    int numInputs, key, value;
    printf("Enter the number of key-value pairs to insert: ");
    scanf("%d", &numInputs);

    for (int i = 0; i < numInputs; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insert(key, value);
    }
    printf("Enter the number of keys to search for: ");
    scanf("%d", &numInputs);

    for (int i = 0; i < numInputs; i++) {
        printf("Enter key to search for %d: ", i + 1);
        scanf("%d", &key);
        int result = search(key);
        if (result != -1)
            printf("Value for key %d: %d\n", key, result);
        else
            printf("Key %d not found.\n", key);
    }
    return 0;
}
