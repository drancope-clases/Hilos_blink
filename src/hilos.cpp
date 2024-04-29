#include "hilos.h"
class Timer {
    bool clear = false;

public:
    GLFWwindow* ventana;
    bool estado = false;
    template<typename Function>
    void setInterval(Function function, int interval) {
        glfwMakeContextCurrent(NULL);	
        this->clear = false;
        std::thread t([=]() {
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
