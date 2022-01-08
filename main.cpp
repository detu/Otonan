
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


struct WtOtonanDialog : public Wt::WContainerWidget
{
    // create a dialag with 3 tabs: saka, masehi, and notes
    WtOtonanDialog()
            : tabW_(addWidget(std::make_unique<Wt::WTabWidget>()))
    {
        setContentAlignment(Wt::AlignmentFlag::Center);
        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalendar Bali."),
                     "Bali", Wt::ContentLoading::Eager);
        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalender Masehi."),
                     "Masehi", Wt::ContentLoading::Eager);
        tabW_->addTab(std::make_unique<Wt::WTextArea>("Catatan."),
                     "Notes", Wt::ContentLoading::Eager);
        auto *tab= tabW_->addTab(std::make_unique<Wt::WTextArea>("Tutup."),
                               "Close");
        tab->setCloseable(true);
        tabW_->setStyleClass("tabwidget");

    }
private:
    Wt::WTabWidget*  tabW_;
};

//---------------------------------------------------------------------------
struct WtOtonanApplication : public Wt::WApplication
{
    WtOtonanApplication(const Wt::WEnvironment& env)
            : Wt::WApplication(env)
    {
        setTitle("Kalendar Bali");
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
