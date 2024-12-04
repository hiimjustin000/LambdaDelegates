#pragma once
#include <functional>
#include <cocos2d.h>
#include <Geode/binding/TableViewDataSource.hpp>
#include <Geode/Enums.hpp>
#include <Geode/GeneratedPredeclare.hpp>

class LambdaTableViewDataSource : public cocos2d::CCObject, public TableViewDataSource {
public:
    std::function<int(unsigned int, TableView*)> m_numberOfRowsInSection;
    std::function<unsigned int(TableView*)> m_numberOfSectionsInTableView;
    std::function<void(TableView*, TableViewCellEditingStyle, CCIndexPath&)> m_TableViewCommitCellEditingStyleForRowAtIndexPath;
    std::function<TableViewCell*(CCIndexPath&, TableView*)> m_cellForRowAtIndexPath;

    int numberOfRowsInSection(unsigned int p0, TableView* p1) override {
        return m_numberOfRowsInSection(p0, p1);
    }
    unsigned int numberOfSectionsInTableView(TableView* p0) override {
        return m_numberOfSectionsInTableView(p0);
    }
    void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* p0, TableViewCellEditingStyle p1, CCIndexPath& p2) override {
        return m_TableViewCommitCellEditingStyleForRowAtIndexPath(p0, p1, p2);
    }
    TableViewCell* cellForRowAtIndexPath(CCIndexPath& p0, TableView* p1) override {
        return m_cellForRowAtIndexPath(p0, p1);
    }

    static LambdaTableViewDataSource* create(
        std::function<int(unsigned int, TableView*)> const& numberOfRowsInSection,
        std::function<unsigned int(TableView*)> const& numberOfSectionsInTableView/* = [](auto) { return 1; }*/,
        std::function<void(TableView*, TableViewCellEditingStyle, CCIndexPath&)> const& TableViewCommitCellEditingStyleForRowAtIndexPath/* = [](auto, auto, auto) {}*/,
        std::function<TableViewCell*(CCIndexPath&, TableView*)> const& cellForRowAtIndexPath
    ) {
        auto delegate = new LambdaTableViewDataSource();
        delegate->m_numberOfRowsInSection = numberOfRowsInSection;
        delegate->m_numberOfSectionsInTableView = numberOfSectionsInTableView;
        delegate->m_TableViewCommitCellEditingStyleForRowAtIndexPath = TableViewCommitCellEditingStyleForRowAtIndexPath;
        delegate->m_cellForRowAtIndexPath = cellForRowAtIndexPath;
        delegate->autorelease();
        return delegate;
    }
};
