#pragma once

#include "CommonIncludes.h"

namespace Dir
{
	enum TDir
	{
		Right,
		Down,
		Left,
		Up
	};

	void Forward(PI & rPos, TDir eDir)
	{
		switch (eDir)
		{
		case Right:
			rPos.first++;
			break;
		case Down:
			rPos.second++;
			break;
		case Left:
			rPos.first--;
			break;
		case Up:
			rPos.second--;
			break;
		default:
			break;
		}
	}

	void Turn(TDir & rDir)
	{
		switch (rDir)
		{
		case Right:
			rDir = Down;
			break;
		case Down:
			rDir = Left;
			break;
		case Left:
			rDir = Up;
			break;
		case Up:
			rDir = Right;
		default:
			break;
		}
	}
};
