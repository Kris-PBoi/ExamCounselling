#define MAXPREFS 5
struct Application
{
    int appNo;
    int rank;
    struct Preference
    {
        char institute[30];
        char program[30];
        int prefNo;        
    } prefList[MAXPREFS];
    int allocations[MAXPREFS];
    int allocationCount;
    int prefCount;
};
void printAppl(int applID);
