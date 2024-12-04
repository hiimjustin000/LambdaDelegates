#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TextAreaDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTextAreaDelegate : public cocos2d::CCObject, public TextAreaDelegate {
public:
    std::function<void(TextArea*)> m_fadeInTextFinished;

    void fadeInTextFinished(TextArea* p0) override {
        return m_fadeInTextFinished(p0);
    }

    static LambdaTextAreaDelegate* create(
        std::function<void(TextArea*)> const& fadeInTextFinished = [](auto) {}
    ) {
        auto delegate = new LambdaTextAreaDelegate();
        delegate->m_fadeInTextFinished = fadeInTextFinished;
        delegate->autorelease();
        return delegate;
    }
};
