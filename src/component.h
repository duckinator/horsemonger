#ifndef COMPONENT_H
#define COMPONENT_H

#include "gen/horsemonger.h"

enum ComponentType {
    UNKNOWN = 0,
    DIP = 1,
};

class Component {
private:
    Fl_Pack *vbox_pins;

public:
    ComponentType type = UNKNOWN;
    int num_pins;

    void setup(UserInterface *ui);
};

#endif
