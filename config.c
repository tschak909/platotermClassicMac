#include "config.h"

#define true 1
#define false 0

ConfigInfo config;

void config_set_defaults(void)
{
  config.baud=baud57600;
}

void config_init(void)
{
  config_load();
}

void config_load(void)
{
  config_set_defaults();
}

void config_save(void)
{

}
