#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectArtDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectArtDelegate : public cocos2d::CCObject, public SelectArtDelegate {
protected:
    std::function<void(LambdaSelectArtDelegate*, SelectArtLayer*)> m_selectArtClosed;
public:
    void selectArtClosed(SelectArtLayer* p0) override {
        if (m_selectArtClosed) return m_selectArtClosed(this, p0);
    }

    static LambdaSelectArtDelegate* create(
        std::function<void(LambdaSelectArtDelegate*, SelectArtLayer*)> const& selectArtClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaSelectArtDelegate();
        delegate->m_selectArtClosed = selectArtClosed;
        delegate->autorelease();
        return delegate;
    }
};
