#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ListButtonBarDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaListButtonBarDelegate : public cocos2d::CCObject, public ListButtonBarDelegate {
protected:
    std::function<void(LambdaListButtonBarDelegate*, ListButtonBar*, int)> m_listButtonBarSwitchedPage;
public:
    void listButtonBarSwitchedPage(ListButtonBar* p0, int p1) override {
        if (m_listButtonBarSwitchedPage) return m_listButtonBarSwitchedPage(this, p0, p1);
    }

    static LambdaListButtonBarDelegate* create(
        std::function<void(LambdaListButtonBarDelegate*, ListButtonBar*, int)> const& listButtonBarSwitchedPage = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaListButtonBarDelegate();
        delegate->m_listButtonBarSwitchedPage = listButtonBarSwitchedPage;
        delegate->autorelease();
        return delegate;
    }
};
