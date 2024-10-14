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

    // Metodi per ottenere il titolo e il testo
    std::string getTitle() const;
    std::string getContent() const;

    // Metodi per gestire i preferiti
    void addToFavorites();
    void removeFromFavorites();
    bool isFavorite() const;

    // Metodo per bloccare o sbloccare la nota
    void lock();
    void unlock();

    // Metodo per controllare se la nota è bloccata
    bool isLocked() const;

};

#endif // NOTE_H