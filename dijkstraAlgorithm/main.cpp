// dijkstraAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "dijkstraAlgorithm.h"
class testClass
{
    
public:
    std::vector<float> bigData{};
    testClass();
    testClass(const testClass& temp);
    testClass(testClass&& temp);
};

testClass testFunk()
{
    testClass test{};
    for (size_t i{}; i < test.bigData.size() / 100; ++i)
    {
        std::cout << test.bigData[i];
    }
    return test;
}

int main()
{
    std::map<std::string, RoadNode<std::string, int>> roadMap{};

    std::map<std::string, int> mapToNode_0{ {"Plastinka", 5}, {"Poster", 0} };
    RoadNode<std::string, int> node_0{ "Book", 80, mapToNode_0 };
    roadMap.insert(std::pair<std::string, RoadNode<std::string, int>>{ "Book", node_0});

    std::map<std::string, int> mapToNode_1{ {"Bas", 15}, {"Baraban", 20} };
    RoadNode<std::string, int> node_1{ "Plastinka", 80, mapToNode_1 };
    roadMap.insert(std::pair<std::string, RoadNode<std::string, int>>{ "Plastinka", node_1});

    std::map<std::string, int> mapToNode_2{ {"Bas", 30}, {"Baraban", 35} };
    RoadNode<std::string, int> node_2{ "Poster", 80, mapToNode_2 };
    roadMap.insert(std::pair<std::string, RoadNode<std::string, int>>{ "Poster", node_2});

    dijkstraAlgoritm<std::string, int>(roadMap, "Book");
    
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

testClass::testClass()
{
    bigData.resize(1000000);
}

testClass::testClass(const testClass& temp):
    bigData{temp.bigData}
{
}

testClass::testClass(testClass&& temp) :
    bigData{ temp.bigData }
{
}
