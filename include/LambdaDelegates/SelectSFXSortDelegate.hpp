#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectSFXSortDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectSFXSortDelegate : public cocos2d::CCObject, public SelectSFXSortDelegate {
protected:
    std::function<void(LambdaSelectSFXSortDelegate*, SelectSFXSortLayer*)> m_sortSelectClosed;
public:
    void sortSelectClosed(SelectSFXSortLayer* p0) override {
        if (m_sortSelectClosed) return m_sortSelectClosed(this, p0);
    }

    static LambdaSelectSFXSortDelegate* create(
        std::function<void(LambdaSelectSFXSortDelegate*, SelectSFXSortLayer*)> const& sortSelectClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaSelectSFXSortDelegate();
        delegate->m_sortSelectClosed = sortSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
