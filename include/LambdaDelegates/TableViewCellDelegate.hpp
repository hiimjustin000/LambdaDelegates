#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TableViewCellDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTableViewCellDelegate : public cocos2d::CCObject, public TableViewCellDelegate {
protected:
    std::function<bool(LambdaTableViewCellDelegate*, TableViewCell*, int, CellAction, cocos2d::CCNode*)> m_cellPerformedAction;
    std::function<int(LambdaTableViewCellDelegate*)> m_getSelectedCellIdx;
    std::function<bool(LambdaTableViewCellDelegate*)> m_shouldSnapToSelected;
    std::function<int(LambdaTableViewCellDelegate*)> m_getCellDelegateType;
public:
    bool cellPerformedAction(TableViewCell* p0, int p1, CellAction p2, cocos2d::CCNode* p3) override {
        if (m_cellPerformedAction) return m_cellPerformedAction(this, p0, p1, p2, p3);
        return false;
    }
    int getSelectedCellIdx() override {
        if (m_getSelectedCellIdx) return m_getSelectedCellIdx(this);
        return 0;
    }
    bool shouldSnapToSelected() override {
        if (m_shouldSnapToSelected) return m_shouldSnapToSelected(this);
        return true;
    }
    int getCellDelegateType() override {
        if (m_getCellDelegateType) return m_getCellDelegateType(this);
        return 0;
    }

    static LambdaTableViewCellDelegate* create(
        std::function<bool(LambdaTableViewCellDelegate*, TableViewCell*, int, CellAction, cocos2d::CCNode*)> const& cellPerformedAction = [](auto*, auto*, auto, auto, auto*) { return false; },
        std::function<int(LambdaTableViewCellDelegate*)> const& getSelectedCellIdx = [](auto*) { return 0; },
        std::function<bool(LambdaTableViewCellDelegate*)> const& shouldSnapToSelected = [](auto*) { return true; },
        std::function<int(LambdaTableViewCellDelegate*)> const& getCellDelegateType = [](auto*) { return 0; }
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
