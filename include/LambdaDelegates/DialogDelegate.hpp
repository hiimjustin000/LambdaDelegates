#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DialogDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDialogDelegate : public cocos2d::CCObject, public DialogDelegate {
public:
    std::function<void(DialogLayer*)> m_dialogClosed;

    void dialogClosed(DialogLayer* p0) override {
        return m_dialogClosed(p0);
    }

    static LambdaDialogDelegate* create(
        std::function<void(DialogLayer*)> const& dialogClosed = [](auto) {}
    ) {
        auto delegate = new LambdaDialogDelegate();
        delegate->m_dialogClosed = dialogClosed;
        delegate->autorelease();
        return delegate;
    }
};
