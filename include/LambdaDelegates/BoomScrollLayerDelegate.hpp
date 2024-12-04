#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/BoomScrollLayerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaBoomScrollLayerDelegate : public cocos2d::CCObject, public BoomScrollLayerDelegate {
public:
    std::function<void(BoomScrollLayer*)> m_scrollLayerScrollingStarted;
    std::function<void(BoomScrollLayer*, int)> m_scrollLayerScrolledToPage;
    std::function<void(cocos2d::CCPoint)> m_scrollLayerMoved;
    std::function<void(BoomScrollLayer*, int)> m_scrollLayerWillScrollToPage;

    void scrollLayerScrollingStarted(BoomScrollLayer* p0) override {
        return m_scrollLayerScrollingStarted(p0);
    }
    void scrollLayerScrolledToPage(BoomScrollLayer* p0, int p1) override {
        return m_scrollLayerScrolledToPage(p0, p1);
    }
    void scrollLayerMoved(cocos2d::CCPoint p0) override {
        return m_scrollLayerMoved(p0);
    }
    void scrollLayerWillScrollToPage(BoomScrollLayer* p0, int p1) override {
        return m_scrollLayerWillScrollToPage(p0, p1);
    }

    static LambdaBoomScrollLayerDelegate* create(
        std::function<void(BoomScrollLayer*)> const& scrollLayerScrollingStarted = [](auto) {},
        std::function<void(BoomScrollLayer*, int)> const& scrollLayerScrolledToPage = [](auto, auto) {},
        std::function<void(cocos2d::CCPoint)> const& scrollLayerMoved = [](auto) {},
        std::function<void(BoomScrollLayer*, int)> const& scrollLayerWillScrollToPage = [](auto, auto) {}
    ) {
        auto delegate = new LambdaBoomScrollLayerDelegate();
        delegate->m_scrollLayerScrollingStarted = scrollLayerScrollingStarted;
        delegate->m_scrollLayerScrolledToPage = scrollLayerScrolledToPage;
        delegate->m_scrollLayerMoved = scrollLayerMoved;
        delegate->m_scrollLayerWillScrollToPage = scrollLayerWillScrollToPage;
        delegate->autorelease();
        return delegate;
    }
};
