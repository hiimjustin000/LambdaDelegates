#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/SelectArtDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaSelectArtDelegate : public cocos2d::CCObject, public SelectArtDelegate {
public:
    std::function<void(SelectArtLayer*)> m_selectArtClosed;

    void selectArtClosed(SelectArtLayer* p0) override {
        return m_selectArtClosed(p0);
    }

    static LambdaSelectArtDelegate* create(
        std::function<void(SelectArtLayer*)> const& selectArtClosed = [](auto) {}
    ) {
        auto delegate = new LambdaSelectArtDelegate();
        delegate->m_selectArtClosed = selectArtClosed;
        delegate->autorelease();
        return delegate;
    }
};
