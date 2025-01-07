// ConcreteObserver.cpp
#include "ConcreteObserver.h"
#include "Folder.h"
#include <iostream>

ConcreteObserver::~ConcreteObserver() {
    // Disiscrive l'osservatore da tutti i canali (Folder) a cui è iscritto
    for (auto* folder : channelsList) {
        folder->removeObserver(this);
    }
}

void ConcreteObserver::update(const Folder& folder) {
    int numNotes = folder.getSize(); // Ottiene il numero di note presenti nel folder
    std::cout << "Il folder contiene " << numNotes << " note.\n";
}

void ConcreteObserver::subscribe(Folder* folder) {
    // Aggiunge l'osservatore alla lista del folder e viceversa
    channelsList.push_back(folder);
    folder->addObserver(this);
}

void ConcreteObserver::unsubscribe(Folder* folder) {
    // Rimuove l'osservatore dalla lista del folder e viceversa
    channelsList.remove(folder);
    folder->removeObserver(this);
}