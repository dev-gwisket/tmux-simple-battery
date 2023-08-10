#include <stdio.h>
#include <string.h>

int main() {
  FILE *f;
  char charging_status[12];
  unsigned charge_full;
  unsigned charge_now;
  
  f = fopen("/sys/class/power_supply/BAT0/status", "r");
  fscanf(f, "%s", charging_status);
  printf("%s: ", strcmp(charging_status, "Charging") ? "BAT" : "CHR");
  fclose(f);

  f = fopen("/sys/class/power_supply/BAT0/charge_full", "r");
  fscanf(f, "%u", &charge_full);
  fclose(f);

  f = fopen("/sys/class/power_supply/BAT0/charge_now", "r");
  fscanf(f, "%u", &charge_now);
  fclose(f);

  printf("%3u%%\n", charge_now * 100 / charge_full);

  return 0;
}
