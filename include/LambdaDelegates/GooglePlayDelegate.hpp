#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GooglePlayDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGooglePlayDelegate : public cocos2d::CCObject, public GooglePlayDelegate {
public:
    std::function<void()> m_googlePlaySignedIn;

    void googlePlaySignedIn() override {
        return m_googlePlaySignedIn();
    }

    static LambdaGooglePlayDelegate* create(
        std::function<void()> const& googlePlaySignedIn = []() {}
    ) {
        auto delegate = new LambdaGooglePlayDelegate();
        delegate->m_googlePlaySignedIn = googlePlaySignedIn;
        delegate->autorelease();
        return delegate;
    }
};
