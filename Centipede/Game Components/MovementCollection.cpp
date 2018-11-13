#include "MovementCollection.h"

//centi
const OffsetArray MovementCollection::OffsetsStraightRight = OffsetArray(1, 0);
const OffsetArray MovementCollection::OffsetsTurnUpEndRight = OffsetArray(0, -1);
const OffsetArray MovementCollection::OffsetsTurnDownEndRight = OffsetArray(0, 1);
const OffsetArray MovementCollection::OffsetsStraightLeft = OffsetArray(-1, 0);
const OffsetArray MovementCollection::OffsetsTurnUpEndLeft = OffsetArray(0, -1);
const OffsetArray MovementCollection::OffsetsTurnDownEndLeft = OffsetArray(0, 1);
const OffsetArray MovementCollection::OffsetsPoisoned = OffsetArray(0, 1);

//spider
const OffsetArray Spider_MovementCollection::DiagonalDownLeft = OffsetArray(-1, 1);
const OffsetArray Spider_MovementCollection::DiagonalDownRight = OffsetArray(1, 1);
const OffsetArray Spider_MovementCollection::DiagonalUpLeft = OffsetArray(-1, -1);
const OffsetArray Spider_MovementCollection::DiagonalUpRight = OffsetArray(1, -1);
const OffsetArray Spider_MovementCollection::Up_ThenLeft = OffsetArray(0, -1);
const OffsetArray Spider_MovementCollection::Up_ThenRight = OffsetArray(0, -1);
const OffsetArray Spider_MovementCollection::Down_ThenLeft = OffsetArray(0, 1);
const OffsetArray Spider_MovementCollection::Down_ThenRight = OffsetArray(0, 1);
