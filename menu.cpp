#include "menu.h"

Menu::Menu()
{

}

void Menu::BeginGame()
{
    //say hello

}

void Menu::NewGame()
{

}

void Menu::EndGame()
{

}

void Menu::setKey(int key)
{

}

void Menu::SetThread(QThread &cThread)
{
    connect(&cThread, SIGNAL(started()), this, SLOT(Update()));
}

void Menu::Update()
{
    runner.Update(0);

}
