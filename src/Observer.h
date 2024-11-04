#ifndef OBSERVER_H
#define OBSERVER_H

class Subject; //forward declaration


// Interfaccia Observer
class Observer {
public:
    virtual ~Observer() = default;
    // Metodo che verrà chiamato per aggiornare l'osservatore
    virtual void update(const Subject& subject) = 0;
};

#endif // OBSERVER_H