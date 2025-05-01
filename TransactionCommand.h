#pragma once
#include <memory>

class TransactionCommand {
public:
    virtual ~TransactionCommand() = default;
    virtual void execute() = 0;
};