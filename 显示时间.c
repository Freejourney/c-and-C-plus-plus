#include <stdio.h>
#include <windows.h>
int main()
{
    int i;
    while(i<1000)
    {
        system("TIME /T");
        Sleep(6000);
        i++;
    }
return 0;
}
