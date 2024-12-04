#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/UserInfoDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaUserInfoDelegate : public cocos2d::CCObject, public UserInfoDelegate {
public:
    std::function<void(GJUserScore*)> m_getUserInfoFinished;
    std::function<void(int)> m_getUserInfoFailed;
    std::function<void(GJUserScore*)> m_userInfoChanged;

    void getUserInfoFinished(GJUserScore* p0) override {
        return m_getUserInfoFinished(p0);
    }
    void getUserInfoFailed(int p0) override {
        return m_getUserInfoFailed(p0);
    }
    void userInfoChanged(GJUserScore* p0) override {
        return m_userInfoChanged(p0);
    }

    static LambdaUserInfoDelegate* create(
        std::function<void(GJUserScore*)> const& getUserInfoFinished = [](auto) {},
        std::function<void(int)> const& getUserInfoFailed = [](auto) {},
        std::function<void(GJUserScore*)> const& userInfoChanged = [](auto) {}
    ) {
        auto delegate = new LambdaUserInfoDelegate();
        delegate->m_getUserInfoFinished = getUserInfoFinished;
        delegate->m_getUserInfoFailed = getUserInfoFailed;
        delegate->m_userInfoChanged = userInfoChanged;
        delegate->autorelease();
        return delegate;
    }
};
