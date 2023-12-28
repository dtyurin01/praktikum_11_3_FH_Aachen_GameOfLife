# Spiel des Lebens (Conway's Game of Life)

Dies ist eine Implementierung des zellulären Automaten "Spiel des Lebens" von John Conway.

## Beschreibung

Das Spiel "Spiel des Lebens" ist ein zellulärer Automat, bei dem jeder Zelle auf dem Spielfeld zwei Zustände haben kann: lebendig oder tot. Das Spiel entwickelt sich auf einem diskreten Feld, auf dem jede Zelle mit ihren acht Nachbarzellen interagiert. Basierend auf einfachen Regeln ändern sich die Zellen von Generation zu Generation.

## Regeln

1. **Überleben:** Eine lebendige Zelle bleibt am Leben, wenn sie zwei oder drei lebendige Nachbarn hat.
2. **Tod durch Einsamkeit:** Eine lebendige Zelle stirbt, wenn sie weniger als zwei lebendige Nachbarn hat.
3. **Tod durch Überbevölkerung:** Eine lebendige Zelle stirbt, wenn sie mehr als drei lebendige Nachbarn hat.
4. **Geburt:** Eine tote Zelle wird lebendig, wenn sie genau drei lebendige Nachbarn hat.

## Verwendung

1. **Installation:**
    - Klonen Sie das Repository: `git clone https://github.com/your_username/GameOfLife.git`
    - Wechseln Sie in das Projektverzeichnis: `cd GameOfLife`

2. **Kompilieren und Ausführen:**
    - Kompilieren Sie das Programm: `g++ -o game_of_life game_of_life.cpp`
    - Starten Sie das Programm: `./game_of_life`

3. **Eingabe:**
    - Wählen Sie beim Starten des Programms eine Anfangskonfiguration für das Spielfeld: zufällig, statisch oder vorgegebene Muster.

4. **Spiel:**
    - Das Fenster zeigt den Zustand des Spielfelds in jeder Generation an.

## Ressourcen

- [Wikipedia - Spiel des Lebens](https://de.wikipedia.org/wiki/Conways_Spiel_des_Lebens)
  

## Beispiele für Muster

- **Statisch:**
      ![Block](https://github.com/dtyurin01/praktikum_11_3_FH_Aachen_GameOfLife/assets/30621310/de979426-d353-4286-ba5f-b865b30192d8)

- **Bewegend:**
    ![moving_pattern](https://github.com/dtyurin01/praktikum_11_3_FH_Aachen_GameOfLife/assets/30621310/75abab40-d1e1-40ac-af32-e6584911c426)
    ![Bewegendes Muster](moving_pattern.gif)
- **Glider:**
    ![Glider](https://github.com/dtyurin01/praktikum_11_3_FH_Aachen_GameOfLife/assets/30621310/6c33c183-2796-46b3-89e3-d32ec7a833c7)
---

Autor: [@dtyurin01](https://github.com/dtyurin01)
