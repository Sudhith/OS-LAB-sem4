#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    char ch;
    fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    write(1, "Enter data: ", 12);
    while (read(0, &ch, 1) > 0)
    {
        write(fd, &ch, 1);
    }
    close(fd);
    return 0;
}
