#include "error_list.h"


void catch_error(err_t error)
{
    switch(error)
    {
        case ERR_FILE_OPEN:
            QMessageBox :: warning(NULL, "Ошибка", "Невозможно открыть файл с данными");
        case ERR_DATA:
            QMessageBox :: warning(NULL, "Ошибка", "Неверно заданы данные");
            break;
        case ERR_MEMORY_ALLOCATE:
            QMessageBox :: warning(NULL, "Ошибка", "Невозможно выделить память");
            break;
        case ERR_NO_FIELD:
            QMessageBox :: warning(NULL, "Ошибка", "Не выделено поле для отрисовки фигуры");
            break;
        case ERR_NO_FIGURE:
            QMessageBox :: warning(NULL, "Ошибка", "Фигура не задана");
            break;
        default:
            QMessageBox :: warning(NULL, "Ошибка", "Непредвиденная ситуация");
            break;
    }
}
