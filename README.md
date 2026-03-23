# ☑️ Traffic-Light-Simulator
This was the 2nd evaluation of my month of training which was done after a week into the process. I used cars in vectors which stored positions and had an own thread that had the traffic light functional.

## ❇️Features
- **Multithreaded application**: I used a total of four threads, one for int main, one of each lane and one for the traffic light logic.
- **Mutex locks**: A concept used in multithreaded applications to ensure data races doesn't happen, which leads to undefined behaviors (often crashes).
- **Vectors**: Dynamic arrays, commonly referred to as vectors used for storing the cards with the datatype struct which allowed us to store multiple datatypes in each element.
- **Dynamic light logic**: I didn't get a ton of time optimizing the algorithm that runs the traffic lights but I made sure it was somewhat dynamic and not entirely fixed just by time.

#### This project was made entirely in C++ with these following libraries: iostream, vector, algorithm, random, chrono, thread

## 🤔The Process 

I had just learnt about threads in C++ and was super eager to get this underway. I had a suprisingly strong start and knew where I wanted to take this.
However, as stated in my last project, I quickly found out I had taken a project a little too advanced and I would pay the price.
I made two functions that were almost identical instead of joining them and I still encountered bugs with threading even though I thought I had it figured out.
I wanted to setup a UI to display the vectors, their positions and the traffic lights but never found the time.

## 📚My takeaways 

My main takeaway from this project was that taking on a task too large will always make you drown.

It was very ambitious to hope I could create this application after only a week of dedicated practice and a few C++ tutorials before that.

UI's is something I hope to get into soon but definetely not something I can start learning in a programming marathon.

In the end I didn't manage to code a lot of the features I wanted and in the process made a bug filled program.

However I don't regret this project at all since it's only when failing that we'll learn and I still learnt alot about mutex locks and threading.

## 🚀Running the project 

1. Install the TrafficLightSimulator.cpp file alongside C++ on your code editor and run the file there.

## 🍿Video
