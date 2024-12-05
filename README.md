# Progetto Note Manager

Questo progetto implementa un sistema di gestione note. Include funzionalità per organizzare, modificare e gestire note all'interno di collezioni, utilizzando il pattern Observer per notificare i cambiamenti.

## **1. Classe Note**
La classe `Note` rappresenta una singola nota con i seguenti attributi e funzionalità:

### **Attributi**
- **`std::string title`**: il titolo della nota.
- **`std::string text`**: il contenuto della nota.
- **`bool locked`**: indica se la nota è bloccata per evitare modifiche o eliminazioni.
- **`bool favorite`**: indica se la nota è contrassegnata come preferita.

### **Metodi**
- **Costruttore**: inizializza il titolo e il testo della nota.
- **`void lock()` / `void unlock()`**: blocca o sblocca la nota.
- **`void addToFavorites()` / `void removeFromFavorites()`**: aggiunge o rimuove la nota dai preferiti.
- **Operatore `==`**: confronta due note in base a titolo e testo.

### **Test**
La classe `Note` è stata completamente testata per garantire il corretto funzionamento dei suoi metodi e attributi.

---

## **2. Classe Folder**
La classe `Folder` gestisce un insieme di note e include i seguenti metodi:

### **Gestione delle Note**
- **`bool addNote(const Note &note)`**: aggiunge una nota alla collezione. Restituisce `true` se l'operazione ha successo.
- **`bool removeNote(const std::string &title)`**: rimuove una nota dalla collezione in base al titolo. Restituisce `true` se l'operazione ha successo.
- **`int getSize() const`**: restituisce il numero di note presenti nella collezione.
- **`bool getNoteFromTitle(const std::string &title, Note &nota) const`**: trova una nota in base al titolo e la memorizza nella variabile passata per riferimento. Restituisce `true` se la nota è stata trovata.
- **`std::list<std::pair<std::string, std::string>> getAllNotesList() const`**: restituisce una lista di coppie (titolo, testo) di tutte le note presenti nella collezione.

### **Modifica delle Note**
- **`bool changeTitle(Note &note, const std::string &newTitle)`**: modifica il titolo di una nota. Restituisce `true` se l'operazione ha successo.
- **`bool changeText(Note &note, const std::string &newText)`**: modifica il contenuto di una nota. Restituisce `true` se l'operazione ha successo.
- **`bool editNoteText(Note& note, const std::string& newText)`**: modifica il testo di una nota (se non è bloccata).
- **`bool editNoteTitle(Note& note, const std::string& newTitle)`**: modifica il titolo di una nota (se non è bloccata).

### **Ricerca delle Note**
- **`std::list<Note> findNotes(const std::string& keyword) const`**: restituisce una lista di note il cui titolo o contenuto contengono una parola chiave.

### **Gestione delle Note Preferite**
- **`bool makeFavourite(Note &note)`**: contrassegna una nota come preferita. Restituisce `true` se l'operazione ha successo.
- **`bool removeFavorite(const std::string &title)`**: rimuove una nota dai preferiti in base al titolo. Restituisce `true` se l'operazione ha successo.
- **`std::list<Note> listFavorites() const`**: restituisce una lista di tutte le note preferite.

### **Gestione delle Note Bloccate**
- **`void blockNote(Note &note)`**: blocca una nota.
- **`void unlockNote(Note &note)`**: sblocca una nota.
- **`std::list<Note> listBlocked() const`**: restituisce una lista di tutte le note bloccate.

---

## **3. Pattern Observer**
Il pattern Observer è utilizzato per tenere traccia delle modifiche nelle collezioni di note.

### **Classe Subject**
- **`void addObserver(Observer *observer)`**: aggiunge un osservatore alla lista.
- **`void removeObserver(Observer *observer)`**: rimuove un osservatore dalla lista.
- **`void notifyObservers()`**: notifica tutti gli osservatori delle modifiche.
- La classe `Subject` è un'interfaccia astratta. La sua implementazione concreta è gestita da `Folder`.

### **Classe Observer**
- Definisce un'interfaccia per gli osservatori.
- **`void update(const Subject& subject)`**: metodo chiamato quando il `Subject` notifica un cambiamento.

### **Classe ConcreteObserver**
- Tiene traccia del numero di note in un folder.
- **`void update(const Subject& subject)`**: utilizza un `dynamic_cast` per accedere al numero di note nel folder.
- Include metodi per:
    - **Iscriversi** a un folder: `void subscribe(Folder *folder)`.
    - **Disiscriversi** da un folder: `void unsubscribe(Folder *folder)`.

---

### **Esempio di Utilizzo**
1. Creare una nota con titolo e contenuto.
2. Aggiungere la nota a un folder.
3. Bloccare o aggiungere ai preferiti la nota.
4. Utilizzare un `ConcreteObserver` per monitorare il numero di note nel folder.