#include "connectiontable.h"
#include "ui_connectiontable.h"

ConnectionTable::ConnectionTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionTable)
{
    ui->setupUi(this);
    //get rid of the default question mark button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

ConnectionTable::~ConnectionTable()
{
    delete ui;
}

//This function browses for pictures and replaces it with the old one, I tried to save it to the database but did not have time
//to finish.
void ConnectionTable::on_pushButtonAdvancedSearch_clicked()
{
    string filepath = QFileDialog::getOpenFileName(
                this,
                "Search for images",
                "",
                "Image files (*png *jpg"
                ).toStdString();
    if (filepath.length())
    {
        QPixmap pixmap(QString::fromStdString(filepath));
        ui->labelPixMap->setPixmap(pixmap);
        _map = pixmap;
    }

    QByteArray bitArray;
    QBuffer buffer(&bitArray);
    buffer.open(QIODevice::WriteOnly);
    _map.save(&buffer, "PNG");
    _list.returnBitArry(bitArray);
}

//Displays picture and bio for scientist with corresponding id
void ConnectionTable::display(int id)
{
    QByteArray myArray = _list.searchScientistPicture(id);
    //This if function finds right bio with id
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
    else
    {
        ui->textBrowserAdvancedSearch->setText("<span style=' color: red'> No bio is available. </span>");
    }

    //If there is no photo, automatic photo will be displayed
    if (myArray.size() != 0)
    {
        QPixmap photo;
        photo.loadFromData(myArray);
        //Scales photo and inputs into textlabel
        ui->labelPixMap->setPixmap(photo.scaled(100, 500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        ui->labelPixMap->setScaledContents(true);
    }
    else
    {
        QPixmap pixmap(":/Icons/Pictures/noPhotoAvailable.png");
        ui->labelPixMap->setPixmap(pixmap.scaled(300, 300, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
}
