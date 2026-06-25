Download Links:
https://github.com/paulchen67/AMS_Spool_Display/releases/download/V1.3Dial/AMS_Display_Dial_V1.3.ino.bin

https://github.com/paulchen67/AMS_Spool_Display/releases/download/V1.3Dial/AMS_Display_Dial_V1.3.ino.bootloader.bin

https://github.com/paulchen67/AMS_Spool_Display/releases/download/V1.3Dial/AMS_Display_Dial_V1.3.ino.partitions.bin

 

Firmware Download:

AMS_Display_Dial_V1.3.ino.bin

AMS_Display_Dial_V1.3.ino.bootloader.bin

AMS_Display_Dial_V1.3.ino.partitions.bin



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

| Flash-Adresse | Datei                           		|
| ------------- | --------------------------------------------- |
| `0x0`         | `AMS_Display_Dial_V1.3.ino.bootloader.bin`	|
| `0x8000`      | `AMS_Display_Dial_V1.3.ino.partitions.bin`	|
| `0x10000`     | `AMS_Display_Dial_V1.3.ino.bin`      		|

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

| Einstellung | Wert		   |
| ----------- | ------------------ |
| IP-Adresse  | `192.168.4.1`      |
| SSID        | `AMS_Dial-Setup`   |
| Passwort    | `12345678`         |

---

# ✅ Hinweis

Beim ersten Start kann der Verbindungsaufbau einige Sekunden dauern.
Nach Eingabe deiner W-LAN Daten und speichern dieser, kann es 1-2 Minuten dauern
bis die Bestätigung kommt, dass die Daten übernommen wurden.
