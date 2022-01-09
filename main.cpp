
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
#include <Wt/WCalendar.h>


struct WtOtonanDialog : public Wt::WContainerWidget
{
    // create a dialag with 3 tabs: saka, masehi, and notes
    WtOtonanDialog()
            : cal_(addNew<Wt::WCalendar>())
    {
        setContentAlignment(Wt::AlignmentFlag::Center);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalendar Bali."),
//                     "Bali", Wt::ContentLoading::Eager);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Kalender Masehi."),
//                     "Masehi", Wt::ContentLoading::Eager);
//        tabW_->addTab(std::make_unique<Wt::WTextArea>("Catatan."),
//                     "Notes", Wt::ContentLoading::Eager);
//        tabW_->setStyleClass("Wt-tabs");
        auto out = addNew<Wt::WText>();
        out->addStyleClass("help-block");

        cal_->selectionChanged().connect([=] {
            std::set<Wt::WDate> selection = cal_->selection();
            if (selection.size() != 0) {
                Wt::WDate d;
                d = (*selection.begin());
                Wt::WDate toDate(d.year() + 1, 1, 1);
                int days = d.daysTo(toDate);
                out->setText(Wt::WString("<p>That's {1} days until New Year's Day!</p>")
                                     .arg(days));
            }
        });

    }
private:
    //Wt::WTabWidget*  tabW_;
    Wt::WCalendar* cal_;
};

//---------------------------------------------------------------------------
struct WtOtonanApplication : public Wt::WApplication
{
    WtOtonanApplication(const Wt::WEnvironment& env)
            : Wt::WApplication(env)
    {
        setTitle("Kalendar Bali");
        useStyleSheet("wt.css");
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
