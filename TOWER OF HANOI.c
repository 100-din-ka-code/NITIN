#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'B', 'C');
    return 0;
}
void towers(int num, char A,char B,char C)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from TOWER %c to TOWER %c", A, C);
        return ;
    }
    towers(num - 1, A, C, B);
    printf("\n Move disk %d from TOWER %c to TOWER %c", num, A, C);
    towers(num - 1, B, A, C);
}
