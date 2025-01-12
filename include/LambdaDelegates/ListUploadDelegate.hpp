#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/ListUploadDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaListUploadDelegate : public cocos2d::CCObject, public ListUploadDelegate {
protected:
    std::function<void(LambdaListUploadDelegate*, GJLevelList*)> m_listUploadFinished;
    std::function<void(LambdaListUploadDelegate*, GJLevelList*, int)> m_listUploadFailed;
public:
    void listUploadFinished(GJLevelList* p0) override {
        if (m_listUploadFinished) return m_listUploadFinished(this, p0);
    }
    void listUploadFailed(GJLevelList* p0, int p1) override {
        if (m_listUploadFailed) return m_listUploadFailed(this, p0, p1);
    }

    static LambdaListUploadDelegate* create(
        std::function<void(LambdaListUploadDelegate*, GJLevelList*)> const& listUploadFinished = [](auto*, auto*) {},
        std::function<void(LambdaListUploadDelegate*, GJLevelList*, int)> const& listUploadFailed = [](auto*, auto*, auto) {}
    ) {
        auto delegate = new LambdaListUploadDelegate();
        delegate->m_listUploadFinished = listUploadFinished;
        delegate->m_listUploadFailed = listUploadFailed;
        delegate->autorelease();
        return delegate;
    }
};
