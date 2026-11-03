#include <stdio.h>
 #define SIZE 10
 int hashTable[SIZE];
 int isOccupied[SIZE] = {0};
 int hashFunction(int key) {
     return key % SIZE;
 }
 void insert(int key) {
     int index = hashFunction(key);
     int start = index;
     int count = 0;
         while (isOccupied[index] == 1) {
             if (hashTable[index] == key) {
                 printf("Key %d already exists.\n", key);
                 return;
             }
             index = (index + 1) % SIZE;
             count++;
             if (count == SIZE) {
                 printf("Hash Table is full. Cannot insert %d\n", key);
                 return;
             }
         }
         hashTable[index] = key;
         isOccupied[index] = 1;
         if (index != start)
             printf("Collision occurred for key %d. ", key);
         printf("Key %d inserted at index %d\n", key, index);
 }
 void search(int key) {
     int index = hashFunction(key);
     int start = index;
     int count = 0;
         while (isOccupied[index] == 1) {
             if (hashTable[index] == key) {
                 printf("Key %d found at index %d\n", key, index);
                 return;
             }
             index = (index + 1) % SIZE;
             count++;
             if (count == SIZE)
                 break;
         }
         printf("Key %d not found in hash table.\n", key);
 }
 void display() {
     int i;
     printf("\nHash Table:\n");
     for (i = 0; i < SIZE; i++) {
         if (isOccupied[i])
              printf("Index %d: %d\n", i, hashTable[i]);
         else
              printf("Index %d: --\n", i);
         }
 }
 int main() {
     int choice, key;
     do {
          printf("\n--- Hashing (Linear Probing) Menu ---\n");
          printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);
             switch (choice) {
                 case 1:
                     printf("Enter key to insert: ");
                     scanf("%d", &key);
                     insert(key);
                     break;
                 case 2:
                     printf("Enter key to search: ");
                     scanf("%d", &key);
                     search(key);
                     break;
                 case 3:
                     display();
                     break;
                 case 4:
                     printf("Exiting program.\n");
                     break;
                 default:
                     printf("Invalid choice.\n");
             }
         } while (choice != 4);
         return 0;
 }
```

### Sample Output

``` text
--- Hashing (Linear Probing) Menu ---
 1. Insert
 2. Search
 3. Display
 4. Exit
 Enter your choice: 1
 Enter key to insert: 25
 Key 25 inserted at index 5
 Enter your choice: 1
 Enter key to insert: 35
 Collision occurred for key 35. Key 35 inserted at index 6
 Enter your choice: 1
 Enter key to insert: 15
 Collision occurred for key 15. Key 15 inserted at index 7
 Enter your choice: 3
 Hash Table:
 Index 0: --
 Index 1: --
 Index 2: --
 Index 3: --
 Index 4: --
 Index 5: 25
 Index 6: 35
 Index 7: 15
 Index 8: --
 Index 9: --
 Enter your choice: 2
 Enter key to search: 35
 Key 35 found at index 6
 Enter your choice: 4
 Exiting program.
