#pragma once
#include <bitset>

class MapNode
{
	/* 
	 connections[0] is 12 o'clock.
	 next 4 steps are N*(1 hour 30 minutes)
	 false - connection is open
	 true  - connection is closed
	 */
	std::bitset<4> connections;

public:
	MapNode() { connections.reset(); }
	~MapNode(){}
	
	void lock(int* setupVector)
	{
		int size = sizeof setupVector;
		if (size>0)
		{
			for (int i = 0; i < size; i++)
			{
				if (setupVector[i]==0)
				{
					return;
				}
				connections[setupVector[i]-1] = true;
			}
		}
	}
	void unlock(int* setupVector)
	{
		int size = sizeof setupVector;
		if (size>0)
		{
			for (int i = 0; i < size; i++)
			{
				if (setupVector[i] == 0)
				{
					return;
				}
				connections[setupVector[i] - 1] = false;
			}
		}
	}
	///returns true when connection is open & boook selected connection
	bool lockNode(uint8_t way)
	{
		uint8_t propervalue = way % 4;
		bool temp = !connections[propervalue];
		if (temp)
		{
			connections[propervalue] = true;
		}
		return temp;
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

	///returns true when all 4 nodes are locked
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

