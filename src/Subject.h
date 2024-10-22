#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <list>

// Interfaccia Subject
class Subject {
protected:
    // Lista degli osservatori
    std::list<Observer*> observerList;

public:
    virtual ~Subject() = default;

    // Aggiunge un osservatore alla lista
    virtual void addObserver(Observer *o) {
        observerList.push_back(o);
    }

    // Rimuove un osservatore dalla lista
    virtual void removeObserver(Observer *o) {
        observerList.remove(o);
    }

    // Notifica tutti gli osservatori nella lista
    virtual void notifyObservers() {
        for (auto observer : observerList) {
            observer->update();
        }
    }
};

#endif // SUBJECT_H