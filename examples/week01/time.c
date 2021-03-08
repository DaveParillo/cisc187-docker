//
// A simple program that deomonstrates time and the C struct 'tm'
//
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv) 
{
  const static uint16_t bufsize = 128;
  time_t now = time(0);  // the current time

  printf("On this system, size of time_t is %lu bits.\n", sizeof(time_t) * 8);

  struct tm gmt = *gmtime(&now);        // structured time in GMT
  struct tm localt = *localtime(&now);  // structured time local

  printf("direct from struct tm:\n");
  printf("universal time is now %04d-%02d-%02d %02d:%02d:%02d\n",
          gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday, gmt.tm_hour, gmt.tm_min, gmt.tm_sec);
  printf("local time is now %04d-%02d-%02d %02d:%02d:%02d\n",
          localt.tm_year + 1900, localt.tm_mon + 1, localt.tm_mday, localt.tm_hour, localt.tm_min, localt.tm_sec);

  char buf[bufsize];  // buffer for strftime

  uint64_t len = strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S", &gmt );
  printf("from strftime (gmt):\n");
  printf("universal time is now %s (%lu characters)\n", buf, len);

  len = strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S %Z", &localt );
  printf("from strftime (localt):\n");
  printf("local time is now %s (%lu characters)\n", buf, len);

  return 0;
}

