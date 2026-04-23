AMS Display – Smart Filament Management für Bambu AMS

Dieses Projekt ist ein eigenständiges Touch-Display für das Bambu AMS, mit dem sich Filament-Spulen komfortabel verwalten, tauschen und überwachen lassen – direkt am Gerät oder über eine Weboberfläche.

Einfaches Anklicken der gewünschten Spule, im NumPad Gewicht des aktuellen Drucks eingeben, Gewicht wird von der gewählten Spule abgezogen.

Das System basiert auf einem ESP32-S3 mit integriertem Display und bietet eine intuitive Benutzeroberfläche für den täglichen Einsatz beim 3D-Druck.

### 🔧 Funktionen

- Touch UI am Display
 - Anzeige aller Slots (4 oder 8)
 - Gewicht direkt anpassen (NumPad)
 - Langdruck für Spulen-Details
 - Schnelles Tauschen von Spulen (Swap-Funktion)

- WebUI (Smartphone / PC)
 - Übersicht aller Spulen
 - Bearbeiten von Material, Farbe, Hersteller etc.
 - Import / Export der Spulendaten
 - WLAN Konfiguration direkt im Browser

- Intelligente Spulenverwaltung
 - Trennung von Slot und Spule (flexibles Tauschen)
 - „Leer“-Status für Spulen
 - Unterstützung für große Spulenbibliotheken

- MQTT Integration

 - Verbindung zu externen Systemen (z. B. Home Assistant)

 - Übertragung von Spulen- und Spulendaten

 - Automatisierungen und Monitoring möglich

 - Erweiterbar für individuelle Workflows

- WLAN & Setup
 - Automatische Verbindung zum gespeicherten WLAN
 - Fallback Access Point (Setup-Modus)
 - Einfache Einrichtung ohne Code-Anpassung

- Weitere Features
 - Boot-Screen mit Logo
 - Live WLAN Status Anzeige
 - Persistente Speicherung (LittleFS)

---

### 🎯 Ziel des Projekts

Das AMS Display erweitert das Bambu AMS um eine eigenständige, komfortable Steuerung – unabhängig von der Bambu Studio Software.  
Ideal für alle, die ihre Filamente direkt am Drucker verwalten möchten.

---

### 🛠️ Hardware

- ESP32-S3 mit Touch Display
- Verbindung zum AMS / Drucker (je nach Setup)

---

### 💡 Hinweis

Das Projekt befindet sich in aktiver Weiterentwicklung und kann flexibel erweitert oder angepasst werden.

---

### 🛠️ Benötigte Teile

Folgende Komponenten werden benötigt:

 - ESP32S3 Display mit 2.8 Zoll, 240x320 Pixel, IPS Capacitive Touch, 512 kB SRAM, 16 MB Flash, 8 MB PSRAM

   Board Spezifikation muss beachtet werden damit das Programm problemlos läuft, ich habe diesen benutzt

   (https://www.amazon.de/FREENOVE-Capacitive-Supporting-XiaoZhiAI-Microcontroller/dp/B0FSQF6FKN?th=1)

   oder (https://de.aliexpress.com/item/1005009876628479.html)

   Wichtig !!! Das CYD funktioniert nicht

 

 - M3 x 6 Linsenkopfschraube (2 Stück)

   (https://www.amazon.de/OPIOL-QUALITY-Linsenkopfschrauben-Innensechsrund-Flachkopfschrauben/dp/B07FF2BJB2?th=1)

 

Folgende Komponenten werden nur benötigt wenn ihr das USB Kabel nicht direkt am ESP einstecken wollt:

 - 2-poliger magnetischer Pogo Pin

   (https://www.amazon.de/ACOLY-magnetische-Pogo-Pin-Anschl%C3%BCsse-L%C3%B6tanschluss-Stromanschluss/dp/B0FXL1C7N1)

 

 -  USB C Einbaubuchse (https://www.amazon.de/chenyang-Anschluss-L%C3%B6tadapter-Schraubloch-Schalttafelmontage/dp/B0D5B96FBR)

 - M2 x 6 Linsenkopfschraube und Mutter

---

### 🔧 Firmware Flash Anleitung

1. ESP32-S3 per USB anschließen

2. Webseite öffnen:
   https://espressif.github.io/esptool-js/

3. „Connect“ klicken und den richtigen COM-Port auswählen

4. Firmware Datei auswählen:
   **AMS_Display_V1.8_FULL.bin**

5. Flash-Adresse setzen:
   **0x0**

6. „Program“ klicken und warten bis der Vorgang abgeschlossen ist

---

Nach dem Flashen startet das Display automatisch.

