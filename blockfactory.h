#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

#include <QPixmap>
#include "Block.h"

enum class BlockType
{
    BLOCK1,
    BLOCK2,
    BLOCK3,
};

class BlockFactory
{
public:
    BlockFactory();
    static Block* GetBlock(BlockType type);
    static QPixmap GetDummyBlock(BlockType type);
private:
    static Block* CreateBlock(BlockType type);
};

#endif // BLOCKFACTORY_H
