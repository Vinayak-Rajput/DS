#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// Function to find and replace pattern in the source string
int stringMatchAndReplace(char source[], char pattern[], char replacement[], char result[]);

int main()
{
    // Declare strings to hold source, pattern, replacement, and result
    char source[MAX] = {0}, pattern[MAX] = {0}, replacement[MAX] = {0}, result[MAX] = {0};
    int found;

    // Get input from the user
    printf("Enter Source String: ");
    fgets(source, MAX, stdin);  // Use fgets instead of gets to avoid overflow
    source[strcspn(source, "\n")] = '\0';  // Remove the newline character added by fgets

    printf("Enter Pattern String: ");
    fgets(pattern, MAX, stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    printf("Enter Replacement String: ");
    fgets(replacement, MAX, stdin);
    replacement[strcspn(replacement, "\n")] = '\0';

    // Call the string match and replace function
    found = stringMatchAndReplace(source, pattern, replacement, result);

    // Display the result
    if(found == 1)
    {
        printf("The final string is:\n");
        puts(result);  // Display the modified string
    }
    else 
    {
        printf("Search string not found.\n");
    }

    return 0;
}

// Function to match the pattern in the source string and replace it with the replacement string
int stringMatchAndReplace(char source[], char pattern[], char replacement[], char result[])
{
    int i = 0, j = 0, k = 0, m = 0, t = 0, found = 0;

    // Loop through each character in the source string
    while(source[i] != '\0')
    {
        // Check if the current substring matches the pattern
        if(source[i] == pattern[j])
        {
            // If all characters of the pattern are matched
            j++;
            if(pattern[j] == '\0')
            {
                // Replace the pattern with the replacement string
                for(k = 0; replacement[k] != '\0'; k++, t++)
                {
                    result[t] = replacement[k];  // Copy replacement string to result
                }

                // Reset pattern match
                j = 0;
                found = 1;
            }
        }
        else
        {
            // If no match, copy the current character from source to result
            result[t++] = source[i++];
            j = 0;  // Reset pattern match index
        }
        i++;
    }

    // Null-terminate the result string
    result[t] = '\0';

    return found;
}
