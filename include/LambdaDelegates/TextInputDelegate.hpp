#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TextInputDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTextInputDelegate : public cocos2d::CCObject, public TextInputDelegate {
public:
    std::function<void(CCTextInputNode*)> m_textChanged;
    std::function<void(CCTextInputNode*)> m_textInputOpened;
    std::function<void(CCTextInputNode*)> m_textInputClosed;
    std::function<void(CCTextInputNode*, float)> m_textInputShouldOffset;
    std::function<void(CCTextInputNode*)> m_textInputReturn;
    std::function<bool(CCTextInputNode*)> m_allowTextInput;
    std::function<void(CCTextInputNode*)> m_enterPressed;

    void textChanged(CCTextInputNode* p0) override {
        if (m_textChanged) return m_textChanged(p0);
    }
    void textInputOpened(CCTextInputNode* p0) override {
        if (m_textInputOpened) return m_textInputOpened(p0);
    }
    void textInputClosed(CCTextInputNode* p0) override {
        if (m_textInputClosed) return m_textInputClosed(p0);
    }
    void textInputShouldOffset(CCTextInputNode* p0, float p1) override {
        if (m_textInputShouldOffset) return m_textInputShouldOffset(p0, p1);
    }
    void textInputReturn(CCTextInputNode* p0) override {
        if (m_textInputReturn) return m_textInputReturn(p0);
    }
    bool allowTextInput(CCTextInputNode* p0) override {
        if (m_allowTextInput) return m_allowTextInput(p0);
        return true;
    }
    void enterPressed(CCTextInputNode* p0) override {
        if (m_enterPressed) return m_enterPressed(p0);
    }

    static LambdaTextInputDelegate* create(
        std::function<void(CCTextInputNode*)> const& textChanged = [](auto) {},
        std::function<void(CCTextInputNode*)> const& textInputOpened = [](auto) {},
        std::function<void(CCTextInputNode*)> const& textInputClosed = [](auto) {},
        std::function<void(CCTextInputNode*, float)> const& textInputShouldOffset = [](auto, auto) {},
        std::function<void(CCTextInputNode*)> const& textInputReturn = [](auto) {},
        std::function<bool(CCTextInputNode*)> const& allowTextInput = [](auto) { return true; },
        std::function<void(CCTextInputNode*)> const& enterPressed = [](auto) {}
    ) {
        auto delegate = new LambdaTextInputDelegate();
        delegate->m_textChanged = textChanged;
        delegate->m_textInputOpened = textInputOpened;
        delegate->m_textInputClosed = textInputClosed;
        delegate->m_textInputShouldOffset = textInputShouldOffset;
        delegate->m_textInputReturn = textInputReturn;
        delegate->m_allowTextInput = allowTextInput;
        delegate->m_enterPressed = enterPressed;
        delegate->autorelease();
        return delegate;
    }
};
