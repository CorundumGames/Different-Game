#ifndef SCOREKEEPER_H_
#define SCOREKEEPER_H_

#include "Declarations.h"
#include "Visible.h"
#include <sstream>
#include <string>

class ScoreKeeper : public Visible
{
    public:
        ScoreKeeper();

        TextDisplay& getText();
        void updateText();
    private:
        TextDisplay text;
        std::stringstream scoreconverter;

};

#endif // SCOREKEEPER_H_