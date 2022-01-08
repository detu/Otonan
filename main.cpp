
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

//---------------------------------------------------------------------------
struct WtTicTacToeApplication : public Wt::WApplication
{
    WtTicTacToeApplication(const Wt::WEnvironment& env)
            : Wt::WApplication(env)
    {
        setTitle("Thinking Wt 4: polishing a TicTacToe game");
        //useStyleSheet("wt.css");
        //root()->addWidget(std::make_unique<WtTicTacToeDialog>());
    }
};
//---------------------------------------------------------------------------
std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env)
{
    return std::make_unique<WtTicTacToeApplication>(env);
}
//---------------------------------------------------------------------------
int main(int argc, char **argv)
{
    return WRun(argc, argv, &createApplication);
}