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
	bool bookNode(uint8_t way)
	{
		uint8_t propervalue = way % 8;
		bool temp = !connections[propervalue];
		if (temp)
		{
			connections[propervalue] = true;
		}
		return temp;
	}

	///returns true when conenction closed & make conenction open 
	bool unbookNode(uint8_t way)
	{
		uint8_t propervalue = way % 8;
		bool temp = connections[propervalue];
		if (temp)
		{
			connections[propervalue] = false;
		}
		return temp;
	}

	bool isNodeFull()
	{
		bool temp = true;
		for (uint8_t  i=0;i<7;i++)
		{
			if (!connections[i])
			{
				
			}
		}
	}
};

