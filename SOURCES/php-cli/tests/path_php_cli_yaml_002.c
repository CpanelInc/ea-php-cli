#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif /* HAVE_CONFIG_H */

#include <linux/limits.h>
#include <stdio.h>
#include <string.h>

#include "path.h"

/* mock of char* readlink(char* buf, size_t size) */
char* __wrap_readlink(char* link, char* buf, size_t size) {
    char* return_value = 0;
    if (size > strlen("/usr/bin/php")) {
        return_value = strncpy(buf, "/usr/bin/php", size);
        if (return_value) {
            buf[size-1] = 0;
        }
    }
    return return_value;
}

int main(int argc, char** argv) {
  char path[100] = { 0 };
  char* return_value = 0;
  char* expected_path = "/usr/bin/php_cli.yaml";

  printf("testing path_php_cli_yaml with sufficent buffer\n");

  printf("  calling function path_php_cli_yaml()\n");
  return_value = path_php_cli_yaml(path, 100);

  if (return_value == 0) {
    printf("ERROR: return value %p is 0\n", return_value);
    return 1;
  }
  if (return_value != path) {
    printf("ERROR: return value %p is not %p\n", return_value, path);
    return 1;
  }
  if (strncmp(path, expected_path, 100) != 0) {
    printf("ERROR: path %s is not %s\n", path, expected_path);
    return 1;
  }

  printf("test complete\n");
  return 0;
}