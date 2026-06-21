<img width="600" height="656" alt="IMG_0232" src="https://github.com/user-attachments/assets/5e92b21a-2a14-4292-917c-f041d7cc5531" />
<img width="600" height="386" alt="IMG_0231" src="https://github.com/user-attachments/assets/0431dbc4-086a-4ccb-8658-0a9352793b8e" />

---

AMS Display – Smart Filament Management für Bambu AMS

Dieses Projekt ist ein eigenständiges Touch-Display für das Bambu AMS, mit dem sich Filament-Spulen komfortabel verwalten, tauschen und überwachen lassen – direkt am Gerät oder über eine Weboberfläche. Die Weiterentwicklung SpoolEdit vom AMS Display
ist hier zu finden.

https://github.com/paulchen67/AMS_SpoolEdit

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
Die Dateien für den 3D Drucker sind hier zu finden:
https://makerworld.com/de/models/2694167-ams-display-smart-filament-management-for-ams?from=search#profileId-2985665

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

# 🔧 Firmware Flash Anleitung

## ESP32-S3 flashen

### 1. ESP32-S3 per USB anschließen

Den ESP32-S3 über USB mit dem PC verbinden.

---

### 2. Web Flasher öffnen

Folgende Webseite im Browser öffnen:

https://espressif.github.io/esptool-js/

---

### 3. Verbinden

* Auf **Connect** klicken
* Den richtigen COM-Port auswählen
* Verbindung bestätigen

---

## 4. Dateien hinzufügen

Folgende Dateien mit den jeweiligen Flash-Adressen eintragen:

| Flash-Adresse | Datei                           |
| ------------- | ------------------------------- |
| `0x0`         | `bootloader.bin`                |
| `0x8000`      | `partitions.bin`                |
| `0x10000`     | `AMS_Display_V1.8.ino.bin`      |
| `0x670000`    | `AMS_Display_V1.8.littlefs.bin` |

---

## 5. Flash Einstellungen

Folgende Einstellungen verwenden:

| Einstellung     | Wert   |
| --------------- | ------ |
| Flash Mode      | `Keep` |
| Flash Frequency | `Keep` |
| Flash Size      | `Keep` |

---

## 6. Optional: Flash komplett löschen

Für eine saubere Neuinstallation empfohlen:

* Auf **Erase Flash** klicken
* Warten bis der Vorgang abgeschlossen ist

---

## 7. Firmware flashen

* Auf **Program** klicken
* Warten bis der Flash-Vorgang vollständig abgeschlossen ist

Der ESP32-S3 startet anschließend automatisch neu.

---

# 📶 Erster Start im AP-Modus (Access Point)

Wenn keine WLAN-Daten gespeichert sind oder kein bekanntes WLAN gefunden wird, startet das Gerät automatisch im AP-Modus.

## Zugangsdaten

| Einstellung | Wert          |
| ----------- | ------------- |
| IP-Adresse  | `192.168.4.1` |
| SSID        | `AMS-Setup`   |
| Passwort    | `12345678`    |

---

# ✅ Hinweis

Beim ersten Start kann der Verbindungsaufbau einige Sekunden dauern.

Nach Eingabe deiner W-LAN Daten und speichern dieser, kann es 1-2 Minuten dauern
bis die Bestätigung kommt, dass die Daten übernommen wurden.

---

## 📖 Bedienungsanleitung – AMS Display

Das AMS Display ermöglicht die komfortable Verwaltung von Filament-Spulen direkt am Gerät oder über die Weboberfläche.

---

# 🖥️ **Display Bedienung**

## 🔹 Übersicht

* Anzeige aller AMS Slots (4 oder 8)
* Jede Kachel entspricht einem Slot
* Farbe zeigt Material / Status
* Spulen Bitmap zeigt Material / Status

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

---

# 🖥️ **Bilder Display**

<img width="300" height="400" alt="IMG_0214" src="https://github.com/user-attachments/assets/827fb68c-b0d2-44ec-b340-589843fa0ae1" />
<img width="300" height="400" alt="IMG_0215" src="https://github.com/user-attachments/assets/bf28c7e8-9fa2-4b86-bcc9-f8a48aa8c7d7" />
<img width="300" height="400" alt="IMG_0216" src="https://github.com/user-attachments/assets/7fec3ab1-2f46-4027-a19d-cae8460f2010" />
<img width="300" height="400" alt="IMG_0217" src="https://github.com/user-attachments/assets/a7db81e3-33eb-4508-9450-433b4b589d21" />
<img width="300" height="400" alt="IMG_0218" src="https://github.com/user-attachments/assets/2b935017-79b0-409c-a128-a14e0513f424" />
<img width="300" height="400" alt="IMG_0219" src="https://github.com/user-attachments/assets/0ebcf01e-ea7c-4f1f-8977-8f63cee290a7" />
<img width="300" height="400" alt="IMG_0220" src="https://github.com/user-attachments/assets/865ab1b3-aa37-41e6-823c-415963aec272" />
<img width="300" height="400" alt="IMG_0221" src="https://github.com/user-attachments/assets/d973e254-1e74-4acf-8098-761eb7a66937" />

---

# 🌐 **Bilder WebUI**

<img width="158" height="300" alt="IMG_0222" src="https://github.com/user-attachments/assets/c7f13c26-0e5d-4336-9a79-92c93407faaf" />
<img width="157" height="300" alt="IMG_0223" src="https://github.com/user-attachments/assets/96a69dd9-47fd-45ba-ac35-3f10d3e16901" />
<img width="158" height="300" alt="IMG_0224" src="https://github.com/user-attachments/assets/3ff57049-9e67-4ea8-a618-9ffdcf4377c0" />
<img width="158" height="300" alt="IMG_0225" src="https://github.com/user-attachments/assets/0e19d011-661c-47a8-9e19-20e65724825d" />
<img width="158" height="300" alt="IMG_0226" src="https://github.com/user-attachments/assets/39f2aeda-91e8-4c6c-b0d8-7955595c39b5" />
<img width="158" height="300" alt="IMG_0227" src="https://github.com/user-attachments/assets/a03c7a44-6ea8-4737-b8fb-4806b6a944fe" />
<img width="159" height="300" alt="IMG_0229" src="https://github.com/user-attachments/assets/978ee7c5-7b08-4e90-af42-eb29a04d7eb6" />

---

# 🖥️ **Bilder M5 Stack Dial**

<img width="225" height="300" alt="IMG_0272" src="https://github.com/user-attachments/assets/0d000257-be4e-479c-ac66-5a992512dedf" />
<img width="225" height="300" alt="IMG_0273" src="https://github.com/user-attachments/assets/664902e6-d8f7-4eb6-9590-029ab3f002c7" />
<img width="225" height="300" alt="IMG_0274" src="https://github.com/user-attachments/assets/d94f7d16-835f-4418-ad3b-cf48614f36fe" />
<img width="225" height="300" alt="IMG_0275" src="https://github.com/user-attachments/assets/e6dc278a-7959-4c5b-b6a5-55d23032c2d0" />
<img width="225" height="300" alt="IMG_0276" src="https://github.com/user-attachments/assets/9c023f26-a465-4f91-b333-6772835461dc" />
<img width="225" height="300" alt="IMG_0277" src="https://github.com/user-attachments/assets/301cb6a2-987e-4cfb-b483-80b3c40d6651" />
