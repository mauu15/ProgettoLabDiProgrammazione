#ifndef NOTE_H
#define NOTE_H

#include <string>

class Note {
private:
    std::string title;      // Titolo della nota
    std::string text;       // Testo della nota
    bool locked;            // Indica se la nota è bloccata
    bool favorite;          // Indica se la nota è un preferito

public:
    // Costruttore
    Note(std::string  title, std::string  text, bool isLocked = false);

    // Getters
    std::string getTitle() const; //Primo const: il valore ritornato è costante. Secondo const: non modifica lo
    // stato dell'oggetto su cui viene chiamata

    std::string getContent() const;

    // Setters
    void setTitle(const std::string &inTitle);
    void setContent(const std::string &inContent);

    // Metodi per gestire i preferiti
    void addToFavorites();
    void removeFromFavorites();
    bool isFavorite() const;

    // Metodo per bloccare o sbloccare la nota
    void lock();
    void unlock();

    // Metodo per controllare se la nota è bloccata
    bool isLocked() const;

    bool operator==(const Note& other) const; // Overloading dell'operatore di uguaglianza, per confrontare due note

};

#endif // NOTE_H