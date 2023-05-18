#include <stdio.h>
#include <stdlib.h>


/* example Consider page reference string 1, 3, 0, 3, 5, 6, 3 with 3 page frames.Find the number of page faults.
Page fault count: 6
Page hit count: 1
 */
// Define page table structure
struct page_table_entry {
    int page_number;
    int valid;
    int referenced;
};

int main() {
    // Get user input for number of frames and page references
    int num_frames, num_refs;
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);
    printf("Enter number of page references: ");
    scanf("%d", &num_refs);
    int* refs = (int*) malloc(sizeof(int) * num_refs);
    printf("Enter sequence of page references:\n");
    for (int i = 0; i < num_refs; i++) {
        scanf("%d", &refs[i]);
    }

    // Initialize page table
    struct page_table_entry page_table[num_frames];
    for (int i = 0; i < num_frames; i++) {
        page_table[i].page_number = -1;
        page_table[i].valid = 0;
        page_table[i].referenced = 0;
    }

    // Perform page replacement using FIFO algorithm
    int page_faults = 0;
    int page_hits = 0;
    int oldest_frame = 0;
    for (int i = 0; i < num_refs; i++) {
        int page_number = refs[i];

        // Check if page is already in a frame
        int page_found = 0;
        for (int j = 0; j < num_frames; j++) {
            if (page_table[j].valid && page_table[j].page_number == page_number) {
                page_found = 1;
                page_table[j].referenced = 1;
                page_hits++;
                break;
            }
        }

        // If page is not in a frame, replace the oldest frame
        if (!page_found) {
            page_faults++;
            page_table[oldest_frame].page_number = page_number;
            page_table[oldest_frame].valid = 1;
            page_table[oldest_frame].referenced = 0;
            oldest_frame = (oldest_frame + 1) % num_frames;
        }
    }

    // Print page fault and hit counts
    printf("Page fault count: %d\n", page_faults);
    printf("Page hit count: %d\n", page_hits);

    // Free memory
    free(refs);

    return 0;
}
