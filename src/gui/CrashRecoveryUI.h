#pragma once
#include <SDL.h>

/**
 * @brief Displays a native modal popup to ask the user if they wish to restore 
 * the previous session after a crash.
 * * @return true if the user clicks "Restore", false if "Discard".
 */
inline bool promptRestoreSession() {
    const SDL_MessageBoxButtonData buttons[] = {
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Restore" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "Discard" },
    };
    
    // Configure the message box data
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_WARNING,
        nullptr,
        "Amplitron Recovery",
        "Amplitron closed unexpectedly during your last session.\n\n"
        "Would you like to restore your previous pedal chain configuration?",
        SDL_arraysize(buttons),
        buttons,
        nullptr  
    };
    
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        return false; 
    }
    return buttonid == 1;
}
