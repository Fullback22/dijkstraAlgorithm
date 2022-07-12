#pragma once
#include <set>

#include "RoadNode.h"

template <typename T, typename N>
void dijkstraAlgoritm(std::map<T, RoadNode<T, N>>& map, const T& startNode);

template <typename T, typename N>
T getKeyWithMinValue(const std::map<T, RoadNode<T, N>>& map, std::set<T>& keys);

template <typename T, typename N>
void updatingWeightsForNeighbors(std::map<T, RoadNode<T, N>>& map, RoadNode<T, N>& activNode);

template <typename T, typename N>
void addNodesToSet(const std::map<T, N>& nodes, std::set<T>& set);

template<typename T, typename N>
inline void dijkstraAlgoritm(std::map<T, RoadNode<T, N>>& map, const T& startNode)
{
	RoadNode<T, N> activNode{ map[startNode] };
	activNode.nodeWeight_ = 0;

	std::set<std::string> testedNodes{ startNode };
	std::set<std::string> nodeInNextLevel{};

	updatingWeightsForNeighbors(map, activNode);
	addNodesToSet(activNode.getNodeNeighbors(), nodeInNextLevel);
	std::map<T, N> activNodeNeighbors{  };
	T keyWithMinValue{ getKeyWithMinValue(activNodeNeighbors) };

	int a;
}

template<typename T, typename N>
inline T getKeyWithMinValue(const std::map<T, RoadNode<T, N>>& map, std::set<T>& keys)
{
	auto it{ data.begin() };
	T key{ it->first };
	N minValue{ it->second };
	++it;
	for (; it != data.end(); ++it)
	{
		if (it->second < minValue)
		{
			key = it->first;
			minValue = it->second;
		}
	}
	return key;
}

template<typename T, typename N>
inline void updatingWeightsForNeighbors(std::map<T, RoadNode<T, N>>& map, RoadNode<T, N>& activNode)
{
	for (auto it{ activNode.getNodeNeighbors().begin() }; it != activNode.getNodeNeighbors().end(); ++it)
	{
		T neighbordName{ it->first };
		RoadNode<T, N> neighbord{ map[neighbordName] };
		N newWeightForNode{ it->second + activNode.nodeWeight_ };

		if (neighbord.nodeWeight_ > newWeightForNode)
		{
			neighbord.nodeWeight_ = newWeightForNode;
			neighbord.setPreviusNode(activNode);
			map[neighbordName] = neighbord;
		}
	}
}

template<typename T, typename N>
inline void addNodesToSet(const std::map<T, N>& nodes, std::set<T>& set)
{
	for (auto it{ nodes.begin() }; it != nodes.end(); ++it)
	{
		set.insert(it->first);
	}
}

