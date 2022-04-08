#include "task3.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <assert.h>

enum TASK
{
    A,
    B,
    C,
    NONE
};

std::string getTypeTask (TASK inTask)
{
    if (inTask == A) return "A"; else
    if (inTask == B) return "B"; else
    if (inTask == C) return "C"; else
        return "None";
}

class Worker
{
    TASK task = NONE;
    std::string name;

public:

    Worker(std::string inName): name(inName){}

    void giveTask()
    {
        task = (TASK)(std::rand() % 3);
        std::cout << "Worker " << name << "get task type " << getTypeTask(task) << std::endl;
    }
};

class Manager
{
    int countWorker = 0;
    Worker** workers = nullptr;
    int teamNumber, lastWorker = 0;
    bool fullOfJob = false;

public:

    Manager (int inCountWorker, int inTeamNumber): countWorker(inCountWorker), teamNumber(inTeamNumber)
    {
        workers = new Worker*[countWorker];
        for (int i = 0; i< countWorker; ++i)
        {
            workers[i] = new Worker(std::to_string(teamNumber) + "."+ std::to_string(i+1));
        }
    }

    void giveTeamTask (int inTask)
    {
        std::cout << "Team " << teamNumber << " get task " << inTask << std::endl;
        std::srand(inTask+teamNumber);
        int taskCount = std::rand()% (countWorker+1);
        if (taskCount > countWorker - lastWorker)
        {
            taskCount = countWorker;
            fullOfJob = true;
        }
        else taskCount = taskCount + lastWorker;
        for (int i = lastWorker; i < taskCount ; ++i)
        {
            workers[i]->giveTask();
            ++lastWorker;
        }
    }

    bool getFullOfJob()
    {
        return fullOfJob;
    }
};

class Director
{
    int task;
    int countTeam = 0;
    Manager** teams = nullptr;

public:

    Director(int inCountTeam, int inCountWorkers): countTeam(inCountTeam)
    {
        teams = new Manager*[countTeam];
        for (int i = 0; i < countTeam; ++i)
        {
            teams[i] = new Manager(inCountTeam,i+1);
        }
    }

    bool doTask (int inTask)
    {
        task = inTask;
        int count = 0;
        for (int i = 0; i<countTeam;++i)
        {
            if (!teams[i]->getFullOfJob()) {
                teams[i]->giveTeamTask(task);
            } else ++count;
        }
        if (count == countTeam) return false;
        else return true;
    }
};



void task3()
{
    std::cout << "Company sim activated"<<std::endl;
    std::cout << "Enter quantity of teams and workers in each team:" <<std::endl;
    int countTeam, countWorkers;
    std::cin >> countTeam >> countWorkers;
    assert(countTeam >0 && countWorkers > 0);
    Director* comp = new Director(countTeam, countWorkers);
    while (true)
    {
        std::cout << "Enter task!" << std::endl;
        int task;
        std::cin >> task;
        if (!comp->doTask(task)) break;
    }
    delete comp;
    comp = nullptr;
    delete comp;
}