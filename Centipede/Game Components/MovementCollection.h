#pragma once

struct OffsetArray
{
	int rowoffset;
	int coloffset;

	OffsetArray(int c, int r) : rowoffset(r), coloffset(c) {};
	OffsetArray() : rowoffset(0), coloffset(0) {}
};

class MovementCollection
{
public:
	static const OffsetArray OffsetsStraightRight;
	static const OffsetArray OffsetsTurnUpEndRight;
	static const OffsetArray OffsetsTurnDownEndRight;
	static const OffsetArray OffsetsStraightLeft;
	static const OffsetArray OffsetsTurnUpEndLeft;
	static const OffsetArray OffsetsTurnDownEndLeft;
};

struct Spider_MovementCollection
{
	static const OffsetArray DiagonalDownLeft;
	static const OffsetArray DiagonalDownRight;
	static const OffsetArray DiagonalUpLeft;
	static const OffsetArray DiagonalUpRight;
	static const OffsetArray Up_ThenLeft;
	static const OffsetArray Up_ThenRight;
	static const OffsetArray Down_ThenLeft;
	static const OffsetArray Down_ThenRight;
};