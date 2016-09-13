#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif /* HAVE_CONFIG_H */

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#include "strategy.h"

int get_bin_php_default_pattern_called = 0;

void get_bin_php_default_pattern(char* buffer, size_t size) {
   get_bin_php_default_pattern_called = 1;
   strncpy(buffer, "/my/alternate/%s/bin/php", size);
}

int main(int argc, char** argv) {
  struct cli_config* cli_config = 0;
  char php_version[8] = "";
  char php_bin[1024] = "junk";

  printf("testing strategy_get_php_bin on empty version\n");
  printf("  calling strategy_get_php_bin(\"%s\", %d, (cli_config*)0, %s)\n", php_bin, 1024, php_version);
  strategy_get_php_bin(php_bin, 1024, cli_config, php_version);

  if (get_bin_php_default_pattern_called) {
    printf("ERROR: get_bin_php_default_pattern was called\n");
    return 1;
  } else {
    printf("  get_bin_php_default_pattern not called\n");
  }
    
  if (strnlen(php_bin, 1024) != 0) {
    printf("ERROR: php_bin \"%s\" is not empty\n", php_bin);
    return 1;
  } else {
    printf("  php_bin \"%s\" is empty\n", php_bin);
  }

  printf("test complete\n");
  return 0;
}
