#ifndef CGRAPHICMAINVIEW_H
#define CGRAPHICMAINVIEW_H

#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsScene>
#include <cmath>
#include <cstructure.h>
#include <QTimer>
#include <QSize>
#include <QPoint>
#include <QObject>
#include "cgraphicbuildingtile.h"

/**
 * @brief Klasa CGraphicMainView (widok główny gry)
 *
 *Klasa nadrzędna dla widoku. Zarządza m.in wyświetlaniem, przesyłaniem informacji do grafik, skalowaniem.
 *Graficzne elementy mapy są dodawanie do niej.
 */
class CGraphicMainView : public QGraphicsView, public IDisplayingInterface
{
    Q_OBJECT
private:
    ///Poprzednie położenie kursora myszki we współrzędnych widoku.
    QPoint beforeCursorPoint;
    ///Pixmapa tła.
    QPixmap* actualPixMap;
    /**
     * @brief Żeton ruchomy.
     *
     *Wskaźnik do aktualnie ruchomego żetonu, który przesuwa się z myszką.
     *Wykorzystywany jako pomocniczy widok wybranego budynku dla gracza.
     */
    CGraphicGameTile* movingTile;

public:
    /**
     * @brief CGraphicMainView - konstruktor
     *
     *Konstruktor inicjalizuje obiekt parametrami.
     * @param _gameMap - rozmiar mapy w żetonach
     * @param _tileSize - rozmiar żetonu w pixelach
     * @param parent - "rodzic" obiektu
     */
    CGraphicMainView(QSize _gameMap = QSize(100,60), QSize _tileSize = QSize(50,50),QWidget *parent = 0);
    ///Ustaw rozmiar żetonu.
    void setTileSize(QSize _size);
    ///Ustaw rozmiar mapy w żetonach.
    void setGameMapSize(QSize _size);
    /**
     * @brief initializeGameMap
     *
     *Metoda odpowiedzialna za poprawne zainicjalizowanie mapy gry.
     *Powoduje stworzenie odpowiednich zmiennych oraz narysowanie tła i żetonów tła mapy.
     */
    void initializeGameMap();
    /**
     * @brief Znajdź odpowiednią grafikę.
     *
     *Reimplementacja metody. Szuka odpowiedniej grafiki w zależności od rodzaju budynku.
     * @param _S - wskaźnik do budynku
     * @return Zwraca znalezioną pixmapę. Jesli nie znaleziono, zwraca grafikę "no image".
     */
    virtual QPixmap findGraphicForBuilding(CStructure *_S);

protected:
    ///Scena.
    QGraphicsScene* scene;
    ///Rozmiar żetonu w pixelach.
    QSize tileSize;
    ///Rozmiar mapy w żetonach.
    QSize gameMapSize;

    ///Wskaźnik do aktualnie wybranej i "niesionej" struktury.
    CStructure *curentHoldingStructure;
    /**
     * @brief Współczynnik skali.
     *
     *Określa aktualną skalę widoku.
     */
    qreal actualFactor;
    /**
     * @brief Czy struktura jest "niesiona"
     *
     *Określa czy w danym momencie jest przyczepiona do kursora struktura.
     */
    bool structureHolding;

#ifndef QT_NO_WHEELEVENT
    /**
     * @brief wheelEvent
     *
     *Pozwala na wychwytywanie ruchu kółkiem scrolla myszki.
     */
    void wheelEvent(QWheelEvent *);
#endif
    /**
     * @brief Skaluj widok.
     *
     *Metoda pozwala na poprawne przeskalowanie widoku po wykryciu\b wheelEvent\c'a
     * @param scaleFactor - współczynniki skali
     * @param event
     */
    void scaleView(qreal scaleFactor, QWheelEvent *event);
    /**
     * @brief Ruch myszki.
     *
     *Pozwala na wykrycie ruchu myszki po widoku i odczytanie aktualnego położenia.
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief Wydarzenie wciśnięcia klawisza klawiatury.
     *
     *Pozwala na obrót przyczepionego do kursora obiektu oraz anulowanie wyboru.
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);

signals:
    /**
     * @brief Odśwież widok pod budynkiem.
     *
     *Sygnał wysyłany jest kiedy należy odświeżyć widok w okolicach niesionego budynku.
     * @param QBrush - "pędzel"
     * @param QSize - koordynaty lewego górnego rogu budynku
     * @param QSize - wymiary budynku
    */
    void repaintAreaUnderBuilding(QBrush,QSize, QSize);
    /**
     * @brief Sprawdź czy można wybudować.
     *
     *Sygnał wysyłany po próbie postawienia nowego elementu na planszy.
     *@param CStructure* - wskaźnik do struktury
     */
    void checkIfCanBeBuiled(CStructure *);
    /**
     * @brief Usuń strukturę.
     *
     *Sygnał wysyłany przy próbie usunięcia struktury z planszy.
     *@param CStructure* - wskaźnik do struktury
     */
    void removeStructure(CStructure*);
private slots:
    /**
     * @brief Nowa struktura wybrana.
     *
     *Metoda powoduje poprawne odłączenie poprzeniej i przyczepienie nowej struktury do kursora myszki.
     *@param CStructure* - wskaźnik do struktury
     */
    void newStructureChosen(CStructure *);
    /**
     * @brief Ruch myszki odświeżanie.
     *
     *Implementacja odświeżania podczas ruchu myszki.
     *Pozwala na poprawne odświeżanie widoku podczas ruchu myszki, np. z przyczepionym do kursora obiektem.
     *Odpowiedzialna za podświetlanie miejsca wybudowania budynku.
     * @param event
     */
    void mouseMoveRepaint(QMouseEvent *);
    /**
     * @brief Kliknięcie pustego żetonu.
     *
     *Po próbie postawienia żetonu, konwertowane są współrzędne z widoku na współrzędne w modelu i emitowany sygnał\b Sprawdź czy można wybudować.
     */
    void emptyTileMouseClicked(CGraphicGameTile*,QPointF,QGraphicsSceneMouseEvent *);
    ///Wybuduj strukturę.
    void buildStructure(CStructure*,bool);
    ///Usuń żeton.
    void removeTile(CGraphicBuildingTile*,CStructure *);
};

#endif // CGRAPHICMAINVIEW_H
