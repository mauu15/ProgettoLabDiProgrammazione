// Folder.cpp
#include "Folder.h"
#include "Note.h"
#include <algorithm>
#include <iostream>

// Restituisce il nome del folder
const std::string &Folder::getName() const {
    return name;
}

// Imposta un nuovo nome per il folder
void Folder::setName(const std::string &newName) {
    name = newName;
}

// Aggiunge una nota alla lista delle note
bool Folder::addNote(const Note &note) {
    notesList.push_back(note);
    notifyObservers();
    return true;
}

// Rimuove una nota dalla lista delle note in base al titolo
bool Folder::removeNote(const std::string &title) {
    auto it = std::find_if(notesList.begin(), notesList.end(),
                           [&title](const Note &note) { return note.getTitle() == title; });
    if (it != notesList.end()) {
        notesList.erase(it);
        notifyObservers();
        return true;
    }
    return false;
}

// Restituisce la dimensione della lista di note
int Folder::getSize() const {
    return notesList.size();
}

// Restituisce la nota in base al titolo
bool Folder::getNoteFromTitle(const std::string &title, Note &nota) const {
    auto it = std::find_if(notesList.begin(), notesList.end(),
                           [&title](const Note &note) { return note.getTitle() == title; });
    if (it != notesList.end()) {
        nota = *it;
        return true;
    }
    return false;
}

// Cambia il titolo di una nota se non è bloccata
bool Folder::changeTitle(Note &note, const std::string &newTitle) {
    if (!note.isLocked()) {
        note.setTitle(newTitle);
        notifyObservers();
        return true;
    }
    return false;
}

// Cambia il contenuto di una nota se non è bloccata
bool Folder::changeText(Note &note, const std::string &newText) {
    if (!note.isLocked()) {
        note.setContent(newText);
        notifyObservers();
        return true;
    }
    return false;
}

// Modifica il titolo di una nota (metodo edit)
bool Folder::editNoteTitle(Note &note, const std::string &newTitle) {
    return changeTitle(note, newTitle);
}

// Modifica il contenuto di una nota (metodo edit)
bool Folder::editNoteText(Note &note, const std::string &newText) {
    return changeText(note, newText);
}

// Ottiene una lista di tutte le note (titolo e cartella di appartenenza)
std::list<std::pair<std::string, std::string>> Folder::getAllNotesList() const {
    std::list<std::pair<std::string, std::string>> notes;
    for (const auto &note : notesList) {
        notes.emplace_back(note.getTitle(), name);
    }
    return notes;
}

// Ottiene una lista di note che contengono una parola specificata
std::list<Note> Folder::findNotes(const std::string &keyword) const {
    std::list<Note> result;
    for (const auto &note : notesList) {
        if (note.getTitle().find(keyword) != std::string::npos ||
            note.getContent().find(keyword) != std::string::npos) {
            result.push_back(note);
        }
    }
    return result;
}

// Metodo per bloccare una nota
void Folder::blockNote(Note &note) {
    note.lock();
}

// Sblocca una nota
void Folder::unlockNote(Note &note) {
    note.unlock();
}

// Aggiunge una nota ai preferiti
bool Folder::makeFavourite(Note &note) {
    if (!note.isLocked() && !note.isFavorite()) {
        note.addToFavorites();
        return true;
    }
    return false;
}

// Rimuove una nota dai preferiti
bool Folder::removeFavorite(const std::string &title) {
    auto it = std::find_if(notesList.begin(), notesList.end(),
                           [&title](const Note& n) { return n.getTitle() == title; });

    if (it != notesList.end()) {
        if (!it->isLocked()) {
            it->removeFromFavorites();
            notifyObservers();
            return true;
        }
    }
    return false;
}

// Restituisce la lista delle note preferite
std::list<Note> Folder::listFavorites() const {
    std::list<Note> favorites;
    for (const auto &note : notesList) {
        if (note.isFavorite()) {
            favorites.push_back(note);
        }
    }
    return favorites;
}

// Restituisce la lista delle note bloccate
std::list<Note> Folder::listBlocked() const {
    std::list<Note> blocked;
    for (const auto &note : notesList) {
        if (note.isLocked()) {
            blocked.push_back(note);
        }
    }
    return blocked;
}

// Gestione degli osservatori
void Folder::addObserver(Observer *o) {
    observerList.push_back(o);
}

void Folder::removeObserver(Observer *o) {
    observerList.remove(o);
}

void Folder::notifyObservers() {
    for (auto observer : observerList) {
        observer->update(*this);  // Passa il riferimento al Folder corrente
    }
}