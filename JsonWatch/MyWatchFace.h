#pragma once
#include <Watchy.h>

class MyWatchFace : public Watchy {
public:
  MyWatchFace(const watchySettings& s) : Watchy(s) {}

  void drawWatchFace() {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    display.drawRect(3, 3, 194, 194, GxEPD_BLACK);
    display.drawRect(4, 4, 192, 192, GxEPD_BLACK);

    int h = currentTime.Hour;
    int m = currentTime.Minute;
    char buf[40];

    display.setTextSize(1);
    display.setCursor(12, 14);
    display.print("{");

    display.setCursor(20, 32);
    display.print("\"time\":");

    display.setTextSize(3);
    sprintf(buf, "%02d:%02d", h, m);
    display.setCursor(20, 46);
    display.print(buf);


    display.drawLine(12, 90, 188, 90, GxEPD_BLACK);

    display.setTextSize(1);

    const char* days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    display.setCursor(20, 100);
    sprintf(buf, "\"day\":  \"%s\",", days[currentTime.Wday]);
    display.print(buf);

    display.setCursor(20, 116);
    sprintf(buf, "\"date\": \"%02d.%02d.%d\",", currentTime.Day, currentTime.Month, currentTime.Year + 1970);
    display.print(buf);

    display.setCursor(20, 132);
    float v = getBatteryVoltage();
    int pct = (int)((v - 3.5) / (4.2 - 3.5) * 100);
    if (pct > 100) pct = 100;
    if (pct < 0) pct = 0;
    sprintf(buf, "\"bat\":  \"%d%% (%.2fv)\"", pct, v);
    display.print(buf);

    display.setCursor(12, 155);
    display.print("}");

    display.setCursor(12, 178);
    display.print("// watchy v2.0");
  }
};