
#include <boost/signals2.hpp>
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WBrush.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WEnvironment.h>
#include <Wt/WEvent.h>
#include <Wt/WPaintDevice.h>
#include <Wt/WPaintedWidget.h>
#include <Wt/WPainter.h>
#include <Wt/WPen.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTextArea.h>
#include <Wt/WTabWidget.h>
#include <Wt/WMenuItem.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WMenu.h>


struct WtOtonanDialog : public Wt::WContainerWidget
{
    // create a dialag with 3 menus: saka, masehi, and notes
    WtOtonanDialog()
            : contents_(std::make_unique<Wt::WStackedWidget>())
    {
        //setContentAlignment(Wt::AlignmentFlag::Center);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalendar Bali."),
//                     "Bali", Wt::ContentLoading::Eager);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalender Masehi."),
//                     "Masehi", Wt::ContentLoading::Eager);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Catatan."),
//                     "Notes", Wt::ContentLoading::Eager);
//        tabW_->setStyleClass("Wt-tabs");
        auto menu = addNew<Wt::WMenu>(contents_.get());
        //menu->setStyleClass("nav nav-pills flex-row");
        menu->setWidth(150);
        menu->addItem("Saka", std::make_unique<Wt::WTextArea>("Saka"));
        menu->addItem("Masehi", std::make_unique<Wt::WTextArea>("Masehi"));
        menu->addItem("Notes", std::make_unique<Wt::WTextArea>("Notes"));
        addWidget(std::move(contents_));
    }
private:
    //Wt::WTabWidget*  tabW_;
    std::unique_ptr<Wt::WStackedWidget> contents_;
};

//---------------------------------------------------------------------------
struct WtOtonanApplication : public Wt::WApplication
{
    WtOtonanApplication(const Wt::WEnvironment& env)
            : Wt::WApplication(env)
    {
        setTitle("Kalendar Bali");
        setCssTheme("polished");
        //useStyleSheet("wt.css");
        root()->addWidget(std::make_unique<WtOtonanDialog>());
    }
};
//---------------------------------------------------------------------------
std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env)
{
    return std::make_unique<WtOtonanApplication>(env);
}
//---------------------------------------------------------------------------
int main(int argc, char **argv)
{
    return WRun(argc, argv, &createApplication);
}
