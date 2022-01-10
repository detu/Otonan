
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
#include <Wt/WNavigationBar.h>

struct WtOtonanDialog : public Wt::WContainerWidget
{
    // create a dialag with 3 menus: saka, masehi, and notes
    WtOtonanDialog()
            : contents_(nullptr),
              navBar_(nullptr)
    {
        //setContentAlignment(Wt::AlignmentFlag::Center);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalendar Bali."),
//                     "Bali", Wt::ContentLoading::Eager);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalender Masehi."),
//                     "Masehi", Wt::ContentLoading::Eager);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Catatan."),
//                     "Notes", Wt::ContentLoading::Eager);
//        tabW_->setStyleClass("Wt-tabs");
        //auto menu = addNew<Wt::WMenu>(contents_.get());
        //menu->setStyleClass("nav nav-pills flex-row");
//        menu->setWidth(150);
//        menu->addItem("Saka", std::make_unique<Wt::WTextArea>("Saka"));
//        menu->addItem("Masehi", std::make_unique<Wt::WTextArea>("Masehi"));
//        menu->addItem("Notes", std::make_unique<Wt::WTextArea>("Notes"));
//        addWidget(std::move(contents_));
        navBar_ = addNew<Wt::WNavigationBar>();
        navBar_->setResponsive(true);
        navBar_->addStyleClass("navbar-light bg-light");
        navBar_->setTitle("Otonan","https://www.google.com/search?q=otonan");

        contents_ = addNew<Wt::WStackedWidget>();
        contents_->addStyleClass("contents");

        auto leftMenu = std::make_unique<Wt::WMenu>(contents_);
        auto leftMenu_ = navBar_->addMenu(std::move(leftMenu));

        leftMenu_->addItem("Masehi", std::make_unique<Wt::WText>("Kalender Masehi"));
        leftMenu_->addItem("Saka", std::make_unique<Wt::WText>("Kalender Bali"));
        leftMenu_->addItem("Notes", std::make_unique<Wt::WText>("Reminder!"));
        leftMenu_->addStyleClass("me-auto");
    }
private:
    //Wt::WTabWidget*  tabW_;
    Wt::WStackedWidget *contents_;
    Wt::WNavigationBar *navBar_;
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
