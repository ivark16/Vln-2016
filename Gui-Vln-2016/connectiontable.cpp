#include "connectiontable.h"
#include "ui_connectiontable.h"

ConnectionTable::ConnectionTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionTable)
{
    ui->setupUi(this);
}

ConnectionTable::~ConnectionTable()
{
    delete ui;
}

void ConnectionTable::on_pushButtonAdvancedSearch_clicked()
{

    int id = ui->lineEditAdvancedSearch->text().toInt();
    QByteArray myArray = _list.searchScientistPicture(id);

    if (id == 2)
    {
        ui->textBrowserAdvancedSearch->setText("Augusta Ada King-Noel, Countess of Lovelace was an English Mathematical and writer, chiefly known for her work on Charles Babbage's early machanical general-purpose computer, the Analytical Engine."
                                               "Ada died at the age of 36 from uterine cancer probably exacerbated by bloodletting by her physicians.");
    }
    else if (id == 4)
    {
        ui->textBrowserAdvancedSearch->setText("Adele Goldstine was an American computer programmer who wrote the complete technical description for the first electrinic digital computer, ENIAC. "
                                               "Through her work programming the computer, she was also an instrumental player in converting the ENIAC from a computer that needed to be reprogrammed each "
                                               "time it was used to one that was able to perform a set of fifty stored instructions. She died of canser at the age of 43 in 1964");
    }
    else if (id == 5)
    {
        ui->textBrowserAdvancedSearch->setText("Frances Elizabeth 'Betty' Holberton was one of the six original programmers of ENIAC, "
                                               "the first general-purpose electrinc dygital computer. During World War II she was hired by "
                                               "the Moore School of Engineering to work as a 'computor', and was after thart chosen to be one "
                                               "of the six. She died in 2001 at the age of 84 due to heart disease.");
    }
    else if (id == 6)
    {
        ui->textBrowserAdvancedSearch->setText("Sophie Wilson is a British computer scientist and a software engineer. "
                                               "She designed the Acorn Micro-Computer, the first of a long line of computers sold by Acorn Computers Ltd. "
                                               "She later designed the instruction set of the ARM Pressor, which became the de facto model udes in 21-st "
                                               "century smartphones.");
    }
    else if (id == 7)
    {
        ui->textBrowserAdvancedSearch->setText("Dr. Erna Schneider Hoover is an American mathematician notable for inventing a computerized telephone "
                                               "switching method which 'revolutionized modern communication' according to several reports. It prevented "
                                               "system overloads by monitoring call center traffic and prioritizing tasks on phone switching systems to "
                                               "enable more robust service during peak calling times. At Bell Laboratories where she worked for over 32 years, "
                                               "Hoover was described as an important pioneer for women in the field of computer technology.");
    }
    else if (id == 8)
    {
        ui->textBrowserAdvancedSearch->setText("Alan Mathison Turing is often known as the father of computer sciense. He was an Englsish mathmatician and a "
                                               "theoratical biologist amongst other things. He was highly influential in the development of theoretical computer science, "
                                               "providing a formalisation of the concepts of algorithm and computation with the Turing machine, which can be considered a "
                                               "model of a general purpose computer."
                                               "Turing was found guilty of homosexuality in 1952. He then died in 1954, 16 days before his 42nd birthday");
    }
    else if (id == 9)
    {
        ui->textBrowserAdvancedSearch->setText("Charles Babbage was an English Polymath. A mathematician, philosopher, inventor and machenical engineer. "
                                               "He is best remembered for originating the concept of a programmable computer. He is often considered to be a "
                                               "father of the computer. Parts of Babbage's uncomplete mechanisms are in display in the Science Museum in London. "
                                               "He died at the age of 79 in 1971.");
    }
    else if (id == 10)
    {
        ui->textBrowserAdvancedSearch->setText("Maurice Wilkes was a British computer scientist credited with several important developments in computing. "
                                               "In 1945, Wilkes was appointed as the second director of the University of Cambridge Mathematical Laboratory "
                                               "(later known as the Computer Laboratory. At the time of his death in 2010, Wilkes was an Emeritus Professor "
                                               "of the University of Cambridge.");
    }
    else if (id == 11)
    {
        ui->textBrowserAdvancedSearch->setText("John Vincent Atansoff was an American physicist and inventor, best known for being credited with inventing "
                                               "the first electronic digital computer. He invented the Atansoff-Berry-Computer (ABC) in the 1930s. "
                                               "He died at the age of 91 in 1995.");
    }
    else if (id == 12)
    {
        ui->textBrowserAdvancedSearch->setText("John Mauchly was an American physicist who, along with J. Presper Eckert, designed ENIAC, "
                                               "the first general purpose electronic digital computer ENIAC, as well as EDVAC, BINAC and "
                                               "UNIVAC I, the first commercial computer made in the United States. "
                                               "He died in 1980 at the age of 72.");
    }
    else if (id == 13)
    {
        ui->textBrowserAdvancedSearch->setText("John Adam Presper 'Pres' Eckert, Jr was an Americal electrical engineer and computer pioneer. "
                                               "With John Mauchly he invented the first general-purpose electronic digital "
                                               "computer ENIAC. He presented the first course in computing topics and designed the f"
                                               "irst commercial computer in the U.S., the UNIVAC, which incorporated Eckert's invention "
                                               "of the mercury delay line memory. He died at the age of 76 in 1995.");
    }
    else if (id == 14)
    {
        ui->textBrowserAdvancedSearch->setText("Clifford Berry helped John Vincent Atansoff create the first electronic computer in 1939, "
                                               "the Atanasoff–Berry computer (ABC). He died in 1963 at the age of 45.");
    }

    if (myArray.size() != 0)
    {
        QPixmap photo;       
        photo.loadFromData(myArray);
        ui->labelPixMap->setPixmap(photo.scaled(100, 500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        ui->labelPixMap->setScaledContents(true);
    }
    else
    {
        ui->labelPixMap->setText("<span style=' color: red'> Sorry, no scientist found. </span>");
    }

}

void ConnectionTable::display(int id)
{
    QByteArray myArray = _list.searchScientistPicture(id);

    if (id == 2)
    {
        ui->textBrowserAdvancedSearch->setText("ada");
    }

    if (myArray.size() != 0)
    {
        QPixmap photo;
        photo.loadFromData(myArray);
        ui->labelPixMap->setPixmap(photo.scaled(100, 500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        ui->labelPixMap->setScaledContents(true);
    }
    else
    {
        ui->labelPixMap->setText("<span style=' color: red'> Sorry, no scientist found. </span>");
    }

}

