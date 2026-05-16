# AMS Dial

Zusätzlicher Drehcontroller für das AMS Spool Display.

## Features

* Gewicht direkt per Encoder abziehen
* Spulen tauschen
* MQTT Unterstützung
* HTTP Fallback
* AP Setup Modus
* Webbasierte Konfiguration
* Deutsch / Englisch
* Persistente Einstellungen
* Factory Reset

---

# Hardware

* M5Stack Dial
* ESP32-S3

---

# Einrichtung

Beim ersten Start öffnet der Dial automatisch einen AP Modus:

```text
SSID: AMS-Dial-Setup
PASS: 12345678
```

Danach im Browser öffnen:

```text
192.168.4.1
```

Dort können eingestellt werden:

* WLAN
* Display IP
* MQTT Server (optional)

---

# MQTT

MQTT ist optional.

Wenn kein MQTT Server genutzt wird:

* Feld leer lassen
* der Dial arbeitet automatisch per HTTP

---

# Funktionen

## Gewicht abziehen

* Modus wählen
* Spule wählen
* Gewicht einstellen
* bestätigen

## Spulen tauschen

* SWAP Modus wählen
* Quellspule wählen
* Zielspule wählen
* bestätigen

---

# Webinterface

Über das Webinterface können:

* WLAN geändert werden
* MQTT aktiviert/deaktiviert werden
* Display IP geändert werden
* Einstellungen gelöscht werden

---

# Factory Reset

Der Button:

```text
DELETE SETTINGS
```

löscht alle gespeicherten Einstellungen.

Danach startet der Dial automatisch wieder im AP Setup Modus.

---

# Lizenz

Private / Open Source Nutzung nach Wunsch anpassen.

