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

---

Erstinstallation:
→ FULL.bin verwenden

Updates:
→ normale .bin (ohne FULL) möglich

---

## 📖 Bedienungsanleitung – AMS Display

Das AMS Display ermöglicht die komfortable Verwaltung von Filament-Spulen direkt am Gerät oder über die Weboberfläche.

---

# 🖥️ **Display Bedienung**

## 🔹 Übersicht

* Anzeige aller AMS Slots (4 oder 8)
* Jede Kachel entspricht einem Slot
* Farbe zeigt Material / Status

---

## 👆 **Touch Funktionen**

### 🔸 Kurzer Touch auf Slot

Öffnet das **NumPad zum Abziehen von Gewicht**

* gewünschte Gramm eingeben
* „OK“ bestätigt
* Gewicht wird von der Spule abgezogen

---

### 🔸 Langer Touch auf Slot

Öffnet die **Spulen-Detailansicht**

Anzeige von:

* Spulennummer
* Material / Typ
* Farbe
* Hersteller
* Gewicht

---

### 🔸 Im Spulen-Popup

* ❌ **X** → schließt das Fenster
* 🔁 **Tauschen** → öffnet Swap-NumPad

---

## 🔁 **Spulen tauschen (Swap)**

1. Spule auswählen (lange drücken)
2. „Tauschen“ drücken
3. Ziel-Spule eingeben (NumPad)
4. „OK“ bestätigen

👉 Die beiden Spulen werden getauscht

---

## 🔢 **NumPad Funktionen**

* Zahlen → Eingabe
* DEL → löscht letzte Zahl
* OK → bestätigt
* X → abbricht

---

# 🌐 **WebUI Bedienung**

Die Weboberfläche ist über die IP-Adresse des Geräts erreichbar.

---

## 🔹 Übersicht

* Anzeige aller Spulen
* Filter:

  * Alle
  * AMS (aktive Slots)
  * Lager

---

## 🔹 Bedienung der Kacheln

👉 Jede Kachel hat drei Hauptfunktionen:

* **Touch auf Kachel**
  → Öffnet das Eingabefeld zum **Abziehen von Gewicht**

* **Button „Tauschen“**
  → Startet den **Spulentausch (Swap)**

* **Button „Edit“**
  → Öffnet die Bearbeitung der **Spulendaten**

---

## 🔹 Spulen bearbeiten (Edit)

👉 Im Edit-Popup können folgende Daten angepasst werden:

* Material
* Typ
* Farbe
* Artikelnummer
* Hersteller

---

## 🔹 „Leer“ Funktion

* Checkbox „Leer“ aktivieren
* Spule wird als leer markiert

👉 Anzeige:

```text id="anm7f3"
Leer (Spule X)
```

---

## 🔹 Import / Export

* 📤 Export → Spulenliste als Datei speichern
* 📥 Import → Spulenliste laden

---

## 🔹 WLAN Setup

* SSID und Passwort eingeben
* Gerät startet neu
* verbindet sich automatisch

---

# 📡 **WLAN Verhalten**

* Beim ersten Start: Access Point (Setup-Modus)
* nach Einrichtung: Verbindung zum WLAN
* bei Fehler: Rückfall in AP-Modus

---

# 📶 **WLAN Status Anzeige**

* 🟢 Verbunden → WLAN + IP
* 🔴 AP Modus → Setup Netzwerk aktiv

---

# 🔗 **MQTT Funktionen (optional)**

Wenn MQTT aktiviert ist:

* Übertragung von:

  * Spulendaten
  * Gewichten
  * Status

* Integration möglich mit:

  * Home Assistant
  * Node-RED
  * eigene Systeme

---

## 🔹 Möglichkeiten

* Automatische Überwachung
* Logging von Filamentverbrauch
* Smart Home Integration

---

# 💡 **Hinweise**

* Slots sind unabhängig von Spulen
* Spulen können flexibel getauscht werden
* Daten werden dauerhaft gespeichert (LittleFS)

---

# ⚠️ **Tipps**

* Gewichtsänderungen immer mit OK bestätigen
* Beim Tauschen richtige Spulennummer eingeben
* WLAN Daten korrekt eingeben (Groß-/Kleinschreibung)

---

# ❤️ **Support**

Bei Fragen oder Problemen:

* GitHub Repository nutzen
* Feedback willkommen

