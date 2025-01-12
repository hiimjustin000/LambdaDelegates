#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UserInfoDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUserInfoDelegate : public cocos2d::CCObject, public UserInfoDelegate {
protected:
    std::function<void(LambdaUserInfoDelegate*, GJUserScore*)> m_getUserInfoFinished;
    std::function<void(LambdaUserInfoDelegate*, int)> m_getUserInfoFailed;
    std::function<void(LambdaUserInfoDelegate*, GJUserScore*)> m_userInfoChanged;
public:
    void getUserInfoFinished(GJUserScore* p0) override {
        if (m_getUserInfoFinished) return m_getUserInfoFinished(this, p0);
    }
    void getUserInfoFailed(int p0) override {
        if (m_getUserInfoFailed) return m_getUserInfoFailed(this, p0);
    }
    void userInfoChanged(GJUserScore* p0) override {
        if (m_userInfoChanged) return m_userInfoChanged(this, p0);
    }

    static LambdaUserInfoDelegate* create(
        std::function<void(LambdaUserInfoDelegate*, GJUserScore*)> const& getUserInfoFinished = [](auto*, auto*) {},
        std::function<void(LambdaUserInfoDelegate*, int)> const& getUserInfoFailed = [](auto*, auto) {},
        std::function<void(LambdaUserInfoDelegate*, GJUserScore*)> const& userInfoChanged = [](auto*, auto*) {}
    ) {
        auto delegate = new LambdaUserInfoDelegate();
        delegate->m_getUserInfoFinished = getUserInfoFinished;
        delegate->m_getUserInfoFailed = getUserInfoFailed;
        delegate->m_userInfoChanged = userInfoChanged;
        delegate->autorelease();
        return delegate;
    }
};
