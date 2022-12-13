#include "workQueue.h"

WorkQueue::WorkQueue(){
    std::vector<std::shared_ptr<Command>> wq = {};
}

std::shared_ptr<Command> WorkQueue::get(){
    static std::mutex mute;
    
    std::lock_guard <std::mutex> lock(mute);

    if(wq.empty()) {
        return nullptr;
    }

    std::shared_ptr<Command> & tmp = wq.front();

    wq.erase(wq.begin());

    return tmp;
}

void WorkQueue::put(std::shared_ptr<Command> var) {
    static std::mutex mute;

    std::lock_guard <std::mutex> lock(mute);

    wq.push_back(var);
}