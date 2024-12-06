#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TableViewDelegate.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTableViewDelegate : public cocos2d::CCObject, public TableViewDelegate {
public:
    std::function<void(CCIndexPath&, TableViewCell*, TableView*)> m_willTweenToIndexPath;
    std::function<void(CCIndexPath&, TableView*)> m_didEndTweenToIndexPath;
    std::function<void(CCIndexPath&, TableViewCell*, TableView*)> m_TableViewWillDisplayCellForRowAtIndexPath;
    std::function<void(CCIndexPath&, TableViewCell*, TableView*)> m_TableViewDidDisplayCellForRowAtIndexPath;
    std::function<void(CCIndexPath&, TableViewCell*, TableView*)> m_TableViewWillReloadCellForRowAtIndexPath;
    std::function<float(CCIndexPath&, TableView*)> m_cellHeightForRowAtIndexPath;
    std::function<void(CCIndexPath&, TableView*)> m_didSelectRowAtIndexPath;

    void willTweenToIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) override {
        if (m_willTweenToIndexPath) return m_willTweenToIndexPath(p0, p1, p2);
    }
    void didEndTweenToIndexPath(CCIndexPath& p0, TableView* p1) override {
        if (m_didEndTweenToIndexPath) return m_didEndTweenToIndexPath(p0, p1);
    }
    void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) override {
        if (m_TableViewWillDisplayCellForRowAtIndexPath) return m_TableViewWillDisplayCellForRowAtIndexPath(p0, p1, p2);
    }
    void TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) override {
        if (m_TableViewDidDisplayCellForRowAtIndexPath) return m_TableViewDidDisplayCellForRowAtIndexPath(p0, p1, p2);
    }
    void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) override {
        if (m_TableViewWillReloadCellForRowAtIndexPath) return m_TableViewWillReloadCellForRowAtIndexPath(p0, p1, p2);
    }
    float cellHeightForRowAtIndexPath(CCIndexPath& p0, TableView* p1) override {
        if (m_cellHeightForRowAtIndexPath) return m_cellHeightForRowAtIndexPath(p0, p1);
        throw std::runtime_error("Lambda Delegates: TableViewDelegate::cellHeightForRowAtIndexPath not implemented");
    }
    void didSelectRowAtIndexPath(CCIndexPath& p0, TableView* p1) override {
        if (m_didSelectRowAtIndexPath) return m_didSelectRowAtIndexPath(p0, p1);
        throw std::runtime_error("Lambda Delegates: TableViewDelegate::didSelectRowAtIndexPath not implemented");
    }

    static LambdaTableViewDelegate* create(
        std::function<void(CCIndexPath&, TableViewCell*, TableView*)> const& willTweenToIndexPath/* = [](auto, auto, auto) {}*/,
        std::function<void(CCIndexPath&, TableView*)> const& didEndTweenToIndexPath/* = [](auto, auto) {}*/,
        std::function<void(CCIndexPath&, TableViewCell*, TableView*)> const& TableViewWillDisplayCellForRowAtIndexPath/* = [](auto, auto, auto) {}*/,
        std::function<void(CCIndexPath&, TableViewCell*, TableView*)> const& TableViewDidDisplayCellForRowAtIndexPath/* = [](auto, auto, auto) {}*/,
        std::function<void(CCIndexPath&, TableViewCell*, TableView*)> const& TableViewWillReloadCellForRowAtIndexPath/* = [](auto, auto, auto) {}*/,
        std::function<float(CCIndexPath&, TableView*)> const& cellHeightForRowAtIndexPath,
        std::function<void(CCIndexPath&, TableView*)> const& didSelectRowAtIndexPath
    ) {
        auto delegate = new LambdaTableViewDelegate();
        delegate->m_willTweenToIndexPath = willTweenToIndexPath;
        delegate->m_didEndTweenToIndexPath = didEndTweenToIndexPath;
        delegate->m_TableViewWillDisplayCellForRowAtIndexPath = TableViewWillDisplayCellForRowAtIndexPath;
        delegate->m_TableViewDidDisplayCellForRowAtIndexPath = TableViewDidDisplayCellForRowAtIndexPath;
        delegate->m_TableViewWillReloadCellForRowAtIndexPath = TableViewWillReloadCellForRowAtIndexPath;
        delegate->m_cellHeightForRowAtIndexPath = cellHeightForRowAtIndexPath;
        delegate->m_didSelectRowAtIndexPath = didSelectRowAtIndexPath;
        delegate->autorelease();
        return delegate;
    }
};
