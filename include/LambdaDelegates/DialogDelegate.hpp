#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/DialogDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaDialogDelegate : public cocos2d::CCObject, public DialogDelegate {
protected:
    std::function<void(LambdaDialogDelegate*, DialogLayer*)> m_dialogClosed;
public:
    void dialogClosed(DialogLayer* p0) override {
        if (m_dialogClosed) return m_dialogClosed(this, p0);
    }

    static LambdaDialogDelegate* create(
        std::function<void(LambdaDialogDelegate*, DialogLayer*)> const& dialogClosed = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaDialogDelegate();
        delegate->m_dialogClosed = dialogClosed;
        delegate->autorelease();
        return delegate;
    }
};
