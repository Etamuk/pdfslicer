#ifndef SLICERVIEW_HPP
#define SLICERVIEW_HPP

#include "../backend/document.hpp"
#include "zoomlevelwithactions.hpp"
#include <gtkmm/flowbox.h>
#include <ctpl_stl.h>

namespace Slicer {

class View : public Gtk::FlowBox {
public:
    View(Gtk::ApplicationWindow& window, Document& document);
    virtual ~View();

    void waitForRenderCompletion();

private:
    Slicer::Document& m_document;
    std::unique_ptr<ctpl::thread_pool> m_pageRendererPool;
    Gtk::ApplicationWindow& m_window;

    ZoomLevelWithActions m_zoomLevel;
    static const std::set<int> zoomLevels;

    Glib::RefPtr<Gio::SimpleAction> m_removeSelectedAction;
    Glib::RefPtr<Gio::SimpleAction> m_removePreviousAction;
    Glib::RefPtr<Gio::SimpleAction> m_removeNextAction;
    Glib::RefPtr<Gio::SimpleAction> m_previewPageAction;

    void generateThumbnails(int targetThumbnailSize);
    void removeSelectedPage();
    void removePreviousPages();
    void removeNextPages();
    void previewPage();
};
}

#endif // SLICERVIEW_HPP
