#include "radio_button.h"

void radio_button_select(Fl_Round_Button *choice) {
    auto parent = choice->parent();

    int num_children = parent->children();
    for (int i = 0; i < num_children; i++) {
        Fl_Round_Button *child = (Fl_Round_Button*)parent->child(i);
        if (child != choice) {
            child->clear();
        }
    }
}
