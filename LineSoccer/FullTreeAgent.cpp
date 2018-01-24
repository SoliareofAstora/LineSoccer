#include "FullTreeAgent.h"
#include "FieldLogic.h"
#include "Visualization.h"


FullTreeAgent::FullTreeAgent()
{
}

void FullTreeAgent::move(sf::Color color)
{
	node Root = node();
	std::vector<int> out = Root.generate();
	std::cerr << "FINAL: ";
	for (int element : out)
	{
		std::cerr << element << " ";
	}
	for (int i = 1;i < out.size();i++)
	{
		FieldLogic::instance().saveMove(out[i], sf::Color::Red);
	}
	//out.display();









	/*

	int destination = 0;
	while (true)
	{
		destination = 2;
		//std::cerr <<"test "<< destination;

		if (FieldLogic::instance().checkIfMoveIsPossible(destination))
		{
			std::cerr << " " << destination;
			FieldLogic::instance().saveMove(destination, color);
			Visualization::instance().draw();
		}
		if (!FieldLogic::instance().MoveNotFinished())
		{
			std::cerr << "koniec ruchu\n\n";
			break;
		}
	}*/
}


FullTreeAgent::~FullTreeAgent()
{
}
