#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectSFXSortDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectSFXSortDelegate : public cocos2d::CCObject, public SelectSFXSortDelegate {
public:
    std::function<void(SelectSFXSortLayer*)> m_sortSelectClosed;

    void sortSelectClosed(SelectSFXSortLayer* p0) override {
        return m_sortSelectClosed(p0);
    }

    static LambdaSelectSFXSortDelegate* create(
        std::function<void(SelectSFXSortLayer*)> const& sortSelectClosed = [](auto) {}
    ) {
        auto delegate = new LambdaSelectSFXSortDelegate();
        delegate->m_sortSelectClosed = sortSelectClosed;
        delegate->autorelease();
        return delegate;
    }
};
