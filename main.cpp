#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int page;
     while (scanf("%d", &page), page)
    {
        printf("Printing order for %d pages:\n", page);

        // Only one that does not have a back for each page
        if (page == 1)
        {
            printf("Sheet 1, front: Blank, 1\n");
        }
        else
        {
            int numberof_sheet=page/4;
            int total_page=numberof_sheet*4;
            if(total_page<page)
                ++numberof_sheet;
            int skip_page=page-total_page;
            for(int i=0; i<numberof_sheet; i++)
            {
                int frontfirstpage=page-2*i+skip_page;
                int frontsecondpage=i*2+1;
                if (frontfirstpage <= page)
                    printf("Sheet %d, front: %d, %d\nSheet %d, back : %d, %d\n", i + 1, frontfirstpage, frontsecondpage, i + 1, frontsecondpage + 1, frontfirstpage - 1);
                else if (frontfirstpage - 1 <= page)
                    printf("Sheet %d, front: Blank, %d\nSheet %d, back : %d, %d\n", i + 1, frontsecondpage, i + 1, frontsecondpage + 1, frontfirstpage - 1);
                else
                    printf("Sheet %d, front: Blank, %d\nSheet %d, back : %d, Blank\n", i + 1, frontsecondpage, i + 1, frontsecondpage + 1);
            }
        }
    }
    return 0;
}
