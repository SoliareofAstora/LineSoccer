#pragma once
#include <bitset>

class MapNode
{
	/* 
	 N = 0 is 12 o'clock.
	 next steps are N*(1 hour 30 minutes)
	 false - connection is open
	 true  - connection is closed
	 */
	std::bitset<8> connections;

public:
	MapNode() { connections.reset(); }
	~MapNode(){}
	
	///returns true when connection is open & boook selected connection
	bool lockNode(uint8_t way)
	{
		uint8_t propervalue = way % 8;
		bool temp = !connections[propervalue];
		if (temp)
		{
			connections[propervalue] = true;
		}
		return temp;
	}

	///lock multiple nodes based on bitset<8> vector
	void lockNodes(std::bitset<8> &way)
	{
		for (uint8_t i = 0; i<7; i++)
		{
			if (way[i])
			{
				connections[i] = true;
			}
		}
	}

	///returns true when conenction closed & make conenction open 
	bool unlockNode(uint8_t way)
	{
		uint8_t propervalue = way % 8;
		bool temp = connections[propervalue];
		if (temp)
		{
			connections[propervalue] = false;
		}
		return temp;
	}

	///returns true when all 8 nodes are locked
	bool isNodeFull()
	{
		for (uint8_t  i=0;i<7;i++)
		{
			if (!connections[i])
			{
				return false;
			}
		}
		return true;
	}
};

