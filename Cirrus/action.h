#pragma once

class Action {
public:
    virtual ~Action() = default;

    virtual void execute() = 0;

    virtual void undo() = 0;

    virtual void redo() = 0;
};