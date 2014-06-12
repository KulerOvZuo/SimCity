#ifndef CGRAPHICTAXES_H
#define CGRAPHICTAXES_H

#include <QtWidgets>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QCloseEvent>

/**
 * @brief Klasa CGraphicTaxes (graficzne przedstawienie menadżera podatków).accept();
 *
 *Klasa pozwala na graficzne przedstawienie menadżera podatków.
 *Łączy informacje wyświetlane z modelem i aktualizuje model w razie potrzeby.
 */
class CGraphicTaxes : public QDialog
{
    Q_OBJECT
public:
    explicit CGraphicTaxes(QWidget *parent = 0);

    ///Pobierz wartość podatków od produkcji.
    int getFromProductionInd() const {return fromProductionInd;}
    ///Pobierz wartość podatków od ludzi.
    int getFromPeopleInd()const {return fromPeopleInd;}
    ///Pobierz wartość podatków od innych.
    int getFromOthersInd()const {return fromOthersInd;}
    ///Ustaw wszystkie wartości podatków.
    void setValues(int _prod, int _people, int _others);

protected:
    ///Wartość podatków od produkcji.
    int fromProductionInd;
    ///Wartość podatków od ludzi.
    int fromPeopleInd;
    ///Wartość podatków od innych.
    int fromOthersInd;

    QVBoxLayout *mainLayout;
    QLabel *fromProductionIndText;
    QLabel *fromPeopleIndText;
    QLabel *fromOthersIndText;
    QSlider *sliderFromProd;
    QSlider *sliderFromPeople;
    QSlider *sliderFromOthers;
    QLineEdit *editFromProd;
    QLineEdit *editFromPeople;
    QLineEdit *editFromOthers;
    QPushButton *OK;

    ///Połącz sygnały i sloty.
    void connectSignalsSlots();

signals:
    /**
     * @brief Wartości podatków zmienione.
     *
     *Emitowany kiedy następuje zmiana wartości podatków w widoku.
     */
    void taxesChanged();
    /**
     * @brief Czytaj podatki z modelu.
     *
     *Odczytuje aktualne podatki wprowadzone w modelu.
     */
    void taxesRead();

public slots:
    void show();
private slots:

    /**
     * @brief  Wartość podatków od produkcji zmieniona.
     *
     *@param int - nowa wartość
     */
    void fromProductionIndChanged(int);
    /**
     * @brief  Wartość podatków od ludzi zmieniona.
     *
     *@param int - nowa wartość
     */
    void fromPeopleIndChanged(int);
    /**
     * @brief  Wartość podatków od innych zmieniona.
     *
     *@param int - nowa wartość
     */
    void fromOthersIndChanged(int);
    /**
     * @brief Wyślij informacje.
     *
     *Powoduje wysłanie informacji o zmianach podatków do modelu.
     */
    void sendInfo();
};

#endif // CGRAPHICTAXES_H
