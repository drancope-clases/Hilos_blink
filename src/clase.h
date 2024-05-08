#include <functional>
#include <chrono>
#include <future>
#include <cstdio>
#include <thread>
#include "ventana.h"

class Led {
  public:
    Led(int tiempo);
    GLFWwindow *ventana;
    bool estado;
    int tiempo;
};

class later
{
public:
    template <class callable, class... arguments>
    later(Led *t, bool async, callable&& f, arguments&&... args)
    {   
        int after = t->tiempo;
        std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

        if (async)
        {
            glfwMakeContextCurrent(NULL);
            std::thread([after, task]() {
                for (;;) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(after));
                    task();
                }
            }).detach();
        }
        else
        {
            for (;;) {
                std::this_thread::sleep_for(std::chrono::milliseconds(after));
                task();
            }
        }
    }

};