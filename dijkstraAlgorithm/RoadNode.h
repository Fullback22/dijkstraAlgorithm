#pragma once

#include <map>

template <typename T, typename N>
class RoadNode
{
public:
	T nodeName_{};
	N nodeWeight_{};
private:
	RoadNode<T, N>* previousNode_{};
	std::map<T, N> neighbors_{};
	bool nodeIsChecked_{ false };
public:
	RoadNode();
	RoadNode(const T& name, const N& startWeight, const std::map<T, N>& neighbors);
	RoadNode(const RoadNode<T, N>& temp);
	RoadNode(RoadNode<T, N>&& temp);

	RoadNode<T, N>& operator=(const RoadNode<T, N>& temp);
	RoadNode<T, N>& operator=(RoadNode<T, N>&& temp);

	const RoadNode<T, N>* getPrevusNode() const;
	const std::map<T, N>& getNodeNeighbors() const;
	void clearNeighbors();
	void setPreviusNode(RoadNode<T, N>& previusNode);
	bool nodeIsChecked() const;
	void setCheckFlag();
};

template<typename T, typename N>
inline RoadNode<T, N>::RoadNode()
{
}

template<typename T, typename N>
inline RoadNode<T, N>::RoadNode(const T& name, const N& startWeight, const std::map<T, N>& neighbors) :
	nodeName_{ name },
	nodeWeight_{ startWeight },
	neighbors_{ neighbors }
{
}

template<typename T, typename N>
inline RoadNode<T, N>::RoadNode(const RoadNode<T, N>& temp) :
	nodeName_{ temp.nodeName_ },
	nodeWeight_{ temp.nodeWeight_ },
	previousNode_{ temp.previousNode_ },
	neighbors_{ temp.neighbors_ },
	nodeIsChecked_{temp.nodeIsChecked_}
{
}

template<typename T, typename N>
inline RoadNode<T, N>::RoadNode(RoadNode<T, N>&& temp) :
	nodeName_{ temp.nodeName_ },
	nodeWeight_{ temp.nodeWeight_ },
	previousNode_{ temp.previousNode_ },
	neighbors_{ temp.neighbors_ },
	nodeIsChecked_{ temp.nodeIsChecked_ }
{
}

template<typename T, typename N>
inline RoadNode<T, N>& RoadNode<T, N>::operator=(const RoadNode<T, N>& temp)
{
	nodeName_ = temp.nodeName_;
	nodeWeight_ = temp.nodeWeight_;
	previousNode_ = temp.previousNode_;
	neighbors_ = temp.neighbors_;
	nodeIsChecked_ = temp.nodeIsChecked_;
	return *this;
}

template<typename T, typename N>
inline RoadNode<T, N>& RoadNode<T, N>::operator=(RoadNode<T, N>&& temp)
{
	nodeName_ = temp.nodeName_;
	nodeWeight_ = temp.nodeWeight_;
	previousNode_ = temp.previousNode_;
	neighbors_ = temp.neighbors_;
	nodeIsChecked_ = temp.nodeIsChecked_;
	return *this;
}

template<typename T, typename N>
inline const RoadNode<T, N>* RoadNode<T, N>::getPrevusNode() const
{
	return previousNode_;
}

template<typename T, typename N>
inline const std::map<T, N>& RoadNode<T, N>::getNodeNeighbors() const
{
	return neighbors_;
}

template<typename T, typename N>
inline void RoadNode<T, N>::clearNeighbors()
{
	neighbors_.clear();
}

template<typename T, typename N>
inline void RoadNode<T, N>::setPreviusNode(RoadNode<T, N>& previousNode)
{
	previousNode_ = &previousNode;
}

template<typename T, typename N>
inline bool RoadNode<T, N>::nodeIsChecked() const
{
	return nodeIsChecked_;
}

template<typename T, typename N>
inline void RoadNode<T, N>::setCheckFlag()
{
	nodeIsChecked_ = true;
}
