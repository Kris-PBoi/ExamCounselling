#include<stdio.h>
#include<string.h>
#include "counsellingMain.h"
int main(int argc, char *argv[])
{
    struct CounsellingMain cMain;
    char allocationFile[20];
    
    cMain.appCount = 0;

    strcpy(allocationFile, "allocationFile");
    printf("Main function called with argc %d.\n", argc);
    for(int i = 0; i < argc; i++)
    {
        printf("argv %s.\n", argv[i]);
    }
    char *seatMatrixFile = argv[1];
    char *applicationFile = argv[2];
    loadApplication(&cMain, applicationFile);
    loadSeatMatrix(&cMain, seatMatrixFile);
    seatAllocation(&cMain);
    saveSeatAllocation(&cMain, allocationFile);
    loadTestData(&cMain);

    printf("Before sorting by rank: \n");
    applTestPrint(&cMain);
    sortAppl(&cMain);
    printf("After sorting by rank: \n");
    applTestPrint(&cMain);

    printf("Counselling done successfully\n");
}
int seatAllocation(struct CounsellingMain *cMainPtr)
{
    printf("Seat Allocation called\n");

}
int saveSeatAllocation(struct CounsellingMain *cMainPtr, char allocationFile[20])
{
    printf("Seat Allocation saved to %s\n", allocationFile);
}
int sortAppl(struct CounsellingMain *cMainPtr)
{
    int pos;
    struct Application temp;
    for(int i = 0; i < cMainPtr->appCount; i++)
    {
        pos = i;
        for(int j = i + 1; j < cMainPtr->appCount; j++)
        {
            if(cMainPtr->appList[i].rank > cMainPtr->appList[j].rank) pos = j;
        }
        if(pos != i)
        {
            temp = cMainPtr->appList[pos]; 
            cMainPtr->appList[pos] = cMainPtr->appList[i];
            cMainPtr->appList[i] = temp; 
        }
    }
    return SUCCESS;
}
void loadTestData(struct CounsellingMain *cMainPtr)
{
    printf("Loading test data: \n");
    cMainPtr->appCount = 3;
    cMainPtr->appList[0].appNo = 0;
    cMainPtr->appList[0].prefCount = 2;
    strcpy(cMainPtr->appList[0].prefList[0].institute, "IIITB");
    cMainPtr->appList[0].prefList[0].prefNo = 0;
    strcpy(cMainPtr->appList[0].prefList[0].program, "Btech-CS");

    strcpy(cMainPtr->appList[0].prefList[1].institute, "NIT");
    cMainPtr->appList[0].prefList[1].prefNo = 1;
    strcpy(cMainPtr->appList[0].prefList[1].program, "Btech-ECE");
    cMainPtr->appList[0].rank = 25;


    cMainPtr->appList[1].appNo = 1;
    cMainPtr->appList[1].prefCount = 3;
    strcpy(cMainPtr->appList[1].prefList[0].institute, "PES");
    cMainPtr->appList[1].prefList[0].prefNo = 0;
    strcpy(cMainPtr->appList[1].prefList[0].program, "Btech-ECE");

    strcpy(cMainPtr->appList[1].prefList[1].institute, "BITS");
    cMainPtr->appList[1].prefList[1].prefNo = 1;
    strcpy(cMainPtr->appList[1].prefList[1].program, "BSc-Maths");

    strcpy(cMainPtr->appList[1].prefList[2].institute, "VIT");
    cMainPtr->appList[1].prefList[2].prefNo = 2;
    strcpy(cMainPtr->appList[1].prefList[2].program, "Btech-AIML");
    cMainPtr->appList[1].rank = 74;


    cMainPtr->appList[2].appNo = 2;
    cMainPtr->appList[2].prefCount = 1;
    strcpy(cMainPtr->appList[2].prefList[0].institute, "IIT-Bombay");
    cMainPtr->appList[2].prefList[0].prefNo = 0;
    strcpy(cMainPtr->appList[2].prefList[0].program, "Btech-ECE");
    cMainPtr->appList[2].rank = 40;

}
void applTestPrint(struct CounsellingMain *cMainPtr)
{
    for(int i = 0; i < cMainPtr->appCount; i++)
    {
        printf("-----------------------------------------------------------------\n");
        printf("Showing details for applicant %d:\n", i);
        //printf("prefcount = %d:\n", cMainPtr->appList[i].prefCount);
        for(int j = 0; j < cMainPtr->appList[i].prefCount; j++)
        {
            printf("institute: %s\n", cMainPtr->appList[i].prefList[j].institute);
            printf("prefNo: %d\n", cMainPtr->appList[i].prefList[j].prefNo);
            printf("program: %s\n", cMainPtr->appList[i].prefList[j].program);
            printf("rank: %d\n", cMainPtr->appList[i].rank);
        }
        printf("-----------------------------------------------------------------\n");
    }
}