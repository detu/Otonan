#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WDate.h>
#include <Wt/WCalendar.h>



class HelloApplication : public Wt::WApplication
{
public:
    HelloApplication(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit *nameEdit_;
    Wt::WText *greeting_;
};

HelloApplication::HelloApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env)
{
    Wt::WCalendar *c2 = root()->addNew<Wt::WCalendar>();
    c2->setSelectionMode(Wt::SelectionMode::Extended);

    Wt::WText* out = root()->addNew<Wt::WText>();
    out->addStyleClass("help-block");

    c2->selectionChanged().connect([=] {
        Wt::WString selected;
        std::set<Wt::WDate> selection = c2->selection();

        for (auto &date : c2->selection()) {
            if (!selected.empty())
                selected += ", ";

            selected += date.toString("dd/MM/yyyy");
        }

        out->setText(Wt::WString("<p>You selected the following dates: {1}</p>")
                             .arg(selected));
    });

    Wt::WText* today = root()->addNew<Wt::WText>();
    auto dateNow = Wt::WDate::currentDate();
    auto sdateNow = dateNow.toString("dd/MM/yyyy");
    today->setText(Wt::WString("<p> Today Gregorian calendar is: {1}</p>").arg(sdateNow));

    Wt::WText* todayBali = root()->addNew<Wt::WText>();
    todayBali->setText(Wt::WString("<p> Today Baliness calendar is: {1}</p>"));
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return std::make_unique<HelloApplication>(env);
    });
}