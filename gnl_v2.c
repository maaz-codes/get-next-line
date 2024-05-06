#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5

int find_next_line(char *buff, int count) {
    for (int i = 0; i < count; i++) {
        if (buff[i] == '\n') return 1;
    }
    return 0;
}

char *get_next_line(int fd) {
    static char *buff = NULL;
    static int count = 0;
    int chars_read;
    char **temp;

    if (!buff) {
        buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buff) return NULL;
    }

    while ((chars_read = read(fd, buff + count, BUFFER_SIZE - count))) {
        if (chars_read == -1) {
            free(buff);
            return NULL;
        }
        count += chars_read;
        if (find_next_line(buff, count)) {
            temp = (char **)malloc(sizeof(char *) * 2);
            if (!temp) {
                free(buff);
                return NULL;
            }
            temp[0] = strndup(buff, count);  // Extract the line
            temp[1] = strdup(buff + count + 1);  // Move the remaining to a new buffer
            free(buff);  // Free the old buffer
            buff = temp[1];  // Update buff to point to the new buffer
            count = strlen(buff);  // Update count
            return temp[0];
        }
        if (count == BUFFER_SIZE) { // Buffer is full, resize
            temp = (char **)malloc(sizeof(char *) * 2);
            if (!temp) {
                free(buff);
                return NULL;
            }
            temp[0] = strndup(buff, count);  // Extract the line
            temp[1] = strdup("");  // Move the remaining to a new buffer
            free(buff);  // Free the old buffer
            buff = temp[1];  // Update buff to point to the new buffer
            count = 0;  // Reset count
            return temp[0];
        }
    }
    return NULL;
}

int main(void) {
    int fd;
    char *line;

    fd = open("read.txt", O_RDONLY);

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s\n", line);
        free(line); // Don't forget to free allocated memory
    }

    close(fd);
    return 0;
}
