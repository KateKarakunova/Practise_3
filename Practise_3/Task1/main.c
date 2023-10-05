#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (list == NULL) {
        printf("Error allocating memory for the list.\n");
        return NULL;
    }
    list->array = (int*)malloc(sizeof(int) * capacity);
    if (list->array == NULL) {
        printf("Error allocating memory for the array.\n");
        free(list);
        return NULL;
    }
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(ArrayList* list, int item) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity);
        if (list->array == NULL) {
            printf("Error allocating memory for the array.\n");
            return;
        }
    }
    list->array[list->size] = item;
    list->size++;
    printf("Added item: %d\n", item);
}

void insert(ArrayList* list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Invalid index for insertion.\n");
        return;
    }
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity);
        if (list->array == NULL) {
            printf("Error allocating memory for the array.\n");
            return;
        }
    }
    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = item;
    list->size++;
    printf("Inserted item: %d at index: %d\n", item, index);
}

int size(ArrayList* list) {
    return list->size;
}

void removeAtIndex(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for removal.\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    printf("Removed item at index: %d\n", index);
}

void set(ArrayList* list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for modification.\n");
        return;
    }
    list->array[index] = item;
    printf("Set item at index: %d to value: %d\n", index, item);
}

int get(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index for retrieval.\n");
        return -1;
    }
    return list->array[index];
}

void display(ArrayList* list) {
    printf("Elements of the list: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

void destroyArrayList(ArrayList* list) {
    free(list->array);
    free(list);
    printf("Destroyed the ArrayList.\n");
}

int main() {
    int capacity;
    printf("Enter the initial capacity of the list: ");
    scanf("%d", &capacity);

    ArrayList* list = createArrayList(capacity);
    if (list == NULL) {
        return 1;
    }

    // Testing and using various functions
    add(list, 42);
    display(list);
    insert(list, 1, 99);
    display(list);
    set(list, 0, 10);
    display(list);
    int element = get(list, 0);
    printf("Value of the first element: %d\n", element);
    display(list);
    removeAtIndex(list,0);
    display(list);
    printf("Size of list = %d\n",size(list));

    destroyArrayList(list);

    return 0;
}
