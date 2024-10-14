#include "Note.h"

#include <utility>

// Costruttore della classe Note
Note::Note(std::string  title, std::string  text, bool isLocked)
        : title(std::move(title)), text(std::move(text)), locked(isLocked), favorite(false) {}

// Restituisce il titolo della nota
std::string Note::getTitle() const {
    return title;
}

// Restituisce il testo della nota
std::string Note::getContent() const {
    return text;
}

void Note::setTitle(const std::string &newTitle) {
    if (!isLocked()) {
        title = newTitle;
    }
}

void Note::setContent(const std::string &newText) {
    if (!isLocked()) {
        text = newText;
    }
}

// Restituisce true se la nota è bloccata
bool Note::isLocked() const {
    return locked;
}

// Aggiunge la nota ai preferiti
void Note::addToFavorites() {
    if (!locked) { // Solo se non è bloccata
        favorite = true;
    }
}

// Rimuove la nota dai preferiti
void Note::removeFromFavorites() {
    if (!locked) { // Solo se non è bloccata
        favorite = false;
    }
}

// Restituisce true se la nota è un preferito
bool Note::isFavorite() const {
    return favorite;
}

// Blocca la nota
void Note::lock() {
    locked = true;
}

// Sblocca la nota
void Note::unlock() {
    locked = false;
}

bool Note::operator==(const Note& other) const {
    return title == other.title && text == other.text &&
           isLocked() == other.isLocked() && isFavorite() == other.isFavorite();
}