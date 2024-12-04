#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ListUploadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaListUploadDelegate : public cocos2d::CCObject, public ListUploadDelegate {
public:
    std::function<void(GJLevelList*)> m_listUploadFinished;
    std::function<void(GJLevelList*, int)> m_listUploadFailed;

    void listUploadFinished(GJLevelList* p0) override {
        return m_listUploadFinished(p0);
    }
    void listUploadFailed(GJLevelList* p0, int p1) override {
        return m_listUploadFailed(p0, p1);
    }

    static LambdaListUploadDelegate* create(
        std::function<void(GJLevelList*)> const& listUploadFinished = [](auto) {},
        std::function<void(GJLevelList*, int)> const& listUploadFailed = [](auto, auto) {}
    ) {
        auto delegate = new LambdaListUploadDelegate();
        delegate->m_listUploadFinished = listUploadFinished;
        delegate->m_listUploadFailed = listUploadFailed;
        delegate->autorelease();
        return delegate;
    }
};
