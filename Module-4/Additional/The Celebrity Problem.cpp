#include <stdio.h>
#include <stdbool.h>

#define N 4  // Number of people

// Mock knows function (should be given or implemented based on input)
int MATRIX[N][N] = {
    {0, 1, 1, 1},
    {0, 0, 0, 1},
    {0, 1, 0, 1},
    {0, 0, 0, 0}  // Person 3 is the celebrity
};

// Function that returns whether A knows B
int knows(int a, int b) {
    return MATRIX[a][b];
}

// Function to find the celebrity
int findCelebrity(int n) {
    int candidate = 0;

    // Step 1: Find the potential celebrity
    for (int i = 1; i < n; i++) {
        if (knows(candidate, i)) {
            candidate = i;  // Candidate cannot be a celebrity
        }
    }

    // Step 2: Verify if the candidate is a real celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;  // No celebrity exists
            }
        }
    }

    return candidate;  // Found a celebrity
}

// Main function
int main() {
    int celebrity = findCelebrity(N);
    if (celebrity == -1)
        printf("No Celebrity found\n");
    else
        printf("Celebrity is Person %d\n", celebrity);
    
    return 0;
}
