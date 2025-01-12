#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/BoomScrollLayerDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaBoomScrollLayerDelegate : public cocos2d::CCObject, public BoomScrollLayerDelegate {
protected:
    std::function<void(LambdaBoomScrollLayerDelegate*, BoomScrollLayer*)> m_scrollLayerScrollingStarted;
    std::function<void(LambdaBoomScrollLayerDelegate*, BoomScrollLayer*, int)> m_scrollLayerScrolledToPage;
    std::function<void(LambdaBoomScrollLayerDelegate*, cocos2d::CCPoint)> m_scrollLayerMoved;
    std::function<void(LambdaBoomScrollLayerDelegate*, BoomScrollLayer*, int)> m_scrollLayerWillScrollToPage;
public:
    void scrollLayerScrollingStarted(BoomScrollLayer* p0) override {
        if (m_scrollLayerScrollingStarted) return m_scrollLayerScrollingStarted(this, p0);
    }
    void scrollLayerScrolledToPage(BoomScrollLayer* p0, int p1) override {
        if (m_scrollLayerScrolledToPage) return m_scrollLayerScrolledToPage(this, p0, p1);
    }
    void scrollLayerMoved(cocos2d::CCPoint p0) override {
        if (m_scrollLayerMoved) return m_scrollLayerMoved(this, p0);
    }
    void scrollLayerWillScrollToPage(BoomScrollLayer* p0, int p1) override {
        if (m_scrollLayerWillScrollToPage) return m_scrollLayerWillScrollToPage(this, p0, p1);
    }

    static LambdaBoomScrollLayerDelegate* create(
        std::function<void(LambdaBoomScrollLayerDelegate*, BoomScrollLayer*)> const& scrollLayerScrollingStarted = [](auto*, auto*) {},
        std::function<void(LambdaBoomScrollLayerDelegate*, BoomScrollLayer*, int)> const& scrollLayerScrolledToPage = [](auto*, auto*, auto) {},
        std::function<void(LambdaBoomScrollLayerDelegate*, cocos2d::CCPoint)> const& scrollLayerMoved = [](auto*, auto) {},
        std::function<void(LambdaBoomScrollLayerDelegate*, BoomScrollLayer*, int)> const& scrollLayerWillScrollToPage = [](auto*, auto*, auto) {}
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
