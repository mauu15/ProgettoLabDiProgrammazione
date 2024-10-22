#ifndef OBSERVER_H
#define OBSERVER_H

// Interfaccia Observer
class Observer {
public:
    virtual ~Observer() = default;
    // Metodo che verrà chiamato per aggiornare l'osservatore
    virtual void update() = 0;
};

#endif // OBSERVER_H