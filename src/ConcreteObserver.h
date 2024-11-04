#ifndef PROGETTOLABDIPROGRAMMAZIONE_CONCRETEOBSERVER_H
#define PROGETTOLABDIPROGRAMMAZIONE_CONCRETEOBSERVER_H
#include "Observer.h"
#include <string>
#include <list>
#include <utility>

// Forward declaration
class Subject;
class Folder;

// Classe ConcreteObserver che implementa l'interfaccia Observer
class ConcreteObserver : public Observer {
private:
    std::string name;                    // Nome dell'osservatore
    std::list<Subject*> channelsList;    // Lista di puntatori ai Subject a cui l'osservatore è iscritto

public:
    // Costruttore che inizializza il nome dell'osservatore
    explicit ConcreteObserver(std::string  n) : name(std::move(n)) {}

    // Distruttore che rimuove l'osservatore da tutti i Subject a cui è iscritto
    ~ConcreteObserver() override;

    void update(const Subject &subject) override; // Metodo per aggiornare l'osservatore

    // Metodo per iscrivere l'osservatore a un Subject
    void subscribe(Subject* subject);

    // Metodo per disiscrivere l'osservatore da un Subject
    void unsubscribe(Subject* subject);


};

#endif //PROGETTOLABDIPROGRAMMAZIONE_CONCRETEOBSERVER_H
