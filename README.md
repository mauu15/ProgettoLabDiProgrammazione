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
   - [x] metodo per bloccare una nota (blockNote)
   - [x] metodo per sbloccare una nota (unblockNote)


   - [x] metodo per gestire le note preferite
     - [x] metodo per aggiungere una nota ai preferiti (makeFavourite)
     - [x] metodo per rimuovere una nota dai preferiti (removeFavourite)
     - [x] metodo per ottenere una lista di note preferite (listFavorites)
     - [x] metodo per ottenere una lista di note bloccate (listBlocked) 


   - [x] metodo per modificare il contenuto di una nota, se non è bloccata (editNoteText)
   - [x] metodo per modificare il titolo di una nota, se non è bloccata (editNoteTitle)


   - [x] metodo per ottenere una lista di note che contengono una parola data (cerca tra titoli e contenuto) (findNotes)


3. **Observer**
   - [x] Implementare un observer per indicare quante note stanno in una collezione. 


4. **Subject**
   - [x] Implementare un subject per notificare l'observer.