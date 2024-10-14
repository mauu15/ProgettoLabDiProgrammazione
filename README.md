# Progetto Note Manager

## Implementato

1. **Classe Note**
    - Attributi: titolo, testo, stato di blocco, stato di preferito.
    - Metodi: costruttore, getter e setter per titolo e testo, metodi per bloccare/sbloccare, aggiungere/rimuovere dai preferiti, operatore di uguaglianza per confrontare note.

## Da Implementare

1. **Classe Note**
   - se la nota viene segnata come preferita, viene messa anche in una cartella "favoriteList”


2. **Classe Folder**
    - Attributi: nome della collezione, vettore di puntatori a oggetti Note.
    - Metodi: costruttore, metodo per aggiungere/rimuovere note, metodo per ottenere la lista di note, metodo per contare le note, metodo per ottenere una lista di note preferite, metodo per ottenere una lista di note che contengono una parola data, metodo findNotesByContent per cercare note in base al contenuto, metodo findNoteByTitle per cercare una nota per titolo e specificare in quale collezione si trova.
    - Test


3. **Observer**
   - Implementare un observer per indicare quante note stanno in una collezione. 


4. **Subject**
   - Implementare un subject per notificare l'observer.