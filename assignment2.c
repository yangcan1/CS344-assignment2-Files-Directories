#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<time.h>

#define PREFIX "movies_"

void largest_finding();
void create_dir();

void create_dir() {
    srand(time(NULL));
    int r = rand() % 100000;
    char* dir_name = malloc(sizeof(char) * 25);
    sprintf(dir_name, "./yangca.movie.%d", r);
    // mkdir(dir_name, 0750);
    printf("Created directory with name: yangca.movies.%d", r);
}

void largest_finding() {

    // This initialization is what I learned from Exploration: Directories in Module 3.
    DIR *currDir = opendir("./");
    struct dirent *aDir;
    struct stat *dirStat;
    int max_size = 0;
    char* max_name;

    while ((aDir = readdir(currDir)) != NULL) {
        // loop through all dir and find the max size dir.
        if (strncmp(PREFIX, aDir->d_name, strlen(PREFIX)) == 0 && strcmp(strstr(aDir->d_name, ".csv"), ".csv") == 0) {      
            stat(aDir->d_name, dirStat);
            if (dirStat->st_size > max_size) {
                max_size = dirStat->st_size;
                max_name = aDir->d_name;
            }
        }
    }
    printf("\nNow processing the chosen file named %s has the maximum size: %d \n", max_name, max_size);
    // Create a directory
    create_dir();
    closedir(currDir);
}

int main () {
    create_dir();
    int first_option, second_option;
    while (first_option != 2) {
        printf("\n1. Select file to process\n2. Exit the program\nEnter a choice 1 or 2: ");
        scanf("%d", &first_option);
        while (first_option != 1 && first_option != 2) {
                printf("\nInvalid option! Please enter again.\n\n1. Select file to process\n2. Exit the program\nEnter a choice 1 or 2: ");
                scanf("%d", &first_option);
            }
            if (first_option == 2) {
                // Option 2, exit program.
                exit(0);
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
                    largest_finding();
                } else if (second_option == 2) {
                    // User picks 2: Processing smallest file.

                } else {
                    // User picks 3: Processing given file.

                }
            }
    }


}