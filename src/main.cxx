#include <stdio.h>
#include <string>
#include "../gen/horsemonger.h"

class Component {
private:
    enum ComponentType {
        UNKNOWN = 0,
        DIP = 1,
    };

    Fl_Pack *vbox_pins;
    ComponentType type = UNKNOWN;

    static void package_style_choice_cb(Fl_Widget *w, void *userdata);
    static ComponentType name_to_type(const char *name);

public:
    int num_pins;

    Component(Fl_Pack *package_style, Fl_Pack *vbox_pins);
};

Component::ComponentType Component::name_to_type(const char *name) {
    if (strncmp("DIP", name, 4) == 0) {
        return Component::ComponentType::DIP;
    } else {
        return Component::UNKNOWN;
    }
}

Component::Component(Fl_Pack *package_style, Fl_Pack *vbox_pins) {
    this->vbox_pins = vbox_pins;

    int num_children = package_style->children();
    for (int i = 0; i < num_children; i++) {
        Fl_Round_Button *child = (Fl_Round_Button*)package_style->child(i);
        child->callback(package_style_choice_cb, 0);
    }

    Fl_Round_Button *first_child = (Fl_Round_Button*)package_style->child(0);
    first_child->set();
}

void Component::package_style_choice_cb(Fl_Widget *w, void *userdata) {
    Fl_Round_Button *choice = (Fl_Round_Button*)w;
    (void)userdata; // unused

    auto parent = choice->parent();

    int num_children = parent->children();
    for (int i = 0; i < num_children; i++) {
        Fl_Round_Button *child = (Fl_Round_Button*)parent->child(i);
        if (child != choice) {
            child->clear();
        }
    }

    printf("name = %s (%i)\n", choice->label(), name_to_type(choice->label()));

    //vbox_pins->begin();

    //vbox_pins->end();
}

int main(int argc, char **argv) {
    auto ui = UserInterface();
    auto window = ui.make_window();
    auto component = Component(ui.package_style, ui.vbox_pins);
    window->show(argc, argv);
    return Fl::run();
}
