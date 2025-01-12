#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TextAreaDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTextAreaDelegate : public cocos2d::CCObject, public TextAreaDelegate {
protected:
    std::function<void(LambdaTextAreaDelegate*, TextArea*)> m_fadeInTextFinished;
public:
    void fadeInTextFinished(TextArea* p0) override {
        if (m_fadeInTextFinished) return m_fadeInTextFinished(this, p0);
    }

    static LambdaTextAreaDelegate* create(
        std::function<void(LambdaTextAreaDelegate*, TextArea*)> const& fadeInTextFinished = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaTextAreaDelegate();
        delegate->m_fadeInTextFinished = fadeInTextFinished;
        delegate->autorelease();
        return delegate;
    }
};
