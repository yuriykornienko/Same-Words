#include <string>
#include "sameWordsAnalyzer.h"

sameWordsAnalyzer::sameWordsAnalyzer(logger log) : log(log) {}

sameWordsAnalyzer::~sameWordsAnalyzer()
{
    if (ofs.is_open()) {
        ofs.close();
    }
    if (ifs.is_open()) {
        ifs.close();
    }
}

void sameWordsAnalyzer::createListFromFile(const std::string path, char separator)
{
    log.log("Начало работы приложения ");

    try
    {
        ifs.open(path);
        if (!ifs)
            throw std::runtime_error("Ошибка при открытии файла " + path);

        std::string word;
        while (getline(ifs, word, separator))
            mylist.pushBack(word);
        mylist.sort();

        ifs.close();
        log.log("Коллекция слов успешно создана ");
    }
    catch (const std::exception& e)
    {
        log.log("Возникла ошибка: " + std::string(e.what()));
    }
}

void sameWordsAnalyzer::createReportFile(const std::string path)
{
    list::Node* current;
    if ((current = mylist.getHead()) == nullptr)
    {
        log.log("Попытка создать отчет из пустых данных ");
        return;
    }

    try
    {
        ofs.open(path);
        if (!ofs)
            throw std::runtime_error("Ошибка при открытии файла " + path);

        while (current != nullptr)
        {
            std::string validstr = current->count > 1 && current->count < 5 ? " раза." : " раз.";

            ofs << "Слово " << current->value << " встречается " << current->count << validstr << std::endl;
            current = current->next;
        }

        ofs.close();
        log.log("Программа успешно отработала, был создан файл " + path);
    }
    catch (const std::exception& e)
    {
        log.log("Возникла ошибка: " + std::string(e.what()));
    }
}
