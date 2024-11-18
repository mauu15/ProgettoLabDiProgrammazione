// Folder.h
#ifndef PROGETTOLABDIPROGRAMMAZIONE_FOLDER_H
#define PROGETTOLABDIPROGRAMMAZIONE_FOLDER_H

#include <string>
#include <list>
#include "Note.h"
#include "Observer.h"
#include "Subject.h"

class Folder : public Subject {
private:
    std::string name;                   // Nome del folder
    std::list<Note> notesList;          // Lista di note

public:
    // Costruttore e Distruttore
    explicit Folder(const std::string &name) : name(name) {}
    ~Folder() = default;

    // Getter e Setter
    const std::string &getName() const;
    void setName(const std::string &name);

    // Metodi per Gestione delle Note
    bool addNote(const Note &note);
    bool removeNote(const std::string &title);
    int getSize() const;
    bool getNoteFromTitle(const std::string &title, Note &nota) const;

    std::list<std::pair<std::string, std::string>> getAllNotesList() const;
    bool changeTitle(Note &note, const std::string &newTitle);
    bool changeText(Note &note, const std::string &newText);

    bool editNoteText(Note& note, const std::string& newText);
    bool editNoteTitle(Note& note, const std::string& newTitle);

    std::list<Note> findNotes(const std::string& keyword) const;

    // Metodi per Gestione dei Preferiti
    bool makeFavourite(Note &note);
    bool removeFavorite(const std::string &title);
    std::list<Note> listFavorites() const;

    // Metodi per Gestione delle Note Bloccate
    void blockNote(Note &note);
    void unlockNote(Note &note);
    std::list<Note> listBlocked() const;

    // Metodi per Gestione degli Osservatori
    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() override;
};

#endif //PROGETTOLABDIPROGRAMMAZIONE_FOLDER_H