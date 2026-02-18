#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    char buffer[100];
    int n, i;
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        write(1, "Error: File not found\n", 23);
        return 1;
    }
    n = read(fd, buffer, sizeof(buffer));
    for (i = 0; i < n; i++)
    {
        write(1, &buffer[i], 1);
    }

    close(fd);
    return 0;
}
