#include <iostream>
#include <gtkmm/application.h>
#include <glibmm/miscutils.h>

#include "src/roggui.h"

int main(int argc, char** argv)
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("rogauracore.gui");  
    RogGui gui;

    gui.window_main->signal_delete_event().connect([&](GdkEventAny* event)
    {
        // Run the shell script
        Glib::spawn_command_line_async("./restart_upower.sh");

        // Returning false allows the default behavior (destroy the window).
        return false;
    });

    return app->run(*gui.window_main);
}
