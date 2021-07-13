#include <stdio.h>
#include <string>
#include "radio_button.h"
#include "../gen/horsemonger.h"

enum ComponentType {
    UNKNOWN = 0,
    DIP = 1,
};

static void package_style_choice_cb(Fl_Widget *w, void *userdata);
static void num_pins_cb(Fl_Widget *w, void *userdata);

class Component {
private:
    Fl_Pack *vbox_pins;

public:
    ComponentType type = UNKNOWN;
    int num_pins;

    void setup(UserInterface *ui);
};

static Component component = Component();

void Component::setup(UserInterface *ui) {
    Fl_Pack *package_style = ui->package_style;
    this->vbox_pins = ui->vbox_pins;

    ui->num_pins->callback(num_pins_cb, 0);

    int num_children = package_style->children();
    for (int i = 0; i < num_children; i++) {
        Fl_Round_Button *child = (Fl_Round_Button*)package_style->child(i);
        child->callback(package_style_choice_cb, 0);
    }

    Fl_Round_Button *first_child = (Fl_Round_Button*)package_style->child(0);
    first_child->set();
}

ComponentType package_name_to_type(const char *name) {
    if (strncmp("DIP", name, 4) == 0) {
        return DIP;
    } else {
        return UNKNOWN;
    }
}


void num_pins_cb(Fl_Widget *w, void *userdata) {
    Fl_Value_Input *input = (Fl_Value_Input*)w;

    component.num_pins = input->value();
    printf("component.num_pins = %i\n", component.num_pins);
}

void package_style_choice_cb(Fl_Widget *w, void *userdata) {
    Fl_Round_Button *choice = (Fl_Round_Button*)w;
    (void)userdata; // unused

    radio_button_select(choice);

    component.type = package_name_to_type(choice->label());
    printf("component.type = %i\n", component.type);
}

int main(int argc, char **argv) {
    auto ui = UserInterface();
    auto window = ui.make_window();
    component.setup(&ui);
    window->show(argc, argv);
    return Fl::run();
}
