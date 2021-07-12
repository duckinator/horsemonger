#include "../gen/horsemonger.h"

void setup(Fl_Input_Choice *package_style, Fl_Pack *vbox_pins) {
    // ...
}

int main(int argc, char **argv) {
    auto ui = UserInterface();
    auto window = ui.make_window();
    setup(ui.package_style, ui.vbox_pins);
    window->show(argc, argv);
    return Fl::run();
}
