#include <iostream>
#include <cstdlib>
#include <gtkmm/application.h>

#include "src/roggui.h"

int main(int argc, char** argv)
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("rogauracore.gui");	
    RogGui gui;

    // Connect the "hide" signal to a lambda function
    gui.window_main->signal_hide().connect([&]()
    {
        // Run the command to restart upower.service using system()
        std::system("sudo systemctl restart upower.service");
    });

    return app->run(*gui.window_main);
}
