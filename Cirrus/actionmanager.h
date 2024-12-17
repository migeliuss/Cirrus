#pragma once
#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <stack>
#include "action.h"

class ActionManager {
public:
    void executeAction(Action* action) {
        action->execute();
        undoStack.push(action);
        while (!redoStack.empty()) {
            delete redoStack.top();
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            Action* action = undoStack.top();
            action->undo();
            redoStack.push(action);
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            Action* action = redoStack.top();
            action->redo();
            undoStack.push(action);
            redoStack.pop();
        }
    }

    ~ActionManager() {
        while (!undoStack.empty()) {
            delete undoStack.top();
            undoStack.pop();
        }
        while (!redoStack.empty()) {
            delete redoStack.top();
            redoStack.pop();
        }
    }

private:
    std::stack<Action*> undoStack;
    std::stack<Action*> redoStack;
};

#endif // ACTIONMANAGER_H
