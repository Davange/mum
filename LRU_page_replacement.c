#include<stdio.h>
#include<stdlib.h>

/*exapmle  the page reference string 7 0 1 2 0 3 0 4 2 3 0 3 2 . Initially we have 4 page slots empty.

Total number of page faults: 6
 */
/*#include<stdio.h>
#include<stdlib.h>
These lines include the standard input/output and standard library header files.

int main() {
This line declares the main function of the program.

int frames, faults = 0, index = 0;
This line declares three integer variables: frames (number of frames in memory), faults (number of page faults), and index (the index of the LRU page).

printf("Enter the number of frames: ");
This line prints the message "Enter the number of frames: " to the console.

scanf("%d", &frames);
This line reads an integer value from the console and stores it in the variable frames.

int memory = (int) calloc(frames, sizeof(int));
This line dynamically allocates memory for an array called memory with a size equal to the number of frames. The calloc function initializes the memory with zeros.

int pages;
This line declares an integer variable called pages.

printf("Enter the page sequence (-1 to stop): ");
This line prints the message "Enter the page sequence (-1 to stop): " to the console.

scanf("%d", &pages);
This line reads an integer value from the console and stores it in the variable pages.

while(pages != -1) {
This line starts a while loop that runs as long as the value of pages is not equal to -1.

int found = 0;
This line declares an integer variable called found and initializes it to zero.

for(int i=0; i<frames; i++) {
This line starts a for loop that iterates over all the frames in memory.

if(memory[i] == pages) {
This line checks if the current frame in memory contains the page that is currently being accessed.

found = 1;
This line sets the value of found to 1 if the page is found in memory.

break;
This line breaks out of the loop if the page is found in memory.

}
This line ends the if statement.

if(!found) {
This line checks if the page is not found in memory (page fault).

faults++;
This line increments the value of faults by 1.

if(index == frames) {
This line checks if all the frames in memory are currently occupied.

index = 0;
This line sets the value of index to 0 if all the frames are occupied.

}
This line ends the if statement.

memory[index++] = pages;
This line replaces the least recently used page (the page at the current index) with the current page and increments the value of index.

printf("Memory: ");
This line prints the message "Memory: " to the console.

for(int i=0; i<frames; i++) {
This line starts a for loop that iterates over all the frames in memory.

if(memory[i] == -1) {
This line checks if the current frame is empty.

printf("- ");
This line prints a hyphen (-) to the console if the frame is empty.

}
This line ends the if statement.

else {
This line starts an else statement.

printf("%d ", memory[i]);
This line prints the value of the current frame to the console.

}
This line ends the else statement.
*/
int main() {
    int frames, faults = 0, index = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int *memory = (int*) calloc(frames, sizeof(int)); // allocate memory for frames
    
    int pages;
    printf("Enter the page sequence (-1 to stop): ");
    scanf("%d", &pages);
    
    while(pages != -1) {
        int found = 0;
        for(int i=0; i<frames; i++) {
            if(memory[i] == pages) {
                found = 1;
                break;
            }
        }
        if(!found) { // page fault
            faults++;
            if(index == frames) { // all frames are full
                index = 0;
            }
            memory[index++] = pages; // replace the LRU page
        }
        
        printf("Memory: ");
        for(int i=0; i<frames; i++) {
            if(memory[i] == -1) {
                printf("- ");
            }
            else {
                printf("%d ", memory[i]);
            }
        }
        printf("\n");
        
        printf("Enter the page sequence (-1 to stop): ");
        scanf("%d", &pages);
    }
    
    printf("Total number of page faults: %d\n", faults);
    free(memory); // free allocated memory
    return 0;
}
