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
