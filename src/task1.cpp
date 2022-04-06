#include "task1.h"
#include <iostream>
#include <cassert>
#include <map>
#include <cstdlib>
#include <ctime>

class Branch
{
    int count = 0;
    std::string nameElf;
    Branch* parent = nullptr;
    Branch** childBranches = nullptr;

public:

    Branch(Branch* inParent = nullptr)
    {
        parent = inParent;
        if (parent == nullptr)
        {
            nameElf= "None";
            count = std::rand() % 3 + 3;
            std::cout << "Tree in filling"<< std::endl;
        }
        else if (parent->parent== nullptr) count = std::rand() % 2 + 2;
        else count = 0;
        if (nameElf != "None")
        {
            std::cout << "Enter name of Elf" << std::endl;
            std::cin >> nameElf;
        }
        for (int i = 0; i< count; ++i) {
            std::cout << "Branch " << i+1 << " out of " << count << " in filling"<< std::endl;
            childBranches[i] = new Branch(this);
        }
    }

    Branch* findElf (std::string inName)
    {
        if (nameElf == inName){
            return this;
        }
        else
            for(int i = 0; i <count;++i)
            {
                return childBranches[i]->findElf(inName);
            }
        return nullptr;
    }

    int neibourghCount (Branch* inBranch)
    {
        int i = 0;
        if (inBranch->parent->parent == nullptr)
        {
            for (int j = 0; j< inBranch->count;++j){
                if (inBranch->childBranches[j]->nameElf != "None")
                    ++i;
            }
        }
        else {
            for (int j = 0; j< inBranch->parent->count;++j){
                if (inBranch->parent->childBranches[j]->nameElf != "None")
                    ++i;
            }
            --i;
        }
        assert(i>=0);
        return i;
    }

};


void task1()
{
    std::srand(std::time(nullptr));
    Branch** tree = nullptr;
    for (int i = 0; i <5; ++i)
    {
        tree[i] = new Branch();
    }
    std::cout << "What elf do you want to find?" <<std::endl;
    int answer = 0;
    std::string input;
    std::cin >> input;
    for (int i = 0; i <5; ++i)
    {
        Branch* found = tree[i]->findElf(input);
        if (found != nullptr)
            answer = found->neibourghCount(found);
    }
    std::cout << "Answer is " << answer <<std::endl;
    delete tree;
    tree= nullptr;
    delete tree;
}