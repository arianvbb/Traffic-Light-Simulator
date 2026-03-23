#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cmath>
#include <atomic>
#include <mutex>

// Variables (atomic so it works with multiple threads)
std::mutex gLock;
std::string light_color1;
std::string light_color2;
int stop_line = 0;

std::atomic<int> Traffic1 = 0;
std::atomic<int> Traffic2 = 0;

std::atomic<bool> enabled = true;

class cars{
    public:
        int position;
        int speed;
        int lane;

        void update(){
            position += speed;
        }

        cars(int position, int speed, int lane){
            this->position = position;
            this->speed = speed;
            this->lane = lane;
        }
};

void TrafficLight();
void Highway1(std::vector<cars>& Highway1);
void Highway2(std::vector<cars>& Highway2);

int main()
{
    srand(time(NULL));
    std::vector<cars> Cars1;
    std::vector<cars> Cars2;

    std::thread worker1(Highway1, std::ref(Cars1));
    std::thread worker2(Highway2, std::ref(Cars2));
    std::thread worker3(TrafficLight);

    std::this_thread::sleep_for(std::chrono::seconds(30));

    enabled = false;
    worker1.join();
    worker2.join();
    worker3.join();
    return 0;
}

void TrafficLight(){
    while(enabled == true){
        gLock.lock();
            light_color1 = "green";
            light_color2 = "red";
        gLock.unlock();
        while(Traffic2 < 10){
            std::this_thread::sleep_for(std::chrono::seconds(3)); // Time to clear the crossing.
        }
        gLock.lock();
        light_color1 = "red";
        light_color2 = "green";
        gLock.unlock();
        while(Traffic1 < 10){
            std::this_thread::sleep_for(std::chrono::seconds(3)); // Time to clear the crossing.
        }
    }
}

void Highway1(std::vector<cars>& Highway1){
    while(enabled == true){
        int num = (rand() % 2) + 1;
        int speed = (rand() % 3) + 1; // Speed
        Highway1.push_back(cars(-15, speed, num));
        for(int i = 0; i < Highway1.size(); i++){
            if(Highway1[i].position < stop_line){
                Traffic1 ++;
            }

            if(Highway1[i].position > 20){
                Highway1.erase(Highway1.begin() + i);
            }
            else{
                if(Highway1[i].position == stop_line && light_color1 == "red"){
                    continue;
                }
                else{
                    if(std::find_if(Highway1.begin(), Highway1.end(), [&](const cars& c){
                    return c.position == Highway1[i].position + 1 && c.lane == Highway1[i].lane;
                    }) == Highway1.end()){{
                        Highway1[i].update();
                    }
                }
            }
        }
        Traffic1 = 0;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
}

void Highway2(std::vector<cars>& Highway2){
    while(enabled == true){
        int num = (rand() % 2) + 1;
        int speed = (rand() % 3) + 1; // Speed
        Highway2.push_back(cars(-15, speed, num));
        for(int i = 0; i < Highway2.size(); i++){
            if(Highway2[i].position < stop_line){
                Traffic2 ++;
            }

            if(Highway2[i].position > 20){
                Highway2.erase(Highway2.begin() + i);
            }
            else{
                if(Highway2[i].position == stop_line && light_color2 == "red"){
                    continue;
                }
                else{
                    if(std::find_if(Highway2.begin(), Highway2.end(), [&](const cars& c){
                    return c.position == Highway2[i].position + 1 && c.lane == Highway2[i].lane;
                    }) == Highway2.end()){{
                        Highway2[i].update();
                    }
                }
            }
        }
        Traffic2 = 0;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
}