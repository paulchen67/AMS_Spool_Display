/*
 * M5 Stack Dial zum bedienen des AMS Display
 * Dateinamen: AMS_Display_Dial_V1.1
 * Erstellt am 03.05.2026
 * Geaendert am 07.05.2026
 * Umschaltung Deutsch/Englisch hinzugefügt
*/  
  
  #include "M5Dial.h"
  #include <WiFi.h>
  #include <PubSubClient.h>
  #include <HTTPClient.h>
  #include "logo.h"

  #define BACK_ITEM -1

// =====================
// WLAN
// =====================
  const char* ssid = "your_ssid";
  const char* password = "your_passwort";
  const char* display_ip = "your_display_ip";       // Your ip Adress of the AMS-Spool-Display

// =====================
// MQTT
// =====================
  const char* mqtt_server = "your_mqtt_server_ip";       // Your MQTT ip of the mqtt-server if you have mqtt
  WiFiClient espClient;
  PubSubClient client(espClient);

// =====================
// STATE
// =====================
  enum ScreenState {
    SCREEN_MODE,
    SCREEN_SPOOL,
    SCREEN_MAIN,
    SCREEN_MENU
  };

  ScreenState screen = SCREEN_MODE;
  ScreenState previousScreen = SCREEN_MODE;

// =====================
// LANGUAGE
// =====================
  enum Language {
    LANG_EN,
    LANG_DE
  };

  Language currentLanguage = LANG_EN;

  String tr(String key) {

    if (currentLanguage == LANG_DE) {

      if (key == "select") return "Modus";
      if (key == "mode") return "waehlen";

      if (key == "weight") return "GEWICHT";
      if (key == "swap") return "TAUSCH";
      if (key == "menu") return "MENUE";
      if (key == "back") return "BACK";
      if (key == "spool") return "SPULE";
      if (key == "to_spool") return "zu Spule =>";
    }

// ENGLISH
    if (key == "select") return "Select";
    if (key == "mode") return "Mode";

    if (key == "weight") return "WEIGHT";
    if (key == "swap") return "SWAP";
    if (key == "menu") return "MENU";
    if (key == "back") return "BACK";
    if (key == "spool") return "SPOOL";
    if (key == "to_spool") return "to Spool =>";

    return key;
  }

// =====================
  int encoderAcc = 0;

  int modeIndex = 0;      // 0 = Weight, 1 = Swap
  int spoolCursor = 0;
  int selectedSpool = 0;
  int menuIndex = 0;
  int value = 0;

  unsigned long lastMoveTime = 0;
  int lastSentValue = -1;
  const int sendDelay = 300;

  const int maxSpools = 8;
  int totalSpools = 32;   // 🔥 gleiche Anzahl wie im Display!

// =====================
// BOOT SCREEN
// =====================
  void drawBoot() {
    M5Dial.Display.fillScreen(TFT_BLACK);
    M5Dial.Display.setTextSize(1);
    M5Dial.Display.setTextColor(TFT_WHITE);
    M5Dial.Display.drawCentreString("Boot ....",120,25,4);    
// 🔹 Logo mittig zeichnen
    M5Dial.Display.pushImage(
      (240 - LOGO_W) / 2,
      (240 - LOGO_H) / 2,
      LOGO_W,
      LOGO_H,
      logo
    );    
    M5Dial.Display.setTextColor(TFT_WHITE);
    M5Dial.Display.drawCentreString("V1.1",120,195,4);
    delay(5000);
  }

// =====================
// MQTT CONNECT
// =====================
  void connectMQTT() {
    client.setServer(mqtt_server, 1883);
    client.connect("M5Dial");
  }

// =====================
// HTTP CONNECT
// =====================
  void sendHTTP(String payload) {
    HTTPClient http;    
    String url = "http://" + String(display_ip) +
             "/dial/set?data=" + payload;
    Serial.println(url);
    http.begin(url);
    http.GET();
    http.end();
  }

  void sendHTTPValue(String payload) {
    HTTPClient http;
    String url = "http://" + String(display_ip) +
               "/dial/value?data=" + payload;
    Serial.println("HTTP VALUE:");
    Serial.println(url);
    http.begin(url);
    http.GET();
    http.end();
  }

// =====================
// DRAW MODE
// =====================
  void drawMode() {
    M5Dial.Display.clear();
    M5Dial.Display.setTextSize(2);
    M5Dial.Display.setTextDatum(middle_center);

    M5Dial.Display.fillRect(0, 0, 240, 35, DARKGREY);
    M5Dial.Display.drawString(tr("select"), 120, 20);
    M5Dial.Display.fillRect(0, 205, 240, 35, DARKGREY);
    M5Dial.Display.drawString(tr("mode"), 120, 220);

    if (modeIndex == 0) {

  M5Dial.Display.fillRoundRect(70, 55, 100, 30, 10, YELLOW);

  M5Dial.Display.setTextColor(BLACK);
  M5Dial.Display.drawString(tr("weight"), 120, 70);

  M5Dial.Display.setTextColor(WHITE);
  M5Dial.Display.drawString(tr("swap"), 120, 120);
  M5Dial.Display.drawString(tr("menu"), 120, 170);

}
else if (modeIndex == 1) {

  M5Dial.Display.drawString(tr("weight"), 120, 70);

  M5Dial.Display.fillRoundRect(70, 105, 100, 30, 10, YELLOW);

  M5Dial.Display.setTextColor(BLACK);
  M5Dial.Display.drawString(tr("swap"), 120, 120);

  M5Dial.Display.setTextColor(WHITE);
  M5Dial.Display.drawString(tr("menu"), 120, 170);

}
else {

  M5Dial.Display.drawString(tr("weight"), 120, 70);
  M5Dial.Display.drawString(tr("swap"), 120, 120);

  M5Dial.Display.fillRoundRect(70, 155, 100, 30, 10, YELLOW);

  M5Dial.Display.setTextColor(BLACK);
  M5Dial.Display.drawString(tr("menu"), 120, 170);

  M5Dial.Display.setTextColor(WHITE);
}
  }

// =====================
// DRAW SPOOL
// =====================
  void drawSpool() {
    M5Dial.Display.clear();
    M5Dial.Display.setTextSize(2);
    M5Dial.Display.setTextDatum(middle_center);

    M5Dial.Display.fillRect(0, 0, 240, 35, DARKGREY);
    M5Dial.Display.drawString(tr("select"), 120, 20);
    M5Dial.Display.fillRect(0, 205, 240, 35, DARKGREY);
    M5Dial.Display.drawString(tr("spool"), 120, 220);

    for (int i = 0; i < maxSpools; i++) {

      float angle = i * 2 * PI / maxSpools;

      int x = 120 + cos(angle) * 70;
      int y = 120 + sin(angle) * 70;

      if (i == spoolCursor) {
// 🔥 Highlight Kreis
        M5Dial.Display.fillCircle(x, y, 15, YELLOW);
        M5Dial.Display.setTextColor(BLACK);
        M5Dial.Display.drawString(String(i + 1), x, y);
        M5Dial.Display.setTextColor(WHITE);
      } else {
        M5Dial.Display.drawString(String(i + 1), x, y);
      }
    }

// 🔥 BACK Button (zentral)
    if (spoolCursor == -1) {
      M5Dial.Display.fillCircle(120, 120, 30, RED);
      M5Dial.Display.setTextColor(WHITE);
      M5Dial.Display.drawString(tr("back"), 120, 120);
    } else {
      M5Dial.Display.drawCircle(120, 120, 30, DARKGREY);
      M5Dial.Display.drawString(tr("back"), 121, 120);
    }
  }

// =====================
// DRAW MAIN
// =====================
  void drawMain() {
    M5Dial.Display.clear();
    M5Dial.Display.setTextSize(2);
    M5Dial.Display.setTextDatum(middle_center);

// TOP: MQTT Status
    M5Dial.Display.fillRect(0, 0, 240, 35, DARKGREY);
    M5Dial.Display.drawString(client.connected() ? "MQTT" : "NO MQTT", 120, 20);

// Spool
    M5Dial.Display.drawString(tr("spool") + " " + String(selectedSpool + 1), 120, 90);

// VALUE + BACK + SWAP UI
    if (value == -1) {
      M5Dial.Display.fillRoundRect(75, 120, 90, 40, 10, RED);
      M5Dial.Display.setTextColor(WHITE);
      M5Dial.Display.drawString(tr("back"), 120, 140);
      M5Dial.Display.setTextColor(WHITE);
    }
    else if (modeIndex == 0) {
// Gewicht
      M5Dial.Display.setTextSize(2);
      M5Dial.Display.drawString(String(value) + " g", 120, 140);
    }
    else {
// 🔥 SWAP Anzeige verbessert
      M5Dial.Display.setTextSize(2);
      M5Dial.Display.drawString(tr("to_spool") + " " + String(value + 1), 120, 140);
    }

// MODE
    M5Dial.Display.fillRect(0, 205, 240, 35, DARKGREY);
    M5Dial.Display.drawString(modeIndex == 0 ? tr("weight") : tr("swap"), 120, 220);
    M5Dial.Display.setTextSize(2);
  }

// =====================
// DRAW MENU
// =====================
  void drawMenu() {
    M5Dial.Display.clear();
    M5Dial.Display.setTextSize(2);
    M5Dial.Display.setTextDatum(middle_center);

// TOP
    M5Dial.Display.fillRect(0, 0, 240, 35, DARKGREY);
    M5Dial.Display.drawString(tr("menu"), 120, 20);

// ENGLISH
    if (menuIndex == 0) {
      M5Dial.Display.fillRoundRect(50, 60, 140, 35, 10, YELLOW);
      M5Dial.Display.setTextColor(BLACK);
    }
    M5Dial.Display.drawString("ENGLISH", 120, 78);
    M5Dial.Display.setTextColor(WHITE);

// DEUTSCH
    if (menuIndex == 1) {
      M5Dial.Display.fillRoundRect(50, 115, 140, 35, 10, YELLOW);
      M5Dial.Display.setTextColor(BLACK);
    }
    M5Dial.Display.drawString("DEUTSCH", 120, 133);
    M5Dial.Display.setTextColor(WHITE);

// BACK
    if (menuIndex == 2) {
      M5Dial.Display.fillRoundRect(50, 170, 140, 35, 10, RED);
      M5Dial.Display.setTextColor(WHITE);
    }
    M5Dial.Display.drawString(tr("back"), 120, 188);
    M5Dial.Display.setTextColor(WHITE);
  }

// =====================
  void setup() {
    auto cfg = M5.config();
    M5Dial.begin(cfg, true, false);

    drawBoot();

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) delay(200);

    connectMQTT();

    M5Dial.Display.setTextSize(2);

    drawMode();
  }

// =====================
  void loop() {

    M5Dial.update();
    client.loop();

    if (!client.connected()) connectMQTT();

// =====================
// ENCODER
// =====================
    encoderAcc += M5Dial.Encoder.readAndReset();
    int step = 0;
    if (encoderAcc >= 4) {
      step = 1;
      encoderAcc = 0;
    }
    if (encoderAcc <= -4) {
      step = -1;
      encoderAcc = 0;
    }
    if (step != 0) {

  // =====================
  // MODE
  // =====================
  if (screen == SCREEN_MODE) {

    modeIndex += step;

    if (modeIndex < 0) modeIndex = 2;
    if (modeIndex > 2) modeIndex = 0;

    drawMode();
  }

  // =====================
  // SPOOL
  // =====================
  else if (screen == SCREEN_SPOOL) {

    spoolCursor += step;

    if (spoolCursor < -1) spoolCursor = maxSpools - 1;
    if (spoolCursor >= maxSpools) spoolCursor = -1;

    drawSpool();
  }

  // =====================
  // MAIN
  // =====================
  else if (screen == SCREEN_MAIN) {

    if (modeIndex == 0) {

      // GEWICHT
      value += step;

      if (value < -1) value = 5000;
      if (value > 5000) value = -1;

    } else {

      // SWAP
      value += step;

      if (value < -1) value = totalSpools - 1;
      if (value >= totalSpools) value = -1;
    }

    lastMoveTime = millis();

    drawMain();
  }

  // =====================
  // MENU
  // =====================
  else if (screen == SCREEN_MENU) {

    menuIndex += step;

    if (menuIndex < 0) menuIndex = 2;
    if (menuIndex > 2) menuIndex = 0;

    drawMenu();
  }
}

// =====================
// BUTTON
// =====================
    if (M5Dial.BtnA.wasPressed()) {
      M5Dial.Speaker.tone(8000, 20);

// =====================
// MODE
// =====================
      if (screen == SCREEN_MODE) {
        previousScreen = screen;
// MENU
        if (modeIndex == 2) {
          screen = SCREEN_MENU;
          drawMenu();
        } else {
          screen = SCREEN_SPOOL;
          drawSpool();
        }
      }

// =====================
// SPOOL
// =====================
      else if (screen == SCREEN_SPOOL) {
// BACK
        if (spoolCursor == -1) {
          screen = SCREEN_MODE;
          drawMode();
          return;
        }
        selectedSpool = spoolCursor;
        value = 0;
        lastSentValue = -1;
        previousScreen = screen;
        screen = SCREEN_MAIN;
        drawMain();
      }

// =====================
// MAIN
// =====================
      else if (screen == SCREEN_MAIN) {
// BACK
        if (value == -1) {
          screen = SCREEN_SPOOL;
          drawSpool();
          return;
        }
        String mode = (modeIndex == 0) ? "W" : "S";
        static int eventId = 0;
        eventId++;

        String payload = mode + ";" + String(selectedSpool) + ";" + String(value) + ";" + String(eventId);
        if (client.connected()) {
          client.publish("ams/dial/set", payload.c_str());
        } else {
          sendHTTP(payload);
        }
        previousScreen = screen;
        screen = SCREEN_MODE;
        drawMode();
      }

// =====================
// MENU
// =====================
      else if (screen == SCREEN_MENU) {
// ENGLISH
        if (menuIndex == 0) {
          currentLanguage = LANG_EN;
          drawMenu();
        }
// DEUTSCH
        else if (menuIndex == 1) {
          currentLanguage = LANG_DE;
          drawMenu();
        }
// BACK
        else {
          screen = SCREEN_MODE;
          drawMode();
        }
      }
    }

// =====================
// SEND BEI STOP
// =====================
    if (screen == SCREEN_MAIN &&  (millis() - lastMoveTime) > sendDelay &&  value != lastSentValue && modeIndex == 0) {
      static int liveEventId = 10000;
      liveEventId++;

      String payload = "W;" + String(selectedSpool) + ";" + String(value) + ";" + String(liveEventId);

      if (client.connected()) {
        client.publish("ams/dial/value", payload.c_str());
      } else {
        sendHTTPValue(payload);
      }
      lastSentValue = value;
    }
  }