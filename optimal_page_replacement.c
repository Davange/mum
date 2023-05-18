#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PAGES 100

/*example  Number of frames, fn = 4 
        Reference String, pg[] = {7, 0, 1, 2, 
                  0, 3, 0, 4, 2, 3, 0, 3, 2}
                  Page Faults: 6
Page Hits: 7 ;*/

int main() {
    int pages[MAX_PAGES], frames, page_faults = 0, page_hits = 0;
    int frame_counter[MAX_PAGES];
    int i, j, k, n;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    if (frames > n) {
        frames = n;
    }

    printf("Enter the reference string: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < frames; ++i) {
        frame_counter[i] = INT_MAX;
    }

    for(i = 0; i < n; ++i) {
        int page = pages[i];

        bool found = false;
        for(j = 0; j < frames; ++j) {
            if(frame_counter[j] == page) {
                page_hits++;
                found = true;
                break;
            }
        }

        if(!found) {
            int frame_to_replace = 0;
            int min_future_use = INT_MAX;

            for(j = 0; j < frames; ++j) {
                int page_future_use = INT_MAX;

                for(k = i + 1; k < n; ++k) {
                    if(frame_counter[j] == pages[k]) {
                        page_future_use = k;
                        break;
                    }
                }

                if(page_future_use >= n) {
                    frame_to_replace = j;
                    break;
                }

                if(page_future_use < min_future_use) {
                    min_future_use = page_future_use;
                    frame_to_replace = j;
                }
            }

            frame_counter[frame_to_replace] = page;
            page_faults++;
        }
    }

    printf("Page Faults: %d\n", page_faults);
    printf("Page Hits: %d\n", page_hits);

    return 0;
}
