#pragma once
#include <Watchy.h>

class MyWatchFace : public Watchy {
public:
  MyWatchFace(const watchySettings& s) : Watchy(s) {}

  void drawWatchFace() {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    char buf[48];
    int h = currentTime.Hour;
    int m = currentTime.Minute;
    const char* days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    float v = getBatteryVoltage();
    int pct = constrain((int)((v - 3.5f) / 0.7f * 100), 0, 100);

    // double border
    display.drawRect(2, 2, 196, 196, GxEPD_BLACK);
    display.drawRect(4, 4, 192, 192, GxEPD_BLACK);

    display.setTextSize(1);
    display.setCursor(12, 12);
    display.print("{");

    display.setCursor(22, 24);
    display.print("\"time\":");

    // inverted block for time
    display.fillRect(10, 34, 180, 40, GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setTextSize(3);
    sprintf(buf, "%02d:%02d", h, m);
    display.setCursor(55, 42);
    display.print(buf);
    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(1);

    display.setCursor(22, 82);
    sprintf(buf, "\"day\":  \"%s\",", days[currentTime.Wday]);
    display.print(buf);

    display.setCursor(22, 94);
    sprintf(buf, "\"date\": \"%04d-%02d-%02d\",", currentTime.Year + 1970, currentTime.Month, currentTime.Day);
    display.print(buf);

    char bar[11];
    int filled = pct / 10;
    for (int i = 0; i < 10; i++) bar[i] = (i < filled) ? '#' : '.';
    bar[10] = '\0';
    display.setCursor(22, 106);
    sprintf(buf, "\"bat\":  %d%% [%s],", pct, bar);
    display.print(buf);

    uint32_t steps = sensor.getCounter();
    display.setCursor(22, 118);
    sprintf(buf, "\"steps\": %lu", (unsigned long)steps);
    display.print(buf);

    display.setCursor(12, 136);
    display.print("}");

    display.drawLine(12, 158, 188, 158, GxEPD_BLACK);

    display.setCursor(12, 166);
    display.print("// JsonWatch v2.0");
  }
};
