#include "../engine/entry/Engine.h"

int main() {
    Program::Engine engine("./config/flash.ini");
    return engine.start();
}
