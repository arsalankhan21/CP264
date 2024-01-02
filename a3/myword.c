#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

void stopword_dictionary(char *filename, char *stopwords[]) // Function to create dictionary of stopwords from file
{ 
    FILE *fp = fopen(filename, "r"); // Open file for reading
    if (fp == NULL) { // Check if file exists
        printf("Error opening stopword file.\n"); // Print error message
        return; // Exit function
    }

    char line[1000]; // Create char array to store line set to 1000
    char delimiters[] = " .,\n\t\r"; // Create char array of delimiters to split line
    char *token; // Create char pointer to store token
    int i; // Create int to store index of stopwords array

    while (fgets(line, 1000, fp) != NULL) { // Read line from file and store in line array until EOF is reached (NULL)
        token = strtok(line, delimiters); // Split line into tokens using delimiters array and store in token
        while (token != NULL) { // Loop until token is NULL (no more tokens)
            i = (int)(*token - 'a'); // Convert first char of token to int and subtract 'a' to get index of stopwords array to store token
            strcat(stopwords[i], token); // Concatenate token to stopwords array at index i (first char of token)
            strcat(stopwords[i], ","); // Concatenate comma to stopwords array at index i (first char of token)
            token = strtok(NULL, delimiters); // Split line into tokens using delimiters array and store in token
        }
    }

    fclose(fp); // Close file
}

int is_stopword(char *stopwords[], char *word) { // Function to check if word is a stopword
    if (word == NULL || *word == '\0') return 0; // Check if word is NULL or empty string and return 0 if true  
    else { // Else
        char temp[20] = {0}; // Create char array to store word
        strcat(temp, ","); // Concatenate comma to temp array
        strcat(temp, word); // Concatenate word to temp array
        strcat(temp, ","); // Concatenate comma to temp array
        if (strstr(stopwords[*word - 'a'], temp) != NULL) // Check if temp array is a substring of stopwords array at index of first char of word
            return 1; // Return 1 if true
        else 
            return 0; // Return 0 if false
    }
}

int process_word(char *filename, WORDSUMMARY *words, char *stopwords[]) { // Function to process words from file
    FILE *fp = fopen(filename, "r"); // Open file for reading
    if (fp == NULL) { // Check if file exists
        printf("Error opening text file.\n"); // Print error message
        return -1; // Return -1
    }

    char line[MAX_LINE_LEN]; // Create char array to store line set to MAX_LINE_LEN
    char delimiters[] = " .,\n\t\r"; // Create char array of delimiters to split line
    char *word_token; // Create char pointer to store word token

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) { // Read line from file and store in line array until EOF is reached (NULL)
        words->line_count++; // Increment line count 
        str_lower(line); // Convert line to lowercase
        str_trim(line); // Trim line
        word_token = strtok(line, delimiters); // Split line into word tokens using delimiters array and store in word_token
        
        while (word_token != NULL) { // Loop until word_token is NULL (no more word tokens)
            int found = is_stopword(stopwords, word_token); // Check if word_token is a stopword
            if (!found) { // If word_token is not a stopword 
                int word_found = 0; // Create int to store whether word_token is found in words array 
                for (int i = 0; i < words->non_common_word_count; i++) { // Loop through words array to check if word_token is found in words array 
                    if (strcmp(words->word_array[i].word, word_token) == 0) { // Check if word_token is found in words array 
                        words->word_array[i].frequency++; // Increment frequency of word_token in words array
                        word_found = 1; // Set word_found to 1
                        break;
                    }
                }
                if (!word_found) { // If word_token is not found in words array
                    strcpy(words->word_array[words->non_common_word_count].word, word_token); // Copy word_token to words array at index of non_common_word_count 
                    words->word_array[words->non_common_word_count].frequency = 1; // Set frequency of word_token in words array to 1
                    words->non_common_word_count++; // Increment non_common_word_count
                }
            }
            words->word_count++;  // Increment word count
            word_token = strtok(NULL, delimiters); // Split line into word tokens using delimiters array and store in word_token
        }
    }

    fclose(fp);
    return 0;
}
