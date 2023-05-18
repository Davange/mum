#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define PAGE_TABLE_SIZE 1024

// Define page table structure
struct page_table_entry {
    int valid;
    int frame_number;
};

// Define page table
struct page_table_entry page_table[PAGE_TABLE_SIZE];

// Translate logical address to physical address
int translate_address(int logical_address) {
    int page_number = logical_address / PAGE_SIZE;
    int page_offset = logical_address % PAGE_SIZE;

    // Check if page is valid
    if (page_table[page_number].valid) {
        int frame_number = page_table[page_number].frame_number;
        int physical_address = (frame_number * PAGE_SIZE) + page_offset;
        return physical_address;
    } else {
        printf("Segmentation fault: Invalid memory access\n");
        exit(1);
    }
}

int main() {
    // Initialize page table
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        page_table[i].valid = 0;
        page_table[i].frame_number = -1;
    }

    // Allocate memory
    int* data = (int*) malloc(sizeof(int) * PAGE_SIZE);
    int* data2 = (int*) malloc(sizeof(int) * PAGE_SIZE);

    // Map pages to frames
    page_table[0].valid = 1;
    page_table[0].frame_number = 0;
    page_table[1].valid = 1;
    page_table[1].frame_number = 1;

    // Get logical address from user input
    int logical_address;
    printf("Enter logical address to translate: ");
    scanf("%d", &logical_address);

    // Access memory using logical address
    int physical_address = translate_address(logical_address);
    printf("Accessing logical address %d (page %d, offset %d) => physical address %d (frame %d, offset %d)\n", 
           logical_address, logical_address / PAGE_SIZE, logical_address % PAGE_SIZE,
           physical_address, physical_address / PAGE_SIZE, physical_address % PAGE_SIZE);

    // Free memory
    free(data);
    free(data2);

    return 0;
}
