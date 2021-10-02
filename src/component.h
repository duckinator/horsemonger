#ifndef COMPONENT_H
#define COMPONENT_H

#include <nlohmann/json.hpp>

#include "gen/horsemonger.h"

class Component {
private:
    Fl_Pack *vbox_pins;

public:
    char type[10] = "UNKNOWN";
    int num_pins = -1;

    void setup(UserInterface *ui);
};

#endif
