#include <stdio.h>
#include <string.h>

union Data
{
    int x;
    double y;
    char z[32];
};

typedef struct
{
    int type;
    union
    {
        char x[1024];
        float y[1024];
        double z[1024];
    } buffer;
} Info;

int main()
{
    union Data myData;

    myData.x = 10;
    myData.y = 20.5;
    strcpy(myData.z, "test 123");

    printf("myData.x =%d\n", myData.x);
    printf("myData.y =%lf\n", myData.y);
    printf("myData.x =%s\n", myData.z);

    myData.x = 10;
    printf("myData.x =%d\n", myData.x);

    myData.y = 20.5;
    printf("myData.y =%lf\n", myData.y);

    strcpy(myData.z, "test 123");
    printf("myData.x =%s\n", myData.z);

    printf("myData size %d\n", sizeof(myData));

    union Data *ptr = &myData;

    printf("ptr->z = %s\n", ptr->z);

    Info info;
    info.type = 0;
    memset(info.buffer.x, 't', 1024);

    if (info.type == 1)
    {
        for (int i = 0; i < 1024; i++)
        {
            printf("info.buffer.x[%d] = %c\n", i, info.buffer.x[i]);
        }
    }

    return 0;
}