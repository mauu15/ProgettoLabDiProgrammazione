#ifndef OBSERVER_H
#define OBSERVER_H

class Folder;

// Interfaccia Observer
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const Folder &folder) = 0; // Metodo puramente virtuale
};

#endif // OBSERVER_H