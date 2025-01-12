#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/GooglePlayDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaGooglePlayDelegate : public cocos2d::CCObject, public GooglePlayDelegate {
protected:
    std::function<void(LambdaGooglePlayDelegate*)> m_googlePlaySignedIn;
public:
    void googlePlaySignedIn() override {
        if (m_googlePlaySignedIn) return m_googlePlaySignedIn(this);
    }

    static LambdaGooglePlayDelegate* create(
        std::function<void(LambdaGooglePlayDelegate*)> const& googlePlaySignedIn = [](auto*) {}
    ) {
        auto delegate = new LambdaGooglePlayDelegate();
        delegate->m_googlePlaySignedIn = googlePlaySignedIn;
        delegate->autorelease();
        return delegate;
    }
};
