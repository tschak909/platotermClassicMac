#include <Serial.h>

typedef struct _configInfo {
  int baud;
} ConfigInfo;

void config_init(void);

void config_load(void);

void config_save(void);
