#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_visual_algorithm.h"

class visual_algorithm : public QMainWindow
{
    Q_OBJECT

public:
    visual_algorithm(QWidget *parent = Q_NULLPTR);
	
private:
    Ui::visual_algorithmClass ui;
};
