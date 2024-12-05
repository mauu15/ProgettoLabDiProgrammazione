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

void ConcreteObserver::update(const Subject& subject) {
    // Usa dynamic_cast per convertire il riferimento a Subject in un riferimento a Folder
    const Folder* folder = dynamic_cast<const Folder*>(&subject);
    if (folder) {
        int numNotes = folder->getSize(); // Ottiene il numero di note presenti nel folder
        std::cout << "Il folder contiene " << numNotes << " note.\n";
    }
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