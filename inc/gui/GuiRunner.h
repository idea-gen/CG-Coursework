//
// Created by daniil on 16.02.2022.
//

#pragma once



class GuiRunner {
private:
    int _argc = 0;
    char **_argv = nullptr;
public:
    GuiRunner(int argc, char **argv) : _argc(argc), _argv(argv) {};
    void run();
};


