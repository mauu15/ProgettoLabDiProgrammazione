# Progetto Note Manager


1. **Classe Note**

    - [x] Attributi: titolo, testo, stato di blocco, stato di preferito.
    - [x] Costruttore: titolo e testo.
    - [x] Metodi: blocca/sblocca, aggiungi/rimuovi dai preferiti, operatore di uguaglianza per confrontare note.
    - [x] Test


2. **Folder**:

   - [x] costruttore
   - [x] metodo per aggiungere/rimuovere note
   - [x] metodo per ottenere la lista di tutte le note (restituisce i titoli e la cartella a cui appartengono) (getAllNotesList)
   - [x] metodo per bloccare una nota
   - [ ] metodo per sbloccare una nota _TEST NON FUNZIONANTE_


   - [x] metodo per gestire le note preferite
     - [ ] metodo per ottenere una lista di note preferite (listFavorites) _TEST NON FUNZIONANTE_
     - [ ] metodo per ottenere una lista di note bloccate (listBlocked) _TEST NON FUNZIONANTE_


   - [x] metodo per modificare il contenuto di una nota, se non è bloccata (editNoteText)
   - [x] metodo per modificare il titolo di una nota, se non è bloccata (editNoteTitle)


   - [x] metodo per ottenere una lista di note che contengono una parola data (cerca tra titoli e contenuto) (findNotes)


3. **Observer**
   - [ ] Implementare un observer per indicare quante note stanno in una collezione. 


4. **Subject**
   - [ ] Implementare un subject per notificare l'observer.