#define MAXPREFS 5
struct Application
{
    int appNo;
    int rank;
    struct Preference
    {
        char collegeCode[30];
        char programCode[30];
        int prefNo;        
    } prefList[MAXPREFS];
    int allocations[MAXPREFS];
    int allocationCount;
    int prefCount;
};
void printAppl(struct Application *app);
