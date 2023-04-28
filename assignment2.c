#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main () {
    int first_option, second_option;
    printf("1. Select file to process\n2. Exit the program\nEnter a choice 1 or 2: ");
    scanf("%d", &first_option);
    while (first_option != 1 && first_option != 2) {
        printf("Invalid option! Please enter again.\n\n1. Select file to process\n2. Exit the program\nEnter a choice 1 or 2: ");
        scanf("%d", &first_option);
    }
    if (first_option == 2) {
        // Option 2, exit program.
        return 0;
    } else {
        // Option 1, goes to Selecting File.
        printf("\nWhich file you want to process?\nEnter 1 to pick the largest file\nEnter 2 to pick the smallest file\nEnter 3 to specify the name of a file\nEnter a choice from 1 to 3: ");
        scanf("%d", &second_option);
        while (second_option != 1 && second_option != 2 && second_option != 3) {
            printf("\nInvalid option! Please Enter again.\n\nWhich file you want to process?\nEnter 1 to pick the largest file\nEnter 2 to pick the smallest file\nEnter 3 to specify the name of a file\nEnter a choice from 1 to 3: ");
            scanf("%d", &second_option);
        }
        if (second_option == 1) {
            // User picks 1: Processing lagest file.

        } else if (second_option == 2) {
            // User picks 2: Processing smallest file.

        } else {
            // User picks 3: Processing given file.

        }
    }

}