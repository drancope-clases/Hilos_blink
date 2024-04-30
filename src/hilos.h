#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>
#include <GL/glx.h>
#include "ventana.h"
class Timer {
    bool clear = false;

public:
    Timer(){
        this->estado = false;
    };
    GLFWwindow* ventana;
    bool estado;
    template<typename Function>
    void setInterval(Function function, int interval) {
        glfwMakeContextCurrent(NULL);	
        this->clear = false;
        std::thread t([=, this]() {
            while(true) {
                if(this->clear) return;
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if(this->clear) return;
                std::cout << "Entrando en hilo\n" << std::endl;
                glfwMakeContextCurrent(this->ventana);
                function(&(this->estado), this->ventana);
            }
        });
        t.detach();
    }
    template<typename Function>
    void setTimeout(Function function, int delay) {
        glfwMakeContextCurrent(NULL);	
        this->clear = false;
        std::thread t([=,this]() {
            if(this->clear) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(this->clear) return;
            glfwMakeContextCurrent(this->ventana);
            function();
        });
        t.detach();
    }
    void stop(){
        this->clear = true;
    }
};
