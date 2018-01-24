#pragma once
#include <bitset>

class MapNode
{
	/* 
	 connections[0] is 12 o'clock.
	 next 4 steps are N*(1 hour 30 minutes)
	 false - connection is open
	 true  - connection is closed

	conn[8] false - no bounce
	 */
	std::bitset<9> connections;

public:
	MapNode() { connections.reset(); }
	~MapNode(){}
	
	bool checkOpen(uint8_t way)
	{
		return !connections[way];
	}

	bool vcheckOpen(uint8_t way)
	{
		return !connections[way+4];
	}

	void allowBounce()
	{
		connections[8] = true;
	}
	void disableBounce(){
		connections[8] = false;
	}
	bool bounce()
	{
		return connections[8];
	}
	///returns true when connection is open & boook selected connection
	bool lockNode(uint8_t way)
	{

			connections[way] = true;
			connections[way+4] = true;
			return true;
	}
	bool vlockNode(uint8_t way)
	{
		bool temp = !connections[way+4];
		if (temp)
		{
			connections[way+4] = true;
		}
		return temp;
	}

	///returns true when conenction closed & make conenction open 
	bool unlockNode(uint8_t way)
	{
		bool temp = connections[way];
		if (temp)
		{
			connections[way] = false;
		}
		return temp;
	}
	bool vunlockNode(uint8_t way)
	{
		bool temp = connections[way+4];
		if (temp)
		{
			connections[way+4] = false;
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

	void lockMultipleNodes(int* setupVector)
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
				connections[setupVector[i] - 1] = true;
			}
		}
	}

	void unlockMultipleNodes(int* setupVector)
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

};

