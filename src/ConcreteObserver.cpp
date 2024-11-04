#include "ConcreteObserver.h"
#include "Folder.h"
#include <iostream>

ConcreteObserver::~ConcreteObserver() {
    // Disiscrive l'osservatore da tutti i canali (Subject) a cui è iscritto
    for (auto* subject : channelsList) {
        subject->removeObserver(this);
    }
}

void ConcreteObserver::update(const Subject& subject) {
    // Tenta un cast sicuro a Folder
    const auto* folder = dynamic_cast<const Folder*>(&subject);
    if (folder) {
        int numNotes = folder->getSize(); // Ottiene il numero di note presenti nel folder
        std::cout << "Il folder contiene " << numNotes << " note.\n";
    }
}

void ConcreteObserver::subscribe(Subject* subject) {
    // Aggiunge l'osservatore alla lista del subject e viceversa
    channelsList.push_back(subject);
    subject->addObserver(this);
}

void ConcreteObserver::unsubscribe(Subject* subject) {
    // Rimuove l'osservatore dalla lista del subject e viceversa
    channelsList.remove(subject);
    subject->removeObserver(this);
}