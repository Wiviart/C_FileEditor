#include <stdio.h>

void readFile(char pwd[100])
{
    FILE *fpr;           /* Tao bien pointer kieu file */
    char str[100];       /* Bien str de doc text tu file */
    fpr = fopen(pwd, "r"); /* Mo file o che do read */

    if (fpr == NULL)
    {
        puts("Issue in opening file!"); /* Neu khong mo duoc file thi bao loi */
    }

    while (1)
    { /* Tuong duong voi while (true), chi dung khi co lenh break */
        if (fgets(str, 10, fpr) == NULL)
        { /* Open file  luu tai pointer voi so luong ky tu toi thieu >2 (char + '\0'), o day chon la 10*/
            break;
        }
        else
        {
            printf("%s", str);
        }
    }

    fclose(fpr); /* Close file */
}

void writeFile(char pwd[100])
{
    FILE *fpw;
    char str[100];
    fpw = fopen(pwd, "w");

    if (fpw == NULL)
    {
        printf("Error");
    }

    printf("\nInput your string: ");
    fflush(stdin);
    gets(str);
    fputs(str, fpw);

    fclose(fpw);
}

int main()
{
    int x;
    char pwd[100];
    printf("Input path of file: ");
    gets(pwd);
    fflush(stdin);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Read File\n");
        printf("2. Write File\n");
        printf("3. Exit\n");
        printf("Choose your choice: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            readFile(pwd);
            break;
        case 2:
            writeFile(pwd);
            break;
        case 3:
            return 0;
        default:
            printf("Please reput your choice!\n");
            break;
        }
    }
}