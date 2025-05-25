#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counsellingMain.h"
#define MAXAPPS 1000

// Error Codes
#define SUCCESS 0
#define APPL_FILE_ERROR 1


/*
 * Function to load application data from the file
 */
int loadApplication(struct CounsellingMain *cMainPtr, char *studApplFile) {
    if (cMainPtr == NULL || studApplFile == NULL) {
        fprintf(stderr, "Invalid input parameters\n");
        return APPL_FILE_ERROR;
    }

    FILE *file = fopen(studApplFile, "r");
    if (file == NULL) {
        perror("Error opening application file");
        return APPL_FILE_ERROR;
    }

    // Initialize count
    cMainPtr->appCount = 0;

    int id, rank;
    char inst1[50], prog1[50];
    char inst2[50], prog2[50];
    char inst3[50], prog3[50];

    // Read file line by line
    while (fscanf(file, "%d %d %s %s %s %s %s %s", 
                  &id, &rank, 
                  inst1, prog1, inst2, prog2, inst3, prog3) == 8) {
        if (cMainPtr->appCount >= MAXAPPS) {
            fprintf(stderr, "Warning: Maximum application limit reached.\n");
            break;
        }

        // Get reference to current application entry
        struct Application *app = &cMainPtr->appList[cMainPtr->appCount];
        app->appNo = id;
        app->rank = rank;
        app->prefCount = 3;
        strcpy(app->prefList[0].collegeCode, inst1);
        strcpy(app->prefList[0].programCode, prog1);
        strcpy(app->prefList[1].collegeCode, inst2);
        strcpy(app->prefList[1].programCode, prog2);
        strcpy(app->prefList[2].collegeCode, inst3);
        strcpy(app->prefList[2].programCode, prog3);
        
        cMainPtr->appCount++;
    }

    fclose(file);
    return SUCCESS;
}

/*
 * Function to print the loaded application data
 */
// void printApplications(struct CounsellingMain *cMainPtr) {
//     if (cMainPtr == NULL || cMainPtr->appCount == 0) {
//         printf("No applications found!\n");
//         return;
//     }

//     printf("Total Applications Loaded: %d\n\n", cMainPtr->appCount);
//     for (int i = 0; i < cMainPtr->appCount; i++) {
//         struct Application app = cMainPtr->appList[i];
//         printf("Application %d:\n", i + 1);
//         printf("  ID: %d, Score: %d\n", app.appNo, app.rank);
//         printf("  Preferences:\n");
//         for (int j = 0; j < 3; j++) {
//             printf("    %d. %s - %s\n", j + 1, app.prefList[j].collegeCode, app.prefList[j].programCode);
//         }
//         printf("\n");
//     }
// }

// /*
//  * Main function to run the program
//  */
// int main() {
//     struct CounsellingMain cMain;
//     const char *fileName = "/mnt/c/Users/kris_/OneDrive/Desktop/PES/Sem2/C/ExamCounselling/docs/Application.txt"; // Specify the file name

//     // Load applications
//     if (loadApplication(&cMain, fileName) == SUCCESS) {
//         printf("Application data loaded successfully!\n\n");
//         printApplications(&cMain); // Display the loaded data
//     } else {
//         printf("Failed to load application data.\n");
//     }

//     return 0;
// }