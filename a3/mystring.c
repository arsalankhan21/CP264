/*
--------------------------------------------------
Project: cp264oc-a3q1
File:    mystring.c
About:   string functions
Author:  Arsalan Khan
ID:      210862640
Version: 2023-06-02
--------------------------------------------------
*/

#include <stdio.h>
#include "mystring.h"
#include <stdbool.h>
#include <ctype.h>

int str_len(char *s) { //Function to find the length of a string
    int count = 0; //Setting a count variable to zero 
    for (; *s != '\0'; s++) { // Sets a for loop
        count++; //Increments the count variable
    }

    return count; //Returns the count variable
}

int str_wc(char *s) { //Function to find the number of words in a string
    int count = 0;  //Setting a count variable to zero
    bool word_check = false;   //Setting a boolean variable to false

    for (; *s != '\0'; s++) { //Sets a for loop to loop through the string

        if (*s == ' '|| *s == '\t' || *s == '\n') { //Checks if the character is a space, tab or new line
        word_check = false;  //Sets the boolean variable to false   
        }
        else if (!word_check) { //Checks if the boolean variable is false
            word_check = true;  //Sets the boolean variable to true
            count++;   //Increments the count variable
        }

    }

    return count;

}

void str_lower(char *s) { //Function to convert a string to lowercase
    for (int i = 0; s[i] != '\0'; i++) { //Sets a for loop to loop through the string
        s[i] = tolower(s[i]); //Converts the character to lowercase
    }
}

void str_trim(char* s) { //Function to trim a string
    if (s == NULL) { //Checks if the string is NULL
        return; // Handle NULL input
    }
    
    char *p = s, *dp = s; //Sets two pointers to the string s
    
    // Skip leading whitespace characters
    while (*p && *p == ' ') { // While *p is not null and *p is whitespace
        p++; //keep moving
    }
    
    // Check if the string is empty or consists entirely of whitespace characters
    if (*p == '\0') { //If *p is null
        *s = '\0'; // Set the first character to null to create an empty string
        return;
    }
    
    // Copy non-leading whitespace characters and reduce consecutive whitespace to a single space
    while (*p) { //While *p is not null
        if (*p != ' ' || (p > s && *(p - 1) != ' ')) { //If *p is not whitespace or if *p is whitespace and the previous character is not whitespace
            *dp = *p; //Copy the character to the destination pointer
            dp++; //Increment the destination pointer
        }
        p++; //Increment the source pointer
    }

    if (*(dp - 1) == ' ') { //If the last character is whitespace
        dp--; //Decrement the destination pointer
    }
    
    *dp = '\0'; // Null-terminate the resulting trimmed string
}
