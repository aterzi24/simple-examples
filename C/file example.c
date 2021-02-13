#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct ext2_dir_entry {
  unsigned int inode;     /* Inode number */
  unsigned short rec_len; /* Directory entry length */
  unsigned char name_len; /* Name length */
  unsigned char file_type;
  char name[]; /* File name, up to EXT2_NAME_LEN */
};

int main()
{
    /*int fd;
    char buff[256];

    fd = open("Text File.txt", O_RDONLY);
    lseek(fd, 10, SEEK_SET);
    read(fd, (void *)buff, 10);
    printf("%d\n", buff == NULL);*/

    struct ext2_dir_entry *asd;

    printf("%ld\n", sizeof(ext2_dir_entry));
}
