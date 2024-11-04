#include "Folder.h"
#include <algorithm>
#include <iostream>

std::list<Note> Folder::favoriteNotes;
std::list<Note> Folder::blockedNotes;

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
    blockedNotes.push_back(note);
}

// Sblocca una nota
void Folder::unlockNote(const Note &note) {
    blockedNotes.remove(note);
}

// Aggiunge una nota ai preferiti
bool Folder::makeFavourite(Note &note) {
    if (!note.isLocked() && !note.isFavorite()) {
        note.addToFavorites();
        favoriteNotes.push_back(note);
        return true;
    }
    return false;
}

// Rimuove una nota dai preferiti
bool Folder::removeFavorite(const std::string &title) {
    auto it = std::find_if(favoriteNotes.begin(), favoriteNotes.end(), [&](const Note& n){ return n.getTitle() == title; });

    if (it != favoriteNotes.end()) {
        if (!it->isLocked()) {
            it->removeFromFavorites();  // Aggiorna lo stato della nota
            favoriteNotes.erase(it);     // Rimuove la nota dai preferiti
            return true;
        } else {
            std::cout << "Stai cercando di cancellare dai preferiti una nota bloccata. Se desideri proseguire, prima dovrai procedere a sbloccarla." << std::endl;
            return false;
        }
    }

    std::cout << "Nota non trovata nei preferiti." << std::endl;
    return false;
}

// Restituisce la lista delle note bloccate
std::list<Note> Folder::listBlocked() {
    return blockedNotes;
}

// Restituisce la lista delle note preferite
std::list<Note> Folder::listFavorites() {
    return favoriteNotes;
}

// Restituisce la dimensione delle note preferite
int Folder::getFavouriteSize() {
    return favoriteNotes.size();
}

// Restituisce la dimensione delle note bloccate
int Folder::getBlockedSize() {
    return blockedNotes.size();
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