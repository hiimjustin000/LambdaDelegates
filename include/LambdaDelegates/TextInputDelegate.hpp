#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TextInputDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTextInputDelegate : public cocos2d::CCObject, public TextInputDelegate {
protected:
    std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> m_textChanged;
    std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> m_textInputOpened;
    std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> m_textInputClosed;
    std::function<void(LambdaTextInputDelegate*, CCTextInputNode*, float)> m_textInputShouldOffset;
    std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> m_textInputReturn;
    std::function<bool(LambdaTextInputDelegate*, CCTextInputNode*)> m_allowTextInput;
    std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> m_enterPressed;
public:
    void textChanged(CCTextInputNode* p0) override {
        if (m_textChanged) return m_textChanged(this, p0);
    }
    void textInputOpened(CCTextInputNode* p0) override {
        if (m_textInputOpened) return m_textInputOpened(this, p0);
    }
    void textInputClosed(CCTextInputNode* p0) override {
        if (m_textInputClosed) return m_textInputClosed(this, p0);
    }
    void textInputShouldOffset(CCTextInputNode* p0, float p1) override {
        if (m_textInputShouldOffset) return m_textInputShouldOffset(this, p0, p1);
    }
    void textInputReturn(CCTextInputNode* p0) override {
        if (m_textInputReturn) return m_textInputReturn(this, p0);
    }
    bool allowTextInput(CCTextInputNode* p0) override {
        if (m_allowTextInput) return m_allowTextInput(this, p0);
        return true;
    }
    void enterPressed(CCTextInputNode* p0) override {
        if (m_enterPressed) return m_enterPressed(this, p0);
    }

    static LambdaTextInputDelegate* create(
        std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> const& textChanged = [](auto*, auto*) {},
        std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> const& textInputOpened = [](auto*, auto*) {},
        std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> const& textInputClosed = [](auto*, auto*) {},
        std::function<void(LambdaTextInputDelegate*, CCTextInputNode*, float)> const& textInputShouldOffset = [](auto*, auto*, auto) {},
        std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> const& textInputReturn = [](auto*, auto*) {},
        std::function<bool(LambdaTextInputDelegate*, CCTextInputNode*)> const& allowTextInput = [](auto*, auto*) { return true; },
        std::function<void(LambdaTextInputDelegate*, CCTextInputNode*)> const& enterPressed = [](auto*, auto*) {}
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
