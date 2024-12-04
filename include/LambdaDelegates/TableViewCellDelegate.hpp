#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TableViewCellDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTableViewCellDelegate : public cocos2d::CCObject, public TableViewCellDelegate {
public:
    std::function<bool(TableViewCell*, int, CellAction, cocos2d::CCNode*)> m_cellPerformedAction;
    std::function<int()> m_getSelectedCellIdx;
    std::function<bool()> m_shouldSnapToSelected;
    std::function<int()> m_getCellDelegateType;

    bool cellPerformedAction(TableViewCell* p0, int p1, CellAction p2, cocos2d::CCNode* p3) override {
        return m_cellPerformedAction(p0, p1, p2, p3);
    }
    int getSelectedCellIdx() override {
        return m_getSelectedCellIdx();
    }
    bool shouldSnapToSelected() override {
        return m_shouldSnapToSelected();
    }
    int getCellDelegateType() override {
        return m_getCellDelegateType();
    }

    static LambdaTableViewCellDelegate* create(
        std::function<bool(TableViewCell*, int, CellAction, cocos2d::CCNode*)> const& cellPerformedAction = [](auto, auto, auto, auto) { return false; },
        std::function<int()> const& getSelectedCellIdx = []() { return 0; },
        std::function<bool()> const& shouldSnapToSelected = []() { return true; },
        std::function<int()> const& getCellDelegateType = []() { return 0; }
    ) {
        auto delegate = new LambdaTableViewCellDelegate();
        delegate->m_cellPerformedAction = cellPerformedAction;
        delegate->m_getSelectedCellIdx = getSelectedCellIdx;
        delegate->m_shouldSnapToSelected = shouldSnapToSelected;
        delegate->m_getCellDelegateType = getCellDelegateType;
        delegate->autorelease();
        return delegate;
    }
};
