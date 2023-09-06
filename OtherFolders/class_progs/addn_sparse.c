// 31st Aug

#include <stdio.h>
void add(int m1[][3], int m2[][3], int m3[][3]);

int main()
{
    int m1[10][3], m2[10][3], m3[10][3];

    printf("INPUT 1: \n");

    printf("Enter the number of rows, cols and num of non-zero rows\n");
    scanf("%d%d%d", &m1[0][0], &m1[0][1], &m1[0][2]);

    int i, j;

    for (i = 1; i <= m1[0][2]; i++)
    {
        scanf("%d%d%d", &m1[i][0], &m1[i][1], &m1[i][2]);
    }

    for (i = 0; i <= m1[0][2]; i++)
    {
        for (j = 0; i < 3; j++)
        {
            printf("%4d", m1[i][j]);
        }
        printf("\n");
    }

    printf("INPUT 2: \n");

    printf("Enter the number of rows, cols and num of non-zero rows\n");
    scanf("%d%d%d", &m2[0][0], &m2[0][1], &m2[0][2]);

    for (i = 1; i <= m2[0][2]; i++)
    {
        scanf("%d%d%d", &m2[i][0], &m2[i][1], &m2[i][2]);
    }

    for (i = 0; i <= m2[0][2]; i++)
    {
        for (j = 0; i < 3; j++)
        {
            printf("%4d", m2[i][j]);
        }
        printf("\n");
    }

    add(m1, m2, m3);

    for (i = 0; i <= m3[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", m3[i][j]);
        }

        printf("\n");
    }

    return 0;
}

char rel(int a, int b)
{
    if (a < b)
        return '<';
    else if (a > b)
        return '>';
    else
        return '=';
}

void add(int m1[][3], int m2[][3], int m3[][3])
{
    if (m1[0][0] != m2[0][0] || m1[0][1] != m2[0][1])
    {
        printf("Invalid input");
        return;
    }

    m3[0][0] = m1[0][0];
    m3[0][1] = m1[0][1];

    int m = m1[0][2];
    int n = m2[0][2];

    int i = 1;
    int j = 1;
    int k = 0;

    while (i <= m && j <= n) // 4,4 will work. but 4,2 will not work. so we need 2 more loops
    {
        k++;

        switch (rel(m1[i][0], m2[j][0]))
        {
        case '=':
            switch (rel(m1[i][1], m2[j][1]))
            {
            case '=': // case where rowid and colid is same

                m3[k][0] = m1[i][0];
                m3[k][1] = m1[i][2];
                m3[k][2] = m1[i][2] + m2[j][2];
                i++;
                j++;
                break;

            case '<':
                m3[k][0] = m1[i][0];
                m3[k][1] = m1[i][1];
                m3[k][2] = m1[i][2];

                i++;

                break;

            case '>':
                m3[k][0] = m2[j][0];
                m3[k][1] = m2[j][1];
                m3[k][2] = m2[j][2];

                j++;

                break;

            default:
                printf("default\n");
                break;
            }
            break;
        case '<':
            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2];
            i++;

            break;
        case '>':
            m3[k][0] = m2[j][0];
            m3[k][1] = m2[j][1];
            m3[k][2] = m2[j][2];
            j++;
            break;

        default:
            printf("default\n");

            break;
        }

        while (i < m1[0][2])
        {

            m3[k][0] = m1[i][0];
            m3[k][1] = m1[i][1];
            m3[k][2] = m1[i][2];
            i++;
            k++;
        }

        while (j < m2[0][2])
        {

            m3[k][0] = m2[j][0];
            m3[k][1] = m2[j][1];
            m3[k][2] = m2[j][2];
            j++;
            k++;
        }

        m3[0][1] = k;
    }
}
